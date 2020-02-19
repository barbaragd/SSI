#include <iostream>
#include "../include/RC4.hpp"
#include <math.h> // para pow(base, exponente)

std::vector<int> string2v_int(std::string msj)
{
    msj.push_back(',');
    std::vector<int> mimsj;

    std::vector<int> aux;
    int r = 0;
    int n = 0;
    int exp = 0;
    for (long unsigned int i = 0; i < msj.size(); i++)
    {
        if (msj[i] != ',')
        {
            n = msj[i] - 48;
            aux.push_back(n); // si le resto 49, el 1 sería el 0
        }
        else
        { // hay una coma, entonces es que ha leido el num
            for (int j = aux.size() - 1; j >= 0; j--)
            {
                r += aux[j] * pow(10, exp);
                exp++;
            }
            mimsj.push_back(r);
            r = 0;
            exp = 0;
            aux.clear();
            aux.resize(0);
        }
    }
    return mimsj;
}

int main()
{
    std::vector<int> millave;
    std::vector<int> mimsj;

    std::string msj;
    std::cout << "Intro msj: ";
    std::cin >> msj;
    mimsj = string2v_int(msj);

    std::string key;
    std::cout << "Intro key: ";
    std::cin >> key;
    millave = string2v_int(key);
    
    RC4 micifrado(millave);
    micifrado.cifrar(mimsj);

}
