#include "../include/a5.hpp"

a5::a5(std::vector<std::bitset<1>> va, std::vector<std::bitset<1>> vb, std::vector<std::bitset<1>> vc)
{
    int c = 0;
    std::bitset<1> aux;

    // semillas insertadas
    insertar_semilla(va, a_);
    insertar_semilla(vb, b_);
    insertar_semilla(vc, c_);

    // polinomios : vector de punteros a las pos correspondientes del polinomio
    for (auto it = a_.begin(); it != a_.end(); it++)
    {
        if (c == 18 || c == 17 || c == 16 || c == 13)
        {
            aux = *it;
            pol_a_.push_back(&aux);
        }
        else if (c == 8)
        {
            a9 = &aux; // puntero a la pos a[9-1] , que determina la entrada a la f. mayoria
        }
        it++;
    }
    c = 0;
    for (auto it = b_.begin(); it != b_.end(); it++)
    {
        if (c == 21 || c == 20)
        {
            aux = *it;
            pol_b_.push_back(&aux);
        }
        else if (c == 10)
        {
            b11 = &aux; // puntero a la pos b[11-1] , que determina la entrada a la f. mayoria
        }
        it++;
    }
    c = 0;
    for (auto it = c_.begin(); it != c_.end(); it++)
    {
        if (c == 22 || c == 21 || c == 20 || c == 7)
        {
            aux = *it;
            pol_c_.push_back(&aux);
        }
        else if (c == 10)
        {
            c11 = &aux; // puntero a la pos c[11-1] , que determina la entrada a la f. mayoria
        }
        it++;
    }
}

a5::~a5()
{
}

void a5::mayoria()
{ // obtengo el bit mayoría guardado en el atributo mayoria_
    mayoria_ = *a9 ^ *b11 ^ *c11;
}

/**
 * Si los bits de las posiciones que determinan la mayoria son iguales a dicha mayoria
 * se llama a la funcion desplazar con dicho registro y su respectivo pol, esta función
 * nos devuelve el valor en la posición más alta, es decir, en el caso del registro a, en
 * la pos 19, del b, la pos 22 y del c, la pos 23.
 * En caso de que el bit en cuestión no sea igual a dicha mayoría, obtenemos dicho valor
 * de la pos más alta pero sin realizar el desplazamiento.
 * 
 * Al final, con todos los bits recogidos, calculamos la xor, y el resultado se guardará
 * en el registro z_.
 */
void a5::det_desplazar()
{
    std::bitset<1> auxa;
    std::bitset<1> auxb;
    std::bitset<1> auxc;
    if (*a9 == mayoria_)
    {
        auxa = desplazar(a_, pol_a_);
    }
    else
    {
        auxa = a_.back();
    }
    if (*b11 == mayoria_)
    {
        auxb = desplazar(b_, pol_b_);
    }
    else
    {
        auxb = b_.back();
    }
    if (*c11 == mayoria_)
    {
        auxc = desplazar(c_, pol_c_);
    }
    else
    {
        auxc = c_.back();
    }

    z_.push_back(auxa ^ auxb ^ auxc); 
}

/**
 * Guardamos el valor que se encuentra en la pos más alta del registro y luego lo eliminamos de
 * dicho registro. Luego, calculamos la xor de todos los bits que se encuentren en las pos
 * indicadas en el polinomio correspondiente. Estas posiciones se encuentran almacenadas en un vector
 * con punteros a dichas posiciones (que son bits).
 * Al calcular el nuevo valor del primer bit, lo introducimos en el registro.
 * Retornamos el valor del bit en la posición más alta.
 */ 
std::bitset<1> a5::desplazar(std::list<std::bitset<1>> x, std::vector<std::bitset<1> *> pol_x)
{
    std::bitset<1> aux = x.back();
    x.pop_back();

    std::bitset<1> r_xor = *pol_x[0];
    for (int i = 1; i < pol_x.size(); i++)
    {
        r_xor ^= *pol_x[i];
    }

    x.push_front(r_xor);
    return aux;
}

/**
 * Insertamos la semilla almacenada en v, en el registro x
 * Como el registro se encuentra con las posicones en orden invertido, empezamos
 * a introducir los valores desde la última posición que sería la pos 0 del 
 * vector v. 
 */ 
void a5::insertar_semilla(std::vector<std::bitset<1>> v, std::list<std::bitset<1>> x)
{
    auto it = x.end();
    int i = 0;
    while (it != x.begin() && i < v.size())
    {
        x.insert(it, v[i]);
        it--;
        i++;
    }
}