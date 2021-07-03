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
      return (double)*(xpot + n) / (double)*(fakt + n) + exp(x, n - 1, fakt, xpot);
   }
}

int main()
{

   double x;
   cout << "Unesi x";
   cin >> x;
   int n;
   cout << "Unesi n";
   cin >> n;

   double *A = new (nothrow) double[n];
   int *fakt = new (nothrow) int[n];
   double *xpot = new (nothrow) double[n];

   fakt[0] = 1;
   xpot[0] = 1;
   A[0] = (float)exp(x, 0, fakt, xpot);

   cout << "0. clan polja je: " << *A << "\n";

   for (auto i = 1; i <= n; i++)
   {
      *(fakt + i) = *(fakt + i - 1) * i;
      *(xpot + i) = *(xpot + i - 1) * (double)x;
      *(A + i) = (float)exp(x, i, fakt, xpot);
      cout << i << ". clan polja je: " << *(A + i) << "\n";
   }
}