#include <bits/stdc++.h>
using namespace std;

class Stog
{
private:
   static const int MAX = 10;
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

   bool skini(int &broj)
   {
      if (top < 0)
         return false;
      broj = stog[top--];
      return true;
   }
};

int main()
{
   Stog stog1, stog2;
   int num;
   srand(time(NULL));

   for (int i = 0; i < 10; i++)
      stog1.dodaj(rand() % 10 + 1);

   while (stog1.skini(num))
      stog2.dodaj(num);

   while (stog2.skini(num))
      cout << num << " ";
}