#include <bits/stdc++.h>
using namespace std;

bool provjeriKvadrat(int x)
{
   float e = 1e-6;
   if (x < 0)
      return false;
   if (x < 2)
      return true;

   //zbog zapisa broja provjeravam ako je res manji od neke epsilon okoline
   auto kvadrat = sqrt(x);
   auto res = kvadrat - floor(kvadrat);
   return res < e;
}

int zbrojiKvadrate(int polje[], int n)
{
   if (n == 0)
      return 0;

   int y = *polje;

   return (provjeriKvadrat(y) ? y : 0) + zbrojiKvadrate(polje + 1, n - 1);
}

int main()
{
   int k;
   cout << "Unesite broj clanova polja:";
   cin >> k;
   int *array = new (nothrow) int[k];

   srand(time(NULL));

   for (int i = 0; i < k; i++)
   {
      array[i] = rand() % 100 + 1;
   }
   cout << "Clanovi polja su: ";
   for (int i = 0; i < k; i++)
   {
      cout << array[i] << " ";
   }
   cout << "\n"
        << "A zbroj kvadrata je: " << zbrojiKvadrate(array, k);

   delete[] array;
}