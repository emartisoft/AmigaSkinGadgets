#ifndef AMIGATABWIDGET_H
#define AMIGATABWIDGET_H

#include <QTabWidget>

class AmigaTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit AmigaTabWidget(QWidget* parent,
                                               int w,
                                               int h,
                                               int x,
                                               int y);
};

#endif // AMIGATABWIDGET_H
