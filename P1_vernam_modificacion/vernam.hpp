#pragma once
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class vernam{

private:
    vector<bitset<8>> key_; // Clave

    vector<bitset<8>> msj_bin_; // mensaje original en binario

    string msj_cifrado_; // Mensaje cifrado
    vector<bitset<8>> msj_cifrado_bin_; // Mensaje cifrado en binario

    string msj_descifrado_; // Mensaje descifrado
    vector<bitset<8>> msj_descifrado_bin_; // Mensaje descifrado en binario

public:
    vernam();
    ~vernam();

    void clean();

    void set_key (string new_key);
    void set_random_key (int l);
    string cifrado (string msj_original);
    string descifrado (string msj_cifrado);

    string get_msj_bin(); // Mensaje original en binario
    string get_msj_cifrado(); // Mensaje cifrado
    string get_msj_cifrado_bin(); // Mensaje cifrado en binario
    string get_msj_descifrado(); // Mensaje descifrado
    string get_msj_descifrado_bin(); // Mensaje descifrado en binario

    string c2binarystring(string msj);
    

private:
    vector<bitset<8>> convert_binary (string msj);
    string convert_bin2string(vector<bitset<8>> msj);
};