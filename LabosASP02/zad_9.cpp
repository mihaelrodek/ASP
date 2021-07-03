#include <bits/stdc++.h>
using namespace std;

class Vozilo
{
public:
   string model;
   int year;

   Vozilo() : model(string()), year(int()) {}
   Vozilo(string model, int year) : model(model), year(year) {}

   ~Vozilo(){};

   string getmodel() { return this->model; }
   unsigned short int getyear() { return this->year; }

   void setmodel(string model) { this->model = model; }
   void setyear(int year) { this->year = year; }

   bool operator<(const Vozilo &o1)
   {
      if (this->model < o1.model)
         return true;

      else if (this->model == o1.model && this->year > o1.year)
         return true;
      else
         return false;
   }

   Vozilo &operator=(Vozilo &o)
   {
      this->model = o.model;
      this->year = o.year;
      return o;
   }
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi)
{
   Vozilo tmp = prvi;
   prvi = drugi;
   drugi = tmp;
}

template <class T>
void SelectionSort(T A[], int N)
{
   int i, j, min;
   for (i = 0; i < N; i++)
   {
      min = i;
      for (j = i + 1; j < N; j++)
      {
         if (A[j] < A[min])
            min = j;
      }
      Zamijeni(A[i], A[min]);
   }
}

int main(void)
{
   Vozilo A[10];
   string model;
   int godina;
   for (int i = 0; i < 10; i++)
   {
      cout << "Unesi " << i + 1 << ". vozilo > ";
      cin >> model;
      A[i].setmodel(model);
      cin >> godina;
      A[i].setyear(godina);
   }

   SelectionSort(A, 10);
   for (int i = 0; i < 10; i++)
   {
      cout << "{" << A[i].model << "," << A[i].year << "} ";
   }

   return 0;
}