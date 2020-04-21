#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <math.h>

bool testLehmanPeralta(int v)
{

	// 1. Comprobar que p no es divisible por
	// ningún primo pequeño (2,3,5,7,11).
	if ((v % 2 == 0) || (v % 3 == 0) || (v % 5 == 0) || (v % 7 == 0) || (v % 11 == 0) || (v % 13 == 0))
		return false;

	// 2. Elegir enteros aleatorios
	// entre 2 y p-1.
	srand(time(NULL));
	std::vector<int> aleatorios;
	int p = v - 1;
	int aux;
	for (int i = 0; i <= 6; i++)
	{
		aleatorios.push_back(rand() % p + 2);
	}

	// 3.
	for (int i = 0; i < aleatorios.size(); i++)
	{
		aux = pow(aleatorios[i], (p / 2));
		if ((aux % v) != -1)
		{
			return false;
		}
	}

	return true;
}

bool testEuclides(int d, int fi)
{
	// int i=0;
	int z = 0;
	int x = 0;

	x = fi / d;
	// z es los dos anterios
}

int exp_rapida(int y, int b, int m)
{
	int x = 1;
	while ((b > 0) && (y > 1))
	{
		if ((b % 2) == 0)
		{ // si es par
			y = (y * y) % m;
			b = b / 2;
		}
		else
		{ // si es impar
			x = (x * y) % m;
			b--;
		}
	}
	return x;
}

int main()
{
	int p, q, d, fi;

	std::cout << "> p: ";
	std::cin >> p;
	std::cout << "> q: ";
	std::cin >> q;
	std::cout << "> d: ";
	std::cin >> d;

	fi = (p - 1) * (q - 1);

	// comprobaciones
	testLehmanPeralta(p);
	testLehmanPeralta(q);

	testEuclides(d, fi);
}