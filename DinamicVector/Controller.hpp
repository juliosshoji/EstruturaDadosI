#ifndef CONTROLLER_HPP_

    #define CONTROLLER_HPP_

    #define MAX 2147483647
    #define MIN -2147483648

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
            void sortMenu();
            static void generate(int num, Datastruct<int>* vetor);
            void sortByQuickSort();
            void sortByBubbleSort();
            void clearVetor();
    };

#endif