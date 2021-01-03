#include "amigalistwidget.h"

AmigaListWidget::AmigaListWidget(QWidget *parent, int w, int h, int x, int y):
    QListWidget(parent)
{
    setGeometry(QRect(x,y,w,h));
    setFrameShape(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet(QString::fromUtf8("QListWidget{\n"
"border: 1px solid;\n"
"background-color: rgb(153, 153, 153);\n"
"color: rgb(0, 0, 0);\n"
"border-top-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(255, 255, 255);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"border-right-color: transparent;\n"
"}\n"
"QListWidget::Item:selected{\n"
"background-color: rgb(80, 120, 160);\n"
"}\n"
));

}
