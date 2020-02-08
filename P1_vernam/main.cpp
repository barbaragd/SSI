#include <cstdio>
#include <iostream>
#include <string>
#include "vernam.hpp"

using namespace std;


int main (void){

    string mykey;
    string msj;
    string aux;
    string msj_cif;
    vernam micifrado;

    cout << "Introducir mensaje para cifrar: ";
    cin >> msj;

    aux = micifrado.convert_binary(msj);
    cout << "Mensaje original en binario: " << aux << endl;
    cout << "Longitud del mensaje: " << aux.length() << endl;
    
    cout << "Introducir key (en binario): "; // misma longitud que el mensaje en binario
    cin >> mykey;
    cout << endl;

    micifrado.set_key(mykey);

    msj_cif = micifrado.cifrado(msj);
    cout << "Mensaje cifrado (en binario): " << msj_cif << endl;
    msj_cif = micifrado.convert_text(msj_cif);
    cout << "Mensaje cifrado: " << msj_cif << endl;

}