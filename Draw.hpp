#ifndef DRAW_HPP_

#define DRAW_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Draw {
    private:
        vector<string> options;
        string title;
        string pattern;
        int biggestQSize;
        void defineWidth();
        void drawLine();

    public:
        Draw(vector<string> options, string title, string pattern);
        void drawMenu();
        int getOption();
};

#endif