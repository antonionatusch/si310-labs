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
    newNode->weight = weight; // Establece el peso de la arista
    newNode->next = nullptr;

    // Encuentra el último nodo en la lista de adyacencia del vértice de origen y agrega el nuevo nodo
    Vertex* temp = adjMatrix[originVertex];
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;


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

void DirectedWeightedGraph::AddEdges(int n) {
    for (int i = 0; i < n; ++i)
    {
        char fromVertex, toVertex;
        int weight;

        std::cout << "Adding edge number: " << i + 1 << "\n";
        std::cout << "From vertex: ";
        std::cin >> fromVertex;
        std::cout << "To: ";
        std::cin >> toVertex;
        std::cout << "With a weight of: ";
        std::cin >> weight;
        AddEdge(fromVertex, toVertex, weight); // Aquí intercambiar fromVertex y toVertex
    }
}

void DirectedWeightedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;

    if (currentVertices == -1) {
        std::cout << "No existe el grafo!!!" << std::endl;
    } else {
        for (int i = 0; i < currentVertices; i++) {
            std::cout << "Vertice " << adjMatrix[i]->name << ": ";
            Vertex* currentVertex = adjMatrix[i]->next;
            while (currentVertex != nullptr) {
                std::cout << currentVertex->name;
                if (currentVertex->weight != 0) {
                    std::cout << " (Peso: " << currentVertex->weight << ")";
                }
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

