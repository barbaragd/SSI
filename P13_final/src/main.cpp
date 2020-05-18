#include <iostream>
#include <cstdlib>
#include <string>

#include "main/main_vernam.hpp"
#include "main/main_vigenere.hpp"
#include "main/main_rc4.hpp"
#include "main/main_a5.hpp"
#include "main/main_e0bluetooth.hpp"
#include "main/main_mult-AES-SNOW3G.hpp"
#include "main/main_rijndael.hpp"
#include "main/main_rijndael_mod.hpp"
#include "main/main_dh.hpp"
#include "main/main_fiatshamir.hpp"
#include "main/main_rsa.hpp"
#include "main/main_criptoelip.hpp"

int main()
{
    int opcion = 1;
    while (opcion != 0)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << ">>>>>> Menú principal <<<<<<" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << " 1\t Cifrado de Vernam" << std::endl;
        std::cout << " 2\t Cifrado de Vigenere" << std::endl;
        std::cout << " 3\t RC4" << std::endl;
        std::cout << " 4\t A5/1" << std::endl;
        std::cout << " 5\t Generador E0 de Bluetooth" << std::endl;
        std::cout << " 6\t Multiplicación en SNOW 3G y AES" << std::endl;
        std::cout << " 7\t Rijndael" << std::endl;
        std::cout << " 8\t Modos de cifrado en bloque" << std::endl;
        std::cout << " 9\t Algoritmo de Diffie-Hellman" << std::endl;
        std::cout << "10\t Algoritmo de Fiat-Shamir" << std::endl;
        std::cout << "11\t Cifrado RSA" << std::endl;
        std::cout << "12\t Criptografía ElípticaTarea" << std::endl;
        std::cout << " 0\t Salir" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;
        std::cout << "--------------------------------------------" << std::endl;

        switch (opcion)
        {
        case 1:
            mvernam();
            break;

        case 2:
            mvigenere();
            break;

        case 3:
            mrc4();
            break;

        case 4:
            ma5();
            break;

        case 5:
            me0bluetooth();
            break;

        case 6:
            mmultAESSNOW3G();
            break;

        case 7:
            mrijndael();
            break;

        case 8:
            mmodcifbloque();
            break;

        case 9:
            mdh();
            break;

        case 10:
            mfiatshamir();
            break;

        case 11:
            mrsa();
            break;

        case 12:
            mcurvas();
            break;

        case 0:
            std::cout << "Bye, bye..." << std::endl;

        default:
            break;
        }
    }
}
