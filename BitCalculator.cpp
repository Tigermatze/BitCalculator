#include "BitCalculator.h"
#include <QtGui>

BitCalculator::BitCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BitCalculatorClass)
{
    ui->setupUi(this);

	oldshiftValue_Row1 = 0;
	oldshiftValue_Row2 = 0;

	CalcExecuted = 0;

	Value_List["Value_Row1"] = 0;
	Value_List["Value_Row2"] = 0;
	Value_List["Value_Row3"] = 0;

    ui->hexEdit_Row3->setText("0");
    ui->decEdit_Row3->setText("0");
    //ui->binEdit_Row3->setText("0");

    //statusBar()->layout()-setMargin(0);
    statusBar()->layout()->setSpacing(0);

    statusbar_label = new QLabel( "", statusBar());
    QLabel *xValue = new QLabel( "xValue ", statusBar());
    xValue->setFixedWidth( 100 );

    //http://doc.trolltech.com/4.5/qframe.html
    xValue->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    statusbar_label->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    xValue->setText("mathiasjost.de");

    statusBar()->addWidget(statusbar_label, 1);
    statusBar()->addWidget(xValue , 0);

    connect(ui->hexEdit_Row1, SIGNAL(textEdited(QString)), this, SLOT(ChangeHex_Row1()));
    connect(ui->decEdit_Row1, SIGNAL(textEdited(QString)), this, SLOT(ChangeDec_Row1()));
    connect(ui->binEdit_Row1, SIGNAL(textEdited(QString)), this, SLOT(ChangeBin_Row1()));
    connect(ui->hexEdit_Row2, SIGNAL(textEdited(QString)), this, SLOT(ChangeHex_Row2()));
    connect(ui->decEdit_Row2, SIGNAL(textEdited(QString)), this, SLOT(ChangeDec_Row2()));
    connect(ui->binEdit_Row2, SIGNAL(textEdited(QString)), this, SLOT(ChangeBin_Row2()));
    connect(ui->shiftSpinBox_Row1, SIGNAL(valueChanged(int)), this, SLOT(Shift_Row1(int)));
    connect(ui->shiftSpinBox_Row2, SIGNAL(valueChanged(int)), this, SLOT(Shift_Row2(int)));
    connect(ui->andButton, SIGNAL(clicked(bool)), this, SLOT(CalcAND(bool)));
    connect(ui->orButton, SIGNAL(clicked(bool)), this, SLOT(CalcOR(bool)));
    connect(ui->xorButton, SIGNAL(clicked(bool)), this, SLOT(CalcXOR(bool)));
    connect(ui->nandButton, SIGNAL(clicked(bool)), this, SLOT(CalcNAND(bool)));
    connect(ui->norButton, SIGNAL(clicked(bool)), this, SLOT(CalcNOR(bool)));
    connect(ui->xnorButton, SIGNAL(clicked(bool)), this, SLOT(CalcXNOR(bool)));
    connect(ui->moduloButton, SIGNAL(clicked(bool)), this, SLOT(CalcMODULO(bool)));

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));
}

BitCalculator::~BitCalculator()
{}

void BitCalculator::about()
{
    QMessageBox msgBox;
    QPixmap pixmap(":/Bilder/Bilder/MaJ_Logo.png");
    pixmap = pixmap.scaledToWidth(200,Qt::FastTransformation);

    msgBox.setIconPixmap(pixmap);

    msgBox.setText("BitCalculator is a free Tool written in Qt. \n"
                   "v1.04\n\n"
                   "Dipl. Inform. (Fh) \n"
                   "Mathias Jost \n\n"
                   "For technical support see: \n"
                   "https://github.com/Tigermatze/");

    msgBox.exec();
}

void BitCalculator::aboutQt()
{
	   QMessageBox::aboutQt(this, tr("About Qt"));
}

void BitCalculator::ChangeHex_Row1()
{
	   bool ok;
       QString str = ui->hexEdit_Row1->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row1"] = (str.toULong(&ok,16));
       ui->shiftSpinBox_Row2->setValue(0);
	   Del_Shift_Value(1);
	   UpdateValues_Row1();
}

void BitCalculator::ChangeDec_Row1()
{
	   bool ok;
       QString str = ui->decEdit_Row1->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row1"] = (str.toULong(&ok,10));
       ui->shiftSpinBox_Row2->setValue(0);
	   Del_Shift_Value(1);
       UpdateValues_Row1();
}

void BitCalculator::ChangeBin_Row1()
{
	   bool ok;
       QString str = ui->binEdit_Row1->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row1"] = (str.toULong(&ok,2));
       ui->shiftSpinBox_Row2->setValue(0);
	   Del_Shift_Value(1);
	   UpdateValues_Row1();
}

