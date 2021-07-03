#include <bits/stdc++.h>
using namespace std;

void Zamijeni(string *prvi, string *drugi)
{
   string tmp = *prvi;
   *prvi = *drugi;
   *drugi = tmp;
}

void BubleSortPoboljsani(string A[], int N, int smjer)
{
   size_t i, j;
   bool swapped = 1;
   for (i = 0; swapped == 1; i++)
   {
      swapped = 0;
      for (j = 0; j < N - 1 - i; j++)
      {
         if (smjer == '1' && A[j + 1] < A[j])
         {
            swap(A[j], A[j + 1]);
            swapped = 1;
         }
         if (smjer == '0' && A[j + 1] > A[j])
         {
            swap(A[j], A[j + 1]);
            swapped = 1;
         }
      }
   }
}

int main()
{
   char smjer;
   cout << "Unesi smjer: ";
   cin >> smjer;
   string str[4] = {"Ivo", "Marija", "Juraj", "Pero"};
   BubleSortPoboljsani(str, 4, smjer);
   for (int i = 0; i < 4; i++)
   {
      cout << str[i] << "  ";
   }
}