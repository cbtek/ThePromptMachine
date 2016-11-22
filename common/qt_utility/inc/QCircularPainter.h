/*
    QCircularPainter.h

    
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

#ifndef _CBTEK_COMMON_QT_UTILITY_QCIRCULARPAINTER_H
#define _CBTEK_COMMON_QT_UTILITY_QCIRCULARPAINTER_H
#include <QPainter>
#include <QPen>

namespace cbtek {
namespace common {
namespace qt_utility {

enum class ShapeType
{
    TRIANGLE,
    CIRCLE,
    SQUARE,
    DIAMOND,
    CROSS_HAIRS
};

class QCircularPainter 
{
public:
    /**
     * @brief Constructor for QCircularPainter
     *  Detailed description for QCircularPainter
     */
    QCircularPainter(QPaintDevice * device);


    void setPen(const QPen & pen);
    void setBrush(const QBrush & brush);
    QPoint drawShape(ShapeType shape, double angle, double distance, double w, double h, double rotation = -1);
    void drawLine(double angle, double distance);
    void drawImage(const QImage & image, double angle, double distance, double w=-1, double h=-1, double rotation = -1);
    void setOrigin(double x, double y);
    void clearBackground(QColor color);
    void drawSceneBorder(QColor color, int borderWidth);
    void drawGrid(QColor color, int lineWidth, int style, int step=50);
    void end();
    //! Destructor
    ~QCircularPainter();	

private:
    double m_originX;
    double m_originY;
    QPaintDevice * m_device;
    QPainter m_painter;

};
}}}//end namespace

#endif // _CBTEK_COMMON_QT_UTILITY_QCIRCULARPAINTER_H

