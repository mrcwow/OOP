#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "Commands.h"

class ConsoleController: public Commands{
    public:
        Command get_command(){
            char c;
            cin >> c;
            return Commands_l[c];
        }
};
#endif