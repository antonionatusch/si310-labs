#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/Queues.h"
#include "Models/Stacks.h"
#include "Models/LinkedList.h"
#include "Models/AvlTree.h"
int main() {
    int n;

   AvlTree avl;
   avl.MultiInsert(5);
    avl.InOrder();


    return 0;
}