#pragma once
#include <string>


class vigenere
{
private:
    std::string key_;
    std::string alfabeto_;
    std::string msj_cifrado_;
    std::string msj_descifrado_;

public:
    vigenere();
    ~vigenere();
    void set_key(std::string key);
    std::string cifrar(std::string msj);
    std::string descifrar(std::string msj);

};