#include "amigaworkbenchicon.h"

AmigaWorkbenchIcon::AmigaWorkbenchIcon(QWidget *parent, int x, int y, int w, QString iconPath, QString iconTitle) : QFrame(parent)
{
    setFrameShape(QFrame::NoFrame);
    setFrameShadow(QFrame::Plain);

    auto verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(2);
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    icon = new QFrame(this);
    icon->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-top-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(255, 255, 255);\n"
"image: url(%1);").arg(iconPath));
    icon->setFrameShape(QFrame::Box);
    icon->setFrameShadow(QFrame::Plain);
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    icon->setSizePolicy(sizePolicy1);
    icon->setMinimumSize(QSize(64, 64));
    icon->setBaseSize(QSize(64, 64));

    verticalLayout->addWidget(icon, 0, Qt::AlignHCenter);
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    title = new QLabel(this);
    sizePolicy2.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
    title->setSizePolicy(sizePolicy1);
    title->setMinimumSize(QSize(0, 32));
    title->setAlignment(Qt::AlignCenter);
    title->setText(iconTitle);
    verticalLayout->addWidget(title, 0, Qt::AlignHCenter);

    setGeometry(QRect(x, y, w, 32));
    mPressed=false;
}

void AmigaWorkbenchIcon::setCommand(QString cmd)
{
    m_cmd = cmd;
}

void AmigaWorkbenchIcon::setIcon(QString iconPath)
{
    icon->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-top-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(255, 255, 255);\n"
"image: url(%1);").arg(iconPath));
    QPixmap p(iconPath);
    icon->setFixedSize(QSize(p.width()+8, p.height()+8));
    setFixedHeight(p.height()+2 + title->height());
}

void AmigaWorkbenchIcon::setTitle(QString iconTitle)
{
    title->setText(iconTitle);
}

void AmigaWorkbenchIcon::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
    setFrameColor(true);
}

void AmigaWorkbenchIcon::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        this->move(mapToParent(event->pos() - offset));
    }
}

void AmigaWorkbenchIcon::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    //qDebug() << m_cmd;
    QProcess *p = new QProcess(this);
    p->start(m_cmd);
    setFrameColor();
}

void AmigaWorkbenchIcon::setFrameColor(bool iconPressed)
{
    QString currentStyle = icon->styleSheet();
    if(iconPressed)
    {
        currentStyle=currentStyle.replace("255","0").replace("black","white");
    }
    else
    {
        currentStyle=currentStyle.replace("0","255").replace("white","black");
    }
    icon->setStyleSheet(currentStyle);
    mPressed=iconPressed;
}

bool AmigaWorkbenchIcon::isPressed()
{
    return mPressed;
}
