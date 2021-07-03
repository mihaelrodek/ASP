#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class SanitizedString
{
   string str;

public:
   SanitizedString() {}
   SanitizedString(string str) : str(str) {}
   ~SanitizedString() {}

   void removeDuplicateWhitespace()
   {
      for (auto i = 0; i < this->str.size(); i++)
         if (this->str[i] == ' ' && this->str[i + 1] == ' ')
         {
            this->str.erase(i, 1);
            i--; // za vise od dvije praznize
         }
   }

   void removeNonAplhaChars()
   {
      string result;
      for (auto i = 0; i < this->str.size(); i++)
         if (isalpha((char)this->str[i]))
            result += str[i];

      this->str = result;
   }

   string getString()
   {
      return this->str;
   }

   friend ostream &operator<<(ostream &os, const SanitizedString &s)
   {
      os << s.str;
      return os;
   }
};

int main(void)
{
   string str;
   cout << "Upisi string > ";
   getline(cin, str);

   SanitizedString s = str;

   cout << "Pocetni string : " << s << endl;
   s.removeDuplicateWhitespace();
   cout << "String bez duplih prazniza : " << s << endl;
   s.removeNonAplhaChars();
   cout << "String bez znakova : " << s << endl;

   return 0;
}
