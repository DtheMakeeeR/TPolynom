#include "Polynome.h"
ostream& operator<<(ostream& out, Polynome& p)
{
    if (p.IsEmpty()) return out;
    p.Reset();
    out << p.GetCurr();
    p.GoNext();
    for (; !p.IsEnd(); p.GoNext()) {
        out << (p.GetCurr().coeff > 1 ? "+" : "") << p.GetCurr();
    }
    return out;
}

istream& operator>>(istream& in, Polynome& p)
{
    double tmpCoeff;
    cin >> tmpCoeff;
    while (tmpCoeff != 0) {
        Monome* tmpMonome = new Monome();
        tmpMonome->coeff = tmpCoeff;
        try {
            cin >> tmpMonome->x >> tmpMonome->y >> tmpMonome->z;
        }
        catch (exception e) { throw e.what(); }
        p.PushBack(*tmpMonome);
        tmpCoeff = 0;
        cin >> tmpCoeff;
    } 
    return in;
}

Polynome::Polynome(Monome* p, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        PushBack(p[i]);
    }
}

void Polynome::AddMonome(Monome m)
{
    if (IsEmpty()) PushBack(m);
    else {
        //добавление первого и последнего звена
        if (pFirst->value < m) {
            PushFront(m);
            return;
        }
        if (m < pLast->value) {
            PushBack(m);
            return;
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (GetCurr() < m) {
                Node<Monome>* add = new Node<Monome>(m);
                add->pNext = pCurr;
                pPrev->pNext = add;
                sz++;
                return;
            }
            if (GetCurr() == m) {
                double c = pCurr->value.coeff + m.coeff;
                if (c != 0) pCurr->value.coeff = c;
                else {
                    if (pCurr == pFirst) Pop();
                    else if (pCurr == pLast) {
                        pPrev->pNext = nullptr;
                        pLast = pPrev;
                        sz--;
                        delete pCurr;
                    }
                    else {
                        Node<Monome>* tmp = pCurr;
                        pPrev->pNext = pCurr->pNext;
                        sz--;
                        delete tmp;
                    }
                    return;
                }
            }
        }
    }
}
