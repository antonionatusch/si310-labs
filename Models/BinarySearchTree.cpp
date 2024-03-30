#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//Privado
TreeNode* BinarySearchTree::Insert(TreeNode *r, TipoElemento &data) {

    if(r == nullptr){
        return new TreeNode(data);
    }

    if(data < r->GetData()){
        TreeNode *left = Insert(r->GetLeft(), data);
        r->SetLeft(left);
    }
    else if(data > r->GetData()){
        TreeNode* right = Insert(r->GetRight(), data);
        r->SetRight(right);
    }

    return r;

}



void BinarySearchTree::Preorder(TreeNode *r) {
    if(r != nullptr){
        r->Visit();
        BinarySearchTree::Preorder(r->GetLeft());
        BinarySearchTree::Preorder(r->GetRight());
    }
}

void BinarySearchTree::InOrder(TreeNode *r) {
    if(r != nullptr){
        BinarySearchTree::InOrder(r->GetLeft());
        r->Visit();
        BinarySearchTree::InOrder(r->GetRight());
    }
}

void BinarySearchTree::PostOrder(TreeNode *r) {
    if(r != nullptr){
        BinarySearchTree::PostOrder(r->GetLeft());
        BinarySearchTree::PostOrder(r->GetRight());
        r->Visit();
    }
}

int BinarySearchTree::Height(TreeNode *r) {
    if (r == nullptr)
        return 0;
    else
    {
        int leftHeight = Height(r->GetLeft());
        int rightHeight = Height(r->GetRight());
        if (leftHeight > rightHeight)
            return leftHeight + 1; // +1 por la raiz
        else
            return rightHeight + 1;
    }
}

bool BinarySearchTree::isFull(TreeNode *r) {
    if (r == nullptr)
        return true;
    else
        if (Height(r->GetLeft()) != Height(r->GetRight()))
            return false;
    return isFull(r->GetLeft()) && isFull(r->GetRight());


}

int BinarySearchTree::NodeCount(TreeNode *r) {
    if (r == nullptr)
        return 0;
    else
        return 1 + NodeCount(r->GetLeft()) + NodeCount(r->GetRight());
}

TreeNode *BinarySearchTree::Find(TreeNode *subRoot, TipoElemento &searched) {
    if (subRoot == nullptr)
        return nullptr;
    else if (searched == subRoot->GetData())
        return subRoot;
    else if (searched < subRoot->GetData())
        return Find(subRoot->GetLeft(), searched);
    else
        return Find(subRoot->GetRight(), searched);
}

//Público
void BinarySearchTree::Insert(TipoElemento data) {
    root = Insert(root, data);
}

void BinarySearchTree::PreOrder() {
    Preorder(root);
}

void BinarySearchTree::InOrder() {
    InOrder(root);
}

void BinarySearchTree::PostOrder() {
    PostOrder(root);
}

void BinarySearchTree::MultiInsert(int n) {
    TipoElemento tmp;
    for (int i = 0; i < n; i++){
        std::cout<<"Elemento "<<i+1<<": ";
        std::cin>>tmp;
        Insert(tmp);
    }
}

bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

int BinarySearchTree::Height() {
    return Height(root);
}

bool BinarySearchTree::isFull() {
    return isFull(root);
}

int BinarySearchTree::NodeCount() {
    return NodeCount(root);
}

TreeNode *BinarySearchTree::Find(TipoElemento searched) {
    return Find(root, searched);
}