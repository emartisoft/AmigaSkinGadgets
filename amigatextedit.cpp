#include "amigatextedit.h"
#include "amigacolors.h"

AmigaTextEdit::AmigaTextEdit(QWidget *parent, int w, int h, int x, int y, const QString &text)
    : QTextEdit(text, parent)
{
    setGeometry(QRect(x,y,w,h));
    setFrameShape(QFrame::NoFrame);
    setContextMenuPolicy(Qt::NoContextMenu);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursorWidth(8);
    setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border: 1px solid;\n"
"background-color: rgb(153, 153, 153);\n"
"color: rgb(0, 0, 0);\n"
"border-top-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(255, 255, 255);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"border-right-color: transparent;\n"
"}\n"
));
    QPalette p = palette();
    p.setColor(QPalette::Highlight, QColor(BLUE));
    setPalette(p);

}
