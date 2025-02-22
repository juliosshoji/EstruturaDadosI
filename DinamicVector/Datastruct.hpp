#ifndef DATASTRUCT_HPP_

    #define DATASTRUCT_HPP_

    #define ALLOCATION_PORTION 16

    #include <stdlib.h>
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
                this->array = (T*)reallocarray(this->array, this->capacity*ALLOCATION_PORTION, sizeof(T));
                if(this->array == NULL){
                    exit(3);
                }
                this->capacity = (sizeof(T)*this->capacity)+ALLOCATION_PORTION;
            };

            void quick_sort(int low, int high){
                if(high <= low)
                    return;
                T temp;
                int index_j, index_i = low-1;
                for(index_j = low; index_j < high; index_j++){
                    if(this->array[high] > this->array[index_j]){
                        index_i++;
                        temp = this->array[index_i];
                        this->array[index_i] = this->array[index_j];
                        this->array[index_j] = temp;
                    }
                }
                temp = this->array[high];
                this->array[high] = this->array[index_i+1];
                this->array[index_i+1] = temp;
                quick_sort(low , index_i); //LEFT
                quick_sort(index_i+2, high); //RIGHT
            };

        public:
            Datastruct() : array(nullptr) {
                this->array = (T*)malloc(sizeof(T)*ALLOCATION_PORTION);
                if(!this->array){
                    exit(2);
                }
                this->capacity = ALLOCATION_PORTION;
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
                if(lenght == capacity)
                    this->allocate();
                if(typeid(T) == typeid(*(this->array))){
                    this->lenght++;
                    this->array[this->lenght-1] = value;
                } 
                else
                    exit(1);
            }; 

            void sort(){
                quick_sort(0, this->lenght-1);
            };

            void print_vector(){
                cout << "[";
                for(int i = 0; i < this->lenght; i++){
                    cout << this->array[i] << " ";
                }
                cout << "]" << endl;
            };
    };

#endif