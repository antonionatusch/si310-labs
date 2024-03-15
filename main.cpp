#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/Queues.h"
#include "Models/Stacks.h"
#include "Models/LinkedList.h"
int main(){

    LinkedList lista;
    lista.InsertarAlPrincipio(5);
    lista.Mostrar();

    BinarySearchTree bst;
    bst.Insert(5);
    bst.Insert(4);
    std::cout<<"\n";
    bst.InOrder();
    std::cout<<"\n";
    bst.PostOrder();

    // a

    return 0;
}