#include <bits/stdc++.h>
using namespace std;

void ShellSort_Hibbard(string A[], int N, int smjer)
{
   size_t i, j, step;
   string temp;

   for (step = pow(2, (int)log2(N)); --step > 0; step /= 2)
   {
      for (i = step; i < N; i++)
      {
         temp = A[i];
         if (smjer == '1')
         {
            for (j = i; j >= step && A[j - step] > temp; j -= step)
            {
               A[j] = A[j - step];
            }
         }
         else if (smjer == '0')
         {
            for (j = i; j >= step && A[j - step] < temp; j -= step)
            {
               A[j] = A[j - step];
            }
         }
         A[j] = temp;
      }
      step++;
   }
}

int main()
{
   char smjer;
   cout << "Unesi smjer: ";
   cin >> smjer;
   string str[4] = {"Ivo", "Marija", "Juraj", "Pero"};
   ShellSort_Hibbard(str, 4, smjer);
   for (int i = 0; i < 4; i++)
   {
      cout << str[i] << "  ";
   }
}