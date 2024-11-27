#include <iostream>

int main() {
    std::string str("onur cepni");
    
    for(char c : str)
        std::cout << c;
    
    for(const char c : str)
        std::cout << c;

    for(const char& c : str)    //immutable
        std::cout << c;
    
    for(char &c : str)          // mutate
        c = '*';
    
}
