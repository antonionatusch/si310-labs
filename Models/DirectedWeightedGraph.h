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
    void Dijkstra(char startingPoint);
    void DeleteEdges(int n);
    void Menu();

};


#endif //SI310_LABS_DIRECTEDWEIGHTEDGRAPH_H
