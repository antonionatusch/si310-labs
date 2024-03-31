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
                std::cout << "Vertice " << name << " creado" << std::endl;
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

void UndirectedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;
    for (int i = 0; i < v; ++i) {
        Vertex* actual = adj[i];
        std::cout << "Vertice " << (char)('A' + i) << ": ";
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