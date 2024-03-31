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
    g.AddEdge('A', 'D');
    g.AddEdge('B', 'C');
    g.AddEdge('A', 'C');
    g.AddEdge('D', 'C');

    g.CreateVertex('D');
    g.CreateVertex('E');
    g.CreateVertex('F');

    g.AddEdge('D', 'E');
    g.AddEdge('D', 'A');
    g.AddEdge('D', 'F');

    // Imprimir el grafo
    g.ShowList();




    return 0;
}