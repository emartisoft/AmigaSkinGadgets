#include "amigaapplication.h"
#include "amigawindow.h"
#include "amigabutton.h"
#include "amigalabel.h"
#include "amigastandartbutton.h"
#include "amigalineedit.h"
#include "amigacheckbox.h"
#include "amigahorizontalline.h"
#include "amigahorizontalslider.h"
#include "amigacombobox.h"
#include "amigaframe.h"
#include "amigatextedit.h"
#include "amigalistwidget.h"
#include "amigaprogressbar.h"
#include "amigaspinbox.h"
#include "amigatabwidget.h"
#include "amigaworkbench.h"
#include "amigaworkbenchicon.h"

#include <QColor>

int main(int argc, char *argv[])
{
    AmigaApplication a(argc, argv);
    AmigaWindow w;//(nullptr, false, false, false);

    // Standart Button
    AmigaStandartButton aSButton(&w, 120, 25, 20, 50, "Button");

    // LineEdit
    AmigaLineEdit aLineEdit(&w, 200, 25, 20, 80);
    aLineEdit.setText("text");

    // horizontal line
    AmigaHorizontalLine hl1(&w, 50, 20, 32);
    // Label
    AmigaLabel aLabel(&w, 190, 25, 70, 20, "This is horizontal line");
    AmigaLabel aLabel2(&w, 150, 25, 20, 140, "This is label.......");

    AmigaHorizontalLine hl2(&w, 50, 260, 32);

    // Checkbox
    AmigaCheckBox aCheckBox(&w, 240, 25, 20, 110, "This is a checkbox");

    // horizontal slider
    AmigaHorizontalSlider aHorSlider(&w, 20, 170, 2, 8);

    // Combobox
    AmigaComboBox aCombobox(&w, 120, 25, 20, 200, QStringList{ "Birinci", "İkinci", "Üçüncü"});

    // frame
    AmigaFrame aFrame(&w, 200, 100, 20, 230);
    AmigaLabel lFrame(&aFrame, 100, 25, 10, 10, "Frame Text");

    AmigaFrame aFrameCaro(&w, 200, 100, 20, 340, true);
    AmigaLabel lFrame2(&aFrameCaro, 140, 25, 10, 10, "Caro Frame Text");

    // textedit
    AmigaTextEdit aTextEdit(&w, 400, 200, 280, 60);
    aTextEdit.setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'AmigaTopazTurkish'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Bold</span></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Italic</span></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Normal</p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This is a boing ball image: <img src=\":/pics/boingball.png\" /></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0 1 2 3 4 5 6 7 8 9</p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"www.aminet.net\"><span style=\" font-size:12pt; text-decoration: underline; color:#5078a0;\""
    ">www.aminet.net</span></a></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /></span>End of Doc</p></body></html>", nullptr));

    // listwidget
    AmigaListWidget aListWidget(&w, 200, 100, 280, 300);
    new QListWidgetItem("Bir", &aListWidget);
    new QListWidgetItem("İki", &aListWidget);
    new QListWidgetItem("Üç", &aListWidget);
    new QListWidgetItem("Dört", &aListWidget);
    new QListWidgetItem("Beş", &aListWidget);
    new QListWidgetItem("Altı", &aListWidget);
    new QListWidgetItem("Yedi", &aListWidget);
    new QListWidgetItem("Sekiz", &aListWidget);

    // progressbar
    //AmigaProgressBar aProgBar(&w, 200, 20, 280, 420);
    AmigaProgressBar aProgBar(&w, 200, 20, 280, 420, 0, 50, true);
    aProgBar.setValue(25);

    // spinbox
    AmigaSpinBox aSpinBox(&w, 120,25,500,420);
    aSpinBox.setMaximum(50);
    aSpinBox.setValue(16);

    // tabwidget
    AmigaTabWidget aTabWidget(&w, 500, 75, 120, 450);
    aTabWidget.addTab(new QWidget(), " Settings   ");
    aTabWidget.addTab(new QWidget(), " Options   ");
    aTabWidget.addTab(new QWidget(), " Help   ");
    aTabWidget.setCurrentIndex(1);

    w.setWindowTitle("Amiga Window Title - çöışüğÇÖİŞÜĞ");
    w.resize(800, 600);
    w.setMinimumSize(800,600);
    //w.bringToAlwaysBottom();
    w.move(120,100);
    w.show();

    // workbench
    AmigaWorkbench wb(nullptr, QStringList{"Workbench", "Window", "Icon", "Tools"});
    QMenu *menuWorbench = new QMenu(&wb);
    menuWorbench->addAction("✓Backdrop");
    menuWorbench->addAction("About...");
    menuWorbench->addSeparator();
    menuWorbench->addAction("Reboot");
    QAction *quitAction = new QAction("Quit");
    QObject::connect(quitAction, SIGNAL(triggered()), &a, SLOT(quit()));
    menuWorbench->addAction(quitAction);
    wb.AddPopupMenu(menuWorbench, 0);
    wb.AddPopupMenu(menuWorbench, 1);
    wb.AddPopupMenu(menuWorbench, 2);
    wb.AddPopupMenu(menuWorbench, 3);

    // RAM icon
    AmigaWorkbenchIcon iconRam(nullptr, 20, 100, 128);
    iconRam.setIcon(":/pics/diskette.png");
    iconRam.setTitle("RAM");
    iconRam.setCommand("c:/windows/write.exe");
    wb.AddIcon(&iconRam);

    // System icon
    AmigaWorkbenchIcon sysIcon(nullptr, 20, 180, 128);
    sysIcon.setIcon(":/pics/systemfolder.png");
    sysIcon.setTitle("System OS 3.1");
    sysIcon.setCommand("C:/windows/notepad.exe");
    wb.AddIcon(&sysIcon);

    // some windows
    AmigaWindow w1(nullptr,false,false,true,true,true,false), w2(nullptr, false, false, false, true);
    w1.resize(320,240);
    w1.move(300,400);
    w1.setWindowTitle("About");
    w2.resize(480,200);
    w2.move(400,600);
    w2.setWindowTitle("Window #2");
    w1.showNormal();
    w2.showNormal();


    return a.exec();
}
