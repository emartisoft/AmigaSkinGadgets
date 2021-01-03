#include "amigastandartbutton.h"

AmigaStandartButton::AmigaStandartButton(QWidget *parent,
                                         int w, int h,
                                         int x, int y,
                                         const QString &text)
    : QPushButton(text, parent)
{
    setGeometry(x, y, w, h);
    pressed=false;
    update();
}

void AmigaStandartButton::setTextColor(QColor c)
{
    setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(c.red(),3,10).arg(c.green(),3,10).arg(c.blue(),3,10));
}

void AmigaStandartButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(QRect(0,0,width(),height()), QBrush((pressed)?BLUE:GRAY));
    painter.setPen((pressed)?WHITE:BLACK);
    painter.drawRect(0,0,width()-1,height()-1);
    painter.drawRect(0,0,width()-2,height()-1);
    painter.setPen((pressed)?BLACK:WHITE);
    painter.drawLine(0,0,width()-2,0);
    painter.drawLine(0,0,0,height()-1);
    painter.drawLine(1,0,1,height()-2);
    painter.setPen(BLACK);
    const QRect rectangle = QRect(0, 0, width(), height());
    QRect boundingRect;
    painter.drawText(rectangle, Qt::AlignHCenter | Qt::AlignVCenter, text(), &boundingRect);
}

void AmigaStandartButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pressed = true;
        update();
    }
}

void AmigaStandartButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pressed = false;
        update();
    }
     if(rect().contains(event->pos())) emit clicked();
}

/*
void AmigaStandartButton::enterEvent(QEnterEvent *)
{

}

void AmigaStandartButton::leaveEvent(QEvent *)
{

}
*/
