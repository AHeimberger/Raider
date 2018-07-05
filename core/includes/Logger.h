#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QMessageLogContext>

void setLogFilePath(const QString &logFilePath);
void saveLogToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // LOGGER_H
