#ifndef AMIGACOMBOBOX_H
#define AMIGACOMBOBOX_H

#include <QPushButton>
#include <QPainter>
#include <QPoint>
#include <QtWidgets>
#include "amigacolors.h"

class AmigaComboBox : public QPushButton
{
    Q_OBJECT
public:
    explicit AmigaComboBox(QWidget* parent,
                        int w,
                        int h,
                        int x,
                        int y,
                        const QStringList& list ={}
                        );
    void setTextColor(QColor c);
    int getSelectedIndex();

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

private:
    bool pressed;
    QMenu *menu;
    int arrowWidth;
    int selectedIndex;
    QStringList menuList;
    void showPopupMenu();
    void showNextItem();

public slots:
    void menuTriggerSlot(QAction *action);
};

#endif // AMIGACOMBOBOX_H
