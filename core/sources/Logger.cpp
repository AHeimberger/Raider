#include "Logger.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>


static QString _logFilePath = "";
static bool _loggingEnabled = false;

void setLogFilePath(const QString &logFilePath)
{
    if (logFilePath.isEmpty())
        return;

    _logFilePath = logFilePath;
    _loggingEnabled = QFileInfo(logFilePath).absoluteDir().exists() && !logFilePath.isEmpty();
    qDebug() << "Logging to file: " << (_loggingEnabled ? "enabled" : "disabled");
}

void saveLogToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    Q_UNUSED(context)

    if ( !_loggingEnabled )
        return;

    QString level;
    switch (type) {
        case QtDebugMsg:
            level = QString("Debug");
            break;

        case QtWarningMsg:
            level = QString("Warning");
            break;

        case QtCriticalMsg:
            level = QString("Critical");
            break;

        case QtFatalMsg:
            level = QString("Fatal");
            break;

        default:
            break;
    }

    const int FileSizeIn_bytes = 102400;
    QFile outFile(_logFilePath);

    if (outFile.size() > FileSizeIn_bytes) {
        outFile.remove();
    }

    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    QString dateTimeNow = QDateTime::currentDateTime().toString(Qt::ISODate);
    ts << QString("%1\t%2\t%3\t%4").arg(dateTimeNow).arg("Raider").arg(level).arg(msg) << endl;
    outFile.close();
}
