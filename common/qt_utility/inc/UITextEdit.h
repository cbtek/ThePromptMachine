#ifndef _MTEXTEDIT_H_
#define _MTEXTEDIT_H_

#include <QTextEdit>
#include <QMimeData>
#include <QImage>


namespace cbtek {
namespace common {
namespace qt_utility {

class UITextEdit : public QTextEdit
{
    Q_OBJECT
  public:
    UITextEdit(QWidget *parent);

    void        dropImage(const QImage& image, const QString& format);

  protected:
    bool        canInsertFromMimeData(const QMimeData *source) const;
    void        insertFromMimeData(const QMimeData *source);
    QMimeData  *createMimeDataFromSelection() const;

};
}}}//namespace
#endif
