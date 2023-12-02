#include "BitCalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{

QApplication app(argc, argv);

BitCalculator *bitcalculator = new BitCalculator;
bitcalculator->show();

return app.exec();
}
