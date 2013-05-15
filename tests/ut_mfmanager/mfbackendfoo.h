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

#ifndef MFBACKENDFOO_H
#define MFBACKENDFOO_H

#include "../../src/lib/mfbackendbase.h"

class MfBackendFoo : public MfBackendBase
{
    Q_OBJECT
    Q_INTERFACES(MfBackendInterface)

public:

    MfBackendFoo();
    MfBackendFoo(bool hw);
    ~MfBackendFoo();

    // Implementation of MfBackendBase methods
    QString name() const;
    bool detectHardware() const;
    bool init(int durationLimit);
    bool loadHandle(const QDir &feedbackDir, void **feedbackHandle);
    void unloadHandle(void **feedbackHandle);
    void play(void *feedbackHandle, playbackVolume volume);
    bool isReady();

    int initCalled;
    int limit;
    bool hardware;
    int deviceStateChangedCalled;

public slots:
    void deviceStateChanged(const QMap<QString, QString> &newState);
};

#endif
