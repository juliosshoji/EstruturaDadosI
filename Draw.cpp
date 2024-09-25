#include  "Draw.hpp"

void Draw::defineWidth(){
    size_t biggest = 0;
    size_t index = 0;
    for(string option : this->options){
        if(option.length() > options.at(biggest).length())
            biggest = index;
        index++;
    }
    this->biggestQSize = this->options.at(biggest).length();
};

void Draw::drawLine(){
    for(int i = 0; i < this->biggestQSize*1.5; i++){
        cout << this->pattern;
    }
    cout << endl;
};

Draw::Draw(vector<string> options, string title, string pattern) : options(options), title(title), pattern(pattern){
            defineWidth();
            drawMenu();
};

void Draw::drawMenu(){
    
    int index = 0;
    cout << endl;
    this->drawLine();
    cout << setw((this->biggestQSize*1.5)/2) << this->title << endl;
    this->drawLine();
    cout << this->pattern << " " << index << ") " << setw(4) << "Sair" << setw(((this->biggestQSize*1.5)-8)) << this->pattern << endl;
    for(string option : options){
        index++;
        cout << this->pattern << " " << index << ") " << setw(option.length()) << option << setw(((this->biggestQSize*1.5)-option.length()-4))  << this->pattern << endl;
    }
    this->drawLine();
};
        
int Draw::getOption(){
    int option;
    cout << endl << "Choose an option: ";
    cin >> option;
    if((option >= 0)&&(option <= this->options.size())){
        return option;
    }
    return -1;
};