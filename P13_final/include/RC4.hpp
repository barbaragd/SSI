#pragma once
#include <string>
#include <vector>
#include <bitset>

class RC4
{
private:
    std::vector<int> key_;
    std::vector<int> S_;
    std::vector<std::bitset<8>> msj_cif_bin_;
	std::vector<int> valor;
    int i_;
    int j_;

public:
    RC4();
    ~RC4();
    void set_key(std::vector<int> key);
    void set_random_key(int size);
    void cifrar(std::vector<int> msj);
    void write();

private:
    int PRGA();
    void KSA();
};
