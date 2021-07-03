#include <bits/stdc++.h>
using namespace std;

void spojiPolja(int A[], int B[], int Rez[], int n1, int n2)
{
   int br1 = 0, br2 = 0, i = 0;
   for (i; i < n1 + n2; i++)
   {
      if (A[br1] > B[br2])
      {
         Rez[i] = A[br1++];
      }
      else if (A[br1] < B[br2])
      {
         Rez[i] = B[br2++];
      }
      else
      {
         Rez[i] = A[br1++];
         Rez[i + 1] = B[br2++];
         i++;
      }
      if (br1 == n1 || br2 == n2)
         break;
   }
   i++;
   if (br1 == n1)
   {
      for (int j = br2; j < n2; j++)
         Rez[i++] = B[j];
   }
   else
   {
      for (int j = br1; j < n1; j++)
         Rez[i++] = A[j];
   }
}

int main()
{
   int A[] = {9, 7, 5, 3, 1};
   int n1 = sizeof(A) / sizeof(*A);
   int B[] = {8, 6, 4, 2, 0};
   int n2 = sizeof(B) / sizeof(*B);

   int *Rez = new int[n1 + n2 + 1];
   spojiPolja(A, B, Rez, n1, n2);

   for (int i = 0; i < n1 + n2; i++)
   {
      cout << Rez[i] << " ";
   }
}