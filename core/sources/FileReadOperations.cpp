#include "FileReadOperations.h"
#include <QFile>

FileReadOperations::FileReadOperations(const QString &filePath)
    : _filePath(filePath) {
}

qint64 FileReadOperations::readFromEndOfFileBackward(int numberOfLines) {
    QFile file(_filePath);
    if ( file.exists() ) {
        qDebug() << "Read number lines: " << numberOfLines;
        file.open(QIODevice::ReadOnly);
        qint64 newFileSize = file.size();

        qint64 currentPos = newFileSize;
        int lineCounter = 0;
        QString text = "";
        QString character = "";
        while (currentPos > 0 && lineCounter < numberOfLines) {
            --currentPos;
            character = file.read(1);
            text += character;
            if (character == "\n") {
                lineCounter += 1;
            }
        }

        file.close();
        emit readString(text);
        return newFileSize;
    }

    return 0;
}

qint64 FileReadOperations::readCompleteFile() {
    QFile file(_filePath);
    if ( file.exists() ) {
        qDebug() << "Start read from beginning";
        file.open(QIODevice::ReadOnly);
        qint64 newFileSize = file.size();

        if ( file.isOpen() ) {
            file.seek(0);
            QString text = file.readAll();
            file.close();
            emit readString(text);
        }

        return newFileSize;
    }

    return 0;
}

qint64 FileReadOperations::readFromPrevFileSizeTillEnd(qint64 prevFileSize) {
    QFile file(_filePath);
    if ( file.exists() ) {
        qDebug() << "Read file from previous file size location";
        file.open(QIODevice::ReadOnly);
        qint64 newFileSize = file.size();

        if ( file.isOpen() ) {
            file.seek(prevFileSize);
            QString text = file.readAll();
            file.close();
            emit readString(text);
        }

        return newFileSize;
    }

    return 0;
}
