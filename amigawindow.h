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
                         bool closeButton=true,
                         bool minimizeButton=true,
                         bool maximizeButton=true);
    void setWindowTitle(const QString &title);

signals:
    void WindowTitleChanged();

protected:
    virtual void resizeEvent(QResizeEvent *);

private: 
    QSizeGrip m_SizeGrip;
    AmigaTitleBar m_TitleBar;
    QWidget *bottomWidget, *leftWidget, *rightWidget;
    QPixmap pixSg;

};

#endif // AMIGAWINDOW_H
