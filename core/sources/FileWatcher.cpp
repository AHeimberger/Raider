#include "FileWatcher.h"
#include <QDebug>
#include <QDir>

FileWatcher::FileWatcher(const QString &filePath, FileReadOperations &fileReadOperations)
    : _watcher(), _fileReadOperations(fileReadOperations), _fileInfo(filePath) {
    QObject::connect(&_watcher, &QFileSystemWatcher::fileChanged,
                     this, &FileWatcher::handleFileChanged);
    QObject::connect(&_watcher, &QFileSystemWatcher::directoryChanged,
                     this, &FileWatcher::handleDirectoryChanged);
}

bool FileWatcher::start(int numberOfLines) {
    if ( _fileInfo.isDir() || _fileInfo.isExecutable() || _fileInfo.isSymLink() ) {
        qDebug() << "Given path is not a file path." << endl;
        return false;
    }

    if ( !_fileInfo.dir().exists() ) {
        qDebug() << "Directory does not exist, operation stops.";
        return false;
    }
    _watcher.addPath(_fileInfo.absolutePath());

    if ( !_fileInfo.exists() ) {
        qDebug() << "File does not exist. Waiting for file creation.";
        return true;
    }
    _watcher.addPath(_fileInfo.absoluteFilePath());

    qDebug() << "File exists. Waiting for file modifications.";
    _prevFileSize = _fileReadOperations.readFromEndOfFileBackward(numberOfLines);
    return true;
}

void FileWatcher::handleFileChanged(const QString &filePath) {
    Q_UNUSED(filePath);

    QFile file(_fileInfo.absoluteFilePath());
    qDebug() << "FileWatcher::handleFileChanged()" << file.exists();
    _prevFileSize = _fileReadOperations.readFromPrevFileSizeTillEnd(_prevFileSize);
}

void FileWatcher::handleDirectoryChanged(const QString &directoryPath) {
    Q_UNUSED(directoryPath);

    QFile file(_fileInfo.absoluteFilePath());
    qDebug() << "FileWatcher::handleDirectoryChanged()" << file.exists();
    if ( !_watcher.files().contains(_fileInfo.absoluteFilePath()) && file.exists() ) {
        _watcher.addPath(_fileInfo.absoluteFilePath());
        _prevFileSize = _fileReadOperations.readCompleteFile();
    }
}
