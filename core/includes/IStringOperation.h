#ifndef ISTRINGOPERATIONS_H
#define ISTRINGOPERATIONS_H

#include <QObject>

class IStringOperation : public QObject {
    Q_OBJECT

public slots:
    virtual void doStringOperation(const QString &content) = 0;
};


#endif // ISTRINGOPERATIONS_H
