#include <cstdio>
#include <iostream>
#include <string>
#include "vernam.hpp"

using namespace std;

void llave(vernam micifrado, string msj, string mykey, int l){
    int opcion;
    cout << "1\tLlave por teclado" << endl;
    cout << "2\tLlave aleatoria" << endl;
    cout << "--------------------" << endl;
    cout << "Introduzca opción: " ;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        while(mykey.size() != micifrado.c2binarystring(msj).length()){
            cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): "; // misma longitud que el mensaje en binario
            cin >> mykey;
        }
        micifrado.set_key(mykey);
        break;
    
    case 2:
    cout << "Hola";
        micifrado.set_random_key(l);
        break;
    
    default:
        break;
    }
}

void cifrar(vernam micifrado, string msj, string mykey){
    int l;
    cout << "> Introducir mensaje para cifrar: ";
    cin >> msj;

    cout << "Mensaje original en binario: " <<  micifrado.c2binarystring(msj) << endl;
    l = micifrado.c2binarystring(msj).length();
    cout << "Longitud del mensaje: " <<  l << endl << endl;
    
    int op;
    cout << "1\tLlave por teclado" << endl;
    cout << "2\tLlave aleatoria" << endl;
    cout << "--------------------" << endl;
    cout << "Introduzca opción: " ;
    cin >> op;
    switch (op){
        case 1:
            while(mykey.size() != micifrado.c2binarystring(msj).length()){
                cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): "; // misma longitud que el mensaje en binario
                cin >> mykey;
            }
            micifrado.set_key(mykey);
            break;
        
        case 2:
            micifrado.set_random_key(l);
            break;
        
        default:
            break;
    }
    
    micifrado.cifrado(msj);

    cout << "Mensaje cifrado (en binario): " << micifrado.get_msj_cifrado_bin() << endl;
    cout << "[!] Mensaje cifrado: " << micifrado.get_msj_cifrado() << endl << endl;

}

void descifrar(vernam micifrado, string msj, string mykey){
    int l;
    cout << "> Introducir mensaje para descifrar: ";
    cin >> msj;

    cout << "Mensaje cifrado en binario: " << micifrado.c2binarystring(msj) << endl;
    l = micifrado.c2binarystring(msj).length();
    cout << "Longitud del mensaje: " << l << endl << endl;

    int op;
    cout << "1\tLlave por teclado" << endl;
    cout << "2\tLlave aleatoria" << endl;
    cout << "--------------------" << endl;
    cout << "Introduzca opción: " ;
    cin >> op;
    switch (op){
        case 1:
            while(mykey.size() != micifrado.c2binarystring(msj).length()){
                cout << "> Introducir key en binario (Debe tener " << micifrado.c2binarystring(msj).length() << " digitos): "; // misma longitud que el mensaje en binario
                cin >> mykey;
            }
            micifrado.set_key(mykey);
            break;
        
        case 2:
            micifrado.set_random_key(l);
            break;
        
        default:
            break;
    }
    
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