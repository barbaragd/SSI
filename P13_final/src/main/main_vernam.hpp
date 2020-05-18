#include <cstdio>
#include <iostream>
#include <string>
#include "vernam.hpp"


void cifrar(vernam micifrado, string msj, string mykey){
    std::cout << "> Introducir mensaje para cifrar: ";
    std::cin >> msj;

    std::cout << "Mensaje original en binario: " <<  micifrado.c2binarystring(msj) << std::endl,
    std::cout << "Longitud del mensaje: " <<  micifrado.c2binarystring(msj).length() << std::endl << std::endl;
    
    while(mykey.size() != micifrado.c2binarystring(msj).length()){
        std::cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): ";
        std::cin >> mykey;
    }
    micifrado.set_key(mykey);
    
    micifrado.cifrado(msj);

    std::cout << "Mensaje cifrado (en binario): " << micifrado.get_msj_cifrado_bin() << std::endl;
    std::cout << "[!] Mensaje cifrado: " << micifrado.get_msj_cifrado() << std::endl << std::endl;

}

void descifrar(vernam micifrado, string msj, string mykey){
    std::cout << "> Introducir mensaje para descifrar: ";
    std::cin >> msj;

    std::cout << "Mensaje cifrado en binario: " << micifrado.c2binarystring(msj) << std::endl,
    std::cout << "Longitud del mensaje: " << micifrado.c2binarystring(msj).length() << std::endl << std::endl;

    while(mykey.size() != micifrado.c2binarystring(msj).length()){
        std::cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): "; 
        std::cin >> mykey;
    }
    micifrado.set_key(mykey);
    
    micifrado.descifrado(msj);
    
    std::cout << "Mensaje descifrado (en binario): " << micifrado.get_msj_descifrado_bin() << std::endl;
    std::cout << "[!] Mensaje descifrado: " << micifrado.get_msj_descifrado() << std::endl << std::endl;
}


void mvernam(){

    std::string mykey;
    std::string msj;
    vernam micifrado;

    int opcion = 1;

    while(opcion!=0){
        std::cout << "--------------------------" << std::endl;
        std::cout << "Cifrado de Vernam" << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1.\tCifrar" << std::endl;
        std::cout << "2.\tDescifrar" << std::endl;    
        std::cout << "0.\tSalir" << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "> Introduzca la opción: ";
        std::cin >> opcion;
        std::cout << "--------------------------" << std::endl;

        switch (opcion)
        {
        case 1:
            cifrar(micifrado, msj, mykey);
            micifrado.clean();
            break;
        
        case 2:
            descifrar(micifrado, msj, mykey);
            micifrado.clean();
            break;

        case 0:
            std::cout << "Saliendo..." << std::endl;
            break;
        
        default:
            std::cout << "Operación incorrecta. Inténtelo de nuevo." << std::endl;
        }
    }

}
