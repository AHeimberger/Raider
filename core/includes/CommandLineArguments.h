#ifndef COMMANDLINEARGUMENTS_H
#define COMMANDLINEARGUMENTS_H

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QString>
#include <QPair>
#include <QList>

#include "Colors.h"
#include "StringColourizeSettings.h"

class CommandLineArguments {
public:
    CommandLineArguments();
    bool parseArguments();
    QString getHelpText();
    QFile &getSettingsFile();
    QString getLogDirectory();
    bool getLogToFileEnabled();
    bool getPrintColors();
    QPair<Colors::Color, StringColourizeSettings> getHighlight();

private:
    QString _helpText;
    QString _logDirectory;
    bool _logToFileEnabled;
    QFile _settingsFile;
    QString _highlight;
    bool _printColors;
};


#endif // COMMANDLINEARGUMENTS_H
