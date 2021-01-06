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

#include <QApplication>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AmigaWindow w;//(nullptr, false, false, false);

    // font
    QFont font;
    font.setFamily(QString::fromUtf8("AmigaTopazTurkish"));
    font.setPointSize(12);

    // Button
    /*
    AmigaButton aButton(&w,
                    ":/pics/pics/normal.png",
                    ":/pics/pics/hover.png",
                    ":/pics/pics/press.png",
                    50, 150, "Deneme");
    aButton.setTextColor(QColor(255,0,255));
    aButton.setFont(font);
    */

    // Standart Button
    AmigaStandartButton aSButton(&w, 120, 25, 20, 50, "Button");
    aSButton.setFont(font);

    // LineEdit
    AmigaLineEdit aLineEdit(&w, 200, 25, 20, 80);
    aLineEdit.setFont(font);
    aLineEdit.setText("text");

    // horizontal line
    AmigaHorizontalLine hl1(&w, 50, 20, 32);
    // Label
    AmigaLabel aLabel(&w, 190, 25, 70, 20, "This is horizontal line");
    aLabel.setFont(font);
    AmigaLabel aLabel2(&w, 150, 25, 20, 140, "This is label.......");
    aLabel2.setFont(font);

    AmigaHorizontalLine hl2(&w, 50, 260, 32);

    // Checkbox
    AmigaCheckBox aCheckBox(&w, 240, 25, 20, 110, "This is a checkbox");
    aCheckBox.setFont(font);

    // horizontal slider
    AmigaHorizontalSlider aHorSlider(&w, 20, 170, 2, 8);

    // Combobox
    AmigaComboBox aCombobox(&w, 120, 25, 20, 200, QStringList{ "Birinci", "İkinci", "Üçüncü"});
    aCombobox.setFont(font);

    // frame
    AmigaFrame aFrame(&w, 200, 100, 20, 230);
    AmigaLabel lFrame(&aFrame, 100, 25, 10, 10, "Frame Text");
    lFrame.setFont(font);

    AmigaFrame aFrameCaro(&w, 200, 100, 20, 340, true);
    AmigaLabel lFrame2(&aFrameCaro, 140, 25, 10, 10, "Caro Frame Text");
    lFrame2.setFont(font);

    // textedit
    AmigaTextEdit aTextEdit(&w, 400, 200, 280, 60);
    aTextEdit.setFont(font);
    aTextEdit.setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'AmigaTopazTurkish'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Bold</span></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Italic</span></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Normal</p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; m"
                            "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This is a boing ball image: <img src=\":/pics/pics/boingball.png\" /></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0 1 2 3 4 5 6 7 8 9</p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"www.aminet.net\"><span style=\" font-size:12pt; text-decoration: underline; color:#0000ff;\""
                            ">www.aminet.net</span></a></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; text-decoration: underline; color:#0000ff;\"><br /></p>\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; text-decoration: underline; color:#0000ff;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /></span>End of Doc</p></body></html>", nullptr));

    // listwidget
    AmigaListWidget aListWidget(&w, 200, 100, 280, 300);
    aListWidget.setFont(font);
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
    aProgBar.setFont(font);
    aProgBar.setValue(25);

    // spinbox
    AmigaSpinBox aSpinBox(&w, 120,25,500,420);
    aSpinBox.setFont(font);


    w.setWindowTitle("Amiga Window Title - çöışüğÇÖİŞÜĞ");
    w.resize(720, 480);
    w.setMinimumSize(720,480);
    w.show();

    return a.exec();
}
