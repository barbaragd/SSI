#include <iostream>
#include <cstdlib>
#include "../include/vigenere.hpp"
#include <string>
#include <vector>

/***
 * Función para limpiar los espacios del mensaje introducido
 * por teclado.
 ***/
std::string limpiar_espacios(char *msj, int size)
{
    std::vector<char> aux; // vector de char auxiliar
    int i = 0;
    int newsize = 0; // el nuevo tamaño del mensaje
    int c;
    while (i < size) // recorrer todo el msj
    {
        if (msj[i] == ' ')
        {
            i++; // si es un espacio no hacemos nada
        }
        else
        {   
            aux.push_back(msj[i]); // si no es un espacio, introducimos este caracter en el vector auxiliar
            c = msj[i]; // cojo el numero de la tabla ascii de ese caracter
            if (c >= 65 && c <= 90) // compruebo que este dentro del rango del alfabeto (de 65 a 90)
            {
                newsize++; // aumento el valor del tamaño del nuevo mensaje
            }
            i++;
        }
    }

    std::string mensaje;
    mensaje.resize(newsize);
    long unsigned int j = 0;
    while (j < mensaje.size()) // copio todo el mensaje en el string
    {
        mensaje[j] = aux[j];
        j++;
    }

    return mensaje;
}


void main()
{

    int opcion = 1;
    char msj[500];

    std::string llave;
    std::string msj_res;
    std::string mensaje;

    while (opcion != 0)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << ">> Cifrado de Vigenere <<" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "1\tCifrar" << std::endl;
        std::cout << "2\tDescifrar" << std::endl;
        std::cout << "0\tSalir" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Introduzca la opción: ";
        std::cin >> opcion;
        std::cout << "-------------------------" << std::endl;

        vigenere micifrado;

        switch (opcion)
        {
        case 1:
            std::cout << "> Introduzca el mensaje: ";
            std::cin.ignore();
            std::cin.getline(msj, 30);
            mensaje = limpiar_espacios(msj, 30);
            std::cout << "> Introduzca la clave: ";
            std::cin >> llave;

            micifrado.set_key(llave);
            msj_res = micifrado.cifrar(mensaje);
            std::cout << "-------------------------" << std::endl;
            std::cout << "[!] Mensaje cifrado: " << msj_res << std::endl;
            break;

        case 2:
            std::cout << "> Introduzca el mensaje: ";
            std::cin.ignore();
            std::cin.getline(msj, 30);
            mensaje = limpiar_espacios(msj, 30);
            std::cout << "> Introduzca la clave: ";
            std::cin >> llave;

            micifrado.set_key(llave);
            msj_res = micifrado.descifrar(msj);
            std::cout << "-------------------------" << std::endl;
            std::cout << "[!] Mensaje descifrado: " << msj_res << std::endl;
            break;

        case 0:
            std::cout << "\tSaliendo..." << std::endl;
            std::cout << "-------------------------" << std::endl;
            break;

        default:
            std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
        }
    }
}