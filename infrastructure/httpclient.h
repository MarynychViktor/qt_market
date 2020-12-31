#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>

typedef void HttpResponseHandler(QNetworkReply *reply);
using namespace std;

class HttpClient
{
public:
    HttpClient(QNetworkAccessManager* m): manager(m) {
    };
    void get(QString path, function<void(QNetworkReply*)> handler);
private:
    QNetworkAccessManager* manager;
};

#endif // HTTPCLIENT_H
