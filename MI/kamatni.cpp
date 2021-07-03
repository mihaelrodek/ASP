#include <bits/stdc++.h>
using namespace std;

float kamrac(float g, int n, float p)
{ // g – glavnica
   // n – trajanje oročenja u godinama
   // p – kamatna stopa u postotcima
   if (n <= 0)
      return g;
   else
      return (1 + p / 100) * kamrac(g, n - 1, p);
}

float kamracRec(float g, int n, float p, float rez)
{
   if (n <= 0)
      return g * rez;
   float percentage = (1 + p / 100);
   rez = percentage * rez;
   return kamracRec(g, n - 1, p, rez);
}
int main()
{
   cout << kamrac(1100, 9, 3);
   cout << kamracRec(1100, 9, 3, 1.0);
   cin.get();
   return 0;
}