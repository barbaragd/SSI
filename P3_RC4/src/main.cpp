#include <iostream>
#include "../include/RC4.hpp"

int main() {
    std::vector<int> millave;
    millave.push_back(2);
    millave.push_back(5);

    RC4 micifrado(millave);
    micifrado.cifrar("1 34");
}