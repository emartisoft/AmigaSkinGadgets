#include "amigatitlebar.h"

AmigaTitleBar::AmigaTitleBar(QWidget *parent, bool closeButton, bool minimizeButton, bool maximizeButton) : QWidget(parent)
{
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMinimumSize(QSize(0, 15));
    setMaximumSize(QSize(16777215, 15));
    setStyleSheet(QString::fromUtf8("background-image: url(:/pics/pics/top.png);"));
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    bClose = new AmigaButton(this, (closeButton) ? ":/pics/pics/top_left.png" : ":/pics/pics/top_left_edge.png",
                             (closeButton) ? ":/pics/pics/top_left.png" : ":/pics/pics/top_left_edge.png",
                             (closeButton) ? ":/pics/pics/top_left_down.png" : ":/pics/pics/top_left_edge.png");
    bClose->setObjectName(QString::fromUtf8("bClose"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(bClose->sizePolicy().hasHeightForWidth());
    bClose->setSizePolicy(sizePolicy1);
    int bCloseWidth = (closeButton) ? 25 : 4;
    bClose->setMinimumSize(QSize(bCloseWidth, 15));
    bClose->setMaximumSize(QSize(bCloseWidth, 15));
    bClose->setBaseSize(QSize(bCloseWidth, 15));

    horizontalLayout->addWidget(bClose);

    windowTitle = new QLabel(this);
    windowTitle->setObjectName(QString::fromUtf8("windowTitle"));
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(windowTitle->sizePolicy().hasHeightForWidth());
    windowTitle->setSizePolicy(sizePolicy2);
    windowTitle->setIndent(8);

    horizontalLayout->addWidget(windowTitle);

    bMin = new AmigaButton(this, ":/pics/pics/bMin.png", ":/pics/pics/bMin.png", ":/pics/pics/bMin_down.png");
    bMin->setObjectName(QString::fromUtf8("bMin"));
    sizePolicy1.setHeightForWidth(bMin->sizePolicy().hasHeightForWidth());
    bMin->setSizePolicy(sizePolicy1);
    bMin->setMinimumSize(QSize(25, 15));
    bMin->setMaximumSize(QSize(25, 15));
    bMin->setBaseSize(QSize(25, 15));
    bMin->setVisible(minimizeButton);

    horizontalLayout->addWidget(bMin);

    bMax = new AmigaButton(this, ":/pics/pics/bMax.png", ":/pics/pics/bMax.png", ":/pics/pics/bMax_down.png");
    bMax->setObjectName(QString::fromUtf8("bMax"));
    sizePolicy1.setHeightForWidth(bMax->sizePolicy().hasHeightForWidth());
    bMax->setSizePolicy(sizePolicy1);
    bMax->setMinimumSize(QSize(23, 15));
    bMax->setMaximumSize(QSize(23, 15));
    bMax->setVisible(maximizeButton);

    horizontalLayout->addWidget(bMax);

    bAot = new AmigaButton(this, ":/pics/pics/bAot.png", ":/pics/pics/bAot.png", ":/pics/pics/bAot_down.png");
    bAot->setObjectName(QString::fromUtf8("bAot"));
    sizePolicy1.setHeightForWidth(bAot->sizePolicy().hasHeightForWidth());
    bAot->setSizePolicy(sizePolicy1);
    bAot->setMinimumSize(QSize(23, 15));
    bAot->setMaximumSize(QSize(23, 15));

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
    windowTitle->setStyleSheet("color: white;");
    // font
    QFont font;
    font.setFamily(QString::fromUtf8("AmigaTopazTurkish"));
    font.setPointSize(8);
    windowTitle->setFont(font);
    windowTitle->setText("Untitled");

    UpdateWindowTitle();
    mAlwaysTopOn = false;
}

AmigaTitleBar::~AmigaTitleBar()
{

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

void AmigaTitleBar::Quit()
{
    window()->close();
}
