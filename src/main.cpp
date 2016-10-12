#include <QtCore/QCoreApplication>
#include <QtGlobal>
#include <QDebug>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    const char *key = "AAAA";
    qputenv(key, QByteArray("1"));
    qDebug() << "key:" << qgetenv(key);

    return app.exec();
}
