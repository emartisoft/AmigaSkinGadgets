#ifndef AMIGACHECKBOX_H
#define AMIGACHECKBOX_H

#include <QCheckBox>
#include "amigacolors.h"

class AmigaCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit AmigaCheckBox(QWidget *parent,
                           int w, int h,
                           int x, int y,
                           const QString &text, bool checkedIt=false);
    void setTextColor(QColor c);
};

#endif // AMIGACHECKBOX_H
