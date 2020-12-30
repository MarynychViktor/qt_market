#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTableView>
#include <QNetworkReply>
#include <form.h>
#include <QJsonDocument>

#include <pages/menu.h>

#include <infrastructure/httpclient.h>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
//  Form form;

  Menu menu(&app);
  menu.show();

//  QAbstractItemModel *model = new ProductTableModel();
//  orders.setModel(model);
//  orders.show();

  auto httpCLient = new HttpClient();
  httpCLient->get(QString("http://www.google.com.ua/"), [](QNetworkReply* reply) {
    QString body = reply->readAll();
    auto statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (statusCode != 200) {
        throw std::runtime_error("Request failed with non 200 code");
    }

    QJsonDocument document;
    document.

    qDebug() << "Report: " << body;
  });

  return app.exec();
}
