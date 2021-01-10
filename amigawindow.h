#ifndef AMIGAWINDOW_H
#define AMIGAWINDOW_H

#include <QMainWindow>
#include <QSizeGrip>
#include "amigatitlebar.h"

class AmigaWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AmigaWindow(QMainWindow *parent = nullptr,
                         bool maximizeButton=true,
                         bool minimizeButton=true,
                         bool rightSideThin=true,
                         bool bottomSideThin=false,
                         bool hideSizeGrip=false,
                         bool closeButton=true);
    void setWindowTitle(const QString &title);
    void bringToAlwaysTop();
    void bringToAlwaysBottom();

signals:
    void WindowTitleChanged();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual bool event(QEvent *event);

private: 
    QSizeGrip m_SizeGrip;
    AmigaTitleBar m_TitleBar;
    QWidget *bottomWidget, *leftWidget, *rightWidget, *lb;
    QPixmap pixSg;
    bool m_RightSideThin, m_HideSizeGrip, m_BottomSideThin;

};

#endif // AMIGAWINDOW_H
