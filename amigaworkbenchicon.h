#ifndef AMIGAWORKBENCHICON_H
#define AMIGAWORKBENCHICON_H

#include <QFrame>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>

class AmigaWorkbenchIcon : public QFrame
{
    Q_OBJECT
public:
    AmigaWorkbenchIcon(QWidget *parent, int x, int y, int w, QString iconPath="", QString iconTitle="Unnamed");
    void setCommand(QString cmd);
    void setIcon(QString iconPath);
    void setTitle(QString iconTitle);
    void setFrameColor(bool iconPressed=false);
    bool isPressed();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QPoint offset;
    QString m_cmd;
    QFrame *icon;
    QLabel *title;
    bool mPressed;
};

#endif // AMIGAWORKBENCHICON_H
