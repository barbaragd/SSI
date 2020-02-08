#pragma once
#include <string>

using namespace std;

class vernam{

private:
    string key;

public:
    vernam();
    ~vernam();
    void set_key (string new_key);
    string cifrado (string msj_original);
    // string descifrado (string msj_cifrado);
    string convert_binary (string msj);
    string convert_text (string msj);

private:
    string set_binary(string m, int num);
    char set_char(int entero);
    unsigned set_int(char letra);
};