#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/LinkedList.h"
#include "Models/Stacks.h"
#include "Models/Queues.h"
#include "Models/UndirectedGraph.h"

int main(){

     UndirectedGraph g(3); // Crear un grafo con 5 vértices

    // Crear vértices
    g.CreateVertex('A');
    g.CreateVertex('B');
    g.CreateVertex('C');

    // Agregar aristas entre vértices existentes
    g.CreateEdge('A', 'B');
    g.CreateEdge('B', 'C');
    g.CreateEdge('A', 'C');



    // Imprimir el grafo
    g.ShowList();




    return 0;
}