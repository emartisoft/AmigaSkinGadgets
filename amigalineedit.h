#ifndef AMIGALINEEDIT_H
#define AMIGALINEEDIT_H

#include <QLineEdit>
#include <QPainter>
#include <QPoint>
#include <QtWidgets>
#include <QProxyStyle>
#include "amigacolors.h"

class AmigaLineEditStyle : public QProxyStyle
{
public:
  AmigaLineEditStyle(QStyle *style = 0);
  int pixelMetric(PixelMetric metric, const QStyleOption *option = 0, const QWidget *widget = 0) const;
};

class AmigaLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit AmigaLineEdit(QWidget* parent,
                        int w,
                        int h,
                        int x,
                        int y,
                        const QString& text=""
                        );

protected:
    virtual void paintEvent(QPaintEvent* event);
};

#endif // AMIGALINEEDIT_H
