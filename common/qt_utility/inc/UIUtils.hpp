/*
    UIUtils.h
    
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

#ifndef _CBTEK_COMMON_QT_UTILITY_UIUTILS_H
#define _CBTEK_COMMON_QT_UTILITY_UIUTILS_H

#include <QFont>
#include <QColor>

#include "utility/inc/Color.h"
#include "utility/inc/ColorFactory.h"

namespace cbtek {
namespace common {
namespace qt_utility {
namespace UIUtils
{


inline cbtek::common::utility::Color toColor(const QColor & color)
{
    return cbtek::common::utility::Color(color.red(),color.green(),color.blue(),color.alpha());
}

inline QColor toQColor(const common::utility::Color & color)
{
    return QColor(color.getRed(),color.getGreen(),color.getGreen(),color.getAlpha());
}

inline QString toHTMLColorRGBString(const QColor & color, bool keepHashSymbol=true)
{
    QString htmlRGB=QString::fromStdString(toColor(color).toString(common::utility::colorStringStyle::RGB_HTML_HEX));
    if (!keepHashSymbol)
    {
        htmlRGB = htmlRGB.remove("#");
    }
    return htmlRGB;
}


inline QString toHTMLColorRGBAString(const QColor & color, bool keepHashSymbol=true)
{
    QString htmlRGBA=QString::fromStdString(toColor(color).toString(common::utility::colorStringStyle::RGBA_HTML_HEX));
    if (!keepHashSymbol)
    {
        htmlRGBA = htmlRGBA.remove("#");
    }
    return htmlRGBA;
}


inline QString toHTMLColorARGBString(const QColor & color, bool keepHashSymbol=true)
{
    QString htmlARGB=QString::fromStdString(toColor(color).toString(common::utility::colorStringStyle::ARGB_HTML_HEX));
    if (!keepHashSymbol)
    {
        htmlARGB = htmlARGB.remove("#");
    }
    return htmlARGB;
}

inline QFont getAutoFont(const QString &text,
                         int width,
                         int maxPointSize=80)
{
    QFont font("arial",maxPointSize);
    while (QFontMetrics(font).width(text) > width)
    {
        font = QFont("arial",font.pointSize()-4);
        if (font.pointSize() < 6)
        {
            break;
        }
        if (font.pointSize() > maxPointSize)
        {
            font.setPointSize(maxPointSize);
        }
    }
    return font;
}


}
}}}//end namespace

#endif

