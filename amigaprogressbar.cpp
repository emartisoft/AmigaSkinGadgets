#include "amigaprogressbar.h"

AmigaProgressBar::AmigaProgressBar(QWidget *parent,
                                   int w, int h,
                                   int x, int y,
                                   int value, int maxValue,
                                   bool textVisible):
    QProgressBar(parent)
{
    setGeometry(x,y,w,h);
    setValue(value);
    setMaximum(maxValue);
    setTextVisible(textVisible);
    setStyleSheet(QString::fromUtf8("QProgressBar {\n"
    "border: 1px solid black; \n"
    "background-color: rgb(153, 153, 153);\n"
    "border-bottom-color: rgb(255, 255, 255);\n"
    "border-right-color: rgb(255, 255, 255);\n"
    "text-align: center;"
    "}\n"
    "QProgressBar::chunk {\n"
    "    background-color: #5078a0;\n"
    "}"));
}
