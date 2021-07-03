#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Lista
{
private:
   struct cvor
   {
      T data;
      cvor *next;
   };

   cvor *head;

public:
   Lista() : head(nullptr) {}

   bool upis(string element)
   {
      cvor *novi = new (nothrow) cvor;
      if (novi == nullptr)
         return false;
      novi->data = element;
      novi->next = nullptr;
      if (!head)
         head = novi;
      else
      {
         cvor *p;
         for (p = head; p->next; p = p->next)
            ;
         p->next = novi;
      }
      return true;
   }
   void ispis()
   {
      cvor *p;
      for (p = head; p->next; p = p->next)
         cout << p->data << " ";
      cout << p->data << " ";
   }
};

int main()
{
   Lista<string> l;
   l.upis("azzz");
   l.upis("ba");
   l.upis("fafaf");
   l.upis("afafaa");
   l.upis("gsgsgs");
   l.upis("pofapfap");
   l.ispis();
}