#include <bits/stdc++.h>
using namespace std;

class Stog
{
private:
   static const size_t increment = 100;
   int size = 100;
   int *stog;
   int top = -1;

public:
   Stog() { stog = (int *)malloc(size * sizeof(int)); }
   Stog(size_t size) : size(size) { (int *)malloc(size * sizeof(int)); }

   bool dodaj(int broj)
   {
      if (top >= size)
      {
         int *tmp = (int *)realloc(stog, (size + increment) * sizeof(int));
         if (!tmp)
            return false;
         stog = tmp;
         size += increment;
      }
      stog[++top] = broj;
      cout << "Broj " << broj << " dodan na stog..." << endl;
      return true;
   }
};

int main()
{
   Stog stog;
   srand(time(NULL));

   for (int i = 0; i < 105; i++)
   {
      cout << "Dodajem " << i + 1 << " ";
      stog.dodaj(rand() % 10 + 1);
   }
}