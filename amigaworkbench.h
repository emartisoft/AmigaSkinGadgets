#ifndef AMIGAWORKBENCH_H
#define AMIGAWORKBENCH_H

#include <QMainWindow>
#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMenu>
#include "amigaworkbenchicon.h"

class AmigaWorkbench : public QMainWindow
{
    Q_OBJECT
public:
    explicit AmigaWorkbench(QWidget *parent = nullptr, QStringList menuList={});
    ~AmigaWorkbench();

    void AddMenuBar(QStringList menuList);
    void AddPopupMenu(QMenu *menu, int index);
    void AddIcon(AmigaWorkbenchIcon *awi);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual bool event(QEvent *event);

signals:

private:
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QStringList m_MenuList;
    void AddMenu();
    QMenu** arrayMenu;
    QPushButton** menuButton;
    QTimer *timer;
    int activeMenuIndex;
    QWidget *centralwidget;
    void setAllIconToNormal();

public slots:
    void menubarpressed();
    void pressedToNormalForMenubar();
};

#endif // AMIGAWORKBENCH_H
