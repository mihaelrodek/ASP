#include <bits/stdc++.h>
using namespace std;

string spojiStringove(string A, string B)
{
   int len1 = A.length();
   int len2 = B.length();
   string Rez;
   int br1 = 0, br2 = 0;

   for (int i = 0; i < len1 + len2; i++)
   {
      if (br1 < len1)
      {
         if (br2 < len2)
         {
            if (A[br1] > B[br2])
            {
               Rez += A[br1++];
            }
            else if (A[br1] < B[br2])
            {
               Rez += B[br2++];
            }
            else
            {
               Rez[i] = A[br1++];
               Rez[i + 1] = B[br2++];
               i++;
            }
         }
         else
            Rez += A[br1++];
      }
      Rez += B[br2++];
   }
   return Rez;
}

int main()
{
   string A = "ecaDB";
   string B = "dbECA";
   cout << spojiStringove(A, B);
}