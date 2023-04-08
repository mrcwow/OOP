#ifndef LOGGER_FILE_H
#define LOGGER_FILE_H

#include "Logger.h"
#include <fstream>

class Logger_file: public Logger{
    private:
        ofstream file;
    public:
        Logger_file(string f_name, string info_begin = "", string info_end = ""): Logger(info_begin, info_end) {
            file.open(f_name);
        }

        void log(string logs) override{
            file << info_begin << logs << info_end << endl;
        }

        ~Logger_file() {
            file.close();
        }
};
#endif 