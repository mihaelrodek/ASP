#include <bits/stdc++.h>
using namespace std;

int provjeri_sortiranost(int *niz, int n)
{
   if (n <= 1)
      return 1;

   if (niz[n - 2] > niz[n - 1])
      return 0;
   return provjeri_sortiranost(niz, n - 1);
}

int main()
{
   int niz1[] = {1, 2, 3};
   std::cout << provjeri_sortiranost(niz1, 3) << std::endl;
   std::cin.get();
   return 0;
}