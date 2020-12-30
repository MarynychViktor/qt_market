#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>

typedef void HttpResponseHandler(QNetworkReply *reply);

class HttpClient
{
public:
    HttpClient();
    void get(QString path, HttpResponseHandler handler);
private:
    QNetworkAccessManager* manager;
};

#endif // HTTPCLIENT_H
