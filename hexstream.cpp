#include "hexstream.h"
#include <QFile>
#include <assert.h>
#include <QMessageBox>

HexStream::HexStream(QObject *parent, Ava::ModeRead mode) : QObject(parent)
{
    assert(parent != NULL);
    assert(mode != NULL);
    this->mode = mode;
}

HexStream::HexStream(QObject *parent, QString  path, Ava::ModeRead mode) : QObject(parent)
{
    assert(path != NULL), "The path is NULL";
    this->path = path;
    this->mode = mode;
    openFile(path);
}


HexStream::~HexStream()
{
   delete file;
}

QString HexStream::getPath() const
{
    assert(path != NULL);
    return path;
}

void HexStream::setPath(const QString &path)
{
    assert(path != NULL);
    this->path = path;
    file = new QFile(path);
    assert(file != NULL);
}

void HexStream::openFile(QString &path) {
    file = new QFile(path);
    bool isAvailable = file->open(QIODevice::ReadOnly | QIODevice::WriteOnly);
    if(!isAvailable)
    {
        QString msg = "Thie " + path + " file not open";
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    }
}

QString HexStream::getHexData(int size)
{
    switch(mode)
    {
    case Ava::big_endian:

        break;
    case Ava::little_endian:

        break;
    default:
        throw;
        break;
    }
}



