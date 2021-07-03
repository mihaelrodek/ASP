#include <bits/stdc++.h>
using std::shared_ptr;

int small;
class BinarnoStablo
{

private:
   struct Node
   {
      int data;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const int &data) : data(data), left(nullptr), right(nullptr) {}
      ~Node() {}
   };

protected:
   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const int &);
   int najmanji(shared_ptr<Node> &);
   void inorder(shared_ptr<Node> &);

public:
   void insert(const int &broj) { insert(root, broj); };
   int najmanji() { return najmanji(root); }
   void inorder() { inorder(root); }
};

void BinarnoStablo::insert(shared_ptr<Node> &node, const int &item)
{
   if (node)
   {
      if (node->data < item)
         insert(node->right, item);
      else if (node->data > item)
         insert(node->left, item);
      else
         throw std::invalid_argument("Broj " + std::to_string(item) +
                                     "se nalazi u stablu");
   }
   else
      std::make_shared<Node>(item);
}

void BinarnoStablo::inorder(shared_ptr<Node> &node)
{
   if (node)
   {
      inorder(node->left);
      std::cout << node->data << " ";
      inorder(node->right);
   }
   return;
}

int BinarnoStablo::najmanji(shared_ptr<Node> &node)
{
   if (node)
   {
      small = node->data;
      najmanji(node->left);
   }
   return small;
}

int main()
{

   BinarnoStablo stablo;
   int a;
   for (int i = 0; i < 10; i++)
   {
      std::cin >> a;
      stablo.insert(a);
   }

   std::cout << stablo.najmanji();
   std::cout << std::endl;
   stablo.inorder();
}