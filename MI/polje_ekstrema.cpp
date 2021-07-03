#include <bits/stdc++.h>
using namespace std;

int poljeEkstrema(int *A, int n)
{

   if (n <= 2)
   {
      return 1;
   }
   int uv1, uv2;
   if (poljeEkstrema(A, n - 1) == 1)
   {
      uv1 = (A[n - 3] < A[n - 2]) && (A[n - 2] > A[n - 1]);
      uv2 = (A[n - 3] > A[n - 2]) && (A[n - 2] < A[n - 1]);
      if (uv1 || uv2)
      {
         return 1;
      }
   }
   return 0;
}

int main()
{
}