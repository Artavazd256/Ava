#include "hexstream.h"
#include <QFile>
#include <assert.h>
#include <QMessageBox>
#include "utils.h"
#include <iostream>
#include "ui_mainwindow.h"


HexStream::HexStream(QObject *parent, Ava::ModeRead mode)
    : QObject(parent)
{
    assert(parent != NULL);
    assert(mode != NULL);
    this->mode = mode;
}

HexStream::HexStream(QObject *parent, QString  path, Ava::ModeRead mode)
    : QObject(parent)
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

Ava::ModeRead HexStream::getMode() const
{
    return mode;
}

void HexStream::setMode(const Ava::ModeRead &value)
{
    mode = value;
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

QString HexStream::splitBySize(QString data, int size)
{
    assert(data != NULL );
    QString result = "";
    int counter = 0;
    for(int i = 0; i < data.size(); i++)
    {
        QChar h = data.at(i);
        result.append(h);
        counter++;
        if(counter == size) {
            result.append(" ");
            counter = 0;
        }

    }
    assert(result != NULL);
    return result;
}


QString HexStream::big_endian(int size)
{
    QByteArray array = file->readAll();
    hexData.append(array.toHex());
    QString data = splitBySize(hexData, size);
    return data;
}

QString HexStream::little_endian(int size)
{
    QByteArray array = file->readAll();
    hexData.append(array.toHex());
    QString data = splitBySize(hexData, size);
    std::reverse(data.begin(), data.end());
    return data;
}



