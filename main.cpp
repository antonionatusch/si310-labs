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
   std::cout<<"El árbol es de altura "<<bst.Height()<<"\n";

   bst.isFull() ? std::cout<<"Arbol lleno \n" : std::cout<<"Arbol no está lleno \n";

   std::cout<<"El árbol tiene: "<<bst.NodeCount()<<" nodos.\n";

    return 0;
}