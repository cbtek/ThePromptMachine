#include "UIColorPicker.h"
#include "ui_UIColorPicker.h"

#include "utility/inc/ColorUtils.hpp"

#include <QImage>
#include <QPainter>
#include <QColorDialog>

namespace cbtek {
namespace common {
namespace qt_utility {

UIColorPicker::UIColorPicker(bool standalone, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIColorPicker)
{
    ui->setupUi(this);    
    m_isStandalone = standalone;
    connect(ui->m_btnCustom,SIGNAL(clicked()),this,SLOT(onSelectCustomColor()));
    connect(ui->m_btnSelect,SIGNAL(clicked()),this,SLOT(onSelectColor()));
    connect(ui->m_btnCancel,SIGNAL(clicked()),this,SLOT(onClose()));
    connect(ui->m_lstColors,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onColorDoubleClicked(QModelIndex)));
    connect(ui->m_txtSearch,SIGNAL(textChanged(QString)),this,SLOT(onTextChanged(QString)));
    onPopulate();    
}

UIColorPicker::~UIColorPicker()
{
    delete ui;
}

void UIColorPicker::onTextChanged(const QString &text)
{
    onPopulate(text);
}

void UIColorPicker::onClose()
{
    if (m_isStandalone)
    {
        this->close();
    }
    else
    {
        this->hide();
    }
}

void UIColorPicker::onSelectCustomColor()
{
    emit colorSelected(QColorDialog::getColor());
    onClose();
}

void UIColorPicker::onPopulate(const QString &filter)
{
    ui->m_lstColors->clear();
    for (size_t a1 = 0;a1<(size_t)common::utility::colors::NUM_COLORS;++a1)
    {
        utility::Color color = utility::ColorFactory::create((utility::colors::ColorType)a1);
        if (filter.trimmed().size()==0 || QString::fromStdString(color.getName()).toLower().trimmed().contains(filter.toLower().trimmed()))
        {
            QListWidgetItem * item = new QListWidgetItem;
            QImage image(64,24,QImage::Format_RGB32);
            image.fill(QColor(color.getRed(),color.getGreen(),color.getBlue()));
            item->setText(QString::fromStdString(color.getName()));
            item->setIcon(QIcon(QPixmap::fromImage(image)));
            item->setData(Qt::UserRole,color.toInteger());
            ui->m_lstColors->setIconSize(QSize(64,24));
            ui->m_lstColors->addItem(item);
        }
    }
    if (ui->m_lstColors->count()>0)
    {
        ui->m_lstColors->setCurrentRow(0);
    }
}

void UIColorPicker::onColorDoubleClicked(const QModelIndex &index)
{
    onSelectColor();
}

void UIColorPicker::onSelectColor()
{
    QListWidgetItem * item = ui->m_lstColors->currentItem();
    if (item)
    {
        utility::Color color(item->data(Qt::UserRole).toInt());
        emit colorSelected(QColor(color.getRed(),color.getGreen(),color.getBlue()));
    }

    onClose();
}

}}}//namespace
