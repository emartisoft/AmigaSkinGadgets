#ifndef AMIGATEXTEDIT_H
#define AMIGATEXTEDIT_H

#include <QTextEdit>

class AmigaTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    AmigaTextEdit(QWidget* parent,
                  int w,
                  int h,
                  int x,
                  int y,
                  const QString& text=""
                  );
};

#endif // AMIGATEXTEDIT_H
