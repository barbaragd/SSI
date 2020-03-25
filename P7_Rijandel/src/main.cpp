#include <iostream>
#include "../include/rijndael.hpp"
#include <sstream>

int main()
{
	std::vector<std::vector<int>> key;
	key.resize(4);
	key[0].resize(4);
	key[0] = {0x00, 0x01, 0x02, 0x03};
	key[1].resize(4);
	key[1] = {0x04, 0x05, 0x06, 0x07};
	key[2].resize(4);
	key[2] = {0x08, 0x09, 0x0a, 0x0b};
	key[3].resize(4);
	key[3] = {0x0c, 0x0d, 0x0e, 0x0f};

	std::vector<std::vector<int>> entrada;
	entrada.resize(4);
	entrada[0].resize(4);
	entrada[0] = {0x00, 0x11, 0x22, 0x33};
	entrada[1].resize(4);
	entrada[1] = {0x44, 0x55, 0x66, 0x77};
	entrada[2].resize(4);
	entrada[2] = {0x88, 0x99, 0xaa, 0xbb};
	entrada[3].resize(4);
	entrada[3] = {0xcc, 0xdd, 0xee, 0xff};

	rijndael micifrado;
	micifrado.set_key(key);
	micifrado.set_entrada(entrada);
	micifrado.algoritmo();
}