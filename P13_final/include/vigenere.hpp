#pragma once
#include <string>


class vigenere
{
private:
    std::string key_;
    std::string alfabeto_;
    std::string msj_;
    std::string msj_cifrado_;
    std::string msj_descifrado_;

public:
    vigenere();
    ~vigenere();
    void set_msj(std::string msj);
    void set_key(std::string key);
    std::string set_random_key(int size);
    std::string cifrar();
    std::string descifrar();

};