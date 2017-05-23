#ifndef FILEREADOPERATIONS_H
#define FILEREADOPERATIONS_H

#include <QObject>
#include <QDebug>

class FileReadOperations : public QObject {
    Q_OBJECT

signals:
    void readString(const QString &content);

public:
    FileReadOperations(const QString &filePath);
    qint64 readFromEndOfFileBackward(int numberOfLines);
    qint64 readCompleteFile();
    qint64 readFromPrevFileSizeTillEnd(qint64 prevFileSize);

private:
    QString _filePath;
};

#endif // FILEREADOPERATIONS_H
