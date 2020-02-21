#include <iostream>
#include "../include/a5.hpp"

int main()
{
    std::vector<std::bitset<1>> a;
    a.push_back(1); // 1001000100011010001
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);

    std::vector<std::bitset<1>> b; // 0101100111100010011010
    b.push_back(0);
    b.push_back(1);
    b.push_back(0);
    b.push_back(1);
    b.push_back(1);
    b.push_back(0);
    b.push_back(0);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(0);
    b.push_back(0);
    b.push_back(0);
    b.push_back(1);
    b.push_back(0);
    b.push_back(0);
    b.push_back(1);
    b.push_back(1);
    b.push_back(0);
    b.push_back(1);
    b.push_back(0);

    std::vector<std::bitset<1>> c; // 10111100110111100001111
    c.push_back(1);
    c.push_back(0);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    c.push_back(1);
    c.push_back(1);
    c.push_back(0);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);

    a5 micifrado(a, b, c);
    std::bitset<1> z;
    z = micifrado.cifrar();
    // std::cout << z << std::endl;
}