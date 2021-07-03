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
   {
      auto *newEl = new (nothrow) ListElement<T>;
      if (newEl == nullptr)
         return false;
      newEl->data = data;
      newEl->next = head;
      head = newEl;
      return true;
   }

   bool append(T data)
   {
      auto *newEl = new (nothrow) ListElement<T>;
      if (newEl == nullptr)
         return false;
      newEl->data = data;
      newEl->next = nullptr;
#if 1
      //s jednostrukim pointerom na kraj liste
      if (!head)
         head = newEl;
      else
      {
         ListElement<T> *p;
         for (p = head; p->next; p = p->next)
            ;
         p->next = newEl;
      }
#else
      //s dvostrukim pointerom
      if (!head)
         head = newEl;
      else
      {
         ListElement<T> **p;
         for (p = &head; *p; p = &((*p)->next))
            ;
         *p = newEl;
      }
#endif
      return true;
   }

   bool insertSorted(T data)
   {
      auto *newEl = new (nothrow) ListElement<T>;
      if (newEl == nullptr)
         return false;
      newEl->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newEl->next = *p;
      *p = newEl;
      return true;
   }

   bool remove(T data)
   {
      ListElement<T> **p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->data))
         ;
      if (*p)
      {
         ListElement<T> tmp;
         tmp = *p;
         *p = (*p)->next;
         delete tmp;
         return true
      }
      else
         return false;
   }
   void print()
   {
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         cout << p->data << " ";
      cout << endl;
   }
};

int main()
{
}