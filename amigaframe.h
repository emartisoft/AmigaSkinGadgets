#ifndef AMIGAFRAME_H
#define AMIGAFRAME_H

#include <QFrame>
#include <QPainter>
#include "amigacolors.h"

class AmigaFrame : public QFrame
{
    Q_OBJECT
public:
    AmigaFrame(QWidget *parent, int w, int h, int x, int y, bool caroTile=false);
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    bool m_caroTile;
};

#endif // AMIGAFRAME_H
