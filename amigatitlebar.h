#ifndef AMIGATITLEBAR_H
#define AMIGATITLEBAR_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QSizePolicy>
#include "amigabutton.h"

class AmigaTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit AmigaTitleBar(QWidget *parent = nullptr);
    ~AmigaTitleBar();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:

public slots:
    void UpdateWindowTitle();
    void Minimized();
    void Maximized();
    void AlwaysTopOn();
    void Quit();

private:
    bool mMoving;
    QPoint mLastMousePosition;
    QLabel *windowTitle;
    AmigaButton *bMin;
    AmigaButton *bMax;
    AmigaButton *bClose;
    AmigaButton *bAot;
    bool mAlwaysTopOn;

};

#endif // AMIGATITLEBAR_H