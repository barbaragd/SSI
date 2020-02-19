#include <iostream>
#include "../include/RC4.hpp"

int main() {
    std::vector<int> millave;
    std::vector<int> mimsj;
    millave.push_back(2);
    millave.push_back(5);

    mimsj.push_back(1);
    mimsj.push_back(34);

    RC4 micifrado;
    micifrado.set_key(millave);
    micifrado.cifrar(mimsj);

    // std::vector<int> miotromsj;

    // miotromsj.push_back(145);
    // miotromsj.push_back(44);
    // micifrado.descifrar(miotromsj);
}