/*
    UIPromptMachineViewer.h
    
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

#ifndef _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEVIEWER_H
#define _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEVIEWER_H

#include <QMainWindow>
#include <QTimer>
#include <QTextBrowser>
#include <QKeyEvent>


#include "PromptSession.h"

class Ui_UIPromptMachineViewer;

namespace cbtek {
namespace products {
namespace productivity {
namespace prompt_machine {


class UIPromptMachineViewer : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIPromptMachineViewer
	/*!
		Detailed description for UIPromptMachineViewer
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIPromptMachineViewer(const PromptSession & session,
                                   QWidget *parent = 0);
        
	//! Descructor for UIPromptMachineViewer
    ~UIPromptMachineViewer();

    void resizeEvent(QResizeEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *event);
private:

    /**
    * MOC generated ui class for this widget
    */
    Ui_UIPromptMachineViewer *m_ui;
    PromptSession m_session;
    QTextBrowser * m_browser;
    QTimer m_countDownTimer;
    QTimer m_scrollTimer;
    QImage m_countDownOverlay;    
    bool m_isCountDownMode;
    QImage m_textOverlay;
    int m_countDownSeconds;
    int m_textHeight;
    int m_scrollSpeed;

    bool m_isFullScreen;
private slots:
     void onToggleFullScreen();
     void onInit();
     void onUpdateCountDown();
     void onUpdateTextScroll();
     void onStart();
};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEVIEWER_H
