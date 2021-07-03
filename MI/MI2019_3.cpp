#include <bits/stdc++.h>
using namespace std;

void izbaciPocetneSamoglasnike(char **niz)
{
   if (**niz == '\0')
      return;
   if (**niz == 'a' || **niz == 'e' || **niz == 'i' || **niz == 'o' || **niz == 'u')
   {
      strcpy(*niz, *niz + 1);
      *niz = (char *)realloc(*niz, strlen(*niz) + 1);
      izbaciPocetneSamoglasnike(niz);
   }
   return;
}

int main()
{
   char *niz;
   niz = (char *)malloc(16 * sizeof(char));
   scanf("%[^\n]", niz);
   izbaciPocetneSamoglasnike(&niz);
   puts(niz);
}