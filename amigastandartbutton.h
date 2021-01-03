#ifndef AMIGASTANDARTBUTTON_H
#define AMIGASTANDARTBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QPoint>
#include <QtWidgets>
#include "amigacolors.h"

class AmigaStandartButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AmigaStandartButton(QWidget* parent,
                        int w,
                        int h,
                        int x,
                        int y,
                        const QString& text=""
                        );
    void setTextColor(QColor c);

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    //virtual void enterEvent(QEnterEvent*);
    //virtual void leaveEvent(QEvent*);

private:
    bool pressed;
};

#endif // AMIGASTANDARTBUTTON_H
