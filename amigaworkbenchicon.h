#ifndef AMIGAWORKBENCHICON_H
#define AMIGAWORKBENCHICON_H

#include <QFrame>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>
#include <QDateTime>

class AmigaWorkbenchIcon : public QFrame
{
    Q_OBJECT
public:
    AmigaWorkbenchIcon(QWidget *parent, int x, int y, int w, QString iconPath=":/pics/diskette.png", QString iconTitle="Unnamed");
    void setCommand(QString cmd);
    void setIcon(QString iconPath);
    void setTitle(QString iconTitle);
    void setFrameColor(bool iconPressed=false);
    bool isPressed();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QPoint offset;
    QString m_cmd;
    QFrame *icon;
    QLabel *title;
    bool mPressed;
};

#endif // AMIGAWORKBENCHICON_H
