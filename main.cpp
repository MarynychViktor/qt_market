#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTableView>
#include <QNetworkReply>
#include <form.h>
#include <QJsonDocument>

#include <pages/menu.h>

#include <infrastructure/httpclient.h>
#include <infrastructure/markethttpclient.h>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
//  Form form;

  Menu menu(&app);
  menu.show();

//  QAbstractItemModel *model = new ProductTableModel();
//  orders.setModel(model);
//  orders.show();
  auto manager = new QNetworkAccessManager();
  auto httpCLient = new HttpClient(manager);
  auto marketClient = new MarketHttpClient(httpCLient);
  marketClient->getTrades([](QList<TradeResponse*> trades) {
    for(auto trade: trades) {
        qDebug() << trade->name << "---" << trade->classId << "---" << trade->instanceId << "---" << trade->uiPrice << "---" << trade->marketPrice;
    }
  }, [](QNetworkReply* reply) {
        qDebug() << "Error ********" << reply->errorString();
  });
  for(int i =0; i < 10; i++) {
      marketClient->getItemInfo("2735521262", "188530139", [i](ItemInfo* item) {
        qDebug() << "Request ********" << i;
        qDebug() << item->toString() ;
      }, [](QNetworkReply* reply) {
          qDebug() << "Error ********" << reply->errorString();
    });
  }


  return app.exec();
}
