#include "amigaspinbox.h"

AmigaSpinBox::AmigaSpinBox(QWidget *parent, int w, int h, int x, int y):
    QFrame(parent)
{
    setGeometry(x,y,w,h);
    setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Plain);
    auto horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(4);
    horizontalLayout->setContentsMargins(3, 0, 0, 0);
    spinBox = new QSpinBox(this);
    spinBox->setFrame(false);
    spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox->setReadOnly(true);
    QPalette p =  spinBox->palette();
    p.setColor(QPalette::Highlight, QColor(BLUE));
    spinBox->setPalette(p);
    spinBox->setContextMenuPolicy(Qt::NoContextMenu);

    horizontalLayout->addWidget(spinBox);

    upDown = new AmigaButton(this, ":/pics/spinbox_normal.png", ":/pics/spinbox_normal.png",  ":/pics/spinbox_normal.png");
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(upDown->sizePolicy().hasHeightForWidth());

    upDown->setSizePolicy(sizePolicy);
    upDown->setMinimumSize(QSize(18, 17));
    upDown->setMaximumSize(QSize(18, 17));
    upDown->setBaseSize(QSize(18, 17));
    upDown->setFlat(false);

    horizontalLayout->addWidget(upDown);

    setFixedHeight(17+2);
    spinBox->setFixedHeight(14);

    connect(upDown, SIGNAL(clicked()), this, SLOT(spinButtonPressed()));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AmigaSpinBox::setPressImage);
    timer->start(500);

    update();
}

void AmigaSpinBox::setFont(QFont &font)
{
    spinBox->setFont(font);
}

void AmigaSpinBox::setValue(int value)
{
    spinBox->setValue(value);
}

int AmigaSpinBox::value()
{
    return spinBox->value();
}

void AmigaSpinBox::setMinimum(int min)
{
    spinBox->setMinimum(min);
}

void AmigaSpinBox::setMaximum(int max)
{
    spinBox->setMaximum(max);
}

void AmigaSpinBox::spinButtonPressed()
{
    spinBox->setValue(spinBox->value()+(isPointInTriangle() ? -1 : 1));
}

void AmigaSpinBox::setPressImage()
{
    upDown->setPressImage(isPointInTriangle() ? ":/pics/spinbox_down_down.png":":/pics/spinbox_up_down.png");
}

bool AmigaSpinBox::isPointInTriangle()
{
    QPoint p = upDown->getCurrentMousePoint();
    return (p.x()+p.y())>upDown->width();
}

void AmigaSpinBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(QRect(0,0,width()-1,height()-1), QBrush(WHITE));
    painter.setPen(BLACK);
    painter.drawLine(1, height()-2, spinBox->width()+7, height()-2);
    painter.drawLine(2, 1, spinBox->width()+4, 1);
    painter.drawLine(2, 1, 2, height()-3);
    painter.drawLine(3, 1, 3, height()-4);
    painter.drawLine(spinBox->width()+6, 1, spinBox->width()+6, height()-3);
    painter.drawLine(spinBox->width()+7, 0, spinBox->width()+7, height()-2);
    painter.setPen(GRAY);
    painter.drawPoint(spinBox->width()+4,2);
}
