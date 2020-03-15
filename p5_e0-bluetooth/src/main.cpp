#include <iostream>
#include "../include/e0_bluetooth.hpp"

int main() {
	e0_bluetooth migenerador;
	int op = 0;
	std::string a;
	std::string b;
	std::string c;
	std::string d;
	std::string r;

	do{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << ">> E0: Bluetooth << " << std::endl;
		std::cout << "1. Valores por defecto" << std::endl;
		std::cout << "2. Introducir valores" << std::endl;
		std::cout << "0. Salir" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "> Opción: ";
		std::cin >> op;
		std::cout << "---------------------------------------" << std::endl;

		switch (op)
		{
		case 1:
			a = "0101011101101001000101111";
			b = "0101011100011101001001010111111";
			c = "010101110110100100011001011101111";
			d = "010101110111011101010101001001100101010";
			r = "01";

			migenerador.insertar_semillas(a, b, c, d, r);
			for(int i=0; i<4; i++){
				migenerador.generar();
			}
			break;

		case 2:
			std::cout << ">> Introducir semilla del registro 1 (25 bits): ";
			std::cin >> a;
			std::cout << ">> Introducir semilla del registro 2 (31 bits): ";
			std::cin >> b;
			std::cout << ">> Introducir semilla del registro 3 (33 bits): ";
			std::cin >> c;
			std::cout << ">> Introducir semilla del registro 4 (39 bits): ";
			std::cin >> d;
			std::cout << ">> Introducir semilla del registro R1 (2 bits): ";
			std::cin >> r;

			migenerador.insertar_semillas(a, b, c, d, r);
			for(int i=0; i<4; i++){
				migenerador.generar();
			}
			break;

		case 0:
			std::cout << "Saliendo..." << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			break;
		default:
			break;
		}

	}while(op!=0);
}