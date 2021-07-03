#include <bits/stdc++.h>
using std::shared_ptr;

class BinarnoStablo
{
private:
   struct Node
   {
      int item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const int &item) : item(item), left(nullptr), right(nullptr) {}
      ~Node() {}
   };

protected:
   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const int &);
   void traziNajmanji(shared_ptr<Node> &, int &);
   void inorder(shared_ptr<Node> &);

public:
   BinarnoStablo() : root(nullptr) {}
   ~BinarnoStablo() {}

   void insert(const int &novi) { insert(root, novi); }
   void traziNajmanji(int &broj) { traziNajmanji(root, broj); }
   void inorder() { inorder(root); }
};

void BinarnoStablo::insert(shared_ptr<Node> &node, const int &novi)
{
   if (node)
   {
      if (node->item < novi)
         insert(node->right, novi);
      else if (node->item > novi)
         insert(node->left, novi);
      else
         throw std::invalid_argument("Broj " + std::to_string(novi) +
                                     "se nalazi u stablu");
   }
   else
      node = std::make_shared<Node>(novi);
}

void BinarnoStablo::traziNajmanji(shared_ptr<Node> &node, int &broj)
{
   if (node)
   {
      broj = node->item;
      traziNajmanji(node->left, broj);
   }

   return;
}

void BinarnoStablo::inorder(shared_ptr<Node> &node)
{
   if (node)
   {
      inorder(node->left);
      std::cout << node->item << " ";
      inorder(node->right);
   }

   return;
}

int main()
{
   BinarnoStablo stablo;
   int a;
   std::cout << "Unesi elemente: ";
   for (int i = 0; i < 10; i++)
   {
      std::cin >> a;
      stablo.insert(a);
   }
   std::cout << std::endl;
   stablo.traziNajmanji(a);

   stablo.inorder();
}