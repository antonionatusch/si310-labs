//
// Created by dylan_tmut0bm on 30/3/2024.
//

#include "UndirectedGraph.h"
#include "iostream"

UndirectedGraph::UndirectedGraph(int v) {
    this->v = v;

    adj = new Vertex * [v];
    for(int i = 0; i < v; i++){
        adj[i] = nullptr;
    }

}

UndirectedGraph::~UndirectedGraph() {
    for (int i = 0; i < v; ++i) {
        Vertex* actual = adj[i];
        while (actual) {
            Vertex* n = actual->next;
            delete actual;
            actual = n;
        }
    }
    delete[] adj;
}

int UndirectedGraph::GetPosition(char name) {
    for (int i = 0; i < v; ++i) {
        if (adj[i] && adj[i]->name == name) return i;
    }
    return -1;
}

bool UndirectedGraph::VertexExists(char name) {
    for (int i = 0; i < v; ++i) {
        if (adj[i] && adj[i]->name == name) return true;
    }
    return false;
}

void UndirectedGraph::CreateVertex(char name) {
    if(!VertexExists(name)){
        for (int i = 0; i < v; ++i) {
            if (!adj[i]) {
                adj[i] = new Vertex(name);
                std::cout << "Vertice " << name << " creado." << std::endl;
                return;
            }
        }
    }
    std::cout << "Can't create more vertices" << std::endl;
}

void UndirectedGraph::CreateEdge(char origin, char destiny) {

    bool ori = VertexExists(origin);
    bool des = VertexExists(destiny);

    if(!ori || !des){
        std::cout<<"An Edge can't be created, a vertex doesn't exists.";
        return;
    }

    int n = GetPosition(origin);
    int k = GetPosition(destiny);

    //Ya que es bidireccional se insertará primero en la lista de origen

    auto*p = new Vertex;
    p->name = adj[n]->name;
    p->next = nullptr;

    Vertex* temp = adj[n];
    while (temp->next){
        temp = temp->next;
    }

    temp->next = p;

    //Insertar lo mismo para el destino

    auto*q = new Vertex;
    q->name = adj[k]->name;
    q->next = nullptr;

    Vertex* temp2 = adj[k];
    while (temp2->next) {
        temp2 = temp2->next;
    }
    temp2->next = q;

}

void UndirectedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;
    for (int i = 0; i < v; ++i) {
        Vertex* actual = adj[i];
        std::cout << "Vertice " << (char)('A' + i) << ": ";
        while (actual) {
            std::cout << actual->name << " ";
            actual = actual->next;
        }
        std::cout << std::endl;
    }
}