void BitCalculator::ChangeHex_Row2()
{
	   bool ok;
       QString str = ui->hexEdit_Row2->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row2"] = (str.toULong(&ok,16));
       ui->shiftSpinBox_Row2->setValue(0);
	   UpdateValues_Row2();
}

void BitCalculator::ChangeDec_Row2()
{
	   bool ok;
       QString str = ui->decEdit_Row2->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row2"] = (str.toULong(&ok,10));
       ui->shiftSpinBox_Row2->setValue(0);
	   UpdateValues_Row2();
}

void BitCalculator::ChangeBin_Row2()
{
	   bool ok;
       QString str = ui->binEdit_Row2->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row2"] = (str.toULong(&ok,2));
       ui->shiftSpinBox_Row2->setValue(0);
	   UpdateValues_Row2();
}

void BitCalculator::ChangeBin_Row3()
{
	   bool ok;
       QString str = ui->binEdit_Row3->text();
	   str.replace(QString(" "), QString(""));
	   Value_List["Value_Row3"] = (str.toULong(&ok,2));
	   UpdateValues_Row3();
}

void BitCalculator::UpdateValues_Row1()
{
	  // QMessageBox::critical(this, "",QString::number(Value_List["Value_Row1"],16));
       ui->hexEdit_Row1->setText(QString::number(Value_List["Value_Row1"],16));
       ui->decEdit_Row1->setText(QString::number(Value_List["Value_Row1"],10));
       ui->binEdit_Row1->setText(QString::number(Value_List["Value_Row1"],2));
	   AdjustValues();
	   Execute_Calc();
}

void BitCalculator::UpdateValues_Row2()
{
       ui->hexEdit_Row2->setText(QString::number(Value_List["Value_Row2"],16));
       ui->decEdit_Row2->setText(QString::number(Value_List["Value_Row2"],10));
       ui->binEdit_Row2->setText(QString::number(Value_List["Value_Row2"],2));
	   AdjustValues();
	   Execute_Calc();
}

void BitCalculator::UpdateValues_Row3()
{
       ui->hexEdit_Row3->setText(QString::number(Value_List["Value_Row3"],16));
       ui->decEdit_Row3->setText(QString::number(Value_List["Value_Row3"],10));
       ui->binEdit_Row3->setText(QString::number(Value_List["Value_Row3"],2));
	   AdjustValues();
}

void BitCalculator::Del_Shift_Value(int row)
{
	   switch(row)
	   {
	   case( 1 ):
			 oldshiftValue_Row1 = 0;
             ui->shiftSpinBox_Row1->setValue(0);
			 break;
	   case( 2 ):
			 oldshiftValue_Row2 = 0;
             ui->shiftSpinBox_Row2->setValue(0);
			 break;
	   }
}

void BitCalculator::Shift_Row1(int shift)
{
	unsigned long value = Value_List["Value_Row1"];

	if ( shift > oldshiftValue_Row1 ){
		value <<= 1;
		Value_List["Value_Row1"] = value;
		UpdateValues_Row1();
	}
	else if ( shift < oldshiftValue_Row1 ){
		value >>= 1;
		Value_List["Value_Row1"] = value;
		UpdateValues_Row1();
	}
	oldshiftValue_Row1 = shift;
	AdjustValues();
}

void BitCalculator::Shift_Row2(int shift)
{
	unsigned long value = Value_List["Value_Row2"];

	if ( shift > oldshiftValue_Row2 ){
		value <<= 1;
		Value_List["Value_Row2"] = value;
		UpdateValues_Row2();
	}
	else if ( shift < oldshiftValue_Row2 ){
		value >>= 1;
		Value_List["Value_Row2"] = value;
		UpdateValues_Row2();
	}
	oldshiftValue_Row2 = shift;
	AdjustValues();
}

void BitCalculator::Execute_Calc()
{
	   switch ( CalcExecuted )
	   {
	   case ( CALC_AND ):
			 CalcAND(NO_BUTTON);
			 break;
	   case ( CALC_OR ):
			 CalcOR(NO_BUTTON);
			 break;
	   case ( CALC_XOR ):
			 CalcXOR(NO_BUTTON);
			 break;
	   case ( CALC_NAND ):
			 CalcNAND(NO_BUTTON);
			 break;
	   case ( CALC_NOR ):
			 CalcNOR(NO_BUTTON);
			 break;
	   case ( CALC_XNOR ):
			 CalcXNOR(NO_BUTTON);
			 break;
	   case ( CALC_MODULO ):
			 CalcMODULO(NO_BUTTON);
			 break;
	   }
}

