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

  QList<QString> ids;
  ids.append(QString(("2532287607_") + QString("188530139")));

  QList<ItemMassInfoResult*> items = marketClient->getMassInfo(ids);
  for(auto item : items) {
    qDebug() << "Result" << "ClassID:" << item->classId << "InstanceId" << item->instanceId <<
                "Best offer: " << item->tradeOffers->bestOffer << "My offers" << item->tradeOffers->myOffers <<
                "OFFERS" << item->tradeOffers->offers << "MIN OFFER " << item->tradeOffers->getMinNotMyOffer();
  }

  return app.exec();
}
