/* This file is part of meegofeedbackd
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#include "mfdevicestatelistener.h"

#include <stdio.h>

#include <QThread>
#include <QDebug>

MfDeviceStateListener::MfDeviceStateListener(QObject* parent)
    : QObject(parent), isDisplayActive(true), sessionStateProperty(NULL)
{
    qRegisterMetaType< QMap<QString,QString> >("QMap<QString,QString>");
}

MfDeviceStateListener::~MfDeviceStateListener()
{
    if (sessionStateProperty != NULL) {
        delete sessionStateProperty;
        sessionStateProperty = NULL;
    }
}

QMap<QString, QString> MfDeviceStateListener::deviceState()
{
    // Collect all device state data and emit it
    QMap<QString, QString> emittedStatus;
    QString sessionState = sessionStateProperty->value().toString();

    if (sessionState == "blanked") {
        isDisplayActive = false;
    } else {
        isDisplayActive = true;
    }

    if (isDisplayActive == true) {
        emittedStatus["display"] = "on";
    } else {
        emittedStatus["display"] = "off";
    }

    return emittedStatus;
}

void MfDeviceStateListener::init()
{
    sessionStateProperty = new ContextProperty("Session.State");

    connect(sessionStateProperty, SIGNAL(valueChanged()),
            SLOT(sessionStateChanged()));
}

void MfDeviceStateListener::sessionStateChanged()
{
    emit deviceStateChanged(deviceState());
}
