#include "amigatitlebar.h"

AmigaTitleBar::AmigaTitleBar(QWidget *parent, bool closeButton, bool minimizeButton, bool maximizeButton) :
    QWidget(parent), mCloseButton(closeButton)
{
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMinimumSize(QSize(0, 22));
    setMaximumSize(QSize(16777215, 22));
   // setStyleSheet(QString::fromUtf8("background-image: url(:/pics/top.png);"));
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    bClose = new AmigaButton(this, (closeButton) ? ":/pics/top_left.png" : ":/pics/top_left_edge.png",
                             (closeButton) ? ":/pics/top_left.png" : ":/pics/top_left_edge.png",
                             (closeButton) ? ":/pics/top_left_down.png" : ":/pics/top_left_edge.png");
    bClose->setObjectName(QString::fromUtf8("bClose"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(bClose->sizePolicy().hasHeightForWidth());
    bClose->setSizePolicy(sizePolicy1);
    int bCloseWidth = (closeButton) ? 25 : 5;
    bClose->setMinimumSize(QSize(bCloseWidth, 22));
    bClose->setMaximumSize(QSize(bCloseWidth, 22));
    bClose->setBaseSize(QSize(bCloseWidth, 22));

    horizontalLayout->addWidget(bClose);

    windowTitle = new QLabel(this);
    windowTitle->setObjectName(QString::fromUtf8("windowTitle"));
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(windowTitle->sizePolicy().hasHeightForWidth());
    windowTitle->setSizePolicy(sizePolicy2);
    windowTitle->setIndent(6);

    horizontalLayout->addWidget(windowTitle);

    bMin = new AmigaButton(this, ":/pics/bMin.png", ":/pics/bMin.png", ":/pics/bMin_down.png");
    bMin->setObjectName(QString::fromUtf8("bMin"));
    sizePolicy1.setHeightForWidth(bMin->sizePolicy().hasHeightForWidth());
    bMin->setSizePolicy(sizePolicy1);
    bMin->setMinimumSize(QSize(25, 22));
    bMin->setMaximumSize(QSize(25, 22));
    bMin->setVisible(minimizeButton);

    horizontalLayout->addWidget(bMin);

    bMax = new AmigaButton(this, ":/pics/bMax.png", ":/pics/bMax.png", ":/pics/bMax_down.png");
    bMax->setObjectName(QString::fromUtf8("bMax"));
    sizePolicy1.setHeightForWidth(bMax->sizePolicy().hasHeightForWidth());
    bMax->setSizePolicy(sizePolicy1);
    bMax->setMinimumSize(QSize(24, 22));
    bMax->setMaximumSize(QSize(24, 22));
    bMax->setVisible(maximizeButton);

    horizontalLayout->addWidget(bMax);

    bAot = new AmigaButton(this, ":/pics/bAot.png", ":/pics/bAot.png", ":/pics/bAot_down.png");
    bAot->setObjectName(QString::fromUtf8("bAot"));
    sizePolicy1.setHeightForWidth(bAot->sizePolicy().hasHeightForWidth());
    bAot->setSizePolicy(sizePolicy1);
    bAot->setMinimumSize(QSize(23, 22));
    bAot->setMaximumSize(QSize(23, 22));

    horizontalLayout->addWidget(bAot);

    connect(bMin, SIGNAL(clicked()),
               this      , SLOT  (Minimized()));
    connect(bMax, SIGNAL(clicked  ()),
               this,       SLOT  (Maximized()));
    if(closeButton)
    {
        connect(bClose   , SIGNAL(clicked  ()),
               this      , SLOT  (Quit()));
    }
    connect(bAot   , SIGNAL(clicked  ()),
               this      , SLOT  (AlwaysTopOn()));

    setFixedHeight(bClose->height());
    //windowTitle->setStyleSheet("color: black;");
    // font
    //QFont font = window()->font();
    //font.setFamily(QString::fromUtf8("AmigaTopazTurkish"));
    //font.setPointSize(10);
    //windowTitle->setFont(font);
    //windowTitle->setText("Untitled");

    UpdateWindowTitle();
    mAlwaysTopOn = false;
}

AmigaTitleBar::~AmigaTitleBar()
{

}

void AmigaTitleBar::setActive(bool active)
{
    if(active)
    {
        windowTitle->setStyleSheet("color: white;");
        setStyleSheet(QString::fromUtf8("background-image: url(:/pics/top.png);"));
        bMin->setNormalImage(":/pics/bMin.png");
        bMax->setNormalImage(":/pics/bMax.png");
        bAot->setNormalImage(":/pics/bAot.png");
        bMin->setHoverImage(":/pics/bMin.png");
        bMax->setHoverImage(":/pics/bMax.png");
        bAot->setHoverImage(":/pics/bAot.png");
        bClose->setNormalImage((mCloseButton) ? ":/pics/top_left.png" : ":/pics/top_left_edge.png");
        bClose->setHoverImage((mCloseButton) ? ":/pics/top_left.png" : ":/pics/top_left_edge.png");
    }
    else
    {
        windowTitle->setStyleSheet("color: black;");
        setStyleSheet(QString::fromUtf8("background-image: url(:/pics/top_deactive.png);"));
        bMin->setNormalImage(":/pics/bMin_deactive.png");
        bMax->setNormalImage(":/pics/bMax_deactive.png");
        bAot->setNormalImage(":/pics/bAot_deactive.png");
        bMin->setHoverImage(":/pics/bMin_deactive.png");
        bMax->setHoverImage(":/pics/bMax_deactive.png");
        bAot->setHoverImage(":/pics/bAot_deactive.png");
        bClose->setNormalImage((mCloseButton) ? ":/pics/top_left_deactive.png" : ":/pics/top_left_edge_deactive.png");
        bClose->setHoverImage((mCloseButton) ? ":/pics/top_left_deactive.png" : ":/pics/top_left_edge_deactive.png");
    }
}

void AmigaTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        QPointF p = event->globalPosition();
        window()->move(p.toPoint() - mLastMousePosition);
    }
}

void AmigaTitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void AmigaTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
    setCursor(QCursor(Qt::ArrowCursor));
}

void AmigaTitleBar::UpdateWindowTitle()
{
    windowTitle->setText(window()->windowTitle());
}

void AmigaTitleBar::Minimized()
{
    window()->showMinimized();
}

void AmigaTitleBar::Maximized()
{
    (window()->windowState() == Qt::WindowMaximized) ? window()->showNormal() : window()->showMaximized();
}

void AmigaTitleBar::AlwaysTopOn()
{
    mAlwaysTopOn = !mAlwaysTopOn;
    Qt::WindowFlags flags = Qt::FramelessWindowHint;
    if(mAlwaysTopOn) flags |= Qt::WindowStaysOnTopHint;
    window()->setWindowFlags(flags);
    window()->showNormal();
}

void AmigaTitleBar::AlwaysToBottom()
{
    Qt::WindowFlags flags = Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint;
    window()->setWindowFlags(flags);
    window()->showNormal();
}

void AmigaTitleBar::Quit()
{
    window()->close();
}
