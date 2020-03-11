#include "../include/e0_bluetooth.hpp"

e0_bluetooth::e0_bluetooth(/* args */)
{
}

e0_bluetooth::~e0_bluetooth()
{
}

void e0_bluetooth::generar(std::string a, std::string b, std::string c, std::string d, std::string r){
    LFSR1 = std::bitset<25>(a);
    LFSR2 = std::bitset<31>(b);
    LFSR3 = std::bitset<33>(c);
    LFSR4 = std::bitset<39>(d);

    R1 = ~std::bitset<2>(r); // NOT r

    int sum1 = LFSR1[0] + LFSR2[0] + LFSR3[0] + LFSR4[0];  

    // desplazar
    LFSR1 <<= 1;
    LFSR2 <<= 1;
    LFSR3 <<= 1;
    LFSR4 <<= 1;
}