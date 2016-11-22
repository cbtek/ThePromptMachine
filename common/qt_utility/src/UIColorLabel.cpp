#include "UIColorLabel.h"
#include "UIColorPicker.h"

#include <QPainter>

namespace cbtek {
namespace common {
namespace qt_utility {

UIColorLabel::UIColorLabel(QWidget *parent) :
    QLabel(parent)
{
    update();
}

UIColorLabel::UIColorLabel(const QColor &color,QWidget *parent) :
    QLabel(parent)
{
    m_color=color;
    update();
}

UIColorLabel::UIColorLabel(const utility::Color &color, QWidget *parent) :
    QLabel(parent)
{
    m_color.setRed(color.getRed());
    m_color.setGreen(color.getGreen());
    m_color.setBlue(color.getBlue());
    m_color.setAlpha(color.getAlpha());
    update();
}

QColor UIColorLabel::getColor() const
{
    return m_color;
}

void UIColorLabel::onSetColor(const QColor &color)
{
    m_color=color;
    emit colorChanged(color);
    emit colorChanged(utility::Color(color.red(),color.green(),color.blue(),color.alpha()));
    update();
}

void UIColorLabel::paintEvent(QPaintEvent * event)
{
    QPainter g(this);
    g.fillRect(0,0,width(),height(),m_color);
    QColor penColor = Qt::white;
    if (m_color == penColor)
    {
        penColor = Qt::gray;
    }
    g.setPen(penColor);
    g.drawRect(0,0,this->width()-2,this->height()-2);
    QLabel::paintEvent(event);
}

void UIColorLabel::mousePressEvent(QMouseEvent *)
{
    UIColorPicker picker(false);
    connect(&picker,SIGNAL(colorSelected(QColor)),this,SLOT(onSetColor(QColor)));
    picker.exec();
}


}}}//namespace
