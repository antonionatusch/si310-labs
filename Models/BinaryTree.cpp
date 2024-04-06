
#include "BinaryTree.h"
BinaryTree::BinaryTree() {
    root = nullptr;
}
// privado

void BinaryTree::PreOrder(VanillaTreeNode *r) {
    if (r != nullptr)
    {
        r->Visit();
        PreOrder(r->subárbolIzdo());
        PreOrder(r->subárbolDcho());
    }
}

void BinaryTree::InOrder(VanillaTreeNode *r) {

    if (r != nullptr)

    {
        InOrder(r->subárbolIzdo());
        r->Visit();
        InOrder(r->subárbolDcho());
    }

}

void BinaryTree::PostOrder(VanillaTreeNode *r) {

    if (r != nullptr)

    {
        PostOrder(r->subárbolIzdo());
        PostOrder(r->subárbolDcho());
        r->Visit();
    }

}

void BinaryTree::Empty(VanillaTreeNode *r) {
    if (r != nullptr)
    {
        Empty(r->subárbolIzdo());
        Empty(r->subárbolDcho());
        std::cout<< "\tNodo borrado. ";
        r = nullptr;
    }
}

VanillaTreeNode *BinaryTree::CopyTree(VanillaTreeNode *r) {
    VanillaTreeNode *copyRoot;

    if (r == nullptr)
        copyRoot = nullptr;
    else
    {
        VanillaTreeNode* leftCopy, *rightCopy;
        leftCopy = CopyTree(r->subárbolIzdo());
        rightCopy = CopyTree(r->subárbolDcho());
        copyRoot = new VanillaTreeNode(leftCopy, r->valorNodo(), rightCopy);
    }
    return copyRoot;
}

// publico
BinaryTree::BinaryTree(VanillaTreeNode *r) {
    root = r;
}

void BinaryTree::SetRoot(VanillaTreeNode *r) {
    root = r;
}

VanillaTreeNode *BinaryTree::GetRoot() {
    return root;
}

VanillaTreeNode BinaryTree::TreeRoot() {
    if(root)
        return *root;
    else
        throw " arbol vacio";
    std::cout<< " arbol vacio";

}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

VanillaTreeNode *BinaryTree::LeftChild() {
    if(root)
        return root->subárbolIzdo();
    else
        throw " arbol vacio";
}

VanillaTreeNode *BinaryTree::RightChild() {
    if(root)
        return root->subárbolDcho();
    else
        throw " arbol vacio";
}

VanillaTreeNode *BinaryTree::NewTree(VanillaTreeNode *leftBranch, TipoElemento data, VanillaTreeNode *rightBranch) {
    return new VanillaTreeNode(leftBranch, data, rightBranch);
}

void BinaryTree::ShortDemo() {
    BinaryTree a1, a2, a3, a4, a;

    VanillaTreeNode *n1, *n2, *n3, *n4;

    n1 = a1.NewTree(nullptr, 1, nullptr);
    n2 = a2.NewTree(nullptr, 6, nullptr);
    n3 = a3.NewTree(n1, 8, n2);

    n1 = a1.NewTree(nullptr, 9, nullptr);
    n2 = a2.NewTree(nullptr, 19, nullptr);
    n4 = a4.NewTree(n1, 11, n2);
    n1 = a1.NewTree(n3, 5, n4);
    a.SetRoot(n1);

    std::cout<<"Recorrido PreOrden: "<<"\n";
    a.PreOrder();
    std::cout<<"Recorrido PostOrden: "<<"\n";
    a.PostOrder();
    std::cout<<"Recorrido EnOrden: "<<"\n";
    a.InOrder();

    std::cout<<"Altura: "<<a.GetHeight()<<"\n";
    std::cout<<"Está lleno?: "<<a.checkIsFull()<<"\n";
    std::cout<<"Nodos en total: "<<a.GetNodes()<<"\n";

}

void BinaryTree::PreOrder() {
    PreOrder(root);
}

void BinaryTree::InOrder() {
    InOrder(root);
}

void BinaryTree::PostOrder() {
    PostOrder(root);
}

void BinaryTree::Empty() {
    Empty(root);
}

int BinaryTree::Height(VanillaTreeNode *r) {
    if (r == nullptr)
        return 0;
    else
    {
        int leftHeight = Height(r->subárbolIzdo());
        int rightHeight = Height(r->subárbolDcho());

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;

    }
}

bool BinaryTree::isFull(VanillaTreeNode *r) {
    if (r == nullptr)
        return true;
    else
        if (Height(r->subárbolIzdo()) != Height(r->subárbolDcho()))
            return false;
        return isFull(r->subárbolIzdo()) && isFull(r->subárbolDcho());
}

int BinaryTree::NodeCount(VanillaTreeNode *r) {
    if (r == nullptr)
        return 0;
    else
        return 1+ NodeCount(r->subárbolIzdo()) + NodeCount(r->subárbolDcho());
}

int BinaryTree::GetHeight() {
    return Height(root);
}

bool BinaryTree::checkIsFull() {
    return isFull(root);
}

int BinaryTree::GetNodes() {
    return NodeCount(root);
}