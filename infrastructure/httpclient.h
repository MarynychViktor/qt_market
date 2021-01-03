#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>

typedef void HttpResponseHandler(QNetworkReply *reply);
using namespace std;

class SyncHttpClient
{
public:
    SyncHttpClient() {
        manager = new QNetworkAccessManager;
    };
    ~SyncHttpClient()
    {
        delete manager;
    };

    QByteArray get(QString path);
    QByteArray post(QString path, QByteArray data);

private:
    QNetworkAccessManager* manager;
    int timeout = 5000;
};

#endif // HTTPCLIENT_H
