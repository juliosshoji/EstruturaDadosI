#include "Controller.hpp"

Controller::Controller(){
    this->start();
};

Controller::~Controller(){

};

node** Controller::findStack(string name){
    int index = 0;
    for(string stack : this->nameStack){
        if(stack.compare(name) == 0){
            return &(this->stacks.at(index));
            break;
        }
        index++;
    }
    return NULL;
}

void Controller::start(){
    vector<string> options {"Inicializar Pilha", "Reinicializar Pilha", "Inserir Topo", "Remover Topo", "Obter Topo", "Verifica vazio", "Obter maior dado da pilha", "Juntar Pilhas", "Mostrar pilha", "Gerar info aleatórias", "Ordenar pilha"};
    vector<void (Controller::*)()> actions { };
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