#include "Controller.hpp"

Controller::Controller(){
    this->start();
};

Controller::~Controller(){
    for(node* stack : this->stacks){
        Reinicialize_stack(&stack);
    }
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
    vector<void (Controller::*)()> actions { &Controller::inicializeStack, &Controller::reinicializeStack, &Controller::insert, &Controller::remove, &Controller::getTopInfo, &Controller::isStackEmpty, &Controller::getStackBiggest, &Controller::mergeStack, &Controller::printStack, &Controller::generateRandomToStack, &Controller::sortStack};
    while(this->doAction("Pilha", options, actions));
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

void Controller::inicializeStack(){
    string name;
    cout << "What is the new stacks name?" << endl;
    cin >> name;
    node* newStack;
    Inicialize_stack(&newStack);
    this->stacks.push_back(newStack);
    this->nameStack.push_back(name);
    cout << "Done!" << endl;
};

void Controller::reinicializeStack(){
    string name;
    cout << "What is the name of the stack? (Type the exact name)" << endl;
    cin >> name;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistent!" << endl;
    }else {
        Reinicialize_stack(stack);
        cout << "Done!" << endl;
    }
    

    
};

void Controller::insert(){
    int info;
    string name;
    cout << "Where do you want to store? (Stack name)" << endl;
    cin >> name;
    cout << "What info do want to store? (int)" << endl;
    cin >> info;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistent!" << endl;
    }else {
        Insert(stack, info);
        cout << "Done!" << endl;
    }
};

void Controller::remove(){
    string name;
    cout << "Where do you want to remove? (stack name)" << endl;
    cin >> name;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistent!" << endl;
    } else {
        Remove(stack);
        cout << "Done!" << endl;
    }
    
    
};

void Controller::isStackEmpty(){
    string name;
    cout << "What stack do you want to verify? (stack name)" << endl;
    cin >> name;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistent!" << endl;
    } else {
        if(isEmpty(stack) == 1){
        cout << name << " is empty!" << endl;
        }
        else {
            cout << name << " is not empty!" << endl;
        }
        cout << "Done!" << endl;
    }
    
};

void Controller::getStackBiggest(){
    string name;
    cout << "Where do you want to find the biggest? (stack name)" << endl;
    cin >> name;

    int biggest;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistent!" << endl;
    }
    else {
         getBiggest(this->findStack(name), &biggest);

        cout << "This stack biggest info is " << biggest << endl;
        cout << "Done!" << endl;
    } 
};

void Controller::mergeStack(){
    string name1, name2;
    cout << "What stack you want to merge to? (stack name)" << endl;
    cin >> name1;
    cout << "What stack you want to merge to " << name1 << "?" << endl;
    cin >> name2;
    node** stack2 = this->findStack(name2);
    node** stack1 = this->findStack(name1);
    if(stack1 == NULL || stack2 == NULL){
        cout << "Stack Inexistent!" << endl;
    }
    else {
        Merge(stack1, stack2);
        cout << "Done!" << endl;
    };
}
    

void Controller::printStack(){
    string name;
    cout << "Which stack do you want to print? (stack name)" << endl;
    cin >> name;
     
    cout << endl;
    int info;
    int index = 0;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistente!" << endl;
    }
    else {
        while(getInfo(stack, &info, index) != 1){
        cout << index+1 << ") " << info << endl;
            index++;
        }
        cout << endl << "Done!" << endl;
    };
}
    

void Controller::generateRandomToStack(){
    string name;
    cout << "Where do you want to add random numbers? (stack name)" << endl;
    cin >> name;
    int qtd;
    cout << "How many info to add to stack?" << endl;
    cin >> qtd;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistente!" << endl;
    }
    else {
        generateRandom(stack, qtd);
        cout << "Done!" << endl;
    }
};

void Controller::getTopInfo(){
    string name;
    cout << "What stacks top info do you want? (stack name)" << endl;
    cin >> name;
    int info;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistente!" << endl;
    }
    else {
        getTop(stack, &info);
        cout << info << endl;
    }
}

void Controller::sortStack(){
    string name;
    cout << "What stack do you want to order? (stack name)" << endl;
    cin >> name;
    node** stack = this->findStack(name);
    if(stack == NULL){
        cout << "Stack Inexistente!\n" << endl;
    }
    else {
        bubbleSort(stack);
        cout << "Done sorting" << endl;
        this->printStack();
    }
}