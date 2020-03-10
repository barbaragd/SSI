#include "../include/a5.hpp"
#include <iostream>

a5::a5()
{
}

a5::~a5()
{
}

void a5::intro_semillas(std::string va, std::string vb, std::string vc)
{
    a_ = insertar_semilla(va, a_);
    b_ = insertar_semilla(vb, b_);
    c_ = insertar_semilla(vc, c_);
    std::cout << "[!] Estado inicial" << std::endl;
    std::cout << "Registro A: ";
    for (auto it = a_.begin(); it != a_.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl << "Registro B: ";
    for (auto it = b_.begin(); it != b_.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl << "Registro C: ";
    for (auto it = c_.begin(); it != c_.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl << "----------------------------------" << std::endl;
}


void a5::reset() // establecer los vectores con las pos de interés a limpio
{
    a_.clear();
    a_.resize(0);
    b_.clear();
    b_.resize(0);
    c_.clear();
    c_.resize(0);
    z_.clear();
    z_.resize(0);
}

std::bitset<1> a5::generar()
{
    pol_a_.clear();
    pol_a_.resize(0);
    pol_b_.clear();
    pol_b_.resize(0);
    pol_c_.clear();
    pol_c_.resize(0);
    det_pos(a_);
    det_pos(b_);
    det_pos(c_);
    mayoria();
    det_desplazar();
    return z_[z_.size() - 1];
}

void a5::write()
{
    // Registros
    std::cout << "Registro A: ";
    for (auto it = a_.begin(); it != a_.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl << "Registro B: ";
    for (auto it = b_.begin(); it != b_.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl << "Registro C: ";
    for (auto it = c_.begin(); it != c_.end(); it++)
    {
        std::cout << (*it) << " ";
    }

    // secuencia generada
    std::cout << std::endl << "Z: ";
    for (long unsigned int i = 0; i < z_.size(); i++)
    {
        std::cout << z_[i] << " ";
    }
    
    std::cout << std::endl;
}

void a5::mayoria()
{ // obtengo el bit mayoría guardado en el atributo mayoria_
    if (a9_ == b11_)
    {
        mayoria_ = a9_;
    }
    else if (a9_ == c11_)
    {
        mayoria_ = a9_;
    }
    else
    {
        mayoria_ = b11_;
    }
    std::cout << "Bit Mayoría: " << mayoria_ << std::endl;
}

/**
 * Función para determinar las posiciones a9, b11 y c11 y las posiciones que necesito
 * para determinar la secuencia de salida, es decir, las del polinomio.
 * 
 * Dependiendo del tamaño del registro determino si es el registro a, b o c. Esto me 
 * interesa porque cada registro tiene unas posiciones de interés diferente.
 * 
 * En el caso del registro a, me interesa las posiciones a_[19-1], a_[18-1], a_[17-1]
 * y a_[14-1] para guardar en el vector de bits que determina el bit nuevo del registro.
 * De este registro también me interesa la posición a_[9-1] que sirve para calcular el 
 * bit mayoría y establecer que registro se desplaza y cuál no. 
 * 
 * En el caso del registro b, me interesa las posiciones b_[22-1], b_[21-1] para guardar 
 * en el vector de bits que determina el bit nuevo del registro.
 * De este registro también me interesa la posición b_[10-1].
 * 
 * En el caso del registro c, me interesa las posiciones c_[23-1], c_[22-1], c_[21-1] y
 * c_[8-1] para guardar en el vector de bits que determina el bit nuevo del registro.
 * De este registro también me interesa la posición c_[10-1].
 */
void a5::det_pos(std::list<std::bitset<1>> x)
{
    int c = 0;
    std::bitset<1> aux;

    // polinomios : vector de con los bits para determinar la sec de salida
    switch (x.size())
    {
    case 19:
        for (auto it = a_.begin(); it != a_.end(); it++)
        {
            if (c == 18 || c == 17 || c == 16 || c == 13)
            {
                aux = *it;
                pol_a_.push_back(aux);
            }
            else if (c == 8)
            {
                aux = *it;
                a9_ = aux; // valor de la pos a[9-1] , que determina la entrada a la f. mayoria
            }
            c++;
        }
        break;

    case 22:
        for (auto it = b_.begin(); it != b_.end(); it++)
        {
            if (c == 21 || c == 20)
            {
                aux = *it;
                pol_b_.push_back(aux);
            }
            else if (c == 10)
            {
                aux = *it;
                b11_ = aux; // puntero a la pos b[11-1] , que determina la entrada a la f. mayoria
            }
            c++;
        }
        break;

    case 23:
        for (auto it = c_.begin(); it != c_.end(); it++)
        {
            if (c == 22 || c == 21 || c == 20 || c == 7)
            {
                aux = *it;
                pol_c_.push_back(aux);
            }
            else if (c == 10)
            {
                aux = *it;
                c11_ = aux; // puntero a la pos c[11-1] , que determina la entrada a la f. mayoria
            }
            c++;
        }
        break;

    default:
        break;
    }
}

/**
 * En la variable auxa/auxb/aux se guarda el valor de la pos más alta del registro.
 * Si los bits de las posiciones que determinan la mayoria son iguales a dicha mayoria
 * se llama a la funcion desplazar con dicho registro y su respectivo pol, esta función
 * nos devuelve el registro desplazado. 
 * 
 * Al final, con todos los bits recogidos, calculamos la xor, y el resultado se guardará
 * en la última posción del registro z_.
 */
void a5::det_desplazar()
{
    std::bitset<1> auxa;
    std::bitset<1> auxb;
    std::bitset<1> auxc;
    auxa = a_.back();
    if (a9_ == mayoria_)
    {
        a_.pop_back();
        a_ = desplazar(a_, pol_a_);
        std::cout << "Registro A se desplaza" << std::endl;
    }
    auxb = b_.back();
    if (b11_ == mayoria_)
    {
        b_.pop_back();
        b_ = desplazar(b_, pol_b_);
        std::cout << "Registro B se desplaza" << std::endl;
    }
    auxc = c_.back();
    if (c11_ == mayoria_)
    {
        c_.pop_back();
        c_ = desplazar(c_, pol_c_);
        std::cout << "Registro C se desplaza" << std::endl;
    }
    z_.push_back(auxa ^ auxb ^ auxc);
}

/**
 * Calculamos la xor de todos los bits que se encuentren en las pos indicadas en el polinomio 
 * correspondiente. Estas posiciones se encuentran almacenadas en un vector que almacena los
 * bits que se encuentran en las posiciones de interés, calculadas previamente con la función
 * det_pos().
 * Al calcular el nuevo valor del primer bit, lo introducimos en el registro.
 * Retornamos el registro desplazado.
 */
std::list<std::bitset<1>> a5::desplazar(std::list<std::bitset<1>> x, std::vector<std::bitset<1>> pol_x)
{

    std::bitset<1> r_xor = pol_x[0];
    for (long unsigned int i = 1; i < pol_x.size(); i++)
    {
        r_xor ^= pol_x[i];
    }
    x.push_front(r_xor);
    return x;
}

/**
 * Insertamos la semilla almacenada en v, en el registro de desplazamiento x
 * Como el registro se encuentra con las posicones en orden invertido, empezamos
 * a introducir los valores desde la última posición que sería la pos 0 del 
 * vector v. 
 */
std::list<std::bitset<1>> a5::insertar_semilla(std::string v, std::list<std::bitset<1>> x)
{
    auto it = x.end();
    it--;
    long unsigned int i = 0;
    while (i < v.size())
    {
        x.insert(it, std::bitset<1>(v[i]));
        it--;
        i++;
    }

    return x;
}