#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>

typedef void HttpResponseHandler(QNetworkReply *reply);
using namespace std;

class HttpClient
{
public:
    HttpClient(QNetworkAccessManager* m): manager(m) {};
    void get(QString path, function<void(QNetworkReply*)> handler, function<void(QNetworkReply*)> onError = nullptr);
    void post(QString path, QByteArray data, function<void(QNetworkReply*)> handler, function<void(QNetworkReply*)> onError = nullptr);
    QNetworkAccessManager* manager;
private:
};

#endif // HTTPCLIENT_H
