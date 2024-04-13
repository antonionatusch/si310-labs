//
// Created by Antonio on 11/04/2024.
//

#include "DirectedGraphBase.h"
#include "iostream"
#include "stack"
#include "queue"
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

void DirectedGraphBase::BFS(char startVertex) const {

    if (!VertexExists(startVertex)) {
        std::cout << "El vertice " << startVertex << " no existe en el grafo." << std::endl;
        return;
    }

    //start with all vertices as not visited
    bool *visited = new bool[currentVertices];
    for(int i = 0; i <currentVertices; i++ ){
        visited[i] = false;
    }

    //Create a queue for BFS
    std::queue<char> bfsQueue;

    //Started Vertex marked as visited and added to queue
    bfsQueue.push(adjMatrix[FindVertexIndex(startVertex)]->name);
    visited[FindVertexIndex(startVertex)] = true;

    //Continue until queue is empty
    while (!bfsQueue.empty()){

        char aux = bfsQueue.front();
        bfsQueue.pop();

        //Get all adjacent vertices from that vertex
        Vertex* temp = adjMatrix[FindVertexIndex(aux)];
        temp = temp->next;

        std::cout << "Checking adjacent vertices from that vertex: " << aux << std::endl;
        while (temp){
            int adjIndex = FindVertexIndex(temp->name);
            if(!visited[adjIndex]) {
                //marked as visited
                std::cout << "Visit and enqueue " << temp->name << std::endl;
                visited[adjIndex] = true;
                bfsQueue.push(temp->name);
            }
            temp = temp->next;
        }
    }

    delete[] visited;
}

void DirectedGraphBase::DFS(char startVertex) const {
    if (!VertexExists(startVertex)) {
        std::cout << "El vértice " << startVertex << " no existe en el grafo." << std::endl;
        return;
    }

    bool *visited = new bool[currentVertices];
    for (int i = 0; i < currentVertices; ++i) {
        visited[i] = false;
    }

    std::stack<char> stack;

    stack.push(startVertex);

    while (!stack.empty()) {
        char currentPos = stack.top();
        stack.pop();

        // Visitamos el nodo actual solo si no ha sido visitado previamente
        if (!visited[FindVertexIndex(currentPos)]) {
            std::cout << "Visiting vertex " << currentPos << std::endl;
            visited[FindVertexIndex(currentPos)] = true;

            // Obtenemos los nodos adyacentes del nodo actual y los agregamos a la pila si no han sido visitados
            Vertex* temp = adjMatrix[FindVertexIndex(currentPos)]->next;
            while (temp != nullptr) {
                int nextPos = FindVertexIndex(temp->name);
                if (!visited[nextPos]) {
                    std::cout << "Going to vertex " << temp->name << " from vertex " << currentPos << std::endl;
                    stack.push(temp->name);
                }
                temp = temp->next;
            }
        }
    }

    delete[] visited;
}

void DirectedGraphBase::DeleteVertices(int n) {
    for (int i = 0; i < n; ++i)
    {
        char deletedVertexName;
        std::cout<<"Vertex number "<<i+1<<" to be deleted: "; std::cin>>deletedVertexName;
        DeleteVertex(deletedVertexName);
    }
}



