#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/LinkedList.h"
#include "Models/Stacks.h"
#include "Models/Queues.h"
#include "Models/UndirectedGraph.h"

int main(){

     UndirectedGraph g(4);

    // Crear vértices
    g.CreateVertex('A');
    g.CreateVertex('B');
    g.CreateVertex('C');
    g.CreateVertex('D');

    // Agregar aristas entre vértices existentes
    g.AddEdge('A', 'D');
    g.AddEdge('B', 'C');
    g.AddEdge('A', 'C');
    g.AddEdge('D', 'C');

    // Imprimir el grafo
    g.ShowList();

    //g.DeleteVertex('B');

    //g.ShowList();




    return 0;
}