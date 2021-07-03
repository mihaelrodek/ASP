#include <bits/stdc++.h>
using namespace std;

template <typename T>
int binarnoTrazi(T polje[], int n, T x)
{

   auto low = 0;
   auto high = n - 1;
   auto ind = -1;

   while (low <= high)
   {
      auto mid = (low + high) / 2;
      if (polje[mid] < x)
      {
         low = mid + 1;
      }
      else if (polje[mid] > x)
      {
         high = mid - 1;
      }
      else
      {
         ind = mid;
         break;
      }
   }

   return ind;
}

int main()
{
   int n;
   float x;
   cout << "Unesite n: ";
   cin >> n;
   float *A = new (nothrow) float[n];

   for (int i = 0; i < n; i++)
   {
      A[i] = i * 1.1;
   }
   cout << "Unesite x koji trazite: ";
   cin >> x;

   if (binarnoTrazi(A, n, x) == -1)
   {
      cout << "Broj ne postoji." << endl;
   }
   else
      cout << "Trazeni broj je na " << binarnoTrazi(A, n, x) << ". mjestu" << endl;

   delete A;
}