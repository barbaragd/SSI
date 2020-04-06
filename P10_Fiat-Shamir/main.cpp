#include <iostream>

int main()
{
	int p, q, s, x, e;
	int N;
	unsigned long int v, a, y;
	int iter;
	std::string f;
	unsigned long int aux, auxb;

	// Inicialización
	std::cout << "> Número primo (p): ";
	std::cin >> p;
	std::cout << "> Número primo (q): ";
	std::cin >> q;

	N = p * q;

	// Identificación secreta de A
	do
	{
		std::cout << "> Número secreto s (0 < s < N): ";
		std::cin >> s;
	} while ((0 > s) || (s > N));

	// Identificación pública de A
	v = (s * s) % N;

	// Iteraciones
	std::cout << "> ¿Iteraciones?: ";
	std::cin >> iter;

	std::cout << "N= " << N << std::endl;
	std::cout << "v= " << v << std::endl;

	int i = 0;
	while (i < iter)
	{
		// Compromiso secreto de A
		do
		{
			std::cout << "> Número secreto x (0 < x < N): ";
			std::cin >> x;
		} while ((0 > x) || (x > N));

		// Testigo: A envía a B
		a = (x * x) % N;

		// Reto: B envía a A
		do
		{
			std::cout << "> Elegir un bit e (0-1): ";
			std::cin >> e;
		} while ((e != 1) && (e != 0));

		// Respuesta: A envía a B
		if (e == 0)
			y = x % N;
		else
			y = (x * s) % N;

		// Verificación: B comprueba la información recibida
		if (e == 0)
		{
			aux = (y * y) % N;
			if (aux == a)
				f = "válida";
			else
				f = "inválida";
			// Salida:
			std::cout << i + 1 << "ª iteración: a=" << a << " comprobar que " << y << "² == " << a << "(mod " << N << ") y da por " << f << " la iteración." << std::endl;
		}
		else
		{
			aux = (y * y) % N;
			auxb = (a * v) % N;
			if (aux == auxb)
				f = "válida";
			else
				f = "inválida";
			// Salida:
			std::cout << i + 1 << "ª iteración: a=" << a << " comprobar que " << y << "² == " << a << "*" << v << "(mod " << N << ") y da por " << f << " la iteración." << std::endl;
		}
		i++;
	}
}