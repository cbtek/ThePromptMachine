/*
    QCircularPainter.cpp

    
///
/// CBTek LLC ("COMPANY") CONFIDENTIAL
/// Copyright (c) 2016 CBTek, All Rights Reserved.
///
/// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
/// herein are proprietary to COMPANY and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
/// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
/// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
/// Confidentiality and Non-disclosure agreements explicitly covering such access.
///
/// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
/// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
/// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
/// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
/// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
///

*/
//----------------------------------------
//QCircularPainter.cpp generated by cbtek on 10-15-2016 at 10:13:52 PM
//----------------------------------------
#include "QCircularPainter.h"

#include "math/inc/MathUtils.hpp"

using namespace cbtek::common::math;

namespace cbtek {
namespace common {
namespace qt_utility {


QCircularPainter::QCircularPainter(QPaintDevice *device)
{
    m_device=device;
    m_painter.begin(device);
    m_originX = device->width()/2;
    m_originY = device->height()/2;
}

void QCircularPainter::setPen(const QPen &pen)
{
    m_painter.setPen(pen);
}

void QCircularPainter::setBrush(const QBrush &brush)
{
    m_painter.setBrush(brush);
}


QPoint QCircularPainter::drawShape(ShapeType shape, double angle, double distance, double w, double h, double rotation)
{
    int screenWidth = m_device->width();
    int screenHeight = m_device->height();
    int diameter = m_device->width() < m_device->height()? m_device->width():m_device->height();
    QPoint center;
    switch(shape)
    {
        case ShapeType::SQUARE:
        {
           double x = MathUtils::translateX(angle,distance,m_originX);
           double y = MathUtils::translateY(angle,distance,m_originY);
           m_painter.drawRect(QRect(x-(w/2),y-(w/2),w,h));
           center = QPoint(x,y);
        }
        break;
        default: break;
    }
    return center;
}

void QCircularPainter::drawLine(double angle, double distance)
{
    double x = MathUtils::translateX(angle,distance,m_originX);
    double y = MathUtils::translateY(angle,distance,m_originY);
    m_painter.drawLine(QPoint(m_originX,m_originY),
                       QPoint(x,y));
}

void QCircularPainter::drawImage(const QImage &image, double angle, double distance, double w, double h, double rotation)
{
    double x = MathUtils::translateX(angle,distance,m_originX);
    double y = MathUtils::translateY(angle,distance,m_originY);
    if (w<0)w=image.width();
    if (h<0)h=image.height();
    m_painter.drawImage(QRect(x-(w/2),y-(w/2),w,h),image);
}

void QCircularPainter::setOrigin(double x, double y)
{
    m_originX = x;
    m_originY = y;
}


void QCircularPainter::clearBackground(QColor color)
{
    m_painter.fillRect(QRect(0,0,this->m_device->width(),this->m_device->height()),color);
}

void QCircularPainter::drawSceneBorder(QColor color, int borderWidth)
{
    QPen lastPen=m_painter.pen();
    QPen pen;
    pen.setColor(color);
    pen.setWidth(borderWidth);
    m_painter.setPen(pen);
    m_painter.drawEllipse(borderWidth,borderWidth,m_device->width()-borderWidth-borderWidth,m_device->height()-borderWidth-borderWidth);
    m_painter.setPen(lastPen);
}

void QCircularPainter::drawGrid(QColor color, int lineWidth,int style, int step)
{
    QPen lastPen=m_painter.pen();
    QPen pen;
    pen.setColor(color);
    pen.setWidth(lineWidth);
    pen.setStyle((Qt::PenStyle)style);
    m_painter.setPen(pen);
    for (size_t x = 0;x<m_device->width();x+=step)
    {
        m_painter.drawLine(QPoint(x,0),QPoint(x,m_device->height()));
    }

    for (size_t y = 0;y<m_device->height();y+=step)
    {
        m_painter.drawLine(QPoint(0,y),QPoint(m_device->width(),y));
    }
    m_painter.setPen(lastPen);
}

void QCircularPainter::end()
{
    m_painter.end();
}

QCircularPainter::~QCircularPainter()
{
    m_painter.end();
}



}}}//end namespace

