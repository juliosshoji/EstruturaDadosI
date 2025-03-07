#include "Controller.hpp"

Controller::Controller(){
    this->vetor = new Datastruct<int>;
    this->start();
};

Controller::~Controller(){
    delete this->vetor;
};

void Controller::start(){
    vector<string> options {"Generate Random (INTEGER) Values", "Sort", "Append", "Pop", "Print"};
    vector<void (Controller::*)()> actions { &Controller::generate_random, &Controller::sort, &Controller::append, &Controller::pop, &Controller::print};
    while(this->doAction("Pilha", options, actions));
};

bool Controller::doAction(string title, vector<string> options, vector<void (Controller:: *)()> actions){
    unique_ptr<Draw> Menu(new Draw(options, title, "*"));
    int choice = -1;
    while(choice == -1){
        choice = Menu->getOption();
    }
    
    if(choice != 0)
        (this->*actions.at(choice-1))();
    else{
        cout << "Exiting!" << endl;
        return false;
    }
    return true;
};

void Controller::generate_random(){
    cout << "How many random numbers to generate?" << endl;
    int num;
    cin >> num;

    this->generate(num, this->vetor);
};

void Controller::generate(int num, Datastruct<int>* vetor){
    for(int i = 0; i < num; i++)
        vetor->append(MIN + (rand() % (MAX - MIN + 1)));
};

void Controller::append(){
    cout << "Which number to append?" << endl;
    int num;
    cin >> num;
    this->vetor->append(num);
};

void Controller::pop(){
    cout << "Poped out this number: " << this->vetor->pop() << endl;
};

void Controller::print(){
    cout << endl;
    this->vetor->print_vector();
    cout << endl;
};

void Controller::sort(){
    clock_t begin = clock();
    this->vetor->sort();
    clock_t end = clock();

    printf("Time spent sorting: %.10lf seconds\n", (double)(end-begin)/CLOCKS_PER_SEC);
    cout << endl << "Sorted!" << endl;
}