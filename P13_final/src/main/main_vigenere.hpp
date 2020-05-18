#include <iostream>
#include <cstdlib>
#include "../include/vigenere.hpp"
#include <string>
#include <vector>
#include <algorithm> // para eliminar los espacios

void mvigenere()
{

    int op;
    int opcion = 1;
    std::string msj_res;
    std::string mensaje;
    std::string llave;
    int size = 0;

    while (opcion != 0)
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << " >>>>> Cifrado de Vigenere <<<<<" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "\t1\tCifrar" << std::endl;
        std::cout << "\t2\tDescifrar" << std::endl;
        std::cout << "\t0\tSalir" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "> Introduzca la opción: ";
        std::cin >> opcion;
        std::cout << "---------------------------------------" << std::endl;

        vigenere micifrado;

        switch (opcion) // para establecer o no una clave aleatoria
        {
        case 1:
            std::cout << "> Introduzca el mensaje: ";
            std::cin.ignore();
            std::getline(std::cin, mensaje);
            mensaje.erase(std::remove(mensaje.begin(), mensaje.end(), ' '), mensaje.end());
            mensaje.erase(std::remove(mensaje.begin(), mensaje.end(), ','), mensaje.end());
            mensaje.erase(std::remove(mensaje.begin(), mensaje.end(), '.'), mensaje.end());
            micifrado.set_msj(mensaje);

            std::cout << "---------------------------------------" << std::endl;
            std::cout << "    >>> ¿Clave aleatoria? <<<" << std::endl;
            std::cout << "1\tIntroducir clave por teclado" << std::endl;
            std::cout << "2\tEstablecer una clave aleatoria" << std::endl;
            std::cout << "*\tEstablecer clave por defecto" << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "> Introduzca la opción: ";
            std::cin >> op;
            std::cout << "---------------------------------------" << std::endl;
            switch (op)
            {
            case 1:
                std::cout << "> Introducir clave: ";
                std::cin >> llave;
                micifrado.set_key(llave);
                break;

            case 2:
                std::cout << "> Introducir tamaño de la clave: ";
                std::cin >> size;
                micifrado.set_random_key(size);
                break;

            default:
                std::cout << "Se introducirá la clave por defecto 'MISION' " << std::endl;
                micifrado.set_key("MISION");
                break;
            }

            msj_res = micifrado.cifrar();
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "[!] Mensaje cifrado: " << msj_res << std::endl;
            break;

        case 2:
            std::cout << "> Introduzca el mensaje: ";
            std::cin.ignore();
            std::getline(std::cin, mensaje);
            micifrado.set_msj(mensaje);

            std::cout << "> Introducir clave: ";
            std::cin >> llave;
            micifrado.set_key(llave);

            msj_res = micifrado.descifrar();
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "[!] Mensaje descifrado: " << msj_res << std::endl;
            break;

        case 0:
            std::cout << "\tSaliendo..." << std::endl;
            std::cout << "---------------------------------------" << std::endl;
            break;

        default:
            std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
        }
    }
}