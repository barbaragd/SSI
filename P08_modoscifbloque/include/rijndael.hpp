#pragma once
#include <vector>
#include <bitset>
#include <iostream>
#include <sstream>

class rijndael
{
private:
    std::vector<std::vector<int>> Rc;
    std::vector<int> Sbox; 

    std::vector<std::vector<int>> expkey_; // clave expandida
    std::vector<std::vector<int>> key_;    // clave sin expandir

    std::vector<std::vector<int>> entrada_;

    std::vector<std::vector<int>> est_inter;

public:
    rijndael();
    ~rijndael();
    void set_key(std::vector<std::vector<int>> key);
    void set_entrada(std::vector<std::vector<int>> entrada);
    std::vector<int> algoritmo();

private:
    void set_Rcon();
    void set_Scon();

    void expan_key();
    void AddRoundKey1();
    
    void AddRoundKey(int iter);
    void SubBytes();
    void ShiftRows();
    void MixColumn();
};
