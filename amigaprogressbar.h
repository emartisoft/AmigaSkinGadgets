#ifndef AMIGAPROGRESSBAR_H
#define AMIGAPROGRESSBAR_H

#include <QProgressBar>
#include "amigacolors.h"

class AmigaProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    AmigaProgressBar(QWidget *parent,
                     int w, int h,
                     int x, int y,
                     int value=0,
                     int maxValue=100,
                     bool textVisible=false);
};

#endif // AMIGAPROGRESSBAR_H
