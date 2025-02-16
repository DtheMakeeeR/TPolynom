#include "Polynome.h"
ostream& operator<<(ostream& out, const Polynome& p)
{
    Node<Monom>* tmp = p.pFirst;
    while (tmp != nullptr) {
        out << tmp->value;
        out << "+";
        tmp = tmp->pNext;
    }
    return out;
}

istream& operator>>(istream& in, Polynome& p)
{
    double tmpCoeff;
    cin >> tmpCoeff;
    while (tmpCoeff != 0) {
        Monom* tmpMonom = new Monom();
        tmpMonom->coeff = tmpCoeff;
        try {
            cin >> tmpMonom->x >> tmpMonom->y >> tmpMonom->z;
        }
        catch (exception e) { throw e.what(); }
        p.PushBack(*tmpMonom);
        cin >> tmpCoeff;
    } 
    return in;
}
