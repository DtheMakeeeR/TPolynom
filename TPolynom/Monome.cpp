#include "Monome.h"

bool Monome::operator<(const Monome& m)
{
    if (x != m.x) return x < m.x;
    if (y != m.y) return y < m.y;
    if (z != m.z) return z < m.z;
    return 0;
}

ostream& operator<<(ostream& out, const Monome& m)
{
    //"\033[31m" << message << "\033[0m
    out << m.coeff;
    if (m.x != 0) cout << "\033[32m" << "*x^" << m.x << "\033[0m";
    if (m.y != 0) cout << "\033[33m" << "*y^" << m.y << "\033[0m";
    if (m.z != 0) cout << "\033[34m" << "*z^" << m.z << "\033[0m";
    return out;
}

istream& operator>>(istream& in, Monome& m)
{
    in >> m.coeff >> m.x >> m.y >> m.z;
    return in;
}
