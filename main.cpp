#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <QNetworkReply>


#include "pages/menu.h"
#include "ui/MainWindow.h"


int main(int argc, char **argv)
{
    // TODO: review shared pointers instead of raw
    // !!!!
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

  return app.exec();
}
