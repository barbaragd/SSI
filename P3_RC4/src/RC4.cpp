#include <iostream>
#include "../include/RC4.hpp"
#include <time.h>

RC4::RC4()
{
}

RC4::~RC4()
{
    S_.clear();
    key_.clear();
}

void RC4::set_key(std::vector<int> key)
{
    key_ = key;
}

void RC4::set_random_key(int size){

    srand(time(NULL));
    std::vector<int> llave;
    std::cout << "[!] Llave aleatoria: ";
    for (int i=0; i<size; i++){
        key_.push_back(rand() % 255);
        llave.push_back(key_[i]);
        std::cout << llave[i] << ",";
    }
    std::cout << std::endl;
}

void RC4::KSA()
{
    S_.resize(256);
    int aux;
    for (int i = 0; i < 256; i++)
    {
        S_[i] = i;
    }
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        j = (j + S_[i] + key_[i % key_.size()]) % 256;
        aux = S_[i];
        S_[i] = S_[j];
        S_[j] = aux;
    }
}

int RC4::PRGA()
{
    int aux;
    i_ = (i_ + 1) % 256;
    j_ = (j_ + S_[i_]) % 256;
    aux = S_[i_];
    S_[i_] = S_[j_];
    S_[j_] = aux;
    int t = (S_[i_] + S_[j_]) % 256;
    return S_[t];
}

void RC4::cifrar(std::vector<int> msj)
{
    S_.clear();
    i_ = 0;
    j_ = 0;
    KSA();
    msj_cif_bin_.resize(msj.size());
    std::bitset<8> aux;
	valor.resize(msj.size());
    for (long unsigned int i = 0; i < msj.size(); i++)
    {
        aux = std::bitset<8>(msj[i]) ^ std::bitset<8>(PRGA());
        msj_cif_bin_[i] = aux;
		valor[i] = aux.to_ulong();
    }
}

void RC4::write()
{
    for (long unsigned int i = 0; i < msj_cif_bin_.size(); i++)
    {
        std::cout << msj_cif_bin_[i] << " [" << valor[i] << "]" << std::endl;
    }
}
