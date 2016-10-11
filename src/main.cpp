#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QSettings s("~/.config/weston.ini", QSettings::IniFormat);
    qDebug() << s.childGroups();
    s.beginGroup("ivi-launcher");
    qDebug() << s.childKeys();
    qDebug() << s.value("path");

    return app.exec();
}
