#include "Controller.hpp"

Controller::Controller(){
    this->start();
};

Controller::~Controller(){
    for(string name : this->nameTrees){
        freeTree((*findTree(name)));
    }
};

void Controller::start(){
    vector<string> options { "Insert", "Remove", "Balance Tree", "Generate Random Numbers", "Print Tree"};
    vector<void (Controller::*)()> actions { &Controller::InsertNode, &Controller::RemoveNode, &Controller::BalanceTree, &Controller::GenerateRandom, &Controller::PrintTree};
    while(this->doAction("Árvore Binária", options, actions));
};

bool Controller::doAction(string title, vector<string> options, vector<void (Controller:: *)()> actions){
    unique_ptr<Draw> Menu(new Draw(options, title, "*"));
    int choice = Menu->getOption();
    if(choice != 0)
        (this->*actions.at(choice-1))();
    else{
        cout << "Exiting!" << endl;
        return false;
    }
    return true;
};

bool Controller::doAction(string title, vector<string> options, vector<void (Controller:: *)(string name)> actions, string name){
    unique_ptr<Draw> Menu(new Draw(options, title, "*"));
    int choice = Menu->getOption();
    if(choice != 0)
        (this->*actions.at(choice-1))(name);
    else{
        cout << "Exiting!" << endl;
        return false;
    }
    return false;
};

void Controller::InsertNode(){
    cout << endl << "What info to insert?" << endl;
    int info;
    cin >> info;
    string name;
    cout << endl << "Where to add?" << endl;
    cin >> name;
    
    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl << "Create new Tree? (y/n) " << endl;
        cin >> name;
        if(name.compare("y") == 0){

            node* newNode;
            inicializeTree(&newNode);

            cout << "What is the Tree's name?" << endl;
            cin >> name;

            this->nameTrees.push_back(name);

            if(insertNode(&newNode, &info, NULL) != 0){
                throw(new exception());
            }

            this->trees.push_back(newNode);
   
        }
    } else {
        if(insertNode(Tree, &info, NULL) != 0){
            throw(new exception());
        }
    }
};

void Controller::RemoveNode(){
    cout << endl << "What info to remove?\n" << endl;
    int info;
    cin >> info;

    string name;
    cout << endl << "Where to remove?" << endl;
    cin >> name;

    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl;
        cout << "Try again!" << endl;
        return;
    }
    if(removeNode(Tree, &info) != 0){
        throw(new exception());
    }
};

void Controller::BalanceTree(){
    cout << "Tree Balanced" << endl;
};

void Controller::GenerateRandom(){
    cout << endl << "How many random info to generate?\n" << endl;
    int info;
    cin >> info;
    string name;
    if(trees.size() != 1){
        cout << endl << "Where to add?" << endl;
        cin >> name;
    } else {
        name = this->nameTrees[0];
    }
    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl;
        cout << "Try again!" << endl;
        return;
    }
    if(generateRandom(Tree, info) != 0){
        throw(new exception());
    }
};

void Controller::PrintTree(){
    vector<string> options {"Print In Ordem", "Print Pre Ordem", "Print Post Ordem"};
    vector<void (Controller::*)(string name)> actions {&Controller::PrintInOrdem, &Controller::PrintPreOrdem, &Controller::PrintPostOrdem};
    cout << endl << "What Tree to print?" << endl;
    string name;
    cin >> name;
    while(this->doAction("Print Menu", options, actions, name));
};


node** Controller::findTree(string name){
    int index = 0;
    for(string stack : this->nameTrees){
        if(stack.compare(name) == 0){
            return &(this->trees.at(index));
            break;
        }
        index++;
    }
    return NULL;
}

void Controller::PrintInOrdem(string name){
    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl;
        cout << "Try again!" << endl;
        return;
    }
    printTreeInOrdem(Tree);
};

void Controller::PrintPreOrdem(string name){
    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl;
        cout << "Try again!" << endl;
        return;
    }
    printTreePreOrdem(Tree);
};

void Controller::PrintPostOrdem(string name){
    node** Tree = findTree(name);
    if(Tree == NULL){
        cout << endl << "No Tree with name: " << name << endl;
        cout << "Try again!" << endl;
        return;
    }
    printTreePostOrdem(Tree);
};