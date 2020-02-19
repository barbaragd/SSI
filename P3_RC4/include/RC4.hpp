#pragma once
#include <string>
#include <vector>
#include <bitset>

class RC4
{
private:
    std::vector<int> key_;
    std::vector<int> S_;
    std::string msj_cif_;
    std::vector<std::bitset<8>> msj_cif_bin_;

    int i_;
    int j_;

public:
    RC4();
    ~RC4();
    void set_key(std::vector<int> key);
    void cifrar(std::vector<int> msj);
    void descifrar(std::vector<int> msj);

private:
    int PRGA();
    void KSA();
    void limpiar();
};
