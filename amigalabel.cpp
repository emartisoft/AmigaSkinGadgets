#include "amigalabel.h"

AmigaLabel::AmigaLabel(QWidget *parent,
                       int w, int h,
                       int x, int y,
                       const QString &text)
: QLabel(text, parent)
{
    setGeometry(x, y, w, h);
    setAttribute(Qt::WA_TranslucentBackground);
}

void AmigaLabel::setTextColor(QColor c)
{
    setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(c.red(),3,10).arg(c.green(),3,10).arg(c.blue(),3,10));
}
