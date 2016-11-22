/*
    UIPromptMachineEditor.h
    
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

#ifndef _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEEDITOR_H
#define _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEEDITOR_H

#include <QMainWindow>

#include "PromptSession.h"

#include "utility/inc/Random.h"

#include "qt_utility/inc/UIColorLabel.h"

class Ui_UIPromptMachineEditor;

namespace cbtek {
namespace products {
namespace productivity {
namespace prompt_machine {


class UIPromptMachineEditor : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIPromptMachineEditor
	/*!
		Detailed description for UIPromptMachineEditor
        @param      parent points to embedding super widget. Defaults to null.
	*/    
    explicit UIPromptMachineEditor(QWidget *parent = 0);

    explicit UIPromptMachineEditor(const PromptSession & session,
                                   QWidget *parent = 0);
        
	//! Descructor for UIPromptMachineEditor
    ~UIPromptMachineEditor();
private:
    /** 
    * MOC generated ui class for this widget
    */
     common::qt_utility::UIColorLabel * m_textFgColorLabel;
     common::qt_utility::UIColorLabel * m_pageBgColorLabel;
     common::utility::Random m_rnd;

     Ui_UIPromptMachineEditor *m_ui;          
private slots:
     void onDeserializeFromSession(const PromptSession & session);
     void onSerializeToSession(PromptSession & session);
     void onInitialize();
     void onTextFGColorChanged(QColor color);
     void onPageBGColorChanged(QColor color);     
     void onTextSizeChanged(int value);
     void onStart();
     void onTextBegin();
     void onTextEnd();
     void onTextSpeedChanged(int value);
     void onRandomColors();

};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINEEDITOR_H
