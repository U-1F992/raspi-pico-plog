// I found the declaration at ~/.platformio/packages/toolchain-gccarmnoneeabi/arm-none-eabi/include/stdio.h:280:2
// with #if __GNU_VISIBLE which defined only #ifdef _GNU_SOURCE at ~/.platformio/packages/toolchain-gccarmnoneeabi/arm-none-eabi/include/sys/features.h:258:0
// Don't know why, but it gives me some warnings, although I can build.
#define _GNU_SOURCE 1

#include <Arduino.h>

#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>

#include "serial_appender.h"

static SerialAppender<plog::TxtFormatter> serial_appender;

void setup()
{
    plog::init(plog::verbose, &serial_appender);
}

void loop()
{
    PLOGV << "verbose";
    PLOGD << "debug";
    PLOGI << "info";
    PLOGW << "warning";
    PLOGE << "error";
    PLOGF << "fatal";
    PLOGN << "none";
    Serial.println("println");
}
