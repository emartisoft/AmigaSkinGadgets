#include "amigacombobox.h"

AmigaComboBox::AmigaComboBox(QWidget *parent,
                             int w, int h,
                             int x, int y,
                             const QStringList &list)
: QPushButton(list[0], parent), menuList(list)
{
    setGeometry(x, y, w, h);
    pressed=false;

    QFont font;
    font.setFamily(QString::fromUtf8("AmigaTopazTurkish"));
    font.setPointSize(12);

    menu = new QMenu(this);
    menu->setFont(font);
    for (int i=0; i<list.length() ; i++ ) {
        QAction *act = new QAction(list[i]);
        act->setData(i);
        menu->addAction(act);
    }
    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(menuTriggerSlot(QAction*)));
    setText(list[0]);

    setStyleSheet(QString::fromUtf8("QMenu {background-color: #ffffff; border: 1px solid black;}\n "
                                    "QMenu::item {padding: 2px 25px 2px 20px; background-color: transparent; color: #000000;}\n "
                                    "QMenu::item:selected {margin: 1px; border-color: #ffffff; background-color: #000000; color: #ffffff;}"));

    update();
}

void AmigaComboBox::setTextColor(QColor c)
{
    setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(c.red(),3,10).arg(c.green(),3,10).arg(c.blue(),3,10));
}

int AmigaComboBox::getSelectedIndex()
{
    return selectedIndex;
}

void AmigaComboBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(QRect(0,0,width(),height()), QBrush((pressed)?BLUE:GRAY));
    painter.setPen((pressed)?WHITE:BLACK);
    painter.drawRect(0,0,width()-1,height()-1);
    painter.drawRect(0,0,width()-2,height()-1);
    painter.setPen((pressed)?BLACK:WHITE);
    painter.drawLine(0,0,width()-2,0);
    painter.drawLine(0,0,0,height()-1);
    painter.drawLine(1,0,1,height()-2);
    painter.setPen(BLACK);
    QPixmap arrow((pressed)? ":/pics/pics/comboarrow_down.png" : ":/pics/pics/comboarrow.png");
    arrowWidth = arrow.width();
    painter.drawPixmap(QPoint(2,(height()-2-arrow.height())/2), arrow);
    const QRect rectangle = QRect(arrowWidth+4, 0, width()-arrowWidth-4, height());
    QRect boundingRect;
    painter.drawText(rectangle, Qt::AlignLeft | Qt::AlignVCenter, text(), &boundingRect);

}

void AmigaComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pressed = true;
        update();
    }
}

void AmigaComboBox::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pressed = false;
        if(event->pos().x() < arrowWidth + 2) showNextItem(); else showPopupMenu();
        update();
    }

    if(rect().contains(event->pos()))
    {
     emit clicked();
    }
}

void AmigaComboBox::showPopupMenu()
{
    menu->exec(mapToGlobal(QPoint(arrowWidth+2, 0)));
}

void AmigaComboBox::showNextItem()
{
    selectedIndex++;
    selectedIndex %= menuList.length();
    setText(menuList[selectedIndex]);
}

void AmigaComboBox::menuTriggerSlot(QAction *action)
{
    setText(action->text());
    selectedIndex = action->data().toInt();
    update();
}
