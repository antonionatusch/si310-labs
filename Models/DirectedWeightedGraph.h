//
// Created by Antonio on 12/04/2024.
//
#include "DirectedGraphBase.h"
#ifndef SI310_LABS_DIRECTEDWEIGHTEDGRAPH_H
#define SI310_LABS_DIRECTEDWEIGHTEDGRAPH_H


class DirectedWeightedGraph : public DirectedGraphBase{
public:
    int* weights;
    explicit DirectedWeightedGraph(int v); ~DirectedWeightedGraph();
    void ShowList() override;
    void DeleteEdge(char origin, char destiny) override;
    void DeleteVertex(char name) override;
    void AddEdge(char fromVertex, char toVertex, int weight);
    void InsertEdge(int originVertex, int destinyVertex, int weight);
    void AddEdges(int n);
    struct WeightedEdge {
        int destiny; // Vértice destino de la arista
        int weight; // Peso de la arista
        WeightedEdge* next; // Puntero al siguiente vértice adyacente
    };

};


#endif //SI310_LABS_DIRECTEDWEIGHTEDGRAPH_H
