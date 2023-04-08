#ifndef COMMANDS_H
#define COMMANDS_H
#include <map>
using namespace std;
#include <iostream>

class Commands{
    public:
        enum Command{
            UP, DOWN, LEFT, RIGHT, SAVE, LOAD
        };
        Command command;
        map<char, Command> Commands_l = {
            {'w', UP}, {'s', DOWN}, {'a', LEFT}, {'d', RIGHT}, {'o', SAVE}, {'l', LOAD}
        };
};
#endif