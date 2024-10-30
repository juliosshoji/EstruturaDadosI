#ifndef CONTROLLER_HPP_

#define CONTROLLER_HPP_

#include <vector>
#include <string>
#include <memory>
#include "Draw.hpp"
#include "B-Tree.h"
class Controller {
    private:
        vector<node*> trees;
        vector<string> nameTrees;

        node** findTree(string name);

        void CreateTree();
        void InsertNode();
        void RemoveNode();
        void BalanceTree();
        void GenerateRandom();
        void PrintTree();

        void PrintInOrdem(string name);
        void PrintPreOrdem(string name);
        void PrintPostOrdem(string name);

    public:
        Controller();
        ~Controller();
        
        void start();
        bool doAction(string title, vector<string> options, vector<void (Controller:: *)()> actions);
        bool doAction(string title, vector<string> options, vector<void (Controller:: *)(string name)> actions, string name);
        
};

#endif