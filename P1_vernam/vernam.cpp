#include "vernam.hpp"
#include <string>
#include <vector>
#include <ostream>
#include <iostream>

using namespace std;

vernam::vernam()
{
}

vernam::~vernam()
{
}

void vernam::set_key (string new_key){
    key = new_key;
}


string vernam::cifrado (string msj_original){
    string msj = convert_binary(msj_original);
    cout << "MSJ original: " << msj_original << endl;

    unsigned r=0; // resultados que voy obteniendo
    unsigned valor1, valor2; // valores que voy a sumar
    vector<int> resultado_suma; // vector donde guardo el resultado de la suma

    int i = msj.length() - 1; // tamaño del mensaje
    
    while(i>=0){ // Mientras la pos no llegue a 0
        valor1 = set_int(msj[i]);
        valor2 = set_int(key[i]); 
        // cout << "Valor 1: " << valor1 << "\tValor 2: " << valor2 << endl;
        r = valor1 + valor2; // guardo en r la suma de los valores anteriores mas el caryy

        if(r>=2){ // si el resultado de la suma es mayor que 2
            r = r - 2; // al resultado le quito 2, y ese será mi r
        }
        // cout << "r: " << r << endl;
        resultado_suma.push_back(set_char(r));
        i--;
    }


    string new_msj;
    new_msj.resize(resultado_suma.size());

    msj.clear();
    msj.resize(resultado_suma.size());
    i = 0;
    int j = resultado_suma.size() - 1;
    
    while(j<resultado_suma.size()){
        msj[i] = resultado_suma[j];
        i++;
        j--; 
    }

    new_msj = msj;

    return new_msj;
}

// string vernam::descifrado (string msj_cifrado){

// }

string vernam::convert_binary (string msj){
    int l = msj.length();
    char aux;

    char letra;

    string new_msj;

    for(int i=0; i<l; i++){
        aux = msj[i];
        letra = 1;
        for(int j=1; j<=255; j++){
            if(aux == letra){
                new_msj = set_binary(new_msj, j);
                j=256;
            }
            else{
                letra++;
            }
        }
        
    }

    return new_msj;
}


string vernam::convert_text (string msj){
    int l = msj.length() / 8;
    char aux;
    int tmn = 8;

    char letra = 1;

    string new_msj;
    string c_ascii;
    int size;
    int resultado;


    for(int i=0; i<l; i++){
        tmn = 8 * i;
        c_ascii = msj.substr(tmn,8);

        size = c_ascii.size() - 1;
        int j = 1;
        resultado=0;

        while(size>=0){
            resultado += set_int(c_ascii[size]) * j;        
            size--;
            j = j * 2;
        }
        new_msj += resultado;

    }

    return new_msj;    
}


string vernam::set_binary(string m, int num){
    // string msjaux = m;
    string resultado = m;
    unsigned d = num;
    unsigned resto;
    unsigned cociente = num;
    vector<char> aux;

    while(cociente >= 2){

        cociente = d / 2;
        resto = d%2;
        d = cociente;

        aux.push_back(set_char(resto));
    }
    aux.push_back(set_char(cociente)); 
    aux.push_back(set_char(0)); 

    unsigned i = 0;
    unsigned j = 7; // (7 - 1)
    m.resize(8);
    while(i<8){ // lo introduzco en mi string m con el msj en binario
        m[j] = aux[i];
        i++;
        j--;
    }

    resultado += m;

    return resultado;
}

char vernam::set_char(int entero){
    int c=10;
    char l='A';
    char letra;
    if(entero>=10){
        while(entero!=c){
            c++;
            l++;
        }
        letra = l;
    }

    else {
        letra = entero + '0'; // convertir de int a char                
    }

    return letra;
}

unsigned vernam::set_int(char letra){
    unsigned c=10;
    char l='A';
    unsigned entero;

    while(letra!=l && c<2){
        c++;
        l++;
    }
    if(letra==l){
        return c;
    }
    else{
        entero = letra - '0'; // convertir de int a char   
        return entero;
    }

}