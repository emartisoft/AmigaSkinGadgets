#include "amigawindow.h"

AmigaWindow::AmigaWindow(QMainWindow *parent, bool maximizeButton, bool minimizeButton, bool rightSideThin, bool bottomSideThin, bool hideSizeGrip, bool closeButton) : QMainWindow(parent),
    m_SizeGrip(this),
    m_TitleBar(this, closeButton, minimizeButton, maximizeButton),
    m_RightSideThin(rightSideThin),
    m_HideSizeGrip(hideSizeGrip),
    m_BottomSideThin(bottomSideThin)
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
    "image: url(:/pics/scrollup.png);\n"
    "}\n"
    "QScrollBar::up-arrow:vertical:pressed{\n"
    "border: 1px solid white;\n"
    "border-top-color:  rgb(0, 0, 0);\n"
    "border-left-color: rgb(0, 0, 0);\n"
    "image: url(:/pics/scrollup_down.png);\n"
    "}\n"
    "QScrollBar::down-arrow:vertical {\n"
    "border: 1px solid black;\n"
    "border-top-color: rgb(255, 255, 255);\n"
    "border-left-color: rgb(255, 255, 255);\n"
    "image: url(:/pics/scrolldown.png);\n"
    "}\n"
    "QScrollBar::down-arrow:vertical:pressed {\n"
    "border: 1px solid white;\n"
    "border-top-color:  rgb(0, 0, 0);\n"
    "border-left-color: rgb(0, 0, 0);\n"
    "image: url(:/pics/scrolldown_down.png);\n"
    "}\n"
    "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
    "background: none;\n"
    "}\n"
    ""));

    pixSg.load(":/pics/bottom_right.png");

    bottomWidget = new QWidget(this);
    bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
    bottomWidget->setGeometry(QRect(0, height()-pixSg.rect().height(), width(), pixSg.rect().height()));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(bottomWidget->sizePolicy().hasHeightForWidth());
    bottomWidget->setSizePolicy(sizePolicy);
    bottomWidget->setMinimumSize(QSize(0, 20));
    bottomWidget->setMaximumSize(QSize(16777215, 20));
  //  bottomWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/bottom.png);"));
    auto horizontalLayout_2 = new QHBoxLayout(bottomWidget);
    horizontalLayout_2->setSpacing(0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    lb = new QWidget(bottomWidget);
    lb->setObjectName(QString::fromUtf8("lb"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(lb->sizePolicy().hasHeightForWidth());
    lb->setSizePolicy(sizePolicy1);
    lb->setMinimumSize(QSize(25, 20));
    lb->setMaximumSize(QSize(25, 20));
  //  lb->setStyleSheet(QString::fromUtf8("image: url(:/pics/bottom_left.png);"));

    horizontalLayout_2->addWidget(lb);
    auto horizontalSpacer_2 = new QSpacerItem(406, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_2->addItem(horizontalSpacer_2);

    leftWidget = new QWidget(this);
    leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
  //  leftWidget->setGeometry(QRect(0, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
    leftWidget->setSizePolicy(sizePolicy3);
    leftWidget->setMinimumSize(QSize(4, 0));
    leftWidget->setMaximumSize(QSize(4, 16777215));
  //  leftWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/left.png);"));
    rightWidget = new QWidget(this);
    rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
   // rightWidget->setGeometry(QRect(width()-4, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    sizePolicy3.setHeightForWidth(rightWidget->sizePolicy().hasHeightForWidth());
    rightWidget->setSizePolicy(sizePolicy3);
    rightWidget->setMinimumSize(QSize(18, 0));
    rightWidget->setMaximumSize(QSize(18, 16777215));
   // rightWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/right.png);"));


   // m_SizeGrip.setStyleSheet(QString::fromUtf8("border-image: url(:/pics/bottom_right.png);"));

}

void AmigaWindow::resizeEvent(QResizeEvent *)
{
    int delta = (window()->windowState() == Qt::WindowMaximized) ? 0 : pixSg.width();
    m_TitleBar.setGeometry(0,0,width(),height());
    bottomWidget->setGeometry(QRect(0, height()-bottomWidget->height(), width()-delta, bottomWidget->height()));
    leftWidget->setGeometry(QRect(0, m_TitleBar.height(), 4, height()-m_TitleBar.height()-pixSg.height()));
    rightWidget->setGeometry(QRect(width()-18, m_TitleBar.height(), 18, height()-m_TitleBar.height()-pixSg.height()));
    m_SizeGrip.move(width() - pixSg.width() , height() - pixSg.height());
    m_SizeGrip.resize(pixSg.width(), pixSg.height());
}

bool AmigaWindow::event(QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        // if window is active
        m_TitleBar.setActive(true);
        m_SizeGrip.setStyleSheet(QString::fromUtf8((m_HideSizeGrip)?"border-image: url(:/pics/bottom_right_thin.png);":"border-image: url(:/pics/bottom_right.png);"));
        rightWidget->setStyleSheet(QString::fromUtf8((m_RightSideThin)?"background-image: url(:/pics/edge.png);":"background-image: url(:/pics/edge_right.png);"));
        leftWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/left_edge.png);"));
        lb->setStyleSheet(QString::fromUtf8((m_BottomSideThin)?"image: url(:/pics/bottom_left_thin.png);":"image: url(:/pics/bottom_left.png);"));
        bottomWidget->setStyleSheet(QString::fromUtf8((m_BottomSideThin)?"background-image: url(:/pics/bottom_thin.png);":"background-image: url(:/pics/bottom.png);"));
    }
    else
    if(event->type() == QEvent::WindowDeactivate)
    {
        // if window is deactive
        m_TitleBar.setActive(false);
        m_SizeGrip.setStyleSheet(QString::fromUtf8((m_HideSizeGrip)?"border-image: url(:/pics/bottom_right_thin_deactive.png);":"border-image: url(:/pics/bottom_right_deactive.png);"));
        rightWidget->setStyleSheet(QString::fromUtf8((m_RightSideThin)?"background-image: url(:/pics/edge_deactive.png);":"background-image: url(:/pics/edge_right_deactive.png);"));
        leftWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/pics/left_edge_deactive.png);"));
        lb->setStyleSheet(QString::fromUtf8((m_BottomSideThin)?"image: url(:/pics/bottom_left_thin_deactive.png);":"image: url(:/pics/bottom_left_deactive.png);"));
        bottomWidget->setStyleSheet(QString::fromUtf8((m_BottomSideThin)?"background-image: url(:/pics/bottom_thin.png);":"background-image: url(:/pics/bottom_deactive.png);"));
    }
    return QMainWindow::event(event) ;
}

void AmigaWindow::setWindowTitle(const QString &title)
{
    QWidget::setWindowTitle(title);
    emit WindowTitleChanged();
}

void AmigaWindow::bringToAlwaysTop()
{
    m_TitleBar.AlwaysTopOn();
}

void AmigaWindow::bringToAlwaysBottom()
{
    m_TitleBar.AlwaysToBottom();
}
