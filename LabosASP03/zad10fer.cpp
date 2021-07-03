#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

class MinGomila
{
private:
   int size;
   string *elements;
   int j;

   void insert()
   {
      int i, k;
      string noviElementindex;
      k = this->j;
      i = this->j / 2;
      noviElementindex = this->elements[this->j];
      while ((i > 0) && (this->elements[i].compare(noviElementindex) < 0))
      {
         this->elements[k] =
             this->elements[i]; // push parent to the lower level
         k = i;
         i /= 2; // parent of A[i] is at A[i/2]
      }
      this->elements[k] = noviElementindex;
   }

public:
   MinGomila(int n)
   {
      this->size = n;
      this->elements = new string[n + 1];
      this->j = 1;
   }
   void add(string &element)
   {
      if (this->j >= (this->size + 1))
         throw std::runtime_error("Heap space is full.");
      this->elements[this->j] = element;
      this->insert();
      this->j++;
   }

   string top() { return this->elements[1]; }

   void Print()
   {
      int i = 1;
      int k = 1;
      while (i < this->size)
      {
         for (; i <= pow(2, k) - 1 && i < this->size; i++)
         {
            cout << " " << this->elements[i] << " ";
         }
         k++;
         cout << endl;
      }
   }
};