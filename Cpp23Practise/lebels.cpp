#include <iostream>
void f(int& x) {
    if (x)
        goto MyLebel;
    x = 42; 
    std::cout << "value of x: " << x << std::endl; //skipped

MyLebel:
    std::cout << "at the end, value of x: " << x << std::endl;
}

int main () {
    int v = 4;
    f(v);
}