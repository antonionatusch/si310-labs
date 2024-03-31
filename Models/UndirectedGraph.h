//
// Created by dylan_tmut0bm on 30/3/2024.
//

#ifndef SI310_LABS_UNDIRECTEDGRAPH_H
#define SI310_LABS_UNDIRECTEDGRAPH_H
#include "Vertex.h"

class UndirectedGraph {
private:
    int v;  //number of vertices
    Vertex** adj; //adjacency matrix
public:
    UndirectedGraph(int v); ~UndirectedGraph();
    void CreateVertex(char name); bool VertexExists(char name);
    void CreateEdge(char origin, char destiny);
    int GetPosition(char name); void ShowList();
};


#endif //SI310_LABS_UNDIRECTEDGRAPH_H
