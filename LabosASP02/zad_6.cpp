#include <iostream>
#include <string>

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

   bool upis(T data)
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
   }

   void ispis()
   {
      for (ListElement<T> *p = head; p; p = p->next)
      {
         cout << p->data << " ";
      }
      cout << endl;
   }
};

int main()
{
   int n;
   cout << "Unesi broj elemenata > ";
   cin >> n;
   List<int> l;
   cout << "Unesi elemente > ";
   for (int i = 0; i < n; i++)
   {
      int a;
      cin >> a;
      l.upis(a);
   }
   l.ispis();
   return 0;
}