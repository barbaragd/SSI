#include <iostream>
#include "../include/rijndael.hpp"
#include <sstream>

std::vector<std::vector<int>> convert2matrix(std::vector<int> v)
{
	std::vector<std::vector<int>> m;
	m.resize(4);
	for (int i = 0; i < 4; i++)
	{
		m[i].resize(4);
	}
	int iter = 0; // pasar a una matriz
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			m[i][j] = v[iter];
			iter++;
		}
	}
	return m;
}

int main()
{
	std::vector<int> key;
	std::vector<std::vector<int>> m_key;

	std::vector<std::vector<int>> bloques;
	std::vector<std::vector<std::vector<int>>> m_bloques;
	int b;

	std::vector<int> iv;
	iv.resize(16, 0);

	std::vector<int> salida;
	int op = 0;
	rijndael aes;
	std::string teclado;
	int t; // tamaño del último bloque

	std::vector<int> intermedio;
	int penultimo;
	int ultimo;

	do
	{
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "\tCBC" << std::endl;
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

			std::cout << "> ¿Clave? (16 bytes): " << std::endl;
			key.resize(16);
			for (int i = 0; i < 16; i++)
			{
				std::cout << "> ";
				std::cin >> teclado;
				std::istringstream(teclado) >> std::hex >> key[i];
			}

			m_key = convert2matrix(key);
			aes.set_key(m_key);

			std::cout << "------------------------" << std::endl;
			std::cout << "> Número de bloques: ";
			std::cin >> b;
			bloques.resize(b);
			m_bloques.resize(b);

			for (long unsigned int k = 0; k < bloques.size() - 1; k++)
			{
				std::cout << "[!] Bloque " << k + 1 << ": " << std::endl;
				bloques[k].resize(16, 0);
				for (int i = 0; i < 16; i++)
				{
					std::cout << "> ";
					std::cin >> teclado;
					std::istringstream(teclado) >> std::hex >> bloques[k][i];
				}
				m_bloques[k] = convert2matrix(bloques[k]);
			}
			// último bloque, que puede no estar completo
			std::cout << "[!] Último Bloque" << std::endl;
			std::cout << "[!] ¿Bytes? > ";
			std::cin >> t;
			bloques[bloques.size() - 1].resize(16, 0);
			for (int i = 0; i < t; i++)
			{
				std::cout << "> ";
				std::cin >> teclado;
				std::istringstream(teclado) >> std::hex >> bloques[bloques.size() - 1][i];
			}
			m_bloques[bloques.size() - 1] = convert2matrix(bloques[bloques.size() - 1]);

			break;

		case 2:
			// 	// Datos del pdf:

			key.resize(16);
			key = {0x00, 0x01, 0x02, 0x03,
				   0x04, 0x05, 0x06, 0x07,
				   0x08, 0x09, 0x0a, 0x0b,
				   0x0c, 0x0d, 0x0d, 0x0f};
			m_key = convert2matrix(key);
			aes.set_key(m_key);

			bloques.resize(2);
			m_bloques.resize(2);
			bloques[0] = {0x00, 0x11, 0x22, 0x33,
						  0x44, 0x55, 0x66, 0x77,
						  0x88, 0x99, 0xaa, 0xbb,
						  0xcc, 0xdd, 0xee, 0xff};
			m_bloques[0] = convert2matrix(bloques[0]);

			for(int i=0; i<4; i++){
				for (int j = 0; j < 4; j++)
				{
					std::cout << std::hex << m_bloques[0][j][i] << " ";
				}
			}
			std::cout << std::endl;

			// ultimo bloque:
			// bloques[1].resize(16, 0x0);
			bloques[1] = {0x00, 0x00, 0x00, 0x00,
						  0x00, 0x00, 0x00, 0x00,
						  0x00, 0x00, 0x00, 0x00,
						  0x00, 0x00, 0x00, 0x00};
			m_bloques[1] = convert2matrix(bloques[1]);
			t = bloques[1].size();

			for(int i=0; i<4; i++){
				for (int j = 0; j < 4; j++)
				{
					std::cout << std::hex<< m_bloques[1][j][i] << " ";
				}
			}

			break;

		case 0:
			std::cout << "Saliendo..." << std::endl;
			break;

		default:
			std::cout << "[!] Opción no válida" << std::endl;
			break;
		}

		salida = iv;
		for (long unsigned int k = 0; k < bloques.size() - 2; k++) //hasta llegar a los dos últimos bloques
		{
			for (int i = 0; i < 16; i++)
			{
				bloques[k][i] = bloques[k][i] ^ salida[i];
			}
			m_bloques[k] = convert2matrix(bloques[k]);

			aes.set_entrada(m_bloques[k]);
			salida = aes.algoritmo();
			bloques[k] = salida;
		}

		penultimo = bloques.size() - 2;
		ultimo = bloques.size() - 1;
		for (int i = 0; i < 16; i++)
		{
			bloques[penultimo][i] = bloques[penultimo][i] ^ salida[i];
		}
		m_bloques[penultimo] = convert2matrix(bloques[penultimo]);
		aes.set_entrada(m_bloques[penultimo]);
		salida = aes.algoritmo();
		intermedio = salida;

		for (int i = 0; i < 16; i++)
		{
			bloques[ultimo][i] = bloques[ultimo][i] ^ salida[i];
		}
		m_bloques[ultimo] = convert2matrix(bloques[ultimo]);
		aes.set_entrada(m_bloques[ultimo]);
		salida = aes.algoritmo();

		bloques[ultimo] = intermedio;
		bloques[penultimo] = salida;

		for (long unsigned int k = 0; k < bloques.size() - 1; k++)
		{
			std::cout << "Bloque " << k + 1 << ": " << std::endl;
			for (int i = 0; i < 16; i++)
			{
				std::cout << std::hex << bloques[k][i] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "Último Bloque: " << std::endl;
		for (int i = 0; i < t; i++)
		{
			std::cout << std::hex << bloques[bloques.size() - 1][i] << " ";
		}
		std::cout << std::endl;
		break;
	} while (op != 0);
}