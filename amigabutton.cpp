#include "amigabutton.h"

AmigaButton::AmigaButton(QWidget *parent,
                       QString normalImage,
                       QString hoverImage,
                       QString pressImage,
                       int x, int y,
                         const QString& text) : QPushButton(parent)
{
    currentStatus = NORMAL;
    imageName[NORMAL] = normalImage;
    imageName[HOVER] = hoverImage;
    imageName[PRESS] = pressImage;

    QPixmap img;
    img.load(normalImage);
    w = img.width();
    h = img.height();
    setGeometry(x, y, w, h);

    noText = text.length()==0;
}

void AmigaButton::setTextColor(QColor c)
{
    setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(c.red(),3,10).arg(c.green(),3,10).arg(c.blue(),3,10));
}

void AmigaButton::enterEvent(QEnterEvent *)
{
    currentStatus = HOVER;
    update();
}

void AmigaButton::leaveEvent(QEvent *)
{
    currentStatus = NORMAL;
    update();
}

void AmigaButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        currentStatus = PRESS;
        update();
    }
}

void AmigaButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        currentStatus = HOVER;
        update();
    }
    if(rect().contains(event->pos())) emit clicked();
}

void AmigaButton::paintEvent(QPaintEvent *)
{
    //QPushButton::paintEvent(event);
    QPainter painter(this);
    QPixmap pixmap(imageName[currentStatus]);
    painter.drawPixmap(rect(), pixmap);
    if(!noText)
    {
        const QRect rectangle = QRect(0, 0, w, h);
        QRect boundingRect;
        painter.drawText(rectangle, Qt::AlignHCenter | Qt::AlignVCenter, "Button", &boundingRect);
    }
}
