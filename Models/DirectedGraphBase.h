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
    static const int MAX_VERTICES;
    Vertex** adjMatrix;
    virtual void InsertEdge(int origin, int destiny) = 0; // se iguala a 0 para que sea una función puramente virtual, sujeta a modificación de la clase concreta
    virtual void RemoveEdge(char origin, char destiny) = 0; // como va a diferir ligeramente el funcionamiento de un grafo con o sin peso, se hace esto
    void ReorganizeAdjList(); // ambos utilizan el mismo concepto de lista de adyancencia
    bool VertexExists(char name);
    void CreateVertex(char name);
    int FindVertexIndex(char name) const;
    virtual void AddEdge(int origin, int destiny) = 0;
    virtual void ShowList()= 0;
    virtual void DeleteEdge(char origin, char destiny) = 0;
    virtual void DeleteVertex(char name) = 0;





};


#endif //SI310_LABS_IDIRECTEDGRAPH_H
