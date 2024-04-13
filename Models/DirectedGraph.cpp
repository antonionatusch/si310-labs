//
// Created by Antonio on 11/04/2024.
//

#include "DirectedGraph.h"
#include "iostream"
#include "queue"
#include "stack"
// constructor

DirectedGraph::DirectedGraph(int v) {
    totalVertices = v;
    currentVertices = -1;

    adjMatrix = new Vertex * [v];
    for(int i = 0; i < v; i++){
        adjMatrix[i] = nullptr;
    }
}
// dest
DirectedGraph::~DirectedGraph() {
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

void DirectedGraph::InsertEdge(int origin, int destiny) {
    auto* p = new Vertex;
    p->name = adjMatrix[destiny]->name;
    p->next = nullptr;

    Vertex* temp = adjMatrix[origin];
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = p;


}

void DirectedGraph::AddEdge(char origin, char destiny) {
    if(!VertexExists(origin) || !VertexExists(destiny)){
        std::cout<<"An Edge can't be created, a vertex doesn't exists." << std::endl;
        std::cout<< "ORIGIN: " << origin << " " << "DESTINY: " << destiny << std::endl;
        return;
    }

    //Insertar al final origen
    InsertEdge(FindVertexIndex(origin), FindVertexIndex(destiny));
}

void DirectedGraph::DeleteEdge(char origin, char destiny) {
    if(!VertexExists(origin) || !VertexExists(destiny)){
        std::cout << "No se puede eliminar la arista al menos un vértice no existe." << std::endl;
    } else{
        for (int i = 0; i < currentVertices; ++i) {
            if(adjMatrix[i]->name == origin || adjMatrix[i]->name == destiny){
                if(adjMatrix[i]->name == origin){
                    Vertex* aux = adjMatrix[i];
                    Vertex* temp = adjMatrix[i];

                    while (aux->next != nullptr){
                        temp =temp->next;
                        if(temp->name == destiny){
                            aux->next = temp->next;
                            delete(temp);
                            break;
                        }
                        aux = temp;
                    }
                }
                else{
                    if(adjMatrix[i]->name == destiny){
                        Vertex* aux = adjMatrix[i];
                        Vertex* temp = adjMatrix[i];

                        while (aux->next != nullptr){
                            temp =temp->next;
                            if(temp->name == origin){
                                aux->next = temp->next;
                                delete(temp);
                                break;
                            }
                            aux = temp;
                        }
                    }
                }
            }
        }
    }
}

void DirectedGraph::ShowList() {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;

    if(currentVertices == -1){
        std::cout << "No existe el grafo!!!" << std::endl;
    }
    else{
        for (int i = 0; i < currentVertices; i++) {
            Vertex* actual = adjMatrix[i];
            std::cout << "Vertice " << adjMatrix[i]->name << ": ";
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

void DirectedGraph::DeleteVertex(char name) {
    if(!VertexExists(name)){
        std::cout << "El vertice que quiere eliminar no existe!!! " << std::endl;
    }
    else{
        for(int i = 0; i < currentVertices; i++){
            //Si en la Lista de Adyacencia el primer valor es el vértice a eliminar
            //Entonces borramos toda la lista de adyacencia de dicho vértice y al final la posición donde estaba nuestro vértice
            //apuntará a null
            if(adjMatrix[i]->name == name){
                Vertex* temp = adjMatrix[i];
                Vertex* aux = adjMatrix[i];
                while (aux->next != nullptr){
                    temp = temp->next;
                    aux->next = temp->next;
                    delete(temp);
                    temp = aux;
                }
                adjMatrix[i] = nullptr;
            } else{
                //Si no se encuentra en la primera posición el vértice a eliminar, se busca si existe
                //la conexión entre dicho vértice y otro y se borra la arista.
                Vertex* temp = adjMatrix[i];
                Vertex* aux = adjMatrix[i];

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
    currentVertices--;
    //como el apuntador del vértice queda en null, esa posición no lo podemos dejar así.
    //Lo que se hace es extraer la siguiente posición donde estaba el vértice borrado para que ocupe su lugar
    //y así hasta que no haya más vértices, es como eliminar un elemento de un vector
    //y recorrer los siguientes valores de adelantes hacia atrás
    ReorganizeAdjList();
}

void DirectedGraph::AddEdges(int n) {
    for(int i = 0; i < n; ++i)
    {
        char fromVertex, toVertex;
        std::cout<<"Edge number: "<<i+1<<" \n";
        std::cout<<"From: "; std::cin>>fromVertex;
        std::cout<<"To: "; std::cin>>toVertex;
        AddEdge(fromVertex, toVertex);
    }
}

void DirectedGraph::DeleteEdges(int n) {
    for (int i = 0; i < n; ++i)
    {
        char deletedFromVertex, deletedToVertex;
        std::cout<<"Edge to be deleted number: "<<i+1<<" \n";
        std::cout<<"From: "; std::cin>>deletedFromVertex;
        std::cout<<"To: "; std::cin>>deletedToVertex;
        DeleteEdge(deletedFromVertex, deletedToVertex);
    }
}

