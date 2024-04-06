#include "AvlNode.h"
class AvlTree {
private:
    AvlNode* root;
    AvlNode* LLRotation(AvlNode* first, AvlNode* next);
    AvlNode* RRRotation(AvlNode* first, AvlNode* next);
    AvlNode* LRRotation(AvlNode* first, AvlNode* next);
    AvlNode* RLRotation(AvlNode* first, AvlNode* next);
    AvlNode* AvlInsert(AvlNode *r, TipoElemento data, bool &heightChanged);
    void Preorder(AvlNode *r);
    void InOrder(AvlNode *r);
    void PostOrder(AvlNode *r);
    AvlNode* Find(AvlNode* subRoot, TipoElemento &searched);
public:
    AvlTree();
    void Insert(TipoElemento data);
    void MultiInsert(int n);
    void Preorder();
    void InOrder();
    void PostOrder();
    AvlNode* Find(TipoElemento searched);
};

