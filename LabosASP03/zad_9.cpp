#include <cmath>
#include <iostream>
using namespace std;

class MinGomila
{
private:
   int size;
   int *elements;
   int j;

   void insert()
   {
      int i, k;
      int noviElementindex;
      k = this->j;
      i = this->j / 2;
      noviElementindex = this->elements[this->j];
      //promjeniti predznak za 10
      while ((i > 0) && (this->elements[i] > noviElementindex))
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
      this->elements = new int[n + 1];
      this->j = 1;
   }
   void add(int &element)
   {
      if (this->j >= (this->size + 1))
         throw std::runtime_error("Heap space is full.");
      this->elements[this->j] = element;
      this->insert();
      this->j++;
   }

   int top() { return this->elements[1]; }

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

int main()
{
   MinGomila g = MinGomila(10);
   int n;
   for (int i = 1; i <= 10; i++)
   {
      cout << "element: ";
      cin >> n;
      g.add(n);
   }
   cout << "elementi gomile :";
   g.Print();
   cout << endl
        << "najmanji je: " << g.top();
}