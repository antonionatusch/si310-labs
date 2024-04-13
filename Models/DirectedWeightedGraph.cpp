//
// Created by Antonio on 12/04/2024.
//

#include "DirectedWeightedGraph.h"
#include "iostream"

DirectedWeightedGraph::DirectedWeightedGraph(int v) {
    totalVertices = v;
    currentVertices = 0;

    adjMatrix = new Vertex * [v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = nullptr;
    }
    this->weights = new int[v]; // inicializo mi vector
    for (int i = 0; i < v; ++i) {
        weights[i] = 0; // Inicializar todos los pesos a 0
    }
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

    // Establecer el peso de la arista
    newNode->weight = weight;

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




void DirectedWeightedGraph::DeleteEdge(char origin, char destiny) {
    int originIndex = FindVertexIndex(origin);
    int destinyIndex = FindVertexIndex(destiny);

    if (originIndex != -1 && destinyIndex != -1) {
        // Buscar y eliminar la arista de la lista de adyacencia del vértice de origen
        Vertex* currentVertex = adjMatrix[originIndex];
        while (currentVertex && currentVertex->next) {
            if (currentVertex->next->name == destiny) {
                Vertex* temp = currentVertex->next;
                currentVertex->next = temp->next;
                delete temp;
                // Actualizar el peso correspondiente
                weights[originIndex] = 0; // Opcional: establecer el peso como 0
                std::cout << "Edge deleted between " << origin << " and " << destiny << std::endl;
                return;
            }
            currentVertex = currentVertex->next;
        }
        std::cout << "Edge between " << origin << " and " << destiny << " not found." << std::endl;
    } else {
        std::cout << "One or both vertices do not exist." << std::endl;
    }
}

void DirectedWeightedGraph::DeleteVertex(char name) {
    int index = FindVertexIndex(name);
    if (index != -1) {
        // Eliminar el vértice de la lista de adyacencia y liberar memoria
        delete adjMatrix[index];
        adjMatrix[index] = nullptr;

        // Eliminar todas las aristas que conectan el vértice con otros vértices
        for (int i = 0; i < totalVertices; ++i) {
            if (i != index) {
                // Buscar y eliminar la arista correspondiente en la lista de adyacencia de otros vértices
                Vertex* currentVertex = adjMatrix[i];
                while (currentVertex && currentVertex->next) {
                    if (currentVertex->next->name == name) {
                        Vertex* temp = currentVertex->next;
                        currentVertex->next = temp->next;
                        delete temp;
                        break; // Avanzar al siguiente vértice en la lista de adyacencia
                    }
                    currentVertex = currentVertex->next;
                }
            }
        }
        std::cout << "Vertex " << name << " deleted." << std::endl;
    } else {
        std::cout << "Vertex " << name << " not found." << std::endl;
    }
}

void DirectedWeightedGraph::Dijkstra(char startingPoint) {
    // Obtener el índice del vértice de inicio
    int startIndex = FindVertexIndex(startingPoint);
    if (startIndex == -1) {
        std::cout << "El vértice de inicio no existe." << std::endl;
        return;
    }

    // Inicializar las distancias mínimas y los vértices visitados
    const int INF = 1000000; // Valor para representar infinito
    int distance[totalVertices];
    bool visited[totalVertices];
    for (int i = 0; i < totalVertices; ++i) {
        distance[i] = (i == startIndex) ? 0 : INF; // La distancia al vértice de inicio es 0, de lo contrario es infinito
        visited[i] = false;
    }

    // Bucle principal
    for (int i = 0; i < totalVertices; ++i) {
        // Encontrar el vértice no visitado con la distancia mínima conocida
        int minDistance = INF;
        int minIndex = -1;
        for (int j = 0; j < totalVertices; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        // Marcar el vértice como visitado
        visited[minIndex] = true;

        // Actualizar las distancias de sus vecinos
        if (adjMatrix[minIndex]) { // Verificar que adjMatrix[minIndex] no sea nullptr
            Vertex* currentVertex = adjMatrix[minIndex]->next;
            while (currentVertex != nullptr) {
                if (currentVertex->name != '\0') { // Verificar que currentVertex->name no sea '\0'
                    int weight = currentVertex->weight;
                    int neighborIndex = FindVertexIndex(currentVertex->name);
                    if (distance[minIndex] != INF && weight != INF &&
                        distance[minIndex] + weight < distance[neighborIndex]) {
                        distance[neighborIndex] = distance[minIndex] + weight;
                    }
                }
                currentVertex = currentVertex->next;
            }
        }
    }

    // Mostrar las distancias mínimas
    std::cout << "Distancias mínimas desde el vértice " << startingPoint << ":" << std::endl;
    for (int i = 0; i < totalVertices; ++i) {
        if (distance[i] != INF) {
            std::cout << "Distancia a " << adjMatrix[i]->name << ": " << distance[i] << std::endl;
        } else {
            std::cout << "No hay camino desde " << startingPoint << " a " << adjMatrix[i]->name << std::endl;
        }
    }
}












