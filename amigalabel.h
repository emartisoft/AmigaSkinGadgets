#ifndef AMIGALABEL_H
#define AMIGALABEL_H

#include <QLabel>

class AmigaLabel : public QLabel
{
    Q_OBJECT
public:
    explicit AmigaLabel(QWidget* parent,
                        int w,
                        int h,
                        int x,
                        int y,
                        const QString& text=""
                        );
    void setTextColor(QColor c);
};

#endif // AMIGALABEL_H