void BitCalculator::CalcAND(bool button)
{
	if ( !button && CalcExecuted == CALC_AND ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_AND;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] & Value_List["Value_Row2"];
		CalcExecuted = CALC_AND;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_AND);
}

void BitCalculator::CalcOR(bool button)
{
	if ( !button && CalcExecuted == CALC_OR ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_OR;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] | Value_List["Value_Row2"];
		CalcExecuted = CALC_OR;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_OR);
}

void BitCalculator::CalcXOR(bool button)
{
	if ( !button && CalcExecuted == CALC_XOR ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_XOR;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] ^ Value_List["Value_Row2"];
		CalcExecuted = CALC_XOR;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_XOR);
}

void BitCalculator::CalcNAND(bool button)
{
	if ( !button && CalcExecuted == CALC_NAND ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_NAND;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] & Value_List["Value_Row2"];
		Value_List["Value_Row3"] = ~Value_List["Value_Row3"];
		CalcExecuted = CALC_NAND;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_NAND);
}

void BitCalculator::CalcNOR(bool button)
{
	if ( !button && CalcExecuted == CALC_NOR ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
    else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_NOR;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] | Value_List["Value_Row2"];
		Value_List["Value_Row3"] = ~Value_List["Value_Row3"];
		CalcExecuted = CALC_NOR;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_NOR);
}

void BitCalculator::CalcXNOR(bool button)
{
	if ( !button && CalcExecuted == CALC_XNOR ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_XNOR;
		statusbar_label->setText(NO_OPERATION_TEXT);
	}
	else{
		Value_List["Value_Row3"] = Value_List["Value_Row1"] ^ Value_List["Value_Row2"];
		Value_List["Value_Row3"] = ~Value_List["Value_Row3"];
		CalcExecuted = CALC_XNOR;
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_XNOR);
}

void BitCalculator::CalcMODULO(bool button)
{
	if ( !button && CalcExecuted == CALC_MODULO ){
		CalcExecuted = CALC_NONE;
		Value_List["Value_Row3"] = 0;
		statusbar_label->setText(EMPTY_TEXT);
	}
	else if ( !Value_List["Value_Row1"] || !Value_List["Value_Row2"] ){
		CalcExecuted = CALC_MODULO;
		statusbar_label->setText(MATH_ERROR_TEXT);
	}
	else {
		CalcExecuted = CALC_MODULO;
		Value_List["Value_Row3"] = Value_List["Value_Row1"] % Value_List["Value_Row2"];
		statusbar_label->setText(EMPTY_TEXT);
		AdjustValues();
	}

	UpdateValues_Row3();
	UpdateButtonColor(CalcExecuted);
	UpdateCheckedButtons(CALC_MODULO);
}

/*
* Fuellt die kleinere Zahl mit fuehrenden Nullen auf.
*/
void BitCalculator::AdjustValues()
{
	   bool ok;
	   int i = 0;
	   QString newstring = "";

	   QString value_row1 = QString::number(Value_List["Value_Row1"],2);
	   QString value_row2 = QString::number(Value_List["Value_Row2"],2);
	   QString value_row3 = QString::number(Value_List["Value_Row3"],2);

	   if ( !Value_List["Value_Row1"] && !Value_List["Value_Row2"] )
		   return;

       int count_row1 = value_row1.size();
       int count_row2 = value_row2.size();
       int count_row3 = value_row3.size();

	   // kleinere Zahl mit fuehrenden Nullen versehen
	   if ( count_row1 > count_row2 && Value_List["Value_Row2"] ){
			 for ( i = 0; i < (count_row1-count_row2); i++ )
			 	newstring.append("0");
 		  newstring.append(value_row2);
          ui->binEdit_Row1->setText(value_row1);
          ui->binEdit_Row2->setText(newstring);
	   }
	   else if ( count_row1 < count_row2 && Value_List["Value_Row1"] ){
			 for ( i = 0; i < (count_row2-count_row1); i++ )
			 	newstring.append("0");
		  newstring.append(value_row1);
          ui->binEdit_Row1->setText(newstring);
          ui->binEdit_Row2->setText(value_row2);
	   }
	   else{
             if ( Value_List["Value_Row1"] ) ui->binEdit_Row1->setText(value_row1);
             if ( Value_List["Value_Row2"] ) ui->binEdit_Row2->setText(value_row2);
	   }

	   // Ergebnis mit fuehrenden Nullen versehen
	   if ( CalcExecuted ){
			 newstring = "";
             value_row1 = ui->binEdit_Row1->text();
			 value_row1.replace(QString(" "), QString(""));
             count_row1 = value_row1.size();

			 if ( count_row1 > count_row3 ){
				    for ( i = 0; i < (count_row1-count_row3); i++ ){
					   newstring.append("0");
				    }
				newstring.append(value_row3);
                ui->binEdit_Row3->setText(newstring);
			 }
			 else if ( count_row1 < count_row3 ){
				    value_row3 = value_row3.right(count_row1);	// die letzten Ziffern nehmen
				    Value_List["Value_Row3"] = value_row3.toInt(&ok,2);
				    UpdateValues_Row3();

				    // Falls eine fuehrende Null entfernt wird, diese wieder auffuellen
                    value_row3 = ui->binEdit_Row3->text();
                    count_row3 = value_row3.size();
				    if ( count_row1 > count_row3 )
						  for ( i = 0; i < (count_row1-count_row3); i++ )
							   newstring.append("0");
				    newstring.append(value_row3);
                    ui->binEdit_Row3->setText(newstring);
			 }
			 else
                    ui->binEdit_Row3->setText(value_row3);
	   }

	   AlignBinValue(1);
	   AlignBinValue(2);
	   AlignBinValue(3);
}

