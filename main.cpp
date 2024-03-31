#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/LinkedList.h"
#include "Models/Stacks.h"
#include "Models/Queues.h"
#include "Models/UndirectedGraph.h"

int main(){

     UndirectedGraph g(5);

    // Crear vértices
    g.CreateVertex('A');
    g.CreateVertex('B');
    g.CreateVertex('C');

    // Agregar aristas entre vértices existentes
    g.CreateEdge('A', 'D');
    g.CreateEdge('B', 'C');
    g.CreateEdge('A', 'C');
    g.CreateEdge('D', 'C');

    g.CreateVertex('D');
    g.CreateVertex('E');
    g.CreateVertex('F');

    g.CreateEdge('D', 'E');
    g.CreateEdge('D', 'A');
    g.CreateEdge('D', 'F');

    // Imprimir el grafo
    g.ShowList();




    return 0;
}