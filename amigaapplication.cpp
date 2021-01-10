#include "amigaapplication.h"

AmigaApplication::AmigaApplication(int &argc, char **argv) :
    QApplication(argc, argv)
{
    // add font
    QFontDatabase::addApplicationFont(":/font/AmigaTopazTurkish.ttf");
    // font
    setFont(QFont("AmigaTopazTurkish", 12));
}
