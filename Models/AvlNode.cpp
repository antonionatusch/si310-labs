#include "AvlNode.h"
#include "iostream"

AvlNode::AvlNode(TipoElemento &data) {
    this->data = data;
    left = right = nullptr;
    balanceFactor = 0;
}

void AvlNode::Visit() const {
    std::cout<< data << " ";
}


//Miembros privados a través de funciones públicas
TipoElemento AvlNode::GetData() const {return data;}
AvlNode* AvlNode::GetLeft() {return left;}
AvlNode* AvlNode::GetRight() {return right;}

void AvlNode::SetLeft(AvlNode *left) {this->left = left;}
void AvlNode::SetRight(AvlNode *right) {this->right = right;}

void AvlNode::SetData(TipoElemento newData) {data = newData;}

int AvlNode::GetBalanceFactor() {return balanceFactor;}

void AvlNode::SetBalanceFactor(int newBalanceFactor) {this->balanceFactor = newBalanceFactor;}