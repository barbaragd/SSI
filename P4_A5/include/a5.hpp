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

    std::vector<std::bitset<1>*> pol_a_;
    std::vector<std::bitset<1>*> pol_b_;
    std::vector<std::bitset<1>*> pol_c_;

    // posiciones que determinan la entrada a la función mayoría
    std::bitset<1>* a9;
    std::bitset<1>* b11;
    std::bitset<1>* c11;

    std::bitset<1> mayoria_; // bit mayoria 
    // lo tengo que quitar de atributo

    std::vector<std::bitset<1>> z_;

public:
    a5(std::vector<std::bitset<1>> a, std::vector<std::bitset<1>> b, std::vector<std::bitset<1>> c);
    ~a5();

private:
    void mayoria(); // calcular el bit mayoria
    void det_desplazar(); // determinar quienes se desplazan
    std::bitset<1> desplazar(std::list<std::bitset<1>> x, std::vector<std::bitset<1>*> pol_x); // desplazar y obtengo el bit de salida
    void insertar_semilla(std::vector<std::bitset<1>> v, std::list<std::bitset<1>> x);
};