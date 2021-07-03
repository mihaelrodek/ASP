#include <bits/stdc++.h>
using namespace std;

bool podnizuniz(string *niz, string *podniz, int pocetak)
{

   if (*niz == "\0")
      return false;
   if (*podniz == "\0")
      return true;

   static int j = 0;

   while (*(podniz + j) != "\0")
   {
      if (*(niz + pocetak) == *(podniz + j))
      {
         j++;
         return podnizuniz(niz, podniz, pocetak + 1);
      }
      else
         return false;
   }
   return true;
}

int main()
{
   string s1 = "dobro jutro";
   string s2 = "dobro";
   bool upit;
   upit = podnizuniz(&s1, &s2, 0);
   if (!upit)
      cout << "nije";
   else
      cout << "jeje";
   cout << endl;
   upit = podnizuniz(&s1, &s2, 3);
   if (!upit)
      cout << "nije";
   else
      cout << "jeje";
}