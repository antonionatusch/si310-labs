#include <VanillaTreeNode.h>
class BinaryTree {
private:
    VanillaTreeNode *root;
    void PreOrder(VanillaTreeNode *r);
    void InOrder(VanillaTreeNode *r);
    void PostOrder(VanillaTreeNode *r);
    void Empty(VanillaTreeNode *r);
    VanillaTreeNode* CopyTree(VanillaTreeNode *r);
public:
    BinaryTree(); BinaryTree(VanillaTreeNode *r);
    void SetRoot(VanillaTreeNode *r);
    VanillaTreeNode* GetRoot();
    VanillaTreeNode TreeRoot();
    bool isEmpty();
    VanillaTreeNode* LeftChild();
    VanillaTreeNode* RightChild();
    VanillaTreeNode* NewTree(VanillaTreeNode* leftBranch, TipoElemento data, VanillaTreeNode *rightBranch);
    void ShortDemo();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void Empty();
    int Height(VanillaTreeNode* r);
    bool isFull(VanillaTreeNode* r);
    int NodeCount(VanillaTreeNode* r);
    void CopyTree(BinaryTree &a);
    int GetHeight();
    bool checkIsFull();
    int GetNodes();
};


