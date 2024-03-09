#include "TreeNode.h"
#include "iostream"

Node::Node(TipoElemento &data) {
    this->data = data;
    left  = right = nullptr;
}

void Node::Visit() const {
    std::cout<< data << " ";
}

//Miembros privados a través de funciones públicas
TipoElemento Node::GetData() const {return data;}
Node* Node::GetLeft() {return left;}
Node* Node::GetRight() {return right;}

void Node::SetLeft(Node *left) {this->left = left;}
void Node::SetRight(Node *right) {this->right = right;}
