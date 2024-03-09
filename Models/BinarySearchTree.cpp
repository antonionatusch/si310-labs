#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//Privado
Node* BinarySearchTree::Insert(Node *r, TipoElemento &data) {

    if(r == nullptr){
        return new Node(data);
    }

    if(data < r->GetData()){
        Node *left = Insert(r->GetLeft(), data);
        r->SetLeft(left);
    }
    else if(data > r->GetData()){
        Node* right = Insert(r->GetRight(), data);
        r->SetRight(right);
    }

    return r;

}

void BinarySearchTree::Preorder(Node *r) {
    if(r != nullptr){
        r->Visit();
        BinarySearchTree::Preorder(r->GetLeft());
        BinarySearchTree::Preorder(r->GetRight());
    }
}

void BinarySearchTree::InOrder(Node *r) {
    if(r != nullptr){
        BinarySearchTree::InOrder(r->GetLeft());
        r->Visit();
        BinarySearchTree::InOrder(r->GetRight());
    }
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