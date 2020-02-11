#include <iostream>
#include "../include/vigenere.hpp"

// Se considera que el rango de caracteres a imprimir es de 65 a 90 (A a Z, solo mayúsculas)

vigenere::vigenere()
{
    alfabeto_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

vigenere::~vigenere()
{
}

void vigenere::set_key(std::string key)
{
    key_ = key;
}

std::string vigenere::cifrar(std::string msj)
{
    msj_cifrado_.resize(msj.size());
    int tmn = key_.size(); // tamaño de la llave
    int pos_key = 0;
    int pos_msj = 0;
    int pos = 0;
    for (long unsigned int i = 0; i < msj.size(); i++)
    {
        pos_key = key_[i % tmn] - 65;
        pos_msj = msj[i] - 65;
        pos = (pos_key + pos_msj) % alfabeto_.size();
        msj_cifrado_[i] = alfabeto_[pos];
    }
    return msj_cifrado_;
}

std::string vigenere::descifrar(std::string msj)
{
    msj_descifrado_.resize(msj.size());
    int tmn = key_.size(); // tamaño de la llave
    int pos_key = 0;
    int pos_msj = 0;
    int pos = 0;
    for (long unsigned int i = 0; i < msj.size(); i++)
    {
        pos_key = key_[i % tmn] - 65;
        pos_msj = msj[i] - 65;
        if(pos_msj - pos_key >= 0){
            pos = (pos_msj - pos_key) % alfabeto_.size();
        }
        else{
            pos = (pos_msj - pos_key +  alfabeto_.size()) % alfabeto_.size();
        }
        msj_descifrado_[i] = alfabeto_[pos];
    }
    return msj_descifrado_;
}