void BitCalculator::AlignBinValue( int row )
{
	   int i;
	   int quarters;
	   QString newvalue = "";
	   QString value;

	   switch ( row ){
	   case (1):
             value = ui->binEdit_Row1->text();
			 break;
	   case (2):
             value = ui->binEdit_Row2->text();
			 break;
	   case (3):
             value = ui->binEdit_Row3->text();
			 break;
	   }

	   value.replace(QString(" "), QString(""));
       int count = value.size();
	   quarters = count / 4;

	   for ( i = 1; i <= quarters; i++ ){
			 newvalue.prepend(value.mid(count-4*i,4));
			 newvalue.prepend(" ");
	   }
	   // wenn kein Rest, dann fuehrende Lehrtaste entfernen
	   if ( (4*quarters) == count ){
			 newvalue = newvalue.mid(1,newvalue.length());
	   }
	   else
			 newvalue.prepend(value.mid(0,count-4*quarters));

	   //QMessageBox::critical(this, "",newvalue);
	   switch ( row ){
	   case (1):
             ui->binEdit_Row1->setText(newvalue);
			 break;
	   case (2):
             ui->binEdit_Row2->setText(newvalue);
			 break;
	   case (3):
             ui->binEdit_Row3->setText(newvalue);
			 break;
	   }
	   //QMessageBox::critical(this, "",QString::number(Value_List["Value_Row1"],2));
}

/*
* Setzt gecheckte Buttons zurueck.
*/
void BitCalculator::UpdateCheckedButtons( int button )
{
       if ( button != CALC_AND ) ui->andButton->setChecked(0);
       if ( button != CALC_OR ) ui->orButton->setChecked(0);
       if ( button != CALC_NOR ) ui->norButton->setChecked(0);
       if ( button != CALC_NAND ) ui->nandButton->setChecked(0);
       if ( button != CALC_XNOR ) ui->xnorButton->setChecked(0);
       if ( button != CALC_XOR ) ui->xorButton->setChecked(0);
       if ( button != CALC_MODULO ) ui->moduloButton->setChecked(0);
}

void BitCalculator::UpdateButtonColor( int button )
{
	   QBrush brush1(QColor(0, 0, 0, 255));
	   brush1.setStyle(Qt::SolidPattern);
	   palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
       ui->andButton->setPalette(palette);
       ui->orButton->setPalette(palette);
       ui->nandButton->setPalette(palette);
       ui->norButton->setPalette(palette);
       ui->xorButton->setPalette(palette);
       ui->xnorButton->setPalette(palette);
       ui->moduloButton->setPalette(palette);

	   QBrush brush(QColor(255, 0, 0, 255));
	   brush.setStyle(Qt::SolidPattern);
	   palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);

	   switch ( button )
	   {
	   case ( CALC_AND ):
             ui->andButton->setPalette(palette);
			 break;
	   case ( CALC_OR ):
             ui->orButton->setPalette(palette);
			 break;
	   case ( CALC_XOR ):
             ui->xorButton->setPalette(palette);
			 break;
	   case ( CALC_NAND ):
             ui->nandButton->setPalette(palette);
			 break;
	   case ( CALC_NOR ):
             ui->norButton->setPalette(palette);
			 break;
	   case ( CALC_XNOR ):
             ui->xnorButton->setPalette(palette);
			 break;
	   case ( CALC_MODULO ):
             ui->moduloButton->setPalette(palette);
			 break;
	   default:
		   break;
	   }
}

