#ifndef AMIGAHORIZONTALLINE_H
#define AMIGAHORIZONTALLINE_H

#include <QFrame>

class AmigaHorizontalLine : public QFrame
{
    Q_OBJECT
public:
    explicit AmigaHorizontalLine(QWidget *parent, int w, int x, int y);

};

#endif // AMIGAHORIZONTALLINE_H
