#include <iostream>
#include "../include/RC4.hpp"

RC4::RC4(std::vector<int> key): key_(key)
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
        j = (j + S_[i] + key_[i % key.size()]) % 256;
        aux = S_[i];
        S_[i] = S_[j];
        S_[j] = aux;
    }
}

RC4::~RC4()
{
    S_.clear();
    key_.clear();
}

int RC4::PRGA()
{
    int aux;
    int i = 0;
    int j = 0;
    i = (i + 1) % 256;
    i = (j + S_[i]) % 256;
    aux = S_[i];
    S_[i] = S_[j];
    S_[j] = aux;
    int t = (S_[i] + S_[j]) % 256;
    return S_[t];
}

void RC4::cifrar(std::string msj)
{
    msj_cif_.resize(msj.size());
    msj_cif_bin_.resize(msj.size());
    std::bitset<8> aux;
    for(long unsigned int i=0; i<msj.length(); i++){
        aux = std::bitset<8>(msj[i]) ^ std::bitset<8>(PRGA());
        msj_cif_[i] = aux.to_ullong();
    }
    for(long unsigned int i=0; i<msj_cif_.size(); i++){
        msj_cif_bin_[i] = std::bitset<8>(msj_cif_[i]);
        std::cout << msj_cif_bin_[i] << std::endl;
    }
}
