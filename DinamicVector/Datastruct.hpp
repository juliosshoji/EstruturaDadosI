#ifndef DATASTRUCT_HPP_

    #define DATASTRUCT_HPP_

    #define INITIAL_SIZE 16

    #include <cstdlib>
    #include <iostream>
    #include <typeinfo>
    #include <thread>

    using namespace std;

    template<typename T>
    class Datastruct {
        
        private:    
            T* array;
            int capacity;
            int lenght;

            void allocate(){
                this->array = (T*)reallocarray(this->array, this->capacity+(this->capacity/2), sizeof(T));
                if(this->array == NULL){
                    exit(3);
                }
                this->capacity = this->capacity+(this->capacity/2);
            };

            static void quick_sort_recursion(const int low, const int high, T* array){
                
                if(low >= high) return;

                const int pivot = high;
                
                int index_j = low;
                int index_i = low-1;
                int temp = 0;

                while(index_j < high){
                    if(array[pivot] >= array[index_j]){
                        index_i++;
                        temp = array[index_j];
                        array[index_j] = array[index_i];
                        array[index_i] = temp;
                        
                    }
                    index_j++;
                }
                temp = array[index_i+1];
                array[index_i+1] = array[pivot];
                array[pivot] = temp;

                
                quick_sort_recursion(low, index_i, array); //LEFT
                quick_sort_recursion(index_i+2, high, array); //RIGHT
            };

        public:
            Datastruct() : array(nullptr) {
                this->array = (T*)malloc(sizeof(T)*INITIAL_SIZE);
                if(!this->array){
                    exit(2);
                }
                this->capacity = INITIAL_SIZE;
                this->lenght = 0;
            };

            ~Datastruct(){free(this->array);};

            T pop(){
                return this->array[--this->lenght];
            };

            T * get_vector(){
                return this->array;
            };

            void append(T value){
                if(lenght == capacity) this->allocate();

                if(typeid(T) == typeid(*(this->array))){
                    this->lenght++;
                    this->array[this->lenght-1] = value;
                } 
                else exit(1);
            }; 

            void quick_sort(){
                quick_sort_recursion(0, this->lenght-1, this->array);
            };

            void print_vector(){
                cout << "[";
                for(int i = 0; i < this->lenght; i++){
                    cout << this->array[i] << " ";
                }
                cout << "]" << endl;
            };

            void bubble_sort(){
                T temp;
                for (int i = this->lenght; i > 0; i--){
                    for (int j = 0; j < i; j++) {
                        if (this->array[j] > this->array[j+1]) {
                            temp = this->array[j];
                            this->array[j] = this->array[j+1];
                            this->array[j+1] = temp;
                        }
                    }
                }
            };

            void clear(){
                free(this->array);
                this->array = (T*)malloc(sizeof(T)*INITIAL_SIZE);
                if(!this->array){
                    exit(2);
                }
                this->capacity = INITIAL_SIZE;
                this->lenght = 0;
            };
    };

#endif