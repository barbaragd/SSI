#include <iostream>
#include "../include/rijndael.hpp"
#include <sstream>

int main()
{
	std::vector<std::vector<int>> key;
	// std::vector<std::vector<int>> bloque1;
	// bloque1.resize(4);
	// std::vector<std::vector<int>> bloque2;
	// bloque2.resize(4);
	std::vector<std::vector<std::vector<int>>> bloques;
	int b;

	std::vector<std::vector<int>> iv;
	iv.resize(4);
	iv[0] = {0x00, 0x00, 0x00, 0x00};
	iv[1] = {0x00, 0x00, 0x00, 0x00};
	iv[2] = {0x00, 0x00, 0x00, 0x00};
	iv[3] = {0x00, 0x00, 0x00, 0x00};

	std::vector<std::vector<int>> salida;
	int op = 0;
	rijndael aes;
	std::string aux;

	do
	{
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "\tCBC" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "\t1\tIntroducir valores" << std::endl;
		std::cout << "\t2\tValores por defecto" << std::endl;
		std::cout << "\t3\tCipher Stealing" << std::endl;
		std::cout << "\t0\tSalir" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "> Opción: ";
		std::cin >> op;
		std::cout << "------------------------------------------------" << std::endl;

		switch (op)
		{
		case 1:
		case 3:
			std::cout << "> Clave (16 bytes): " << std::endl;
			key.resize(4);
			for (int i = 0; i < 4; i++)
			{
				key[i].resize(4);
			}
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
			std::cout << "> Número de bloques: ";
			std::cin >> b;
			bloques.resize(b);
			for (long unsigned int k = 0; k < bloques.size(); k++)
			{
				bloques[k].resize(4);
				for (int i = 0; i < 4; i++)
				{
					bloques[k][i].resize(4);
				}

				std::cout << "[!] Bloque " << k + 1 << ": " << std::endl;
				for (int j = 0; j < 4; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						std::cout << "[" << i << "][" << j << "] > ";
						std::cin >> aux;
						std::istringstream(aux) >> std::hex >> bloques[k][i][j];
					}
				}
			}

			std::cout << "------------------------------------------------" << std::endl;
			aes.set_key(key);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					bloques[0][i][j] = bloques[0][i][j] ^ iv[i][j]; // primer bloque
				}
			}
			aes.set_entrada(bloques[0]);
			salida = aes.algoritmo();

			if (bloques[bloques.size() - 1].size() < 16)
			{															   // si el último bloque no es múltiplo
				for (long unsigned int i = 1; i < bloques.size() - 2; i++) // hacemos el mismo procedimiento hasta llegar a los dos últimos bloques
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							bloques[i][j][k] = bloques[i][j][k] ^ salida[j][k];
						}
					}
					aes.set_entrada(bloques[i]);
					salida = aes.algoritmo();
				}

				std::vector<std::vector<int>> intermedio;

				int penultimo = bloques.size() - 2;
				int ultimo = bloques.size() - 1;
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						bloques[penultimo][j][k] = bloques[penultimo][j][k] ^ salida[j][k];
					}
				}
				aes.set_entrada(bloques[penultimo]);
				salida = aes.algoritmo();

				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						bloques[ultimo][j][k] = bloques[penultimo][j][k] ^ salida[j][k];
					}
				}


			}
			else
			{ // si sí es, hacemos lo normal :
				for (long unsigned int i = 1; i < bloques.size(); i++)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							bloques[i][j][k] = bloques[i][j][k] ^ salida[j][k];
						}
					}
					aes.set_entrada(bloques[i]);
					salida = aes.algoritmo();
				}
			}

			break;

		case 2:
			// Datos del pdf:
			key.resize(4);
			key[0] = {0x00, 0x04, 0x08, 0x0c};
			key[1] = {0x01, 0x05, 0x09, 0x0d};
			key[2] = {0x02, 0x06, 0x0a, 0x0e};
			key[3] = {0x03, 0x07, 0x0b, 0x0f};

			bloques.resize(2);

			bloques[0].resize(4);
			bloques[0][0] = {0x00, 0x44, 0x88, 0xcc};
			bloques[0][1] = {0x11, 0x55, 0x99, 0xdd};
			bloques[0][2] = {0x22, 0x66, 0xaa, 0xee};
			bloques[0][3] = {0x33, 0x77, 0xbb, 0xff};

			bloques[1].resize(4);
			bloques[1][0] = {0x00, 0x00, 0x00, 0x00};
			bloques[1][1] = {0x00, 0x00, 0x00, 0x00};
			bloques[1][2] = {0x00, 0x00, 0x00, 0x00};
			bloques[1][3] = {0x00, 0x00, 0x00, 0x00};

			aes.set_key(key);

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					bloques[0][i][j] = bloques[0][i][j] ^ iv[i][j]; // primer bloque
				}
			}
			aes.set_entrada(bloques[0]);
			salida = aes.algoritmo();

			for (long unsigned int i = 1; i < bloques.size(); i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						bloques[i][j][k] = bloques[i][j][k] ^ salida[j][k];
					}
				}
				aes.set_entrada(bloques[i]);
				salida = aes.algoritmo();
			}

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