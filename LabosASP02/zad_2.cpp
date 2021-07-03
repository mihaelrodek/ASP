#include <bits/stdc++.h>
using namespace std;

void swap(int *i, int *j)
{
   int tmp = *i;
   *i = *j;
   *j = tmp;
}

void selection2Sort(int A[], int n, char smjer)
{
   int temp, min, max, i, j, k;
   for (i = 0, j = n - 1; i < j; i++, j--)
   {
      min = max = i;
      for (k = i; k <= j; k++)
      {
         if (A[k] < A[min])
            min = k;
         else if (A[k] > A[max])
            max = k;
      }
      if (smjer == '0')
      {
         swap(&A[i], &A[min]);
         if (A[i] == A[max])
            swap(&A[j], &A[min]);
         else
            swap(&A[j], &A[max]);
      }
      else
      {
         swap(&A[i], &A[max]);
         if (A[i] == A[min])
            swap(&A[j], &A[max]);
         else
            swap(&A[j], &A[min]);
      }
   }
}

int main()
{
   int n;
   char smjer;
   cout << "Upisi broj zapisa:";
   cin >> n;
   cout << "\n";

   int *A = new int[n];
   for (int i = 0; i < n; i++)
   {
      cin >> A[i];
   }
   cout << "\n";
   cout << "Unesi smjer sortiranja: ";
   cin >> smjer;

   selection2Sort(A, n, smjer);

   for (int i = 0; i < n; i++)
   {
      cout << A[i] << " ";
   }
}