#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/Queues.h"
#include "Models/Stacks.h"
#include "Models/LinkedList.h"
int main() {
    int n;
   BinarySearchTree bst;

   std::cout<<"Digite la cantidad de elementos: ";
   std::cin>>n;

   bst.MultiInsert(n);

   bst.InOrder();
    // holag

    return 0;
}