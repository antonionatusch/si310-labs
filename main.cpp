#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/LinkedList.h"
#include "Models/Stacks.h"
#include "Models/Queues.h"
#include "Models/UndirectedGraph.h"

int main(){

     UndirectedGraph g(4);

    g.CreateVertex('A');
    g.CreateVertex('B');
    g.CreateVertex('C');
    g.CreateVertex('D');

    g.AddEdge('A', 'D');
    g.AddEdge('C', 'D');
    g.AddEdge('A', 'B');
    g.AddEdge('A', 'C');

    g.ShowList();

    g.BFS('C');





    return 0;
}