#include "amigaworkbench.h"
#include "amigabutton.h"

AmigaWorkbench::AmigaWorkbench(QWidget *parent, QStringList menuList) :
    QMainWindow(parent),
    m_MenuList(menuList)
{ 
    setStyleSheet(QString::fromUtf8("QMainWindow{background-color: rgb(153, 153, 153);}\n"
                                    "QMenu {background-color: #ffffff; border: 1px solid black;}\n "
                                    "QMenu::item {padding: 2px 16px 2px 4px; background-color: transparent; color: #000000;}\n "
                                    "QMenu::item:selected {margin: 1px; border-color: #ffffff; background-color: #000000; color: #ffffff;}"));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AmigaWorkbench::pressedToNormalForMenubar);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    showMaximized();
}

AmigaWorkbench::~AmigaWorkbench()
{
    delete timer;
}

void AmigaWorkbench::AddMenu()
{
    QLayoutItem *item;
    while((item = horizontalLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            horizontalLayout->removeWidget(item->widget());
            delete item->widget();
        }
        delete item;
    }
    int c = m_MenuList.count();
    menuButton = new QPushButton*[c];
    arrayMenu = new QMenu*[c];
    for (int i=0; i<c ; i++ ) {
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        menuButton[i] = new QPushButton(frame);
        menuButton[i]->setEnabled(true);
        sizePolicy.setHeightForWidth(menuButton[i]->sizePolicy().hasHeightForWidth());
        menuButton[i]->setSizePolicy(sizePolicy);
        menuButton[i]->setMinimumSize(QSize(0, 20));
        menuButton[i]->setMaximumSize(QSize(16777215, 20));
        menuButton[i]->setText(QString("%1").arg(m_MenuList[i]));

        connect(menuButton[i], SIGNAL(pressed()), this, SLOT(menubarpressed()));

        horizontalLayout->addWidget(menuButton[i]);
        arrayMenu[i] = new QMenu;
    }
}

void AmigaWorkbench::setAllIconToNormal()
{
    // Getting all icons
    QList<AmigaWorkbenchIcon*> icons = findChildren<AmigaWorkbenchIcon*>();
    for (auto *ico: icons)
    {
        ico->setFrameColor();
    }
}

void AmigaWorkbench::menubarpressed()
{
    QPushButton *button = (QPushButton*) sender();
    //qDebug() << button->text();
    int i = 0;
    while(i<m_MenuList.count())
    {
        if(m_MenuList[i]==button->text().trimmed()) break;
        i++;
    }
    //qDebug() << "index=" << i; // menubar index
    activeMenuIndex = i;
    arrayMenu[i]->exec(mapToGlobal(QPoint(menuButton[i]->pos().x() + frame->pos().x(), menuButton[i]->pos().y() + frame->pos().y() + 20-2)));
    timer->start(250);
}

void AmigaWorkbench::pressedToNormalForMenubar()
{
    if(!arrayMenu[activeMenuIndex]->isVisible())
    {
        timer->stop();
        menuButton[activeMenuIndex]->setDown(false);
    }
}

void AmigaWorkbench::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    AddMenuBar(m_MenuList);
}

void AmigaWorkbench::AddPopupMenu(QMenu *menu, int index)
{
    arrayMenu[index] = menu;
}

void AmigaWorkbench::AddIcon(AmigaWorkbenchIcon *awi)
{
    awi->setParent(centralwidget);
}

void AmigaWorkbench::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    setAllIconToNormal();
}

bool AmigaWorkbench::event(QEvent *event)
{
    if(event->type() == QEvent::WindowDeactivate)
    {
        setAllIconToNormal();
    }
    return QMainWindow::event(event);
}

void AmigaWorkbench::AddMenuBar(QStringList menuList)
{
    int screenWidth =  QGuiApplication::primaryScreen()->geometry().width();
    m_MenuList = menuList;

    centralwidget = new QWidget(this);
    frame = new QFrame(centralwidget);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(1, 1, screenWidth-2*1, 22));
    frame->setMinimumSize(QSize(0, 22));
    frame->setMaximumSize(QSize(16777215, 22));
    frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-image: url(:/pics/wb_back.png);\n"
"}\n"
"\n"
"QPushButton {\n"
"    border: 0px;\n"
"    background-color: white;\n"
"color: black;\n"
"padding: 1 4 1 4; "
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:black;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; \n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: none;\n"
"\n"
"}\n"
""));
    frame->setFrameShape(QFrame::NoFrame);
    frame->setFrameShadow(QFrame::Plain);
    frame->setLineWidth(0);

    horizontalLayout = new QHBoxLayout(frame);
    horizontalLayout->setSpacing(16);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(8, 0, 0, 2);

    AddMenu();

    auto horizontalSpacer = new QSpacerItem(452, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    auto pushButton = new AmigaButton(frame, ":/pics/bAot_deactive.png", ":/pics/bAot_deactive.png", ":/pics/bAot_down_deactive.png");
    pushButton->setMinimumSize(QSize(23, 22));
    pushButton->setMaximumSize(QSize(23, 22));

    horizontalLayout->addWidget(pushButton);

    setCentralWidget(centralwidget);
}

