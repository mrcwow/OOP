#ifndef LOGGER_CONSOLE_H
#define LOGGER_CONSOLE_H

#include "Logger.h"

class Logger_console: public Logger{
    public:
        Logger_console(string info_begin = "", string info_end = ""): 
            Logger(info_begin, info_end) {}

        void log(string logs) override{
            cout << info_begin << logs << info_end << endl;
        }
};
#endif 