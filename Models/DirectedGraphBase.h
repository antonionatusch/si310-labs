//
// Created by Antonio on 11/04/2024.
//
#include "Vertex.h"
#ifndef SI310_LABS_IDIRECTEDGRAPH_H
#define SI310_LABS_IDIRECTEDGRAPH_H


class DirectedGraphBase {
public:
    int totalVertices; // dylan: v
    int currentVertices; // dylan: numV
    Vertex** adjMatrix;
    void ReorganizeAdjList() const; // ambos utilizan el mismo concepto de lista de adyancencia
    bool VertexExists(char name) const;
    void CreateVertex(char name);
    int FindVertexIndex(char name) const;
    void CreateVertices(int n);
    void DeleteVertices(int n);
    virtual void ShowList()= 0;
    virtual void DeleteEdge(char origin, char destiny) = 0;
    virtual void DeleteVertex(char name) = 0;
    void BFS(char startVertex) const;
    void DFS(char startVertex) const;






};


#endif //SI310_LABS_IDIRECTEDGRAPH_H
