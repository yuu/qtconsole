/*! \file prettyprinter.h
 * \brief 文字列整形機能を定義するファイルです．
 */

class QString;
class QByteArray;

/*!
 * \brief QByteArray を 16 進数表記の文字列に変換します．
 * \param data 入力。
 * \return 変換結果。
 */
QString ToHexString(const QByteArray &data);

/*!
 * \brief QByteArrayを整形します．
 * \param data 入力
 * \return 整形結果
 */
QString PrettyPrint(const QByteArray& data);
