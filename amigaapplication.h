#ifndef AMIGAAPPLICATION_H
#define AMIGAAPPLICATION_H

#include <QApplication>
#include <QFontDatabase>

class AmigaApplication : public QApplication
{
    Q_OBJECT
public:
    explicit AmigaApplication(int &argc, char **argv);
};

#endif // AMIGAAPPLICATION_H
