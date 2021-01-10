#include "amigacheckbox.h"

AmigaCheckBox::AmigaCheckBox(QWidget *parent,
                             int w, int h,
                             int x, int y,
                             const QString &text,
                             bool checkedIt)
    : QCheckBox(text, parent)
{
    setGeometry(x,y,w,h);
    setChecked(checkedIt);
    setTextColor(BLACK);
}

void AmigaCheckBox::setTextColor(QColor c)
{
    setStyleSheet(QString("QCheckBox::indicator:checked { image: url(:/pics/unchecked.png);}\n"
                          "QCheckBox::indicator:unchecked {image: url(:/pics/checked.png);}\n"
                          "QCheckBox{ color: rgb(%1, %2, %3);}"
                          ).arg(c.red(),3,10).arg(c.green(),3,10).arg(c.blue(),3,10));
}
