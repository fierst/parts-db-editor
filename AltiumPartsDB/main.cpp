#include "parts_browser_dlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    parts_browser_dlg w;
    w.show();

    return a.exec();
}
