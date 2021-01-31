#ifndef AMIGAWORKBENCH_H
#define AMIGAWORKBENCH_H

#include <QMainWindow>
#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScreen>

#include "amigaworkbenchicon.h"
<<<<<<< HEAD
#include "amigalabel.h"
=======
>>>>>>> 7b92d63d726a4d77e069c24a598da51c044ab9ab

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
<<<<<<< HEAD
    AmigaLabel *info;
    void showInfo(bool visible=true);
    int freememory;
=======
>>>>>>> 7b92d63d726a4d77e069c24a598da51c044ab9ab

public slots:
    void menubarpressed();
    void pressedToNormalForMenubar();

protected:
    virtual void showEvent(QShowEvent *event);

};

#endif // AMIGAWORKBENCH_H
