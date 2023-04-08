#ifndef OBJECT_OF_GAME_H
#define OBJECT_OF_GAME_H

#include <iostream>
#include "Classes_game.h"
#include "Logger/Loggable.h"
#include "Logger/Observable.h"
#include "Logger/Logger_file.h"
#include "Logger/Logger_console.h"

class Object_of_game: public Observable{
    public:
        virtual bool interact(Creature* obj) = 0;
        void add_observer(Logger* Logger){
            loggers_l.push_back(Logger);
        }
        void add_observer_choose(string c, string v){
            if (c == "file"){
                Logger_file* F = new Logger_file("Log" + v + ".log", "P" + v + ": ");
                loggers_l.push_back(F);
            }
            if (c == "console"){
                Logger_console* F = new Logger_console("P" + v + ": ");
                loggers_l.push_back(F);
            }
            if (c == "both"){
                Logger_file* F = new Logger_file("Log" + v + ".log", "P" + v + ": ");
                loggers_l.push_back(F);
                Logger_console* F1 = new Logger_console("P" + v + ": ");
                loggers_l.push_back(F1);
            }
        }
};
#endif 