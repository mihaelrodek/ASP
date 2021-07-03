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

   bool poljeURed(int polje[], int n)
   {
      Red r;
      if (n == 0)
         return true;
      if (r.dodaj(polje[n - 1]))
      {
         cout << "U red je dodan broj " << polje[n - 1] << endl;
         poljeURed(polje, n - 1);
      }
      return false;
   }
};

int main()
{
   Red red;
   srand(time(NULL));
   int polje[10];
   for (int i = 0; i < 10; i++)
   {
      polje[i] = rand() % 10 + 1;
   }
   for (int i = 0; i < 10; i++)
   {
      cout << polje[i] << " ";
   }
   cout << endl;

   red.poljeURed(polje, 10);
}