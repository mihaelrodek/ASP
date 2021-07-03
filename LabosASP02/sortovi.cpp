#include <bits/stdc++.h>
using namespace std;
#define FORI(n)                  \
   for (int i = 0; i < (n); i++) \
      cout << A[i];              \
   cout << endl;

//swap1(a,b)
void swap1(int &a, int &b)
{
   int tmp = a;
   a = b;
   b = tmp;
}

//swap2(&a,&b)
void swap2(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

//SELECTION SORT
void SelectionSort(int A[], size_t n)
{
   size_t i, j, min;

   for (i = 0; i < n; i++)
   {
      min = i;
      for (j = i + 1; j < n; j++)
         if (A[j] < A[min])
            min = j;
      swap1(A[i], A[min]);
   }
}

//BUBBLE SORT
void BubbleSort(int A[], size_t n)
{
   size_t i, j;

   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - 1 - i; j++)
      {
         if (A[j + 1] < A[j])
            swap2(&A[j], &A[j + 1]);
      }
   }
}

//POBOLJSANI BUBBLE SORT
void PoboljsaniBubbleSort(int A[], size_t n)
{
   size_t i, j;
   bool swapped = 1;
   for (i = 0; swapped == 1; i++)
   {
      swapped = 0;
      for (j = 0; j < n - 1 - i; j++)
      {
         if (A[j + 1] < A[j])
         {
            swap2(&A[j], &A[j + 1]);
            swapped = 1;
         }
      }
   }
}

//INSERTION SORT
void InsertionSort(int A[], size_t n)
{
   size_t i, j;
   int temp;

   for (i = 1; i < n; i++)
   {
      temp = A[i];
      for (j = i; j >= 1 && A[j - 1] > temp; j--)
         A[j] = A[j - 1];
      A[j] = temp;
   }
}

//SHELL SORT
void ShellSort(int A[], size_t n)
{
   size_t i, j, step;
   int temp;

   for (step = n / 2; step > 0; step /= 2)
   {
      for (i = step; i < n; i++)
      {
         temp = A[i];
         for (j = i; j >= step && A[j - step] > temp; j -= step)
            A[j] = A[j - step];
         A[j] = temp;
      }
   }
}

//HIBBARDOV SHELL SORT
void HibbardShellSort(int A[], size_t n)
{
   size_t i, j, step;
   int temp;
   for (step = pow(2, (int)log2(n)); --step > 0; step /= 2)
   {
      for (i = step; i < n; i++)
      {
         temp = A[i];
         for (j = i; j >= step && A[j - step] > temp; j -= step)
            A[j] = A[j - step];
         A[j] = temp;
      }
      step++;
   }
}

int main()
{
   int *A = new int[10];
   cout << "Upisi brojeve: ";
   for (int i = 0; i < 10; i++)
   {
      cin >> A[i];
   }
   SelectionSort(A, 10);
   FORI(10)

   BubbleSort(A, 10);
   FORI(10)

   PoboljsaniBubbleSort(A, 10);
   FORI(10)

   InsertionSort(A, 10);
   FORI(10)

   ShellSort(A, 10);
   FORI(10)

   HibbardShellSort(A, 10);
   FORI(10)
}