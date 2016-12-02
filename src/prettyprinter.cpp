
#include "prettyprinter.h"

#include <QString>
#include <QByteArray>
#include <QChar>
#include <QLatin1Char>

#include <QtDebug>

#include <cstdio>

QString ToHexString(const QByteArray &data) {
    QString hex;

    char buf[3];
    for (char c : data) {
        snprintf(buf, sizeof(buf), "%02hhx", c);
        hex.push_back(buf);
    }

    return hex;
}

static QString PrintLine(const QByteArray& line) {
    QString hex;
    QString text;

    char buf[3];
    for(char c: line) {
        snprintf(buf, 3, "%02hhx", c);
        hex.push_back(buf);
        if (QChar(c).isLetterOrNumber()) {
            text.push_back(c);
        } else {
            text.push_back('.');
        }
    }

    const int lack = 16 - line.length();
    hex += QString(lack*2, ' ');
    text += QString(lack, ' ');

    QString hex_line;
    for (int i=0; i<8; ++i) {
        hex_line += hex.mid(i*4,4) + " ";
    }

    return hex_line + text;
}

QString PrettyPrint(const QByteArray& data) {
    QByteArray tmp = data;
    QString ret;
    for (int i=0; !tmp.isEmpty(); i++) {
        ret += QString().sprintf("%07x ", i*16) + PrintLine(tmp.mid(0,16)) + "\n";
        tmp.remove(0,16);
    }

    return ret;
}
