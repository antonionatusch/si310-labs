#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/Queues.h"
#include "Models/Stacks.h"
#include "Models/LinkedList.h"
#include "Models/AvlTree.h"
#include "Models/BinaryTree.h"
int main() {
    int op;

    do
    {
        std::cout<<"\n MENU PRINCIPAL \n";
        std::cout<<"1.- Árbol AVL \n";
        std::cout<<"2.- Árbol Binario de Búsqueda \n";
        std::cout<<"3.- Árbol Binario \n";
        std::cout<<"Digite alguna opción para ejecutarla o \"0\" para salir... ";
        std::cin>>op;
        while(std::cin.fail()){
            std::cout<<"Se introdujo un valor no numérico, intente de nuevo. \n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin>>op;
        }
        switch (op) {
            case 1:
                AvlTree().Menu();
                break;
            case 2:
                BinarySearchTree().Menu();
                break;
            case 3:
                BinaryTree().ShortDemo();
                break;
            case 0:
                std::cout<<"Hasta luego.";
                break;
            default:
                std::cout<<"No existe esa opción, intente de nuevo...";
                break;
        }
    }
    while (op != 0);

    return 0;
}






