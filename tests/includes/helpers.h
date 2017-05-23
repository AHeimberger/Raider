#ifndef HELPER_H
#define HELPER_H

#include <QString>

QString getFileContent(const QString &filePath);

void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // HELPER_H
