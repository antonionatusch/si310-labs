#include "TreeNode.h"
#include "iostream"

TreeNode::TreeNode(TipoElemento &data) {
    this->data = data;
    left  = right = nullptr;
}

void TreeNode::Visit() const {
    std::cout<< data << " ";
}



//Miembros privados a través de funciones públicas
TipoElemento TreeNode::GetData() const {return data;}
TreeNode* TreeNode::GetLeft() {return left;}
TreeNode* TreeNode::GetRight() {return right;}

void TreeNode::SetLeft(TreeNode *left) {this->left = left;}
void TreeNode::SetRight(TreeNode *right) {this->right = right;}

void TreeNode::SetData(TipoElemento newData) {data = newData;}
