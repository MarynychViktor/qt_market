#include <QApplication>
#include <QPushButton>
#include <QTableView>
#include <form.h>

#include <pages/menu.h>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
//  Form form;

  Menu menu(&app);
  menu.show();

//  QAbstractItemModel *model = new ProductTableModel();
//  orders.setModel(model);
//  orders.show();

  return app.exec();
}
