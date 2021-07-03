#include <bits/stdc++.h>
using namespace std;

class Stog
{
private:
   static const int MAX = 100;
   int stog[MAX];
   int top = -1;

public:
   bool dodaj(int broj)
   {
      if (top >= MAX)
         return false;
      stog[++top] = broj;
      return true;
   }
};

int main()
{
   Stog stog;
   srand(time(NULL));

   for (int i = 0; i < 101; i++)
   {
      stog.dodaj(rand() % 10 + 1);
   }
}