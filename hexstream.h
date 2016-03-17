#ifndef HEXSTREAM_H
#define HEXSTREAM_H


#include <QObject>
#include <QFile>

namespace Ava {
    class HexStream;
    enum ModeRead
    {  big_endian
      ,little_endian
    };
}

class HexStream : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief HexStream constructor
     * @param parent
     * @param mode  should be BIG_ENDIAN or LITTLE_ENDIAN
     */
    explicit HexStream(QObject *parent = 0, Ava::ModeRead mode = Ava::big_endian);
    /**
     * @brief HexStream constructor
     * @param parent
     * @param path
     * @param mode
     */
    explicit HexStream(QObject *parent, QString path, Ava::ModeRead mode = Ava::big_endian);

    /**
     * desctructor
     *
     */
    ~HexStream();

    /**
     * @brief getPath
     * @return
     */
    QString getPath() const;
    /**
     * @brief setPath
     * @param value
     */
    void setPath(const QString &value);
    /**
     * @brief getHexData
     * @param size
     * @return
     */
    QString getHexData(int size);

    /**
     * @brief openFile
     * @param path
     */
    void openFile(QString &path);
    Ava::ModeRead getMode() const;
    void setMode(const Ava::ModeRead &value);

signals:

public slots:

private:
    QString path = NULL;
    QString hexData = NULL;
    QFile * file;
    Ava::ModeRead mode;
    QString big_endian(int size);
    QString little_endian(int size);
    QString splitBySize(QString data, int size);
};


#endif // HEXSTREAM_H


