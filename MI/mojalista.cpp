#include <bits/stdc++.h>

using namespace std;

template <class T>
class List
{
    template <class X>
    struct ListElement
    {
        X data;
        ListElement<X> *next;
    };
    ListElement<T> *head = nullptr;

public:
    bool insert(T data)
    { // umetanje na početak liste
        ListElement<T> *newElement = new (nothrow) ListElement<T>;
        if (newElement == nullptr)
            return false;
        newElement->data = data;
        newElement->next = head;
        head = newElement;
        return true;
    }
    bool append(T data)
    { // dodavanje na kraj liste
        ListElement<T> *newElement = new ListElement<T>;
        if (newElement == nullptr)
            return false;
        newElement->data = data;
        newElement->next = nullptr;
#if 1
        // elementarno, s jednostrukim pokazivačem
        if (!head)
        { // prazna lista
            head = newElement;
        }
        else
        {
            ListElement<T> *p;
            for (p = head; p->next; p = p->next)
                ; // iteracija na kraj liste
            p->next = newElement;
        }
#else
        // naprednije, s **
        ListElement<T> **p;
        for (p = &head; *p; p = &((*p)->next))
            ;
        *p = newElement;
#endif
        return true;
    }

    void print()
    {
        for (ListElement<T> *p = &head; p; p = p->next)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
    bool insertSorted(T data)
    { // umetanje po sortiranom redoslijedu, T mora
        // imati implementiran operator >
        ListElement<T> *newElement = new (nothrow) ListElement<T>;
        if (newElement == nullptr)
            return false;
        newElement->data = data;
        ListElement<T> **p;
        for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
            ;
        newElement->next = *p;
        *p = newElement;
        return true;
    }

    bool remove(T data)
    {
        ListElement<T> **p;
        for (p = &head; *p && data != (*p)->data; &((*p)->next))
            ;
        if (*p)
        {
            ListElement<T> *tmp;
            tmp = *p;
            *p = (*p)->next;
            delete tmp;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    List<int> ListaInt;
    ListaInt.insert(1);
    ListaInt.insert(2);
    ListaInt.insert(3);
    ListaInt.print();
    ListaInt.append(4);
    ListaInt.print();
    ListaInt.append(5);
    ListaInt.print();
}