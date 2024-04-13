//
// Created by Antonio on 12/04/2024.
//

#include "DirectedWeightedGraph.h"
#include "iostream"
DirectedWeightedGraph::DirectedWeightedGraph(int v) {
    totalVertices = v;
    currentVertices = -1;

    adjMatrix = new Vertex * [v];
    for(int i = 0; i < v; i++){
        adjMatrix[i] = nullptr;
    }
    this->weights = new int[v]; // inicializo mi vector
}

DirectedWeightedGraph::~DirectedWeightedGraph() {
    for (int i = 0; i < totalVertices; ++i) {
        Vertex* actual = adjMatrix[i];
        while (actual) {
            Vertex* n = actual->next;
            delete actual;
            actual = n;
        }
    }
    delete[] adjMatrix;
}

void DirectedWeightedGraph::InsertEdge(int originVertex, int destinyVertex, int weight) {
    Vertex* newNode = new Vertex;
    newNode->name = adjMatrix[destinyVertex]->name;
    newNode->next = nullptr;

    // Encuentra el último nodo en la lista de adyacencia del vértice de origen y agrega el nuevo nodo
    Vertex* temp = adjMatrix[originVertex];
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;

    // Actualiza el peso correspondiente en el arreglo de pesos
    weights[originVertex] = weight;


}

void DirectedWeightedGraph::AddEdge(char fromVertex, char toVertex, int weight) {
    int fromIndex = FindVertexIndex(fromVertex);
    int toIndex = FindVertexIndex(toVertex);

    if (fromIndex != -1 && toIndex != -1) {
        InsertEdge(fromIndex, toIndex, weight);
        std::cout << "Edge added between " << fromVertex << " and " << toVertex << " with weight " << weight << ".\n";
    } else {
        std::cout << "One or both vertices do not exist." << std::endl;
    }
}

void DirectedWeightedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;

    if (currentVertices == -1) {
        std::cout << "No existe el grafo!!!" << std::endl;
    } else {
        for (int i = 0; i < currentVertices; i++) {
            std::cout << "Vertice " << adjMatrix[i]->name << ": ";
            Vertex* currentVertex = adjMatrix[i]->next; // Se omite el primer vértice que es el mismo
            while (currentVertex != nullptr) {
                std::cout << currentVertex->name << " (Peso: " << weights[i] << ")";
                if (currentVertex->next != nullptr) {
                    std::cout << "-> ";
                }
                currentVertex = currentVertex->next;
            }
            std::cout << std::endl;
        }
    }
}

void DirectedWeightedGraph::DeleteEdge(char origin, char destiny) {}

void DirectedWeightedGraph::DeleteVertex(char name) {}

