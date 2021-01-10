#include "amigahorizontalline.h"

AmigaHorizontalLine::AmigaHorizontalLine(QWidget *parent, int w, int x, int y) : QFrame(parent)
{
    setGeometry(QRect(x,y,w,2));
    setFixedHeight(2);
    setStyleSheet(QString::fromUtf8("background-image: url(:/pics/line.png);"));
}
