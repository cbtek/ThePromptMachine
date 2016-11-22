#ifndef _CBTEK_COMMON_QTUTILS_UICOLORPICKER_H
#define _CBTEK_COMMON_QTUTILS_UICOLORPICKER_H

#include <QModelIndex>
#include <QDialog>

class Ui_UIColorPicker;

namespace cbtek {
namespace common {
namespace qt_utility {

class UIColorPicker : public QDialog
{
    Q_OBJECT
    
public:
    explicit UIColorPicker(bool standalone = true, QWidget *parent = 0);
    ~UIColorPicker();
    
private slots:
    void onTextChanged(const QString & text);

    void onSelectColor();

    void onClose();

    void onSelectCustomColor();

    void onPopulate(const QString & filter="");

    void onColorDoubleClicked(const QModelIndex & index);

signals:
    void colorSelected(const QColor & color);

private:

    bool m_isStandalone;
    Ui_UIColorPicker *ui;
};
}}}//namespace
#endif // _CBTEK_COMMON_QTUTILS_UICOLORPICKER_H
