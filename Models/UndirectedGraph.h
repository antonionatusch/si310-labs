#ifndef SI310_LABS_UNDIRECTEDGRAPH_H
#define SI310_LABS_UNDIRECTEDGRAPH_H
#include "Vertex.h"

class UndirectedGraph {
private:
    int v;  //number of vertices
    int numV; //curren number of vertices
    Vertex** adj; //adjacency matrix
    void Insert(int origin, int destiny);
    int GetPosition(char name);
    void ReorganizeList();

public:
    explicit UndirectedGraph(int v); ~UndirectedGraph();
    void CreateVertex(char name); bool VertexExists(char name);
    void AddEdge(char origin, char destiny); void DeleteVertex(char name);
    void ShowList();
};


#endif //SI310_LABS_UNDIRECTEDGRAPH_H
