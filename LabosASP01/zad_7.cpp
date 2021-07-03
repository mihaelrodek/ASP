#include <bits/stdc++.h>

using namespace std;

int *sqShuffle(int *niz, int n)
{

   //unsigned seed = 0;
   random_shuffle(&niz[0], &niz[n]);

   for (auto i = 0; i < n; i++)
   {
      niz[i] = niz[i] * niz[i];
   }

   return niz;
}

int main(void)
{
   int *polje, n;

   cout << "Upisite koliko clanova ima niz: ";
   cin >> n;

   polje = (int *)malloc(sizeof(int) * n);

   cout << "Unesite clanove polja: ";

   for (auto i = 0; i < n; i++)
   {
      cin >> polje[i];
   }

   sqShuffle(polje, n);

   for (auto i = 0; i < n; i++)
   {
      cout << polje[i] << "\n";
   }
   return 0;
}
