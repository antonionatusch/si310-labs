#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/LinkedList.h"
#include "Models/Stacks.h"
#include "Models/Queues.h"
#include "Models/UndirectedGraph.h"
#include "Models/UndirectedWeightedGraph.cpp"

int main(){

    std::cout << "UndirectedGraph " << std::endl;

    UndirectedGraph g(6);

    g.CreateVertex('A');
    g.CreateVertex('B');
    g.CreateVertex('C');
    g.CreateVertex('D');

    g.AddEdge('A', 'D');
    g.AddEdge('C', 'D');
    g.AddEdge('A', 'B');
    g.AddEdge('A', 'C');

    g.ShowList();

    std::cout<< "BFS" << std::endl;
    g.BFS('C');
    std::cout<< "DFS" << std::endl;
    g.DFS('C');

    std::cout << "UndirectedWeightedGraph " << std::endl;

    UndirectedWeightedGraph graph;

    graph.createVertex('A');
    graph.createVertex('B');
    graph.createVertex('C');
    graph.createVertex('D');
    graph.createVertex('E');
    graph.createVertex('F');

    graph.addEdge('A', 'B', 10);
    graph.addEdge('A', 'C',11);
    graph.addEdge('B', 'E',12);
    graph.addEdge('D', 'E',5);
    graph.addEdge('E', 'F',3);
    graph.addEdge('D', 'F',6);

    graph.showList();

    // Ejemplo de uso de otros métodos
    std::cout << "BFS" << "\n";
    graph.bfs('C');
    std::cout << "DFS" << "\n";
    graph.dfs('C');
    std::cout << "Dijkstra" << std::endl;
    graph.dijkstra('A');


    return 0;
}