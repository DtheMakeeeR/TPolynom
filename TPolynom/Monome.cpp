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
    out << m.coeff;
    if (m.x != 0) cout << "*x^" << m.x;
    if (m.y != 0) cout << "*y^" << m.y;
    if (m.z != 0) cout << "*z^" << m.z;
    return out;
}

istream& operator>>(istream& in, Monome& m)
{
    in >> m.coeff >> m.x >> m.y >> m.z;
    return in;
}
