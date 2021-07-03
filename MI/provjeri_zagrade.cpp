#include <bits/stdc++.h>
using namespace std;

int provjeriZagrade(char *niz, int *zastavica)
{
   if (*niz == '\0')
   {
      return (*zastavica == 0 ? 1 : 0);
   }
   else
   {
      if (*niz == '[')
         ++(*zastavica);
      else
         --(*zastavica);
      return provjeriZagrade(niz + 1, zastavica);
   }
}
int main()
{
   int zastavica = 0;
   if (provjeriZagrade("[[]", &zastavica) == 1)
   {
      cout << "Sve zagrade su uparene";
   }
   else
   {
      cout << "Neke zagrade nisu uparene";
   }
   cin.get();
}