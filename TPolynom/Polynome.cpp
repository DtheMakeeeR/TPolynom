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
    int power;
    cin >> tmpCoeff;
    while (tmpCoeff != 0) {
        Monom* tmpMonom = new Monom();
        tmpMonom->coeff = tmpCoeff;
        cin >> tmpMonom->x >> tmpMonom->y >> tmpMonom->z;
        p.PushBack(*tmpMonom);
        cin >> tmpCoeff;
    } 
    return in;
}
