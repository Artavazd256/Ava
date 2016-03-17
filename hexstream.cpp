#include "hexstream.h"
#include <QFile>
#include <assert.h>
#include <QMessageBox>
#include "utils.h"

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
    assert(path != NULL);
    file = new QFile(path);
    bool isAvailable = file->open(QIODevice::ReadOnly | QIODevice::WriteOnly);
    if(!isAvailable)
    {
        QString msg = "Thie " + path + " file not open";
        Utils::showMessage(msg);
    }
}

QString HexStream::getHexData(int size)
{
    assert(size != NULL);
    QString out;
    switch(mode)
    {
    case Ava::big_endian:
        out = big_endian(size);
        break;
    case Ava::little_endian:
        out = little_endian(size);
        break;
    }
    assert(out != NULL);
    return out;
}


QString HexStream::big_endian(int size)
{
    assert(size != NULL);
    while(!file->atEnd())
    {
    }
    return NULL;
}

QString HexStream::little_endian(int size)
{
    assert(size != NULL);
    return NULL;
}



