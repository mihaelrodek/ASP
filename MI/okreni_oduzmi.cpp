#include <bits/stdc++.h>
using namespace std;

void okreni_oduzmi(int *a, int m, int n)
{
   if (m < n)
   {
      okreni_oduzmi(a, m + 1, n);
   }
   cout << a[m] - a[0] << " ";
}
int main()
{
   int A[] = {2, 6, 8, 11, -3, 100};
   okreni_oduzmi(A, 0, 4);
   cin.get();
   return 0;
}
