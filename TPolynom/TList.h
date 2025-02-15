#pragma once
template <typename T>
struct Node {
	T value;
	Node* pNext;
	Node(T v) : value(v), pNext(nullptr) {};
	Node() {
		value = new T();
		pNext = nullptr;
	}
};

template <class T>
class TList {
protected:
	Node<T>* pFirst, *pLast;
	int sz;
public:
	TList() :pFirst(nullptr), pLast(nullptr), sz(0) {}
	TList(const TList& l);

	TList<T>& operator=(const TList<T>& l);
	bool operator ==(const TList<T>& l);
	bool operator !=(const TList<T>& l) { return !(*this == l); };
	~TList();

	bool IsEmpty() { return sz == 0; };
	void Clear();
	void PushFront(T v);
	void PushBack(T v);
	void DelFront();
	T Pop();
};

template<class T>
TList<T>::TList(const TList& l)
{
	Node<T>* tmp = l.pFirst;
	while (tmp != nullptr) {
		PushBack(tmp->value);
		tmp = tmp->pNext;
	}
	sz = l.sz;
}

template<class T>
TList<T>& TList<T>::operator=(const TList<T>& l) 
{
	if (this == &l) return *this;
	if (sz == l.sz) {
		Node<T>* tmp1 = l.pFirst;
		Node<T>* tmp2 = pFirst;
		for (int i = 0; i < sz; i++) {
			tmp2->value = tmp1->value;
			tmp1 = tmp1->pNext;
			tmp2 = tmp2->pNext;
		}
	}
	else 
	{
		for (size_t i = 0; i < sz; i++) DelFront();
		Node<T>* tmp = l.pFirst;
		while (tmp != nullptr) {
			PushBack(tmp->value);
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
bool TList<T>::operator==(const TList<T>& l)
{
	if (this == &l) return true;
	if (sz != l.sz) return false;
	Node<T>* tmp1 = pFirst, * tmp2 = l.pFirst;
	for (int i = 0; i < sz; i++) {
		if (tmp1->value != tmp2->value) return false;
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	return true;
}

template<class T>
TList<T>::~TList()
{
	while (sz != 0) Pop();
}

template<class T>
void TList<T>::Clear()
{
	while (sz != 0) DelFront();
}

template<class T>
void TList<T>::PushFront(T v)
{
	Node<T>* tmp = new Node<T>(v);
	tmp->pNext = pFirst;
	pFirst = tmp;
	if(sz == 0){
		pLast = tmp;
	}
	sz++;
}

template<class T>
void TList<T>::PushBack(T v)
{
	Node<T>* tmp = new Node<T>(v);
	if (sz == 0) {
		pLast = pFirst = tmp;
	}
	else {
		pLast->pNext = tmp;
		pLast = tmp;
	}
	sz++;
}

template<class T>
void TList<T>::DelFront()
{
	if (sz == 0) return;
	Node<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	sz--;
	if (sz == 0) pLast = pFirst;
}

template<class T>
T TList<T>::Pop()
{
	if (sz == 0) throw - 1;
	Node<T>* tmp = pFirst;
	T res = tmp->value;
	pFirst = pFirst->pNext;
	delete tmp;
	sz--;
	if (sz == 0) pLast = pFirst;
	return res;
}
