#include <QtCore/QCoreApplication>
#include <QtGlobal>
#include <QDebug>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    const char *key = "AAAA";
    qputenv(key, QByteArray("1"));
    qDebug() << "key:" << qgetenv(key);

    bool ok = false;
    if (0 == qEnvironmentVariableIntValue(key, &ok) && ok)
        qDebug() << "引数1";
    else
        qDebug() << "引数0";

    return app.exec();
}
