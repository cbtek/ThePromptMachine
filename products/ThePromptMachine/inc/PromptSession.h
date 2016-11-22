/*
    PromptSession.h

    
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

#ifndef _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_PROMPTSESSION_H
#define _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_PROMPTSESSION_H
#include <QString>
#include <QColor>

namespace cbtek {
namespace products {
namespace productivity {
namespace prompt_machine {

class PromptSession 
{
public:
    /**
     * @brief Constructor for PromptSession
     *  Detailed description for PromptSession
     */

    PromptSession();
    /**
    * @brief Setter for m_text
    * @param Value to replace m_text
    */
    void setText(const QString & value);

    /**
    * @brief Setter for m_textForegroundColor
    * @param Value to replace m_textForegroundColor
    */
    void setTextForegroundColor(const QColor & value);

    /**
    * @brief Setter for m_textBackgroundColor
    * @param Value to replace m_textBackgroundColor
    */
    void setTextBackgroundColor(const QColor & value);

    /**
    * @brief Setter for m_pageBackgroundColor
    * @param Value to replace m_pageBackgroundColor
    */
    void setPageBackgroundColor(const QColor & value);

    /**
    * @brief Setter for m_textSize
    * @param Value to replace m_textSize
    */
    void setTextSize(int value);

    /**
    * @brief Setter for m_timeoutSeconds
    * @param Value to replace m_timeoutSeconds
    */
    void setTimeoutSeconds(int value);

    /**
    * @brief Setter for m_initialScrollSpeed
    * @param Value to replace m_initialScrollSpeed
    */
    void setInitialScrollSpeed(int value);


    /**
    * @brief Getter for m_text
    * @return Return copy of m_text
    */
    const QString & getText() const;

    /**
    * @brief Getter for m_textForegroundColor
    * @return Return copy of m_textForegroundColor
    */
    const QColor & getTextForegroundColor() const;

    /**
    * @brief Getter for m_textBackgroundColor
    * @return Return copy of m_textBackgroundColor
    */
    const QColor & getTextBackgroundColor() const;

    /**
    * @brief Getter for m_pageBackgroundColor
    * @return Return copy of m_pageBackgroundColor
    */
    const QColor & getPageBackgroundColor() const;

    /**
    * @brief Getter for m_textSize
    * @return Return copy of m_textSize
    */
    int getTextSize() const;

    /**
    * @brief Getter for m_timeoutSeconds
    * @return Return copy of m_timeoutSeconds
    */
    int getTimeoutSeconds() const;

    /**
    * @brief Getter for m_initialScrollSpeed
    * @return Return copy of m_initialScrollSpeed
    */
    int getInitialScrollSpeed() const;




    //! Destructor
    ~PromptSession();	
private:
    QString m_text;
    QColor m_textForegroundColor;
    QColor m_textBackgroundColor;
    QColor m_pageBackgroundColor;
    int m_textSize;
    int m_timeoutSeconds;
    int m_initialScrollSpeed;

};
}}}}//end namespace

#endif // _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_PROMPTSESSION_H

