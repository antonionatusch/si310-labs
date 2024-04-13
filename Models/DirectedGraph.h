//
// Created by Antonio on 11/04/2024.
//
#include "DirectedGraphBase.h"
#ifndef SI310_LABS_DIRECTEDGRAPH_H
#define SI310_LABS_DIRECTEDGRAPH_H


class DirectedGraph : public DirectedGraphBase{

public:
    explicit DirectedGraph(int v); ~DirectedGraph();
    void ShowList() override;
    void InsertEdge(int origin, int destiny);
    void AddEdge(char origin, char destiny);
    void AddEdges(int n);
    void DeleteEdge(char origin, char destiny) override;
    void DeleteVertex(char name) override;
    void DeleteEdges(int n);
};


#endif //SI310_LABS_DIRECTEDGRAPH_H