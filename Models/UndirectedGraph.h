#ifndef SI310_LABS_UNDIRECTEDGRAPH_H
#define SI310_LABS_UNDIRECTEDGRAPH_H
#include "Vertex.h"

class UndirectedGraph {
private:
    int v;  //number of vertices
    int numV; //curren number of vertices
    Vertex** adj; //adjacency matrix
    void InsertEdge(int origin, int destiny); // Cuando se llama a la función pública "AddEdge" (Código más legible)
    int GetPosition(char name); // Obtenemos la posición de un vértice en la función "AddEdge"
    void ReorganizeList(); //Reorganizamos la lista luego de borrar un vértice "DeleteVertex"

public:
    explicit UndirectedGraph(int v); ~UndirectedGraph();
    void CreateVertex(char name); bool VertexExists(char name);
    void AddEdge(char origin, char destiny); void DeleteVertex(char name);
    void ShowList(); void DeleteEdge(char origin, char destiny);
    void BFS(char startVertex);
};


#endif //SI310_LABS_UNDIRECTEDGRAPH_H
