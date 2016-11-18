#include <QtCore/QCoreApplication>

#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("qt template project");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("file", QCoreApplication::translate("main", "Change QML property via ini"));

    QCommandLineOption forceOption(QStringList() << "f" << "force",
        QCoreApplication::translate("main", "Overwrite existing files."));
    parser.addOption(forceOption);

    parser.process(app);

    const QStringList args = parser.positionalArguments();
    for (auto &&x : args)
        qDebug() << x;

    qDebug() <<  parser.isSet(forceOption);

    return app.exec();
}
