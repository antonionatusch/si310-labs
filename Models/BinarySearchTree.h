#include "TreeNode.h"

class BinarySearchTree {
private:
    Node *root;

    Node* Insert(Node *r, TipoElemento &data);
    void Preorder(Node* r);
    void InOrder(Node *r);

public:
    BinarySearchTree(); void Insert(TipoElemento data);
    void PreOrder(); void InOrder();
};


