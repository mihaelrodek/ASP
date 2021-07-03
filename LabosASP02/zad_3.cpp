#include <bits/stdc++.h>
using namespace std;

struct Zapis
{
   int code;
   string name;
};

void obicanBubbleSort(Zapis A[], int n, char smjer)
{
   size_t i, j;
   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - 1 - i; j++)
      {
         if (smjer == '0' && A[j + 1].code < A[j].code)
            swap(A[j], A[j + 1]);
         if (smjer == '1' && A[j + 1].code > A[j].code)
            swap(A[j], A[j + 1]);
      }
   }
}

void swap(Zapis &i, Zapis &j)
{
   Zapis tmp = i;
   i = j;
   j = tmp;
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
      A[i].code = num;
      A[i].name = str;
   }
   cout << "\n";
   cout << "Unesi smjer sortiranja: ";
   cin >> smjer;

   obicanBubbleSort(A, n, smjer);

   for (int i = 0; i < n; i++)
   {
      cout << A[i].code << " " << A[i].name << "\n";
   }
}