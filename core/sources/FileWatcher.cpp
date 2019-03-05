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

void FileWatcher::start(int numberOfLines) {
    if ( _fileInfo.isDir() || _fileInfo.isExecutable() || _fileInfo.isSymLink() ) {
        qDebug() << "Given path is not a file path." << endl;
        return;
    }

    _watcher.addPaths(getParentDirectories());
    printWatchDirectories();

    if ( !_fileInfo.dir().exists() ) {
        qDebug() << "Directory does not exist. Waiting for file creation.";
        return;
    }

    if ( !_fileInfo.exists() ) {
        qDebug() << "File does not exist. Waiting for file creation.";
        return;
    }
    _watcher.addPath(_fileInfo.absoluteFilePath());
    printWatchFiles();

    qDebug() << "File exists. Waiting for file modifications.";
    _prevFileSize = _fileReadOperations.readFromEndOfFileBackward(numberOfLines);
}

void FileWatcher::handleFileChanged(const QString &filePath) {
    Q_UNUSED(filePath);
    qDebug() << "handleFileChanged()";

    QFile file(_fileInfo.absoluteFilePath());
    _prevFileSize = _fileReadOperations.readFromPrevFileSizeTillEnd(_prevFileSize);
}

void FileWatcher::handleDirectoryChanged(const QString &directoryPath) {
    Q_UNUSED(directoryPath);
    qDebug() << "handleDirectoryChanged()";

    _watcher.removePaths(_watcher.directories());
    _watcher.addPaths(getParentDirectories());
    printWatchDirectories();

    _watcher.removePath(_fileInfo.absoluteFilePath());
    if ( _fileInfo.exists() ) {
        _watcher.addPath(_fileInfo.absoluteFilePath());
        printWatchFiles();
        _prevFileSize = _fileReadOperations.readCompleteFile();
    }
}

QStringList FileWatcher::getParentDirectories() {
    QStringList directoriesToSpy;
    QStringList subDirectories = _fileInfo.absolutePath().split(QDir::separator());
    while( !subDirectories.isEmpty() ) {
        QString path = subDirectories.join(QDir::separator());
        subDirectories.removeLast();
        if ( !path.isEmpty() )
            directoriesToSpy.append(path);
    }
    return directoriesToSpy;
}

void FileWatcher::printWatchFiles() {
    if (_watcher.files().isEmpty())
        return;

    qDebug() << "Spying Files: ";
    for (auto file: _watcher.files()) {
        qDebug() << "- " << file;
    }
}

void FileWatcher::printWatchDirectories() {
    if (_watcher.directories().isEmpty())
        return;

    qDebug() << "Spying Directories: ";
    for (auto directory: _watcher.directories()) {
        qDebug() << "- " << directory;
    }
}
