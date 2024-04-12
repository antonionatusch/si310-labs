//
// Created by Antonio on 11/04/2024.
//

#include "DirectedGraphBase.h"
#include "iostream"
void DirectedGraphBase::CreateVertex(char name) {
    if(!VertexExists(name)){
        if(currentVertices == -1){
            currentVertices = 0;
        }
        for (int i = 0; i < totalVertices; ++i) {
            if (!adjMatrix[i]) {
                adjMatrix[i] = new Vertex(name);
                std::cout << "Vertice " << name << " creado" << std::endl;
                currentVertices++;
                return;
            }
        }
    }
    std::cout << "Can't create more vertices" << std::endl;
}

bool DirectedGraphBase::VertexExists(char name) const {
    for (int i = 0; i < totalVertices; ++i) {
        if (adjMatrix[i] && adjMatrix[i]->name == name) return true;
    }
    return false;
}

void DirectedGraphBase::ReorganizeAdjList() const {
    int newPosition = 0;
    // Itera sobre todos los vértices restantes
    for (int i = 0; i < totalVertices; ++i) {
        // Si el vértice actual no es nulo
        if (adjMatrix[i] != nullptr) {
            // Mueve la lista de adyacencia al nuevo índice
            adjMatrix[newPosition] = adjMatrix[i];
            // Incrementa la posición donde copiar la lista de adyacencia
            newPosition++;
        }
    }
    // Rellena los elementos restantes con nullptr
    for (int i = newPosition; i < totalVertices; ++i) {
        adjMatrix[i] = nullptr;
    }
}

int DirectedGraphBase::FindVertexIndex(char name) const {
    for (int i = 0; i < totalVertices; ++i) {
        if (adjMatrix[i] && adjMatrix[i]->name == name) return i;
    }
    return -1;
}

void DirectedGraphBase::CreateVertices(int n) {
    for (int i = 0; i < n; ++i)
    {
        char vertexName;
        std::cout<<"Vertex "<<i+1<<": "; std::cin>>vertexName;
        CreateVertex(vertexName);
    }
}

