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
    CommandLineArguments(QCoreApplication &app);
    bool parseArguments();
    QString getHelpText();
    QFile &getSettingsFile();
    bool getPrintColors();
    QPair<Colors::Color, StringColourizeSettings> getHighlight();

private:
    QCoreApplication &_app;
    QString _helpText;
    QFile _settingsFile;
    QString _highlight;
    bool _printColors;
};


#endif // COMMANDLINEARGUMENTS_H
