//
// Created by Antonio on 11/04/2024.
//
#include "DirectedGraphBase.h"
#ifndef SI310_LABS_DIRECTEDGRAPH_H
#define SI310_LABS_DIRECTEDGRAPH_H


class DirectedGraph : public DirectedGraphBase{

public:
    explicit DirectedGraph(int v); ~DirectedGraph();
    void ShowList();
    void InsertEdge(int origin, int destiny) override;
    void AddEdge(int origin, int destiny) override;
    void RemoveEdge(char origin, char destiny) override;
    void DeleteEdge(char origin, char destiny) override;
    void DeleteVertex(char name) override;
};


#endif //SI310_LABS_DIRECTEDGRAPH_H
