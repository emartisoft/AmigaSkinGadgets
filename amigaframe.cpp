#include "amigaframe.h"

AmigaFrame::AmigaFrame(QWidget *parent, int w, int h, int x, int y, bool caroTile)
    :QFrame(parent)
{
    setGeometry(QRect(x,y,w,h));
    m_caroTile = caroTile;
    update();
}

void AmigaFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(m_caroTile)
    {
        painter.drawTiledPixmap(QRect(0,0,width(),height()), QPixmap(":/pics/karo.png"));
    }
    else
    {
        painter.fillRect(QRect(0,0,width(),height()), QBrush(GRAY));
        painter.setPen(BLACK);
        painter.drawLine(0,0,width()-1,0);
        painter.drawLine(0,0,0,height()-1);
        painter.setPen(WHITE);
        painter.drawLine(width()-1,0,width()-1,height()-1);
        painter.drawLine(0,height()-1,width()-1,height()-1);
        painter.setPen(GRAY);
        painter.drawPoint(QPoint(0, height()-1));
        painter.drawPoint(QPoint(width()-1, 0));
    }
}
