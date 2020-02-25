#pragma once
#include <vector>
#include <list>
#include <bitset>

class a5
{
private:
    std::list<std::bitset<1>> a_;
    std::list<std::bitset<1>> b_;
    std::list<std::bitset<1>> c_;

    std::vector<std::bitset<1>> pol_a_;
    std::vector<std::bitset<1>> pol_b_;
    std::vector<std::bitset<1>> pol_c_;

    // posiciones que determinan la entrada a la función mayoría
    std::bitset<1> a9_;
    std::bitset<1> b11_;
    std::bitset<1> c11_;

    std::bitset<1> mayoria_; // bit mayoria 

    std::vector<std::bitset<1>> z_;

public:
    a5(std::string a, std::string b, std::string c);
    ~a5();
    std::bitset<1> cifrar();
    void write();
    
private:
    void mayoria(); // calcular el bit mayoria
    void det_desplazar(); // determinar quienes se desplazan
    std::list<std::bitset<1>> desplazar(std::list<std::bitset<1>> x, std::vector<std::bitset<1>> pol_x); // desplazar 
    std::list<std::bitset<1>> insertar_semilla(std::string v, std::list<std::bitset<1>> x);
    void det_pos(std::list<std::bitset<1>> x); // determinar las pos de interés del registro
    void reset();
};