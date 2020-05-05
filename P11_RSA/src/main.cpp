#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <math.h>

int exp_rapida(long unsigned int y, int b, int m)
{
	long unsigned int x = 1;
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

bool testLehmanPeralta(int p)
{

	// 1. Comprobar que p no es divisible por
	// ningún primo pequeño (2,3,5,7,11).
	if ((p % 2 == 0) || (p % 3 == 0) || (p % 5 == 0) || ((p % 7 == 0) && (p != 7)) || ((p % 11 == 0) && (p != 11)))
		return false;

	// 2. Elegir enteros aleatorios
	// entre 2 y p-1.
	srand(time(NULL));
	std::vector<int> aleatorios;
	int p_ = p - 1;
	int a = 0;
	for (int i = 0; i <= 6; i++)
	{
		// variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
		a = 2 + rand() % (p - 2);
		aleatorios.push_back(a);
	}

	// 3. Para cada i calcular aleatorios[i] ^ ((p-1)/2)) (mod p):
	int aux;
	bool flag = true;
	for (long unsigned int i = 0; i < aleatorios.size(); i++)
	{
		// 3.1. Si para todo i de aleatorios[i] ^ ((p-1)/2)) == 1 (mod p)
		// entonces p es compuesto
		aux = exp_rapida(aleatorios[i], (p_ / 2), p);
		if (aux != 1)
			flag = false;
	}

	// si para todo i de aleatorios[i] ^ ((p-1)/2)) es igual a 1,
	// entonces no es primo, devolvemos false. En caso contrario,
	// seguimos comprobando
	if (flag)
		return false;

	// Si existe i tal que aleatorios[i] ^ ((p-1)/2)) ≠-1 (mod p),
	// entonces p no es primo
	for (long unsigned int i = 0; i < aleatorios.size(); i++)
	{
		aux = exp_rapida(aleatorios[i], (p_ / 2), p);
		if (aux != 1)
		{
			aux = aux - p;
		}
		if ((aux != -1 && (aux != 1)))
		{
			return false;
		}
	}

	// si no cumple con nada de lo anterior,
	// podemos decir que p entonces, tal vez, es primo.
	return true;
}

int testEuclides(int d, int fi)
{
	unsigned i = 1;
	std::vector<int> x, z;
	x.push_back(fi);
	x.push_back(d);
	z.push_back(0);
	z.push_back(1);

	while (x[i - 1] % x[i] != 0)
	{
		x.push_back(x[i - 1] % x[i]);
		z.push_back(-(x[i - 1] / x[i]) * z[i] + z[i - 1]);
		i++;
	}

	if (x[i] == 1)
	{
		if (z[i] < 0)
			z[i] = fi + z[i];
		return z[i];
	}

	return 0;
}

int get_letra(char letra)
{
	std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (unsigned i = 0; i < 26; i++)
	{
		if (alfabeto[i] == letra)
			return i;
	}
	return -1;
}

int cod_numerica(int tamBlock, std::string mensaje)
{
	int r = 0;
	for (int i = 0; i < tamBlock; i++)
	{
		r += get_letra(mensaje[i]) * pow(26, tamBlock-(i+1));
	}

	return r;
}

std::string quitar_espacios(std::string cad)
{
	std::string aux;
	aux.clear();
	for (unsigned i = 0; i < cad.size(); i++)
		if (cad[i] != ' ')
			aux += cad[i];
	return aux;
}

void RSA(int n, int e, std::string men) 
{											
	std::string mensaje = quitar_espacios(men);

	// elegir el tamaño del bloque
	int j = 0;
	int tamBlock;
	while (pow(26,j) < n)
	{
		j++;
	}
	tamBlock = j - 1;
	std::cout << "tamaño del bloque: " << tamBlock << std::endl;

	std::vector<int> msj_codificado;
	std::vector<int> msj_cifrado;

	// Comprobar que el msj es múltiplo del tamaño del bloque	
	int aux = mensaje.size() % tamBlock;
	if(aux!=0){
		for(int i=0; i<(tamBlock - aux); i++){
			mensaje.push_back('X');
		}
	}
	for (long unsigned int i = 0; i < mensaje.size(); i++)
	{
		std::string cadaux (mensaje,i,tamBlock);
		int cod = cod_numerica(tamBlock, cadaux);
		msj_codificado.push_back(cod);
		msj_cifrado.push_back(exp_rapida(cod, e, n));
		i += tamBlock - 1;
	}

	std::cout << "Mensaje codificado: ";
	for (long unsigned int i = 0; i < msj_codificado.size(); i++)
	{
		std::cout << msj_codificado[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Mensaje cifrado: ";
	for (long unsigned int i = 0; i < msj_cifrado.size(); i++)
	{
		std::cout << msj_cifrado[i] << " ";
	}
	std::cout << std::endl;

}

int main()
{
	int p, q, d, fi, n;
	bool flag = true;
	long int e;
	do
	{
		std::cout << "> p: ";
		std::cin >> p;
		std::cout << "> q: ";
		std::cin >> q;
		std::cout << "> d: ";
		std::cin >> d;

		fi = (p - 1) * (q - 1);
		std::cout << "fi: " << fi << std::endl;
		n = p * q;
		std::cout << "n: " << n << std::endl;

		// comprobaciones
		flag = testLehmanPeralta(p);
		flag = testLehmanPeralta(q);
		e = testEuclides(d, fi); // si me devuelve 0 es que no se cumple el test
	} while ((!flag || (e == 0)));

	std::cout << "e: " << e << std::endl;

	std::string mensaje;
	std::cout << "Mensaje: ";
	std::cin.ignore();
	std::getline (std::cin, mensaje);

	RSA(n, e, mensaje);
}