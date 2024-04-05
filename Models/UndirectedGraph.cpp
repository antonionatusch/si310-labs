#include "UndirectedGraph.h"
#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"
#include "stack"

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

void UndirectedGraph::InsertEdge(int origin, int destiny) {
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
    InsertEdge(GetPosition(origin), GetPosition(destiny));
    //Insertar al final destino
    InsertEdge(GetPosition(destiny), GetPosition(origin));

}

void UndirectedGraph::DeleteVertex(char name) {

    if(!VertexExists(name)){
        std::cout << "El vertice que quiere eliminar no existe!!! " << std::endl;
    }
    else{
        for(int i = 0; i < numV; i++){
            //Si en la Lista de Adyacencia el primer valor es el vértice a eliminar
            //Entonces borramos toda la lista de adyacencia de dicho vértice y al final la posición donde estaba nuestro vértice
            //apuntará a null
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
                //Si no se encuentra en la primera posición el vértice a eliminar, se busca si existe
                //la conexión entre dicho vértice y otro y se borra la arista.
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
    //como el apuntador del vértice queda en null, esa posición no lo podemos dejar así.
    //Lo que se hace es extraer la siguiente posición donde estaba el vértice borrado para que ocupe su lugar
    //y así hasta que no haya más vértices, es como eliminar un elemento de un vector
    //y recorrer los siguientes valores de adelantes hacia atrás
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

void UndirectedGraph::DeleteEdge(char origin, char destiny) {
    if(!VertexExists(origin) || !VertexExists(destiny)){
        std::cout << "No se puede eliminar la arista al menos un vértice no existe." << std::endl;
    } else{
        for (int i = 0; i < numV; ++i) {
            if(adj[i]->name == origin || adj[i]->name == destiny){
                if(adj[i]->name == origin){
                    Vertex* aux = adj[i];
                    Vertex* temp = adj[i];

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
                    if(adj[i]->name == destiny){
                        Vertex* aux = adj[i];
                        Vertex* temp = adj[i];

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

void UndirectedGraph::BFS(char startVertex) {

    if (!VertexExists(startVertex)) {
        std::cout << "El vertice " << startVertex << " no existe en el grafo." << std::endl;
        return;
    }

    //start with all vertices as not visited
    bool *visited = new bool[numV];
    for(int i = 0; i <numV; i++ ){
        visited[i] = false;
    }

    //Create a queue for BFS
    std::queue<char> bfsQueue;

    //Started Vertex marked as visited and added to queue
    bfsQueue.push(adj[GetPosition(startVertex)]->name);
    visited[GetPosition(startVertex)] = true;

    //Continue until queue is empty
    while (!bfsQueue.empty()){

        char aux = bfsQueue.front();
        bfsQueue.pop();

        //Get all adjacent vertices from that vertex
        Vertex* temp = adj[GetPosition(aux)];
        temp = temp->next;

        std::cout << "Checking adjacent vertices from that vertex: " << aux << std::endl;
        while (temp){
            int adjIndex = GetPosition(temp->name);
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

void UndirectedGraph::DFS(char startVertex) {
    if (!VertexExists(startVertex)) {
        std::cout << "El vértice " << startVertex << " no existe en el grafo." << std::endl;
        return;
    }

    bool *visited = new bool[numV];
    for (int i = 0; i < numV; ++i) {
        visited[i] = false;
    }

    std::stack<char> stack;

    stack.push(startVertex);

    while (!stack.empty()) {
        char currentPos = stack.top();
        stack.pop();

        // Visitamos el nodo actual solo si no ha sido visitado previamente
        if (!visited[GetPosition(currentPos)]) {
            std::cout << "Visiting vertex " << currentPos << std::endl;
            visited[GetPosition(currentPos)] = true;

            // Obtenemos los nodos adyacentes del nodo actual y los agregamos a la pila si no han sido visitados
            Vertex* temp = adj[GetPosition(currentPos)]->next;
            while (temp != nullptr) {
                int nextPos = GetPosition(temp->name);
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