#include "main_window.h"
#include <QtWidgets/QApplication>

int main( int argc, char *argv[] )
{
   QApplication a( argc, argv );
   a.setAttribute( Qt::AA_DisableWindowContextHelpButton );
   MainWindow w;
   w.show();
   return a.exec();
}
