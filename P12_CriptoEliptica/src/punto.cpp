#include "../include/punto.hpp"
#include <iostream>
#include <math.h>
#include <vector>

int testEuclides(int d, int fi)
{
    unsigned i = 1;
    std::vector<int> x, z;
    x.push_back(fi);
    x.push_back(d);
    z.push_back(0);
    z.push_back(1);

    while (x[i - 1] % x[i] != 0)
    {
        x.push_back(x[i - 1] % x[i]);
        z.push_back(-(x[i - 1] / x[i]) * z[i] + z[i - 1]);
        i++;
    }

    if (x[i] == 1)
    {
        if (z[i] < 0)
            z[i] = fi + z[i];
        return z[i];
    }

    return 0;
}

punto::punto(int x, int y)
{
    x_ = x;
    y_ = y;
}

punto::punto()
{
    x_ = 0;
    y_ = 0;
}

punto::~punto()
{
}

int punto::get_x()
{
    return x_;
}

int punto::get_y()
{
    return y_;
}

void punto::set_x(int v)
{
    x_ = v;
}

void punto::set_y(int v)
{
    y_ = v;
}

void punto::write()
{
    std::cout << "(" << x_ << ", " << y_ << ")";
}

punto punto::multiplicarx2(int a, int p)
{
    int nom = 3 * pow(x_, 2) + a;
    int den = 2 * y_;
    den = testEuclides(den, p);
    int lambda = nom * den;

    int x3, y3;
    x3 = pow(lambda, 2) - x_ - x_;
    x3 = x3 % p;
    if (x3 < 0)
        x3 += p;
    y3 = lambda * (x_ - x3) - y_;
    y3 = y3 % p;
    if (y3 < 0)
        y3 += p;

    return punto(x3, y3);
}

punto punto::sumar(punto otropunto, int p)
{
    int nom = otropunto.y_ - y_;
    int den = otropunto.x_ - x_;
    den = testEuclides(den, p);
    int lambda = nom * den;

    int x3, y3;
    x3 = pow(lambda, 2) - x_ - otropunto.x_;
    x3 = x3 % p;
    if (x3 < 0)
        x3 += p;
    y3 = lambda * (x_ - x3) - y_;
    y3 = y3 % p;
    if (y3 < 0)
        y3 += p;


    return punto(x3, y3);
}

punto &punto::operator=(punto n)
{
    x_ = n.x_;
    y_ = n.y_;

    return *this;
}

bool punto::operator==(punto &n) const
{
    if ((x_ == n.x_) && (y_ == n.y_))
    {
        return true;
    }
    else
        return false;
}