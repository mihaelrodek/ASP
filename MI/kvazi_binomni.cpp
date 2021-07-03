#include <bits/stdc++.h>
using namespace std;

int kvazi_binomni(int n, int m)
{

   if ((n == m) || m == 0)
      return 1;
   if (n < m || m > n)
      return 0;
   return kvazi_binomni(n - 1, m - 1) + m * kvazi_binomni(n, m);
};

int main()
{
}