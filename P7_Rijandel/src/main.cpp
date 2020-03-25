#include <iostream>
#include "../include/rijndael.hpp"
#include <sstream>

int main()
{
	std::vector<std::vector<int>> key;
	key.resize(4);
	key[0] = {0x00, 0x01, 0x02, 0x03};
	key[1] = {0x04, 0x05, 0x06, 0x07};
	key[2] = {0x08, 0x09, 0x0a, 0x0b};
	key[3] = {0x0c, 0x0d, 0x0e, 0x0f};

	rijndael micifrado;
	micifrado.expan_key(key);
}