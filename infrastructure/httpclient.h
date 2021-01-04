#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>

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

    QByteArray get(const QString& path);
    QByteArray post(const QString& path, const QByteArray& data);

private:
    QNetworkAccessManager* manager;
    int timeout = 5000;
};

#endif // HTTPCLIENT_H
