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
    std::cout<<"El elemento 7 se encuentra ubicado en el nodo con la siguiente dirección de memoria:"<<avl.Find(7);


    return 0;
}