#include "Monom.h"

bool Monom::operator<(const Monom& m)
{
    int s1 = x * 100 + y * 10 + z, s2 = m.x * 100 + m.y * 10 + m.z;
    return s1 < s2;
}

ostream& operator<<(ostream& out, const Monom& m)
{
    out << m.coeff << "x^" << m.x << "y^" << m.y << "z^" << m.z << endl;;
    return out;
}

istream& operator>>(istream& in, Monom&)
{
    return in;
}
