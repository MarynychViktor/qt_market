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

  Menu menu(&app);
  menu.show();

  auto marketClient = new MarketHttpClient();

//  QList<TradeResponse*> trades = marketClient->getTrades();
//  for(auto trade: trades) {
//      qDebug() << trade->name << "---" << trade->classId << "---" << trade->instanceId << "---" << trade->uiPrice << "---" << trade->marketPrice;
//  }

//  for(int i =0; i < 5; i++) {
//      ItemInfo* item = marketClient->getItemInfo("2735521262", "188530139");
//      qDebug() << "Request ********" << i;
//      qDebug() << item->toString() ;
//  }
  QList<QString> ids;
  ids.append(QString(("2735521262_") + QString("188530139")));

  qDebug() << "Get mass info";
  QList<ItemMassInfoResult*> items = marketClient->getMassInfo(ids);

  qDebug() << "Get mass info finished" << items.length();
  for(auto item : items) {
    qDebug() << "Result" << item->classId << item->instanceId << item->tradeOffers->bestOffer << item->tradeOffers->myOffers << item->tradeOffers->offers;
  }

  return app.exec();
}
