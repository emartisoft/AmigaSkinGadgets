#ifndef AMIGALISTWIDGET_H
#define AMIGALISTWIDGET_H

#include <QListWidget>

class AmigaListWidget : public QListWidget
{
    Q_OBJECT
public:
    AmigaListWidget(QWidget* parent,
                    int w,
                    int h,
                    int x,
                    int y
                    );
};

#endif // AMIGALISTWIDGET_H
