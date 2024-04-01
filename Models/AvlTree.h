#include "AvlNode.h"
class AvlTree {
private:
    AvlTree* root;
    AvlNode* LLRotation(AvlNode* first, AvlNode* next);
    AvlNode* RRRotation(AvlNode* first, AvlNode* next);
    AvlNode* LRRotation(AvlNode* first, AvlNode* next);
    AvlNode* RLRotation(AvlNode* first, AvlNode* next);
public:
    AvlTree();
};

