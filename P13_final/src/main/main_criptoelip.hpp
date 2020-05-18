#include <iostream>
#include "../../include/punto.hpp"
#include <vector>
#include <math.h>

std::vector<punto> calcularPuntos(int a, int b, int p)
{
	std::vector<int> x, y;
	int aux;
	for (int i = 0; i < p; i++)
	{
		aux = pow(i, 3) + a * i + b;
		aux = aux % p;
		x.push_back(aux);
		aux = i * i;
		aux = aux % p;
		y.push_back(aux);
	}

	std::vector<punto> puntos;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (x[i] == y[j])
			{
				punto point(i, j);
				puntos.push_back(point);
			}
		}
	}

	return puntos;
}

void mcurvas()
{
	int p, a, b, dB;
	int x, y;
	int m, M = 2;
	std::vector<punto> puntos;

	std::cout << "Introducir p (Zp): ";
	std::cin >> p;
	std::cout << "Introducir a (valor de la curva): ";
	std::cin >> a;
	std::cout << "Introducir b (valor de la curva): ";
	std::cin >> b;
	// calcular los puntos
	puntos = calcularPuntos(a, b, p);
	std::cout << "Puntos de la curva: ";
	for (long unsigned int i = 0; i < puntos.size(); i++)
	{
		puntos[i].write();
		std::cout << ", ";
	}
	std::cout << std::endl;

	std::cout << "Seleccionar punto base." << std::endl
			  << "> Coordenada x: ";
	std::cin >> x;
	std::cout << "> Coordenada y: ";
	std::cin >> y;
	punto Pt(x, y);

	std::cout << "Clave privada de B: ";
	std::cin >> dB;

	std::cout << "Mensaje (número): ";
	std::cin >> m;
	while (M <= m)
	{
		M *= 2;
	}

	// codificar punto
	int h = p/M;
	for(long unsigned int j=0; j<puntos.size();j++){
		x = m * h + j;
		for(long unsigned int k=0; k<puntos.size();k++){
			if(x==puntos[k].get_x()){
				y = puntos[k].get_y();
				k = puntos.size();
				j = puntos.size();
			}
		}
	}
	punto Qm(x,y);
	std::cout << "Mensaje original codificado como punto: ";
	Qm.write();
	std::cout << std::endl;

	int aA = 4;
	std::cout << "Clave pública de B: ";
	punto dBxP = Pt.multiplicarx2(a, p);
	for (int i = 2; i < dB; i += 2)
	{
		dBxP = dBxP.multiplicarx2(a, p);
	}
	dBxP.write();
	std::cout << std::endl;

	std::cout << "Primer punto del msj cifrado: ";
	punto aAxdBxP = dBxP.multiplicarx2(a, p);
	for (int i = 2; i < aA; i += 2)
	{
		aAxdBxP = aAxdBxP.multiplicarx2(a, p);
	}
	punto p1;
	p1 = aAxdBxP.sumar(Qm, p);
	p1.write();
	std::cout << std::endl;

	std::cout << "Segundo punto del msj cifrado: ";
	punto aAxP = Pt.multiplicarx2(a, p);
	for (int i = 2; i < aA; i += 2)
	{
		aAxP = aAxP.multiplicarx2(a, p);
	}
	aAxP.write();
	std::cout << std::endl;
}