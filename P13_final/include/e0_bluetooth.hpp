#include <iostream>
#include <bitset>
#include <vector>


class e0_bluetooth
{
private:
    
    // registros
    std::bitset<25> LFSR1;
    std::bitset<31> LFSR2;
    std::bitset<33> LFSR3;
    std::bitset<39> LFSR4;

    std::bitset<2> R1;
    std::bitset<2> R2;

    std::bitset<2> T1;
    std::bitset<2> T2;

    int sum1;
    int sum2;

    std::bitset<2> mod2;

    std::vector<std::bitset<1>> salida_;

public:
    e0_bluetooth();
    ~e0_bluetooth();
    void insertar_semillas(std::string a, std::string b, std::string c, std::string d, std::string r);
    void generar();

private:
    void realimentacion();
    int get_bit(int pos, int reg);
    void write();
};
