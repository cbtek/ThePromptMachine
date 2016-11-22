#ifndef _CBTEK_COMMON_QTUTILS_UICOLORLABEL_H_
#define _CBTEK_COMMON_QTUTILS_UICOLORLABEL_H_

#include <QLabel>

#include "utility/inc/ColorUtils.hpp"

namespace cbtek {
namespace common {
namespace qt_utility {

class UIColorLabel : public QLabel
{
    Q_OBJECT
public:
    explicit UIColorLabel(QWidget * parent = 0);

    explicit UIColorLabel(const QColor &color, QWidget *parent = 0);

    explicit UIColorLabel(const utility::Color &color, QWidget *parent = 0);
    
    QColor getColor() const;        

public slots:
    void onSetColor(const QColor & color);

signals:
    void colorChanged(const QColor & color);
    void colorChanged(const common::utility::Color & color);
public slots:

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QColor m_color;
};

}}}//namespace
#endif // _CBTEK_COMMON_QTUTILS_UICOLORLABEL_H
