#ifndef AMIGABUTTON_H
#define AMIGABUTTON_H

#include <QPushButton>
#include <QPoint>
#include <QtWidgets>
#include <QPixmap>

class AmigaButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AmigaButton(QWidget* parent,
                        QString normalImage,
                        QString hoverImage,
                        QString pressImage,
                        int x=0,
                        int y=0,
                        const QString& text=""
                        );
    void setTextColor(QColor c);
    void setPressImage(QString pressImage);
    void setNormalImage(QString normalImage);
    void setHoverImage(QString hoverImage);
    QPoint getCurrentMousePoint();

protected:
    virtual void enterEvent(QEnterEvent*);
    virtual void leaveEvent(QEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent*);

private:
    typedef enum
    {
        NORMAL,
        HOVER,
        PRESS
    } Status;
    Status currentStatus;
    QString imageName[3];
    int w, h;
    int x, y;
    bool noText;
    QPoint curMousePoint;

};

#endif // AMIGABUTTON_H
