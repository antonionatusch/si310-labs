#include "UndirectedGraph.h"
#include "iostream"

UndirectedGraph::UndirectedGraph(int v) {
    this->v = v;
    numV = -1;

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
        if(numV == -1){
            numV = 0;
        }
        for (int i = 0; i < v; ++i) {
            if (!adj[i]) {
                adj[i] = new Vertex(name);
                std::cout << "Vertice " << name << " creado" << std::endl;
                numV++;
                return;
            }
        }
    }
    std::cout << "Can't create more vertices" << std::endl;
}

void UndirectedGraph::Insert(int origin, int destiny) {
    auto* p = new Vertex;
    p->name = adj[destiny]->name;
    p->next = nullptr;

    Vertex* temp = adj[origin];
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = p;
}

void UndirectedGraph::AddEdge(char origin, char destiny) {

    if(!VertexExists(origin) || !VertexExists(destiny)){
        std::cout<<"An Edge can't be created, a vertex doesn't exists." << std::endl;
        std::cout<< "ORIGIN: " << origin << " " << "DESTINY: " << destiny << std::endl;
        return;
    }

    //Insertar al final origen
    Insert(GetPosition(origin), GetPosition(destiny));
    //Insertar al final destino
    Insert(GetPosition(destiny), GetPosition(origin));

}

void UndirectedGraph::DeleteVertex(char name) {

    if(!VertexExists(name)){
        std::cout << "El vertice que quiere eliminar no existe!!! " << std::endl;
    }
    else{
        for(int i = 0; i < v; i++){
            if(adj[i]->name == name){
                Vertex* temp = adj[i];
                Vertex* aux = adj[i];
                while (aux->next != nullptr){
                    temp = temp->next;
                    aux->next = temp->next;
                    delete(temp);
                    temp = aux;
                }
                adj[i] = nullptr;
            } else{
                Vertex* temp = adj[i];
                Vertex* aux = adj[i];

                while (aux->next != nullptr){
                    temp =temp->next;
                    if(temp->name == name){
                        aux->next = temp->next;
                        delete(temp);
                        break;
                    }
                    aux = temp;
                }
            }
        }
    }
    numV--;
    ReorganizeList();
}

void UndirectedGraph::ReorganizeList() {

    int newPosition = 0;
    // Itera sobre todos los vértices restantes
    for (int i = 0; i < v; ++i) {
        // Si el vértice actual no es nulo
        if (adj[i] != nullptr) {
            // Mueve la lista de adyacencia al nuevo índice
            adj[newPosition] = adj[i];
            // Incrementa la posición donde copiar la lista de adyacencia
            newPosition++;
        }
    }
    // Rellena los elementos restantes con nullptr
    for (int i = newPosition; i < v; ++i) {
        adj[i] = nullptr;
    }
}

void UndirectedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;

    if(numV == -1){
        std::cout << "No existe el grafo!!!" << std::endl;
    }
    else{
        for (int i = 0; i < numV; i++) {
            Vertex* actual = adj[i];
            std::cout << "Vertice " << adj[i]->name << ": ";
            if (actual) {
                std::cout << actual->name;
                actual = actual->next;
            }
            while (actual) {
                std::cout << "->" << actual->name;
                actual = actual->next;
            }
            std::cout << std::endl;
        }
    }

}