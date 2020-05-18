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



void mrc4()
{
    int opcion = 1;
    std::vector<int> millave;
    std::vector<int> mimsj;
    std::string msj;
    std::string key;
    int op = 1;
    int size = 0;

    while (opcion != 0)
    {
				std::cout << "--------------------------------------------" << std::endl;
				std::cout << "--------------------------------------------" << std::endl;
        std::cout << ">>> Cifrado en flujo RC4 <<<" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "1\tCifrar" << std::endl;
        std::cout << "2\tDescifrar" << std::endl;
        std::cout << "0\tSalir" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << " > Introduzca la opción: ";
        std::cin >> opcion;
        std::cout << "--------------------------------------------" << std::endl;

        RC4 micifrado;

        switch (opcion)
        {
        case 1:
            std::cout << " > Introduzca el mensaje: ";
            std::cin >> msj;
            mimsj = string2v_int(msj);
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << " >> Establecer llave << " << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << "1\tIntroducir llave por teclado" << std::endl;
            std::cout << "2\tEstablecer la llave aleatoria" << std::endl;
            std::cout << "*\tEstablecer la llave por defecto" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << " > Introduzca la opción: ";
            std::cin >> op;
            std::cout << "--------------------------------------------" << std::endl;

            switch (op)
            {
            case 1:
                std::cout << " > Introduzca la llave: ";
                std::cin >> key;
                millave = string2v_int(key);
                micifrado.set_key(millave);
                break;

            case 2:
                std::cout << " > Introduzca tamaño de la llave: ";
                std::cin >> size;
                micifrado.set_random_key(size);
                break;

            default:
                std::cout << " > Se introducirá la llave por defecto: 2,5" << std::endl;
                millave = string2v_int("2,5");
                micifrado.set_key(millave);
                break;
            }

            std::cout << "--------------------------------------------" << std::endl;
            micifrado.cifrar(mimsj);
            micifrado.write();
            break;

        case 2:
            std::cout << " > Introduzca el mensaje: ";
            std::cin >> msj;
            mimsj = string2v_int(msj);
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << " > Introduzca la llave: ";
            std::cin >> key;
            millave = string2v_int(key);
            std::cout << "--------------------------------------------" << std::endl;
            micifrado.set_key(millave);
            micifrado.cifrar(mimsj);
            micifrado.write();
            break;

        case 0:
            std::cout << "\tSaliendo..." << std::endl;
						std::cout << "--------------------------------------------" << std::endl;
						std::cout << "--------------------------------------------" << std::endl;
            break;

        default:
            std::cout << "\tOpción incorrecta." << std::endl;
            break;
        }
    }
}
