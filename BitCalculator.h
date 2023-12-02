#ifndef BITCALCULATOR_H
#define BITCALCULATOR_H

#include <QWidget>
#include <QMainWindow>
#include <QMap>
#include <QStatusBar>
#include <QMessageBox>
#include <ui_BitCalculator.h>

#define LEFT  0
#define RIGHT 1

#define NO_BUTTON	1

#define CALC_NONE	0
#define CALC_AND	1
#define CALC_OR	2
#define CALC_XOR	3
#define CALC_NAND	4
#define CALC_NOR	5
#define CALC_XNOR	6
#define CALC_MODULO	7

#define NO_OPERATION_TEXT "Nothing to do"
#define EMPTY_TEXT ""
#define MATH_ERROR_TEXT "Math operation error. Division by zero."

namespace Ui {
class BitCalculator;
}

class BitCalculator : public QMainWindow
{
     Q_OBJECT

public:
    explicit BitCalculator(QWidget *parent = 0);
    ~BitCalculator();
	//enum Mode { NavigationMode, AddingMode, EditingMode };

public slots:
	void ChangeHex_Row1();
	void ChangeDec_Row1();
	void ChangeBin_Row1();
	void ChangeHex_Row2();
	void ChangeDec_Row2();
	void ChangeBin_Row2();
	void Shift_Row1(int shift);
	void Shift_Row2(int shift);
	void CalcAND(bool button);
	void CalcOR(bool button);
	void CalcXOR(bool button);
	void CalcNAND(bool button);
	void CalcNOR(bool button);
	void CalcXNOR(bool button);
	void CalcMODULO(bool button);
	void about();
	void aboutQt();

private:
    Ui::BitCalculatorClass *ui;

	QPalette palette;
	QAction *aboutAct;
	QLabel* statusbar_label;
	QMap<QString, unsigned long> Value_List;	// QMap<key, value>
	int oldshiftValue_Row1;
	int oldshiftValue_Row2;
	int CalcExecuted;
	void SaveValues_Row1(QString str);
	void SaveValues_Row2(QString str);
	void UpdateValues_Row1();
	void UpdateValues_Row2();
	void UpdateValues_Row3();
	void ChangeBin_Row3();
	void AdjustValues();
	void AlignBinValue( int row );
	void Del_Shift_Value(int row);
	void Execute_Calc();
	void UpdateButtonColor( int button );
	void UpdateCheckedButtons( int button );

//	void updateInterface(Mode mode);

//	Mode currentMode;
};

#endif

