#include <Arduino.h>

#include <plog/Appenders/IAppender.h>

template<class Formatter>
class SerialAppender : public plog::IAppender
{
public:
    void write(const plog::Record &record) PLOG_OVERRIDE
    {
        Serial.print(Formatter::format(record).c_str());
    }
};
