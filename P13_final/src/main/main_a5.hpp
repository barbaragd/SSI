#include <iostream>
#include "../include/a5.hpp"

void ma5()
{
    int op = 1;
    int l = 0;

    // std::string a = "1001000100011010001";
    // std::string b = "0101100111100010011010";
    // std::string c = "10111100110111100001111";
    std::string a;
    std::string b;
    std::string c;

    a5 micifrado;
    std::bitset<1> z;

    while (op != 0)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\t>>> Generador A5/1 <<<" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "\t1\tIntroducir valores" << std::endl;
        std::cout << "\t2\tPor defecto" << std::endl;
        std::cout << "\t0\tSalir" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "> Opción: ";
        std::cin >> op;
        std::cout << "----------------------------------------" << std::endl;

        switch (op)
        {
        case 1:
            std::cout << "> Introducir semilla del 1er registro: ";
            std::cin >> a;
            std::cout << "> Introducir semilla del 2do registro: ";
            std::cin >> b;
            std::cout << "> Introducir semilla del 3er registro: ";
            std::cin >> c;
            std::cout << "> Introducir longitud: ";
            std::cin >> l;
            std::cout << "----------------------------------------" << std::endl;
            micifrado.intro_semillas(a,b,c);
            for (int i = 0; i < l; i++)
            {
                z = micifrado.generar();
                micifrado.write();
            }
            micifrado.reset();
            break;

        case 2:
            a = "1001000100011010001";
            b = "0101100111100010011010";
            c = "10111100110111100001111";
            std::cout << "> Introducir longitud: ";
            std::cin >> l;
            std::cout << "----------------------------------------" << std::endl;
            micifrado.intro_semillas(a,b,c);
            for (int i = 0; i < l; i++)
            {
                z = micifrado.generar();
                micifrado.write();
            }
            micifrado.reset();
            break;
            break;

        case 0:
            std::cout << "Saliendo..." << std::endl;
            break;

        default:
            break;
        }
    }
}