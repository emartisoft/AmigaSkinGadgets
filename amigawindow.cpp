#include "amigawindow.h"

AmigaWindow::AmigaWindow(QMainWindow *parent) : QMainWindow(parent),
    m_SizeGrip(this),
    m_TitleBar(this)
{
    connect(this       , SIGNAL(WindowTitleChanged()),
        &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(400, 300);
    setWindowTitle(tr("Amiga Window"));
    setWindowFlags(Qt::FramelessWindowHint);
    m_TitleBar.setGeometry(0,0,width(),height());
    //setAttribute(Qt::WA_TranslucentBackground);
    //setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));

    setStyleSheet(QString::fromUtf8("QMainWindow{background-color: rgb(153, 153, 153);}\n"
    "QScrollBar{\n"
    "}\n"
    "QScrollBar:vertical {\n"
    "border: 1px solid black;\n"
    "background: #999999;\n"
    "width: 17px;\n"
    "border-left-color: rgb(255, 255, 255);\n"
    "border-top-color: rgb(255, 255, 255);\n"
    "border-right-color: rgb(0, 0, 0);\n"
    "border-bottom-color: rgb(0, 0, 0);\n"
    "margin: -1px 0 26px 0;\n"
    "}\n"
    "QScrollBar::handle:vertical {\n"
    "background: black;\n"
    "min-height: 14px;\n"
    "margin:3;\n"
    "}\n"
    "QScrollBar::handle:vertical:pressed {\n"
    "background: white;\n"
    "min-height: 14px;\n"
    "margin:3;\n"
    "}\n"
    "QScrollBar::add-line:vertical {\n"
    "border: 1px solid black;\n"
    "background: #999999;\n"
    "height: 11px;\n"
    "subcontrol-position: bottom;\n"
    "subcontrol-origin: margin;\n"
    "margin: 0 0 0 0\n"
    "}\n"
    "\n"
    "QScrollBar::sub-line:vertical {\n"
    "border: 1px solid black;\n"
    "background: #999999;\n"
    "height: 11px;\n"
    "subcontrol-position: bottom;\n"
    "subcontrol-origin: margin;\n"
    "margin: 0 0 13px 0\n"
    "}\n"
    "QScrollBar::up-arrow:vertical{\n"
    "border: 1px solid black;\n"
    "border-top-color: rgb(255, 255, 255);\n"
    "border-left-color: rgb(255, 255, 255);\n"
    "image: url(:/pics/pics/scrollup.png);\n"
    "}\n"
    "QScrollBar::up-arrow:vertical:pressed{\n"
    "border: 1px solid white;\n"
    "border-top-color:  rgb(0, 0, 0);\n"
    "border-left-color: rgb(0, 0, 0);\n"
    "image: url(:/pics/pics/scrollup_down.png);\n"
    "}\n"
    "QScrollBar::down-arrow:vertical {\n"
    "border: 1px solid black;\n"
    "border-top-color: rgb(255, 255, 255);\n"
    "border-left-color: rgb(255, 255, 255);\n"
    "image: url(:/pics/pics/scrolldown.png);\n"
    "}\n"
    "QScrollBar::down-arrow:vertical:pressed {\n"
    "border: 1px solid white;\n"
    "border-top-color:  rgb(0, 0, 0);\n"
    "border-left-color: rgb(0, 0, 0);\n"
    "image: url(:/pics/pics/scrolldown_down.png);\n"
    "}\n"
    "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
    "background: none;\n"
    "}\n"
    ""));

    pixSg.load(":/pics/pics/bottom_right.png");

    bottomWidget = new QWidget(this);
    bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
    bottomWidget->setGeometry(QRect(0, height()-pixSg.rect().height(), width(), pixSg.rect().height()));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(bottomWidget->sizePolicy().hasHeightForWidth());
    bottomWidget->setSizePolicy(sizePolicy);
    bottomWidget->setMinimumSize(QSize(0, 16));
    bottomWidget->setMaximumSize(QSize(16777215, 16));
    bottomWidget->setBaseSize(QSize(0, 16));
    bottomWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/pics/bottom.png);"));
    auto horizontalLayout_2 = new QHBoxLayout(bottomWidget);
    horizontalLayout_2->setSpacing(0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    auto lb = new QWidget(bottomWidget);
    lb->setObjectName(QString::fromUtf8("lb"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(lb->sizePolicy().hasHeightForWidth());
    lb->setSizePolicy(sizePolicy1);
    lb->setMinimumSize(QSize(22, 16));
    lb->setMaximumSize(QSize(22, 16));
    lb->setBaseSize(QSize(22, 16));
    lb->setStyleSheet(QString::fromUtf8("image: url(:/pics/pics/bottom_left.png);"));

    horizontalLayout_2->addWidget(lb);
    auto horizontalSpacer_2 = new QSpacerItem(406, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_2->addItem(horizontalSpacer_2);

    leftWidget = new QWidget(this);
    leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
    leftWidget->setGeometry(QRect(0, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
    leftWidget->setSizePolicy(sizePolicy3);
    leftWidget->setMinimumSize(QSize(4, 0));
    leftWidget->setMaximumSize(QSize(4, 16777215));
    leftWidget->setBaseSize(QSize(4, 0));
    leftWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/pics/left.png);"));
    rightWidget = new QWidget(this);
    rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
    rightWidget->setGeometry(QRect(width()-4, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    sizePolicy3.setHeightForWidth(rightWidget->sizePolicy().hasHeightForWidth());
    rightWidget->setSizePolicy(sizePolicy3);
    rightWidget->setMinimumSize(QSize(4, 0));
    rightWidget->setMaximumSize(QSize(4, 16777215));
    rightWidget->setBaseSize(QSize(4, 0));
    rightWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/pics/right.png);"));


    m_SizeGrip.setStyleSheet(QString::fromUtf8("border-image: url(:/pics/pics/bottom_right.png);"));
    update();
}

void AmigaWindow::resizeEvent(QResizeEvent *)
{
    int delta = (window()->windowState() == Qt::WindowMaximized) ? 0 : pixSg.width();
    m_TitleBar.setGeometry(0,0,width(),height());
    bottomWidget->setGeometry(QRect(0, height()-bottomWidget->height(), width()-delta, bottomWidget->height()));
    leftWidget->setGeometry(QRect(0, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    rightWidget->setGeometry(QRect(width()-4, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    m_SizeGrip.move(width() - pixSg.width() , height() - pixSg.height());
    m_SizeGrip.resize(pixSg.width(), pixSg.height());
}

void AmigaWindow::setWindowTitle(const QString &title)
{
    QWidget::setWindowTitle(title);
    emit WindowTitleChanged();
}
