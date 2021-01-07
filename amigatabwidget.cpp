#include "amigatabwidget.h"

AmigaTabWidget::AmigaTabWidget(QWidget *parent, int w, int h, int x, int y):
    QTabWidget(parent)
{
    setGeometry(x,y,w,h);
    setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
    "    border: 1px solid #ffffff;\n"
    "	background-color: rgb(153, 153, 153);\n"
    "    position: absolute;\n"
    "	border-right-color: rgb(0, 0, 0);\n"
    "	border-bottom-color: rgb(0, 0, 0);\n"
    "	top:0px;\n"
    "}\n"
    "\n"
    "QTabWidget::tab-bar {\n"
    "    alignment: left;\n"
    "	left:2px;\n"
    "	top:1px;\n"
    "}\n"
    "\n"
    "QTabBar::tab {\n"
    "    border: 1px solid #ffffff;\n"
    "    border-bottom-color: #ffffff;\n"
    "	border-right-color: rgb(0, 0, 0);\n"
    "    border-top-left-radius: 4px;\n"
    "    border-top-right-radius: 4px;\n"
    "    min-width: 8ex;\n"
    "    padding: 4px;\n"
    "\n"
    "\n"
    "}\n"
    "\n"
    "\n"
    "QTabBar::tab:selected {\n"
    "    border-color: #ffffff;\n"
    "	border-right-color: rgb(0, 0, 0);\n"
    "	border-bottom-color: rgb(153, 153, 153);\n"
    "	font: bold;\n"
    "}"));

    setTabShape(QTabWidget::Rounded);
    setElideMode(Qt::ElideNone);
    setUsesScrollButtons(false);
    setDocumentMode(false);
    setTabBarAutoHide(false);


}
