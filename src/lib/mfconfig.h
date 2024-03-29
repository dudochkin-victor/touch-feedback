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

#ifndef MFCONFIG_H
#define MFCONFIG_H

#include <QtGlobal>

class MfConfig {
public:
    static qint64 feedbackLatencyLimit();
    static int feedbackDurationLimit();

private:
    static void load();

    static qint64 _feedbackLatencyLimit;
    static int _feedbackDurationLimit;
    static bool _loaded;
};

#endif
