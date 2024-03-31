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
   /* std::cout<<"El árbol es de altura "<<bst.Height()<<"\n";

   bst.isFull() ? std::cout<<"Arbol lleno \n" : std::cout<<"Arbol no está lleno \n";

   std::cout<<"El árbol tiene: "<<bst.NodeCount()<<" nodos.\n";

   std::cout<<"El elemento 7 está en el nodo con dirección: "<<bst.Find(7)<<"\n"; */

   std::cout<<"Eliminando el número 7 con dirección: "<<bst.Find(7)<<"\n";
   bst.Delete(7);

   std::cout<<"Comprobando que es un puntero nulo: "<<bst.Find(7);
   std::cout<<"Recorrido enorden post eliminación: \n";
   bst.InOrder();


    return 0;
}