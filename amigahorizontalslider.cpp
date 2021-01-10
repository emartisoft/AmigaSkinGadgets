#include "amigahorizontalslider.h"

AmigaHorizontalSlider::AmigaHorizontalSlider(QWidget *parent, int x, int y, int value, int maxValue)
    : QSlider(Qt::Horizontal, parent)
{
    // tile image (width x height) 24x16 pixels
    // +16 padding
    setGeometry(QRect(x, y, 24 * (maxValue+1)+1, 16));
    setFixedHeight(16);
    setOrientation(Qt::Horizontal);
    setStyleSheet(QString::fromUtf8(
    "QSlider::groove:horizontal {\n"
    "	background-image: url(:/pics/slider_groove.png);	\n"
    "	left: 8;\n"
    "	right:8;\n"
    "}\n"
    "QSlider::handle:horizontal {\n"
    "	image: url(:/pics/slider_handle.png);\n"
    "	top:-2;\n"
    "	left:-7;\n"
    "}"));
    setMaximum(maxValue);
    setValue(value);
    setSingleStep(1);
}
