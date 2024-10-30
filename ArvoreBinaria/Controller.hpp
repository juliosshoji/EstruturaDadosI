#ifndef CONTROLLER_HPP_

#define CONTROLLER_HPP_

#include <vector>
#include <string>
#include <memory>
#include "Draw.hpp"
#include "B-Tree.h"

class Controller {
    private:
        vector<node*> stacks;
        vector<string> nameStack;

        node** findStack(string name);

    public:
        Controller();
        ~Controller();
        
        void start();
        bool doAction(string title, vector<string> options, vector<void (Controller:: *)()> actions);

        
};

#endif