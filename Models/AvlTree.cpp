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