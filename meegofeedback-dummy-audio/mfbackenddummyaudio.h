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

#ifndef MFBACKENDDUMMYAUDIO_H
#define MFBACKENDDUMMYAUDIO_H

#include <mfbackendbase.h>

#include <QDir>
#include <QObject>

class QStringList;

class MfBackendDummyAudio : public MfBackendBase {
    Q_OBJECT
    Q_INTERFACES(MfBackendInterface)

public:
    MfBackendDummyAudio();
    virtual ~MfBackendDummyAudio();

    // Exported methods (defined in MfBackendBase)
    QString name() const;
    bool detectHardware() const;
    bool init(int durationLimit);
    bool loadHandle(const QDir &feedbackDir, void **feedbackHandle);
    void unloadHandle(void **feedbackHandle);
    void play(void *feedbackHandle, playbackVolume volume);
    bool isReady();

    playbackVolume volume;

#ifdef MF_THEME_TESTING
    QStringList playList;
    QList<playbackVolume> volumeList;
#endif
#ifdef MF_RECONNECTION_TESTING
    static int initTrials;
#endif

public slots:
    void deviceStateChanged(const QMap<QString, QString> &newState);
};

#endif
