#include <iostream>
#include "../include/e0_bluetooth.hpp"

int main() {
	e0_bluetooth migenerador;

	std::string a = "0101011101101001000101011";
	std::string b = "0101011100011101001001010111011";
	std::string c = "010101110110100100011001011101010";
	std::string d = "010101110111011101010101001001100101011";


	std::string r = "01";

	migenerador.insertar_semillas(a, b, c, d, r);
	for(int i=0; i<2; i++){
		migenerador.generar();
	}
	migenerador.write();
}