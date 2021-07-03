#include <bits/stdc++.h>
using std::shared_ptr;

class BinarnoStablo
{
private:
   struct Node
   {
      std::string item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      Node(const std::string &item) : item(item), left(nullptr), right(nullptr) {}
      ~Node() {}
   };

protected:
   shared_ptr<Node> root;

   void insertStr(shared_ptr<Node> &, const std::string &);
   void traziNajveciStr(shared_ptr<Node> &, std::string &);
   void preorder(shared_ptr<Node> &);

public:
   BinarnoStablo() : root(nullptr) {}
   ~BinarnoStablo() {}
   void insertStr(const std::string &str) { insertStr(root, str); }
   void traziNajveciStr(std::string &str) { traziNajveciStr(root, str); };
   void preorder() { preorder(root); }
};

void BinarnoStablo::insertStr(shared_ptr<Node> &node, const std::string &str)
{
   if (node)
   {
      if (node->item.compare(str) < 0)
         insertStr(node->right, str);
      else if (node->item.compare(str) > 0)
         insertStr(node->left, str);
      else
         throw std::invalid_argument("Broj " + str +
                                     " vec se nalazi u stablu");
   }
   else
      node = std::make_shared<Node>(str);
}

void BinarnoStablo::preorder(shared_ptr<Node> &node)
{
   if (node)
   {
      std::cout << node->item << " ";
      preorder(node->left);
      preorder(node->right);
   }
}

void BinarnoStablo::traziNajveciStr(shared_ptr<Node> &node, std::string &str)
{
   if (node)
   {
      str = node->item;
      traziNajveciStr(node->right, str);
   }
   else
      return;
}

int main()
{
   BinarnoStablo stablo;
   std::string a;
   std::cout << "Unesi elemente: ";
   for (int i = 0; i < 10; i++)
   {
      std::cin >> a;
      stablo.insertStr(a);
   }
   std::cout << std::endl;
   stablo.traziNajveciStr(a);
   stablo.preorder();
}
