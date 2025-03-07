#include "Controller.hpp"

int main(){
    try {
        srand(time(NULL));
        unique_ptr<Controller> controlObj = make_unique<Controller>();
    } catch (exception* e){
        cout << e->what() << endl;
    }
    return 0;
}
