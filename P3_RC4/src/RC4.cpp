#include <iostream>
#include "../include/RC4.hpp"

RC4::RC4(std::vector<int> key): key_(key)
{
    i_ = 0;
    j_ = 0;
    KSA();
}

RC4::~RC4()
{
    S_.clear();
    key_.clear();
}

void RC4::KSA(){
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
    msj_cif_bin_.resize(msj.size());
    std::bitset<8> aux;
    for(long unsigned int i=0; i<msj.size(); i++){
        aux = std::bitset<8>(msj[i]) ^ std::bitset<8>(PRGA());
        msj_cif_bin_[i] = aux;
        std::cout << msj_cif_bin_[i] << std::endl;
    }
    reset();
}


void RC4::reset(){
    S_.clear();
    i_=0;
    j_=0;
    KSA();   
}
