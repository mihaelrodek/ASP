#include <bits/stdc++.h>
using namespace std;

void f(int *polje, int n, int m)
{
   if (n == 0)
   {
      polje[n] = 1;
   }
   else
   {
      polje[n] = pow(m, n);
      f(polje, n - 1, m);
   }
}

int main()
{
   int n, m;
   cout << "Unesi n: ";
   cin >> n;
   cout << "Unesi m: ";
   cin >> m;

   int *polje = new int[n];
   f(polje, n, m);

   for (auto i = 0; i < n; i++)
   {
      cout << polje[i] << "\n";
   }

   delete[] polje;
   return 0;
}