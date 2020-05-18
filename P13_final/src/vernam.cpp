#include "vernam.hpp"
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

vernam::vernam()
{
}

vernam::~vernam()
{
}

void vernam::clean(){
    key_.clear(); // Clave
    msj_bin_.clear(); // mensaje original en binario
    msj_cifrado_.clear(); // Mensaje cifrado
    msj_cifrado_bin_.clear(); // Mensaje cifrado en binario
    msj_descifrado_.clear(); // Mensaje descifrado
    msj_descifrado_bin_.clear(); // Mensaje descifrado en binario
}


void vernam::set_key (string new_key){
    bitset<8> k;
    istringstream key (new_key);
    for (long unsigned int i=0; i< new_key.size() / 8; i++){
        key >> k;
        key_.push_back(k);
    }
}


string vernam::cifrado (string msj_original){
    string msj_cifrado_bin;
    msj_bin_ = convert_binary(msj_original);
    vector<bitset<8>> result_sum = msj_bin_;
    result_sum.resize(msj_bin_.size());

    // Suma XOR
    for(long unsigned int i=0; i<msj_bin_.size(); i++){
        result_sum[i] ^=key_[i];
    }

    // Pasar a un String
    for (long unsigned int i=0; i<msj_bin_.size(); i++){
        msj_cifrado_bin += result_sum[i].to_string();
    }

    // Guardar en el atributo del mensaje cifrado en binario
    msj_cifrado_bin_.resize(result_sum.size());
    for(long unsigned int i=0; i<result_sum.size(); i++){
        msj_cifrado_bin_[i] = result_sum[i];
    }

    // Guardar msj cifrado en el atributo mensaje cifrado
    msj_cifrado_ = convert_bin2string(msj_cifrado_bin_);


    return msj_cifrado_bin;
}

string vernam::descifrado (string msj_cifrado){
    string msj_descifrado_bin;

    msj_cifrado_bin_ = convert_binary(msj_cifrado);
    vector<bitset<8>> result_sum = msj_cifrado_bin_;
    result_sum.resize(msj_cifrado_bin_.size());

    // Suma XOR
    for(long unsigned int i=0; i<msj_cifrado.size(); i++){
        result_sum[i] ^=key_[i];
    }

    // Pasar a un String
    for (long unsigned int i=0; i<msj_cifrado.size(); i++){
        msj_descifrado_bin += result_sum[i].to_string();
    }

    // Guardar en el atributo del mensaje cifrado en binario
    msj_descifrado_bin_.resize(result_sum.size());
    for(long unsigned int i=0; i<result_sum.size(); i++){
        msj_descifrado_bin_[i] = result_sum[i];
    }

    // Guardar msj cifrado en el atributo mensaje cifrado
    msj_descifrado_ = convert_bin2string(msj_descifrado_bin_);

    return msj_descifrado_bin;
}

vector<bitset<8>> vernam::convert_binary (string msj){
    int l = msj.length();
    char aux;
    char letra;

    bitset<8> b;
    vector<bitset<8>> msj_binario;

    for(int i=0; i<l; i++){
        aux = msj[i];
        letra = 1;
        for(int j=1; j<=255; j++){
            if(aux == letra){
                // msj_binario = set_binary(msj_binario, j);
                b = bitset<8>(j);
                msj_binario.push_back(b);
                j=256;
            }
            else{
                letra++;
            }
        }
        
    }

    return msj_binario;
}


string vernam::convert_bin2string(vector<bitset<8>> msj){
    string new_msj;
    int l = msj.size();
    bitset<8> aux;
    int caracter = 0;
    int p;

    for(int i=0; i<l; i++){
        aux = msj[i];
        p = 1;
        caracter = 0;
        for(int j=0; j<8; j++){
            caracter += aux[j] * p;
            p = p * 2;
        }
        new_msj += caracter;
    }

    return new_msj;    
}

string vernam::c2binarystring(string msj){
    vector<bitset<8>> msjbin = convert_binary(msj);
    string msjx;
    for(long unsigned int i=0; i<msjbin.size(); i++){
        msjx += msjbin[i].to_string();
    }
    return msjx;
}


string vernam::get_msj_bin(){ // Mensaje original en binario
    string msj;
    for(long unsigned int i=0; i<msj_bin_.size(); i++){
        msj += msj_bin_[i].to_string();
    }
    return msj;
}


string vernam::get_msj_cifrado(){ // Mensaje cifrado
    return msj_cifrado_;
}


string vernam::get_msj_cifrado_bin(){ // Mensaje cifrado en binario
    string msj;
    for(long unsigned int i=0; i<msj_cifrado_bin_.size(); i++){
        msj += msj_cifrado_bin_[i].to_string();
    }
    return msj;
}


string vernam::get_msj_descifrado(){ // Mensaje descifrado
    return msj_descifrado_;
}


string vernam::get_msj_descifrado_bin(){ // Mensaje descifrado en binario
    string msj;
    for(long unsigned int i=0; i<msj_descifrado_bin_.size(); i++){
        msj += msj_descifrado_bin_[i].to_string();
    }
    return msj;
}
