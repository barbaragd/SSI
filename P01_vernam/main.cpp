#include <cstdio>
#include <iostream>
#include <string>
#include "vernam.hpp"

using namespace std;

void cifrar(vernam micifrado, string msj, string mykey){
    cout << "> Introducir mensaje para cifrar: ";
    cin >> msj;

    cout << "Mensaje original en binario: " <<  micifrado.c2binarystring(msj) << endl,
    cout << "Longitud del mensaje: " <<  micifrado.c2binarystring(msj).length() << endl << endl;
    
    while(mykey.size() != micifrado.c2binarystring(msj).length()){
        cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): ";
        cin >> mykey;
    }
    micifrado.set_key(mykey);
    
    micifrado.cifrado(msj);

    cout << "Mensaje cifrado (en binario): " << micifrado.get_msj_cifrado_bin() << endl;
    cout << "[!] Mensaje cifrado: " << micifrado.get_msj_cifrado() << endl << endl;

}

void descifrar(vernam micifrado, string msj, string mykey){
    cout << "> Introducir mensaje para descifrar: ";
    cin >> msj;

    cout << "Mensaje cifrado en binario: " << micifrado.c2binarystring(msj) << endl,
    cout << "Longitud del mensaje: " << micifrado.c2binarystring(msj).length() << endl << endl;

    while(mykey.size() != micifrado.c2binarystring(msj).length()){
        cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): "; 
        cin >> mykey;
    }
    micifrado.set_key(mykey);
    
    micifrado.descifrado(msj);
    
    cout << "Mensaje descifrado (en binario): " << micifrado.get_msj_descifrado_bin() << endl;
    cout << "[!] Mensaje descifrado: " << micifrado.get_msj_descifrado() << endl << endl;
}


int main (void){

    string mykey;
    string msj;
    vernam micifrado;

    int opcion = 1;

    while(opcion!=0){
        cout << "--------------------------" << endl;
        cout << "Cifrado de Vernam" << endl;
        cout << "--------------------------" << endl;
        cout << "1.\tCifrar" << endl;
        cout << "2.\tDescifrar" << endl;    
        cout << "0.\tSalir" << endl;
        cout << "--------------------------" << endl;
        cout << "> Introduzca la opción: ";
        cin >> opcion;
        cout << "--------------------------" << endl;

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
            cout << "Saliendo..." << endl;
            break;
        
        default:
            cout << "Operación incorrecta. Inténtelo de nuevo." << endl;
        }
    }

}
