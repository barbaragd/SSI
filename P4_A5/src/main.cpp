#include <iostream>
#include "../include/a5.hpp"

int main()
{
    int op = 1;
    int l = 0;

    std::string a = "1001000100011010001";
    std::string b = "0101100111100010011010";
    std::string c = "10111100110111100001111";

    a5 micifrado(a, b, c);
    std::bitset<1> z;

    while (op != 0)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\t>>> Cifrado A5/1 <<<" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\t1\tCifrar" << std::endl;
        std::cout << "\t2\tDescifrar" << std::endl;
        std::cout << "\t0\tSalir" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "> Opción: ";
        std::cin >> op;
        std::cout << "----------------------------------------" << std::endl;

        switch (op)
        {
        case 1:
            std::cout << "> Introducir longitud: ";
            std::cin >> l;
            std::cout << "----------------------------------------" << std::endl;
            for (int i = 0; i < l; i++)
            {
                z = micifrado.cifrar();
            }
            std::cout << "[!] ";
            micifrado.write();
            break;

        case 2:
            std::cout << "De momento nada." << std::endl;
            break;

        case 0:
            std::cout << "Saliendo..." << std::endl;
            break;

        default:
            break;
        }
    }
}