/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c QTestableDBusAdaptor -a QTestableDBusAdaptor.h:QTestableDBusAdaptor.cpp org.qTestable.xml
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "QTestableDBusAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class QTestableDBusAdaptor
 */

QTestableDBusAdaptor::QTestableDBusAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

QTestableDBusAdaptor::~QTestableDBusAdaptor()
{
    // destructor
}

QString QTestableDBusAdaptor::Automate(const QString &request)
{
    // handle method call org.qTestable.Automate
    QString response;
    QMetaObject::invokeMethod(parent(), "Automate", Q_RETURN_ARG(QString, response), Q_ARG(QString, request));
    return response;
}

