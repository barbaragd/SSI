#pragma once
#include <vector>
#include <bitset>
#include <iostream>
#include <sstream>

class rijndael
{
private:
    std::vector<int> Rc;
    std::vector<int> Sbox; // pos = i * tmño_fila + j

    std::vector<std::vector<int>> expkey_; // clave expandida
    std::vector<std::vector<int>> key_;    // clave sin expandir

    std::vector<std::vector<int>> entrada_;

    std::vector<std::vector<int>> est_inter;

public:
    rijndael();
    ~rijndael();
    void set_key(std::vector<std::vector<int>> key);
    void set_entrada(std::vector<std::vector<int>> entrada);
    void algoritmo();

private:
    void set_Rcon();
    void set_Scon();
    int get_data_Scon(int i, int j);

    void expan_key();
    void AddRoundKey();
    void SubBytes();
    void ShiftRows();
    void MixColumn();
    void AddRoundKey2(int iter);
};
