
#include <QApplication>

#include "UIPromptMachineEditor.h"
#include "UIPromptMachineViewer.h"

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    cbtek::products::productivity::prompt_machine::UIPromptMachineEditor ui;
    ui.show();
    return a.exec();
}
