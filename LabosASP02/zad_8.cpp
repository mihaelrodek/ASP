#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <class T>
void InsertionSort(T A[], int n)
{
   size_t i, j;
   T temp;
   for (i = 1; i < n; i++)
   {
      temp = A[i];
      for (j = i; j >= 1 && temp < A[j - 1]; j--)
         A[j] = A[j - 1];
      A[j] = temp;
   }
}

class Osoba
{
public:
   string name;
   unsigned short int age;

   Osoba() : name(string()), age(0) {}
   Osoba(string name, unsigned short int age) : name(name), age(age) {}

   string getName() { return this->name; }
   unsigned short int getAge() { return this->age; }

   void setName(string name) { this->name = name; }
   void setAge(unsigned short int age) { this->age = age; }

   bool operator<(Osoba &o1)
   {
      if (this->age < o1.age)
         return true;

      else if (this->age == o1.age && this->name < o1.name)
         return true;
      else
         return false;
   }

   Osoba &operator=(Osoba &o)
   {
      this->name = o.name;
      this->age = o.age;
      return o;
   }

   ~Osoba() {}
};

int main()
{
   Osoba A[10];
   string name;
   int age;
   for (int i = 0; i < 10; i++)
   {
      cout << "Unesi " << i + 1 << ". osobu > ";
      cin >> name;
      A[i].setName(name);
      cin >> age;
      A[i].setAge(age);
   }
   InsertionSort(A, 10);
   for (int i = 0; i < 10; i++)
   {
      cout << "{" << A[i].name << "," << A[i].age << "} ";
   }
   return 0;
}