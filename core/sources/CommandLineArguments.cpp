#include "CommandLineArguments.h"
#include <QDebug>

CommandLineArguments::CommandLineArguments(QCoreApplication &app) :
    _app(app),
    _settingsFile() {
}

bool CommandLineArguments::parseArguments() {
    QCoreApplication::setApplicationName("Raider");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineOption argHighlight (
        QStringList() << "hl" << "highlight",
        "First sign e.g. @ defines the delimiter. Requires 5 delimiters to be a valid expression. Example: @color@pre@regex@post@",
        "arguments",
        ""
    );

    QCommandLineOption argColors (
        QStringList() << "cl" << "colors",
        "Printing a list of available colors.",
        "",
        ""
    );

    QList<QCommandLineOption> options;
    options.append(argHighlight);
    options.append(argColors);

    QCommandLineParser parser;
    parser.setApplicationDescription("File colorization and transmitting.");
    parser.addPositionalArgument("settings", "Requires path to settings file.");
    parser.addHelpOption();
    parser.addVersionOption();
    bool ok = parser.addOptions(options);
    if (!ok) {
        qWarning() << "Error within command line option definition.";
        return false;
    }
    parser.process(_app);

    _helpText = parser.helpText();
    _highlight = parser.value(argHighlight);
    _printColors = parser.isSet(argColors);

    QStringList positionalArguments = parser.positionalArguments();
    if ( positionalArguments.length() == 1 ) {
        _settingsFile.setFileName(positionalArguments.at(0));
        return true;
    }
    return false;
}

QString CommandLineArguments::getHelpText() {
    return _helpText;
}

QFile &CommandLineArguments::getSettingsFile() {
    return _settingsFile;
}

QPair<Colors::Color, StringColourizeSettings> CommandLineArguments::getHighlight() {
    _highlight = _highlight.replace("\\t", "\t");

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    if (_highlight.length() > 1) {
        QChar ch = _highlight.at(0);
        QStringList list = _highlight.split(ch, QString::KeepEmptyParts, Qt::CaseSensitive);
        if (list.length() == 6) {
            // list.at(0) symbol before first @
            newHighlight.first = Colors::fromString(list.at(1));
            StringColourizeSettings colourizeSettings;
            colourizeSettings._preDelimiter = list.at(2);
            colourizeSettings._regex = list.at(3);
            colourizeSettings._postDelimiter = list.at(4);
            // list.at(5) symbol before first @
            newHighlight.second = colourizeSettings;
        }
    }
    return newHighlight;
}

bool CommandLineArguments::getPrintColors() {
    return _printColors;
}
