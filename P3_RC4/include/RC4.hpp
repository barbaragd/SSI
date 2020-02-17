#pragma once
#include <string>
#include <vector>
#include <bitset>

class RC4
{
private:
    std::vector<int> key_;
    std::vector<int> S_; // creo que sería un vector de bitset de 32 bits
    std::string msj_cif_;
    std::vector<std::bitset<8>> msj_cif_bin_;

public:
    RC4(std::vector<int> key);
    ~RC4();
    void cifrar(std::string msj);
private:
    int PRGA();
};
