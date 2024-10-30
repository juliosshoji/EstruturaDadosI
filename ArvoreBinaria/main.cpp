#include "Controller.hpp"

int main(){
    try
    {
        std::unique_ptr<Controller> controlObj = make_unique<Controller>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
};