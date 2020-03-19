#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>

std::bitset<8> sumar(std::vector<std::bitset<8>> aux, std::bitset<8> r)
{
	for (int i = 0; i < aux.size(); i++)
	{
		r ^= aux[i];
	}
	return r;
}

/**
 * Función para sumar el byte AES o SNOW3G
 */
std::bitset<8> op_xor(std::bitset<8> m, int x)
{
	std::bitset<8> r;
	switch (x)
	{
	case 1: // SNOW 3G
		r = m ^ std::bitset<8>("10101001");
		return r;
		break;

	case 2: // AES
		// std::cout << " con 00011011 y me da: ";
		r = m ^ std::bitset<8>("00011011");
		// std::cout << r << std::endl;
		return r;
		break;

	default:
		break;
	}
}

void write(std::bitset<8> m1, std::bitset<8> m2, int x)
{
	std::cout << "Primer byte: " << m1 << std::endl;
	std::cout << "Segundo byte: " << m2 << std::endl;
	if (x == 1)
	{
		std::cout << "Byte Algoritmo: 10101001" << std::endl;
	}
	else
	{
		std::cout << "Byte Algoritmo: 00011011" << std::endl;
	}
}

/**
 * m1 = multiplicando
 * m2 = multiplicador
 * Si el bit menos significativo de m2 es 1, guardamos en nuestro resultado el valor de m1,
 * si no, r vale 0.
 * 
 * A continuación, desplazamos, y si el bit mas significativo de m1 es 1, además de 
 * desplazar, sumamos el byte correspondientes (AES o SNOW3G). El resultado de esto es 
 * el nuevo m1.
 * 
 * Luego, si el bit i del multiplicador es 1, guardamos m1 en un vector de bytes para 
 * finalmente sumar todos los bytes y esté será el resultado final.
 */
std::bitset<8> multiplicar(std::bitset<8> m1, std::bitset<8> m2, int x) // m2 = abajo, m1 = arriba
{
	write(m1, m2, x);
	std::vector<std::bitset<8>> aux;
	std::bitset<8> r = 0;
	if (m2[0] == 1)
	{
		r = m1;
		// std::cout << "1era iter: " << r << std::endl;
	}

	for (long unsigned int i = 1; i < 8; i++)
	{
		std::cout << "desplazo ";
		m1 <<= 1;
		if (m1[m1.size() - 1] == 1)
		{
			// std::cout << "y sumo :";
			// std::cout << m1;
			m1 = op_xor(m1, x);
		}
		if (m2[i] == 1)
		{
			// std::cout << "\tguardo ";
			aux.push_back(m1);
		}
		// std::cout << std::endl;
	}
	r = sumar(aux, r);
	// std::cout << std::endl
	//   << "Resultado: ";
	std::cout << "Multiplicación: ";
	return r;
}

int main()
{
	int a;
	int b;
	std::string sa;
	std::string sb;
	int op;

	do
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << ">> Multiplicación binaria AES y SNOW3G << " << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "\t1. AES" << std::endl;
		std::cout << "\t2. SNOW3G" << std::endl;
		std::cout << "\t3. Por defecto" << std::endl;
		std::cout << "\t0. Salir" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "> Opción: ";
		std::cin >> op;
		std::cout << "--------------------------------------------" << std::endl;

		switch (op)
		{
		case 1:
			std::cout << "> Multiplicando: ";
			std::cin >> sa;
			std::cout << "> Multiplicador: ";
			std::cin >> sb;
			std::cout << "--------------------------------------------" << std::endl;
			std::istringstream(sa) >> std::hex >> a;
			std::istringstream(sb) >> std::hex >> b;
			std::cout << multiplicar(a, b, 2) << std::endl;

			break;

		case 2:
			std::cout << "> Multiplicando: ";
			std::cin >> sa;
			std::cout << "> Multiplicador: ";
			std::cin >> sb;
			std::cout << "--------------------------------------------" << std::endl;
			std::istringstream(sa) >> std::hex >> a;
			std::istringstream(sb) >> std::hex >> b;
			std::cout << multiplicar(a, b, 1) << std::endl;

			break;

		case 3:
			std::istringstream("57") >> std::hex >> a;
			std::istringstream("83") >> std::hex >> b;

			std::cout << "[!]\tAES" << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << multiplicar(a, b, 2) << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << "[!]\tSNOW 3G" << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << multiplicar(a, b, 1) << std::endl;
			break;

		case 0:
			std::cout << "Saliendo..." << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
			break;
		default:
			break;
		}

	} while (op != 0);
}