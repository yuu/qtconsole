#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtGui/QColor>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    qDebug() << "colorF: " <<  QColor("#808080FF").alphaF();

    return app.exec();
}
