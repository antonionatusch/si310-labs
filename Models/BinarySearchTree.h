#include "TreeNode.h"

class BinarySearchTree {
private:
    TreeNode *root;

    TreeNode* Insert(TreeNode *r, TipoElemento &data);
    void Preorder(TreeNode* r);
    void InOrder(TreeNode *r);
    void PostOrder(TreeNode *r);
    int Height(TreeNode *r);
    bool isFull(TreeNode *r);


public:
    BinarySearchTree(); void Insert(TipoElemento data);
    void PreOrder(); void InOrder(); void PostOrder();
    void MultiInsert(int n); bool isEmpty(); int Height(); bool isFull();
};


