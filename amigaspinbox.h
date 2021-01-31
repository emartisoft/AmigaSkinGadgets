#ifndef AMIGASPINBOX_H
#define AMIGASPINBOX_H

#include <QFrame>
#include <QPainter>
#include <QSpinBox>
#include <QTimer>
#include "amigacolors.h"
#include "amigabutton.h"

class AmigaSpinBox : public QFrame
{
    Q_OBJECT
public:
    explicit AmigaSpinBox(QWidget* parent,
                        int w,
                        int h,
                        int x,
                        int y);
    void setFont(QFont &font);
    void setValue(int value);
    int value();
    void setMinimum(int min);
    void setMaximum(int max);

private slots:
    void spinButtonPressed();
private:
       QSpinBox *spinBox;
       AmigaButton *upDown;
       QTimer *timer;
       void setPressImage();
       bool isPointInTriangle();
protected:
       virtual void paintEvent(QPaintEvent*);
};

#endif // AMIGASPINBOX_H
