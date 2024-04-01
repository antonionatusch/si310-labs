//
// Created by Antonio on 31/03/2024.
//

#include "AvlTree.h"
AvlTree::AvlTree() {
    root = nullptr;
}

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

