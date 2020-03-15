#include "../include/e0_bluetooth.hpp"

e0_bluetooth::e0_bluetooth()
{
    sum1 = 0;
    sum2 = 0;
}

e0_bluetooth::~e0_bluetooth()
{
}

void e0_bluetooth::insertar_semillas(std::string a, std::string b, std::string c, std::string d, std::string r){
    LFSR1 = std::bitset<25>(a);
    LFSR2 = std::bitset<31>(b);
    LFSR3 = std::bitset<33>(c);
    LFSR4 = std::bitset<39>(d);

    R1 = std::bitset<2>(r); 

    std::cout << "INICIO: " << std::endl;
    std::cout << "LFSR1: " << "              " << LFSR1 << std::endl;
    std::cout << "LFSR2: " << "        "<< LFSR2 << std::endl;
    std::cout << "LFSR3: " << "      " << LFSR3 << std::endl;
    std::cout << "LFSR4: " << LFSR4 << std::endl;
    std::cout << "R1: " << R1 << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

// Posicion a la que quiero acceder y luego el registro LFSR al que quiero acceder
int e0_bluetooth::get_bit(int pos, int reg){
    switch (reg)
    {
    case 1:
        return LFSR1[24 - pos];
        break;

    case 2:
        return LFSR2[30 - pos];
        break;

    case 3:
        return LFSR3[32 - pos];
        break;
    
    case 4:
        return LFSR4[38 - pos];
        break;
    
    default:
        break;
    }
}

void e0_bluetooth::generar(){

    std::bitset<2> aux = R1;
    R1[0] = aux[1];
    R1[1] = aux[0];

    salida_.push_back(get_bit(24, 1) ^ get_bit(30, 2) ^ get_bit(32, 3) ^ get_bit(38, 4) ^ R1[0]);
    std::cout << "z: " << get_bit(24, 1) << "^" << get_bit(30, 2) << "^" << get_bit(32, 3) << "^" << get_bit(38, 4) << "^" << R1[0] << std::endl;
    
    sum1 = get_bit(24, 1) + get_bit(30, 2) + get_bit(32, 3) + get_bit(38, 4);
    std::cout << "sum1: " << sum1 << std::endl;

    sum2 = sum1 + R1.to_ulong();
    std::cout << "sum2: " << sum2 << std::endl;

    mod2 = sum2 / 2;
    std::cout << "mod2: " << mod2 << std::endl;
    
    R2[0] = R1[1];
    R2[1] = R1[0];
    std::cout << "R2: " << R2 << std::endl;

    T1 = R1;
    std::cout << "T1: " << T1 << std::endl;

    T2[1] = R2[0];
    T2[0] = R2[0] ^ R2[1];
    std::cout << "T2: " << T2 << std::endl;

    R1 = mod2 ^ T2 ^ T1;
    std::cout << "R1: " << R1 << std::endl;

    realimentacion();
    write();
}


void e0_bluetooth::realimentacion(){ 
    // desplazar
    LFSR1 >>= 1;
    LFSR2 >>= 1;
    LFSR3 >>= 1;
    LFSR4 >>= 1;

    LFSR1[24] = get_bit(7, 1) ^ get_bit(11, 1) ^ get_bit(19, 1) ^ get_bit(24, 1);
    LFSR2[30] = get_bit(11, 2) ^ get_bit(15, 2) ^ get_bit(23, 2) ^ get_bit(30, 2);
    LFSR3[32] = get_bit(3, 3) ^ get_bit(23, 3) ^ get_bit(27, 3) ^ get_bit(32, 3);
    LFSR4[38] = get_bit(3, 4)  ^ get_bit(27, 4)  ^ get_bit(35, 4) ^ get_bit(38, 4) ;
}

void e0_bluetooth::write(){
    std::cout << "LFSR1: " << "              " << LFSR1 << std::endl;
    std::cout << "LFSR2: " << "        "<< LFSR2 << std::endl;
    std::cout << "LFSR3: " << "      " << LFSR3 << std::endl;
    std::cout << "LFSR4: " << LFSR4 << std::endl;
    std::cout << "Z: ";
    for(long unsigned int i=0; i<salida_.size(); i++){
        std::cout << salida_[i] << " ";
    }
    std::cout << std::endl << "---------------------------------------" << std::endl;
}