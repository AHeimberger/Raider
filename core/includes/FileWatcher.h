#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileInfo>
#include <QFile>
#include <QFileSystemWatcher>

#include "FileReadOperations.h"

class FileWatcher: public QObject {
	Q_OBJECT

public:
    FileWatcher(const QString &filePath, FileReadOperations &fileReadOperations);
    bool start(int numberOfLines);

protected slots:
    void handleFileChanged(const QString &filePath);
    void handleDirectoryChanged(const QString &directoryPath);

private:
	QFileSystemWatcher _watcher;
    FileReadOperations &_fileReadOperations;
	QFileInfo _fileInfo;
    qint64 _prevFileSize;
};

#endif // FILEWATCHER_H
