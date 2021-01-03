#include "amigalineedit.h"

AmigaLineEdit::AmigaLineEdit(QWidget *parent,
                             int w, int h,
                             int x, int y,
                             const QString &text)
    : QLineEdit(text, parent)
{
    setGeometry(x, y, w, h);
    setFrame(false);
    setContextMenuPolicy(Qt::NoContextMenu);
    setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
    setStyle(new AmigaLineEditStyle(style()));
    qApp->setCursorFlashTime(0);
    QPalette p = palette();
    p.setColor(QPalette::Highlight, QColor(BLUE));
    setPalette(p);
    update();
}

void AmigaLineEdit::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);
    QPainter painter(this);
    painter.setPen(WHITE);
    painter.drawRect(0,0,width()-2,height()-2);
    painter.setPen(BLACK);
    painter.drawRect(1,1,width()-2,height()-2);
    painter.setPen(GRAY);
    painter.drawPoint(QPoint(1,height()-2));
    painter.drawPoint(QPoint(width()-2,1));
}

AmigaLineEditStyle::AmigaLineEditStyle(QStyle *style)
{
    Q_UNUSED(style);
}

int AmigaLineEditStyle::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    if (metric == QStyle::PM_TextCursorWidth) return 0x08;
    return QProxyStyle::pixelMetric(metric,option,widget);
}
