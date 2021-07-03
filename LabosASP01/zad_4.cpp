#include <bits/stdc++.h>
using namespace std;

double exp(double x, int n, int *fakt, double *xpot)
{
   if (n == 0)
   {
      return 1;
   }
   else
   {
      return ((double)*(xpot + n) / ((double)*(fakt + n)) +
              exp(x, n - 1, fakt, xpot));
   }
}

int main()
{
   int n;
   double x;
   cout << "Unesi broj elemenata jednodimenzionalnog polja n: ";
   cin >> n;
   cout << "Unesi broj x";
   cin >> x;
   double *A = new (nothrow) double[n];
   double *xpot = new (nothrow) double[n];
   int *fakt = new (nothrow) int[n];

   *(fakt) = 1;
   *(xpot) = 1;
   *(A) = (float)exp(x, 0, fakt, xpot);

   cout << "0. clan polja je: " << *A << "\n";

   for (auto i = 1; i <= n; i++)
   {
      *(fakt + i) = *(fakt + i - 1) * i;
      *(xpot + i) = *(xpot + i - 1) * (double)x;
      *(A + i) = (float)exp(x, i, fakt, xpot);

      cout << i << ". clan polja je: " << *(A + i) << "\n";
   }

   delete[] A, xpot, fakt;
}