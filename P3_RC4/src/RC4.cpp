#include <iostream>
#include "../include/RC4.hpp"

RC4::RC4()
{
    i_ = 0;
    j_ = 0;
    // S_.resize(256);
}

RC4::~RC4()
{
    S_.clear();
    key_.clear();
}

void RC4::set_key(std::vector<int> key){
    key_ = key;
}

void RC4::KSA()
{
    int aux;
    for (int i = 0; i < 256; i++)
    {
        S_.push_back(i);
        key_[i] = key_[i % key_.size()];
    }
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        j = (j + S_[i] + key_[i]) % 256;
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
    std::cout << "S[" << t << "]: " << S_[t] << std::endl;
    return S_[t];
}

void RC4::cifrar(std::vector<int> msj)
{
    KSA();
    // msj_cif_.resize(msj.size());
    // msj_cif_bin_.resize(msj.size());
    std::bitset<8> aux;
    std::cout << msj_cif_bin_.size();
    for (long unsigned int i = 0; i < msj.size(); i++)
    {
        aux = std::bitset<8>(msj[i]) ^ std::bitset<8>(PRGA());
        std::cout << "msj[" << i << "]: " << msj[i] << std::endl;
        msj_cif_bin_.push_back(aux);
        // std::cout << msj_cif_bin_[i] << std::endl;
    }
    // for (long unsigned int i = 0; i < msj_cif_.size(); i++)
    // {
    //     msj_cif_bin_.push_back(std::bitset<8>(msj_cif_[i]));
    // }

    // limpiar();
}

void RC4::descifrar(std::vector<int> msj)
{
    KSA();
    // msj_cif_.resize(msj.size());
    // msj_cif_bin_.resize(msj.size());
    // std::bitset<8> aux;
    // for (long unsigned int i = 0; i < msj.size(); i++)
    // {
    //     aux = std::bitset<8>(msj[i]) ^ std::bitset<8>(PRGA());
    //     std::cout << "msj[" << i << "]: " << msj[i] << std::endl;
    //     msj_cif_[i] = aux.to_ullong();
    // }
    // for (long unsigned int i = 0; i < msj_cif_.size(); i++)
    // {
    //     msj_cif_bin_[i] = std::bitset<8>(msj_cif_[i]);
    //     std::cout << msj_cif_bin_[i] << std::endl;
    // }

    // std::cout << "HOLI";

    // limpiar();
}

void RC4::limpiar()
{
    i_ = 0;
    j_ = 0;
    KSA();
}