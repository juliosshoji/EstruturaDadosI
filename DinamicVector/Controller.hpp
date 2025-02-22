#ifndef CONTROLLER_HPP_

    #define CONTROLLER_HPP_

    #define MAX 99999
    #define MIN -99999

    #include <memory>
    #include "Draw.hpp"
    #include "Datastruct.hpp"
    #include <time.h>

    using namespace std;

    class Controller {
        private:
            Datastruct<int>* vetor;
        public:
            Controller();
            ~Controller();
            
            void start();
            bool doAction(string title, vector<string> options, vector<void (Controller:: *)()> actions);

            void append();
            void pop();
            void print();
            void generate_random();
            void sort();
    };

#endif