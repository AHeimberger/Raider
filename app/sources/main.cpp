#include "CommandLineArguments.h"
#include "Logger.h"
#include "Settings.h"
#include "FileReadOperations.h"
#include "FileWatcher.h"
#include "StringColourize.h"
#include "UdpTransmission.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[]) {

    QTextStream stream(stdout);
    QCoreApplication app(argc, argv);

    CommandLineArguments commandLineArguments;
    if ( !commandLineArguments.parseArguments() ) {
        stream << commandLineArguments.getHelpText();
        return -1;
    }

    setLogFilePath(commandLineArguments.getLogFile());
    qInstallMessageHandler(saveLogToFile);

    if ( commandLineArguments.getPrintColors() ) {
        stream << "Available Colors" << endl;
        stream << Colors::getAvailableColors() << endl;
    }

    Settings settings(commandLineArguments.getSettingsFile());
    settings.load();

    QString fileToSpy = settings.getFileToSpy();
    FileReadOperations fileReadOperations(fileToSpy);
    FileWatcher fileWatcher(fileToSpy, fileReadOperations);

    StringColourize stringColourize(stream);
    QFile colourizeSettings(settings.getColourizeSettings());
    stringColourize.readSettings(colourizeSettings);
    stringColourize.addHighlight(commandLineArguments.getHighlight());
    QObject::connect(&fileReadOperations, &FileReadOperations::readString,
                     &stringColourize, &StringColourize::doStringOperation);

    UdpTransmission udpTransmission;
    QFile udpTransmissionSettings(settings.getUdpTransmissionSettings());
    udpTransmission.readSettings(udpTransmissionSettings);
    QObject::connect(&fileReadOperations, &FileReadOperations::readString,
                     &udpTransmission, &UdpTransmission::doStringOperation);

    if ( !fileWatcher.start(5) ) {
        return -1;
    }

    return app.exec();
}
