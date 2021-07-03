#include <bits/stdc++.h>
using namespace std;

class Red
{
private:
   static const int MAX = 11;
   int ulaz = 0, izlaz = 0;
   double polje[MAX];

public:
   bool dodaj(double broj)
   {
      if ((ulaz + 1) % MAX == izlaz)
         return false;
      polje[ulaz] = broj;
      ulaz = (ulaz + 1) % MAX;
      return true;
   }

   bool skini(double *broj)
   {
      if (izlaz == ulaz)
         return false;
      *broj = polje[izlaz];
      izlaz = (izlaz + 1) % MAX;
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