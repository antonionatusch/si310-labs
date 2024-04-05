//
// Created by Antonio on 31/03/2024.
//

#include "AvlTree.h"
AvlTree::AvlTree() {
    root = nullptr;
}

// Privado
AvlNode *AvlTree::LLRotation(AvlNode *first, AvlNode *next) {
    first->SetLeft(next->GetRight());
    next->SetRight(first);
    if (next->GetBalanceFactor() == -1)
    {
        first->SetBalanceFactor(0);
        next->SetBalanceFactor(0);
    }
    else
    {
        first->SetBalanceFactor(-1);
        next->SetBalanceFactor(1);
    }
    return next;
}

AvlNode *AvlTree::RRRotation(AvlNode *first, AvlNode *next) {
    first->SetRight(next->GetLeft());
    next->SetLeft(first);

    if(next->GetBalanceFactor() == 1)
    {
        first->SetBalanceFactor(0);
        next->SetBalanceFactor(0);
    }
    else
    {
        first->SetBalanceFactor(1);
        next->SetBalanceFactor(-1);
    }
    return next;
}

AvlNode *AvlTree::LRRotation(AvlNode *first, AvlNode *next) {
    AvlNode* further;

    further = next->GetRight();
    first->SetLeft(further->GetRight());
    further->SetRight(first); // hasta aca, lo deja en rotación derecha derecha

    next->SetRight(further->GetLeft());
    further->SetLeft(next);

    if(further->GetBalanceFactor() == 1)
        next->SetBalanceFactor(-1);
    else
        next->SetBalanceFactor(0);

    if(further->GetBalanceFactor() == -1)
        first->SetBalanceFactor(1);
    else
        first->SetBalanceFactor(0);

    further->SetBalanceFactor(0); // se entiende que ya está equilibrado el nodo
    return further;
}

AvlNode *AvlTree::RLRotation(AvlNode *first, AvlNode *next) {
    AvlNode* further;

    further = next->GetLeft();
    first->SetRight(further->GetLeft());
    further->SetLeft(first);

    next->SetLeft(further->GetRight());
    further->SetRight(next);

    if (further->GetBalanceFactor() == 1)
        first->SetBalanceFactor(-1);
    else
        first->SetBalanceFactor(0);

    if(further->GetBalanceFactor() == -1)
        first->SetBalanceFactor(1);
    else
        first->SetBalanceFactor(0);
    further->SetBalanceFactor(0);
    return further;

}

AvlNode *AvlTree::AvlInsert(AvlNode *r, TipoElemento data, bool &heightChanged) {
    AvlNode* next;

    if (r == nullptr)
    {
        r = new AvlNode(data);
        heightChanged = true;
    }
    else if (data < r->GetData())
    {
        AvlNode* newLeft;
        newLeft = AvlInsert(r->GetLeft(), data, heightChanged);
        r->SetLeft(newLeft);
        if (heightChanged)
        {   // comprobamos primero si cambio de altura

            switch (r->GetBalanceFactor()) {

                case 1:
                    r->SetBalanceFactor(0);
                    heightChanged = false;
                    break;
                case 0:
                    r->SetBalanceFactor(-1);
                    break;
                case -1:
                    next = r->GetLeft();
                    if (next->GetBalanceFactor() == -1)
                        r = LLRotation(r, next);
                    else
                        r = LRRotation(r, next);
                    heightChanged = false;

            }
        }
    }
    else if (data > r->GetData())
    {
        AvlNode* newRight;
        newRight = AvlInsert(r->GetRight(), data, heightChanged);
        r->SetRight(newRight);

        if (heightChanged)
        {
            switch (r->GetBalanceFactor()) {
                case 1:
                    next = r->GetRight();
                    if (next->GetBalanceFactor() == 1)
                        r = RRRotation(r, next);
                    else
                        r = RLRotation(r, next);
                    heightChanged = false;
                    break;
                case 0:
                    r->SetBalanceFactor(1);
                    break;
                case -1:
                    r->SetBalanceFactor(0);
                    break;

            }
            
            
            
        }

    }
    else
        std::cout<<"No puede haber claves repetidas";
    return r;
}

void AvlTree::Preorder(AvlNode *r) {
    if (r != nullptr)
    {
        r->Visit();
        Preorder(r->GetLeft());
        Preorder(r->GetRight());
    }
}

void AvlTree::InOrder(AvlNode *r) {

    if (r != nullptr)
    {
        InOrder(r->GetLeft());
        r->Visit();
        InOrder(r->GetRight());
    }
}

void AvlTree::PostOrder(AvlNode *r) {

    if (r != nullptr)
    {
        PostOrder(r->GetLeft());
        PostOrder(r->GetRight());
        r->Visit();
    }

}

// Público
void AvlTree::Insert(TipoElemento data) {
    bool heightChanged = false;
    root = AvlInsert(root, data, heightChanged);
}

void AvlTree::MultiInsert(int n) {
    TipoElemento tmp;
    for (int i = 0; i < n; i++){
        std::cout<<"Elemento "<<i+1<<": ";
        std::cin>>tmp;
        Insert(tmp);
    }
}

void AvlTree::Preorder() {
    Preorder(root);
}

void AvlTree::InOrder() {
    InOrder(root);
}

void AvlTree::PostOrder() {
    PostOrder(root);
}






