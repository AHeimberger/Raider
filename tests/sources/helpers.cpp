#include "helpers.h"
#include <QFile>
#include <QtMsgHandler>

QString getFileContent(const QString &filePath) {
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    return QString::fromUtf8(file.readAll());
}

void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type)
    Q_UNUSED(context)
    Q_UNUSED(msg)
}


