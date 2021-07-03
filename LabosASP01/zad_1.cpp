#include <bits/stdc++.h>
using namespace std;

void ispis(float *polje, int n)
{
   if (n == 0)
      return;
   if (*polje < 0)
   {
      cout << *polje << " ";
   }
   return ispis(polje + 1, n - 1);
}

int main()
{

   int k, input;
   cout << "Unesite broj clanova polja:";
   cin >> k;

   float *array = new (nothrow) float[k];
   cout << "Unesite clanove polja: ";
   for (int i = 0; i < k; i++)
   {
      cin >> array[i];
   }
   ispis(array, k);

   delete[] array;
}