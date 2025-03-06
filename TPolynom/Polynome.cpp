#include "Polynome.h"
ostream& operator<<(ostream& out, Polynome& p)
{
    if (p.IsEmpty()) {
        out << "0";
        return out;
    }
    p.Reset();
    out << p.GetCurr();
    p.GoNext();
    for (; !p.IsEnd(); p.GoNext()) {
        out << (p.GetCurr().coeff >= 1 ? " +" : " ") << p.GetCurr();
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

bool Polynome::operator==(const Polynome& p) const {
    if (this == &p) return true;
    if (sz != p.sz) return false;
    Node<Monome>* tmp1 = pFirst, * tmp2 = p.pFirst;
    for (int i = 0; i < sz; i++) {
        if ((tmp1->value != tmp2->value) || (tmp1->value.coeff != tmp2->value.coeff))
            return false;
        tmp1 = tmp1->pNext;
        tmp2 = tmp2->pNext;
    }
    return true;
}
Polynome& Polynome::operator=(const Polynome& p) {
    if (this == &p) return *this;
    TList<Monome>::operator=(p); //нельзя просто return TList<Monome>::operator=(p)
    return *this; 
}

//Polynome Polynome::operator+(Polynome& p)
//{
//    Polynome res(*this);
//    Polynome::iterator pi = p.Begin();
//    for (; pi != p.End(); ++pi) {
//        res.AddMonome(*pi);
//    }
//    return res;
//}
Polynome Polynome::operator+(Polynome& p)
{
    Polynome res(*this);
    for (res.Reset(), p.Reset(); (!res.IsEnd()) && (!p.IsEnd());) {
        Monome rcur = res.GetCurr(), pcur = p.GetCurr();
        if (rcur == pcur) {
            double c = rcur.coeff + pcur.coeff;
            if (c == 0) {
                res.DelCurr();
                p.GoNext();
            }
            else {
                res.GetCurr().coeff = c;
                res.GoNext();
                p.GoNext();
            }
        }
        else if (rcur < pcur) {
            res.InsCurr(pcur);
            p.GoNext();
        }
        else if (pcur < rcur) {
            res.GoNext();
        }
    }
    if (!p.IsEnd()) {
        for (; !p.IsEnd(); p.GoNext()) {
            res.PushBack(p.GetCurr());
        }
    }
    return res;
}
Polynome Polynome::operator-(Polynome& p)
{
    Polynome res, negative = p * (-1);
    res = *this + negative;
    return res;
}
//равны - двигаем оба, если удалился то двигаем в п
// > InsCurr двигаем п
// < двигаем res
Polynome Polynome::operator*(double coef)
{
    Polynome res(*this);
    if (coef == 0.0) res.Clear();
    else {
        for (res.Reset(); !res.IsEnd(); res.GoNext()) {
            res.GetCurr().coeff *= coef;
        }
    }
    return res;
}

Polynome Polynome::operator*(Polynome p)
{
    Polynome res, multer(*this);
    if (p.sz == 0) return res;
    for (p.Reset(); !(p.IsEnd()); (p.GoNext())) {
//res = res + (*this * p.GetCurr()); не работает!

//при приминении операции полинома к самому себе кур и прев меняются в умножении ->
//  внутренний цикл ломает внешний (так было из-за передачи ссылки...)
        Polynome tmp = (*this * p.GetCurr());
        //Polynome tmp = (multer * p.GetCurr());
        res = (res + tmp);
    }
    return res;
}

Polynome Polynome::operator*(Monome m)
{
    Polynome res;
    if (m.coeff == 0.0) return res;
    for (Reset(); !IsEnd(); GoNext()) {
        Monome tmp;
        tmp.coeff = GetCurr().coeff * m.coeff;
        tmp.x = m.x + GetCurr().x;
        tmp.y = m.y + GetCurr().y;
        tmp.z = m.z + GetCurr().z;
        res.AddMonome(tmp);
    }
    return res;
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
                }
                return;
            }
        }
    }
}
