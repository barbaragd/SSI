#include <iostream>
#include <bitset>


class e0_bluetooth
{
private:
    std::bitset<25> LFSR1;
    std::bitset<31> LFSR2;
    std::bitset<33> LFSR3;
    std::bitset<39> LFSR4;

    std::bitset<2> R1;
    std::bitset<2> R2;

    std::bitset<2> T1;
    std::bitset<2> T2;

public:
    e0_bluetooth();
    ~e0_bluetooth();
    void generar(std::string a, std::string b, std::string c, std::string d, std::string r);

private:
    // void det_t(std::bitset<1> c1, std::bitset<1> c0);
    // void det_r(std::bitset<1> c1, std::bitset<1> c1)
    void det_z()
};

