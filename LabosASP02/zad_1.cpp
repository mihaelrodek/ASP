#include <bits/stdc++.h>
using namespace std;

struct Zapis
{
   int postnum;
   string name;
};

void insertionSort(Zapis *A, int n, char smjer)
{
   int i = 0;
   while (i < n)
   {
      int j = i;
      while (j > 0 && (smjer == '0' ? A[j - 1].postnum > A[j].postnum : A[j - 1].postnum < A[j].postnum))
      {
         Zapis t = A[j];
         A[j] = A[j - 1];
         A[j - 1] = t;
         j--;
      }
      i++;
   }
}

int main()
{
   int n, num;
   char smjer;
   string str;

   cout << "Upisi broj zapisa:";
   cin >> n;
   cout << "\n";

   Zapis *A = new Zapis[n];
   for (int i = 0; i < n; i++)
   {
      cin >> num >> str;
      A[i].postnum = num;
      A[i].name = str;
   }
   cout << "\n";
   cout << "Unesi smjer sortiranja: ";
   cin >> smjer;

   insertionSort(A, n, smjer);

   for (int i = 0; i < n; i++)
   {
      cout << A[i].postnum << A[i].name << "\n";
   }
}