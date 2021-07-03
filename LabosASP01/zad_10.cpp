#include <bits/stdc++.h>
using namespace std;

double f(double z, int k)
{
   if (k == 0)
      return z;
   else
   {
      return ((-1) * f(z, (k - 1)) * z * z / ((2 * k + 1) * 2 * k));
   }
}

int main(void)
{
   double z;
   int k;

   z = 0.5;

   for (k = 0; k < 10; k++)
   {
      cout << f(z, k) << "\n";
   }
   return 0;
}
