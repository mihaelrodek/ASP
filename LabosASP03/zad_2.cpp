#include <bits/stdc++.h>
using namespace std;

class Red
{
private:
   struct Cvor
   {
      double num;
      Cvor *next;
   };
   Cvor *ulaz = nullptr;
   Cvor *izlaz = nullptr;

public:
   bool dodaj(double broj)
   {
      Cvor *novi = new (nothrow) Cvor;
      if (novi == nullptr)
         return false;
      novi->next = nullptr;
      novi->num = broj;

      if (izlaz == nullptr)
      {
         ulaz = novi;
      }
      else
         izlaz->next = novi;
      izlaz = novi;
      return true;
   }

   bool skini(double *broj)
   {
      if (ulaz == nullptr)
         return false;
      *broj = ulaz->num;
      Cvor *tmp = ulaz;
      ulaz = ulaz->next;
      if (ulaz == nullptr)
         izlaz = nullptr;
      delete tmp;
      return true;
   }
};

int main()
{
   cout << "Unesite 10 brojeva: ";
   double a;
   Red red;

   for (int i = 1; i <= 10; i++)
   {
      cin >> a;
      red.dodaj(a);
   }
   cout << "";
   for (int i = 1; i <= 10; i++)
   {
      red.skini(&a);
      cout << a;
   }
}