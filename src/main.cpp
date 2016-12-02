#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <QString>
#include "prettyprinter.h"

#define STX    "\x02"    /* Text start    */
#define ETX    "\x03"    /* Text end      */
#define ETB    "\x17"    /* Block end     */
#define ESC    "\x1b"    /* Escape code   */

struct D {
    QChar c;
    QString val;
    QString data;
};

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    auto raw = QString("\x02\x1bN99pic000111.png \x17 \x1bN99pic000222.png \x17 \x03");
    qDebug() << PrettyPrint(raw.toLocal8Bit());

    QList<D> list;
    int from = 0;
    while (int stx = raw.indexOf(ETB, from)) {
        if (-1 == stx) {
            break;
        }

        auto l = raw.left(stx);
        auto ll = l.split(ESC);

        // 次の検索は STX 以降
        raw.remove(from, stx + 1);

        for (auto &&x : ll) {
            qDebug() << "for:" << x;
            if (3 <= x.size()) {
                list.push_back(D{x.at(0),
                                 QString("%1%2").arg(x.at(1)).arg(x.at(2)),
                                 x.mid(3, x.length()).trimmed()}
                              );
            }
        }
    }

    for (auto &&x : list) {
        qDebug() << x.c << x.val << x.data;
    }

    return 0;
}
