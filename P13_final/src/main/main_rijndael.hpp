#include <iostream>
#include "../include/rijndael.hpp"
#include <sstream>

void mrijndael()
{
	std::vector<std::vector<int>> key;
	key.resize(4);
	std::vector<std::vector<int>> entrada;
	entrada.resize(4);

	int op = 0;
	rijndael micifrado;
	std::string aux;

	do
	{
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "\tAlgoritmo Rijndael" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "\t1\tIntroducir valores" << std::endl;
		std::cout << "\t2\tValores por defecto" << std::endl;
		std::cout << "\t0\tSalir" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "> Opción: ";
		std::cin >> op;
		std::cout << "------------------------------------------------" << std::endl;

		switch (op)
		{
		case 1:
			std::cout << "> Clave (16 bytes): " << std::endl;
			for (int j = 0; j < 4; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					std::cout << "[" << i << "][" << j << "] = ";
					std::cin >> aux;
					std::istringstream(aux) >> std::hex >> key[i][j];
				}
			}

			std::cout << "------------------------" << std::endl;
			std::cout << "> Entrada (16 bytes): " << std::endl;
			for (int j = 0; j < 4; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					std::cout << "[" << i << "][" << j << "] = ";
					std::cin >> aux;
					std::istringstream(aux) >> std::hex >> entrada[i][j];
				}
			}
			std::cout << "------------------------------------------------" << std::endl;
			micifrado.set_key(key);
			micifrado.set_entrada(entrada);
			micifrado.algoritmo();

			break;

		case 2:
			// Datos del pdf:
			key[0] = {0x00, 0x04, 0x08, 0x0c};
			key[1] = {0x01, 0x05, 0x09, 0x0d};
			key[2] = {0x02, 0x06, 0x0a, 0x0e};
			key[3] = {0x03, 0x07, 0x0b, 0x0f};
			entrada[0] = {0x00, 0x44, 0x88, 0xcc};
			entrada[1] = {0x11, 0x55, 0x99, 0xdd};
			entrada[2] = {0x22, 0x66, 0xaa, 0xee};
			entrada[3] = {0x33, 0x77, 0xbb, 0xff};
			// Datos del vídeo:
			// key[0] = {0x2b, 0x28, 0xab, 0x09};
			// key[1] = {0x7e, 0xae, 0xf7, 0xcf};
			// key[2] = {0x15, 0xd2, 0x15, 0x4f};
			// key[3] = {0x16, 0xa6, 0x88, 0x3c};
			// entrada[0] = {0x32, 0x88, 0x31, 0xe0};
			// entrada[1] = {0x43, 0x5a, 0x31, 0x37};
			// entrada[2] = {0xf6, 0x30, 0x98, 0x07};
			// entrada[3] = {0xa8, 0x8d, 0xa2, 0x34};
			micifrado.set_key(key);
			micifrado.set_entrada(entrada);
			micifrado.algoritmo();
			break;

		case 0:
			std::cout << "Saliendo..." << std::endl;
			break;

		default:
			std::cout << "[!] Opción no válida" << std::endl;
			break;
		}
	} while (op != 0);
}