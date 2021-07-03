#include <bits/stdc++.h>
using namespace std;

double pi(int n)
{
   if (n == 0)
      return 0;

   return 4 * (1. / (2 * n - 1) * (n % 2 ? 1 : -1)) + pi(n - 1);
}

int main()
{
   int k;
   double input;
   cout << "Unesite broj clanova polja:";
   cin >> k;

   double *A = new (nothrow) double[k];

   for (int i = 0; i < k; i++)
   {
      A[i] = pi(i + 1);
   }
   cout << "\n";
   cout << "Clanovi polja su: ";
   for (int i = 1; i <= k; i++)
   {
      cout << A[i] << " ";
   }
   delete[] A;
}