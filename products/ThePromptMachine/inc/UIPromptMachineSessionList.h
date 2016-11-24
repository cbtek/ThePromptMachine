/*
    UIPromptMachineSessionList.h
    

*/

#ifndef _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINESESSIONLIST_H
#define _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINESESSIONLIST_H
#include <QMainWindow>

class Ui_UIPromptMachineSessionList;

namespace cbtek {
namespace products {
namespace productivity {
namespace prompt_machine {


class UIPromptMachineSessionList : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIPromptMachineSessionList
	/*!
		Detailed description for UIPromptMachineSessionList
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIPromptMachineSessionList(QWidget *parent = 0);
    
    
	//! Descructor for UIPromptMachineSessionList
    ~UIPromptMachineSessionList();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIPromptMachineSessionList *m_ui;
    
};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_PRODUCTIVITY_PROMPT_MACHINE_UIPROMPTMACHINESESSIONLIST_H
