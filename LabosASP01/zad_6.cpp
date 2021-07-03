#include <bits/stdc++.h>
using namespace std;

char *ostaviSlova(const string &ulaz)
{

   string result;
   int i = 0;

   for (const auto slovo : ulaz)
      if (isalpha(slovo))
      {
         result += slovo;
         i++;
      }

   auto ret = (char *)malloc(i * sizeof(char));
   memcpy(ret, result.c_str(), i);
   return ret;
}

int main()
{
   string niz = "asp12_i_ASP13";
   cout << ostaviSlova(niz);
}