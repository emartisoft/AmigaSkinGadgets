#ifndef AMIGAHORIZONTALSLIDER_H
#define AMIGAHORIZONTALSLIDER_H

#include <QSlider>

class AmigaHorizontalSlider : public QSlider
{
    Q_OBJECT
public:
    AmigaHorizontalSlider(QWidget *parent, int x, int y, int value=0, int maxValue=10);
};

#endif // AMIGAHORIZONTALSLIDER_H
