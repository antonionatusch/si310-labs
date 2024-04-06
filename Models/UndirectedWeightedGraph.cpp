#include <iostream>
#include "stack"
#include "queue"

class UndirectedWeightedGraph {
private:
    class Vertex {
    public:
        char data;
        static const int MAX_EDGES = 10; // Máximo número de aristas por vértice
        char edges[MAX_EDGES];
        int weights[MAX_EDGES];
        int numEdges;

        Vertex(char d) : data(d), numEdges(0) {}
        Vertex(): numEdges(0) {}

        void addEdge(char dest, int weight) {
            if (numEdges < MAX_EDGES) {
                edges[numEdges] = dest;
                weights[numEdges] = weight;
                numEdges++;
            }
        }

        void removeEdge(char dest) {
            for (int i = 0; i < numEdges; ++i) {
                if (edges[i] == dest) {
                    for (int j = i; j < numEdges - 1; ++j) {
                        edges[j] = edges[j + 1];
                        weights[j] = weights[j + 1];
                    }
                    numEdges--;
                    break;
                }
            }
        }
    };

    static const int MAX_VERTICES = 10; // Máximo número de vértices
    static const int MAX_EDGES = MAX_VERTICES * (MAX_VERTICES - 1) / 2; // Número máximo de aristas
    Vertex vertices[MAX_VERTICES];
    int numVertices;

    int findVertexIndex(char data) {
        for (int i = 0; i < numVertices; ++i) {
            if (vertices[i].data == data) {
                return i;
            }
        }
        return -1;
    }

public:
    UndirectedWeightedGraph() : numVertices(0), vertices{} {}

    void createVertex(char data) {
        if (findVertexIndex(data) == -1 && numVertices < MAX_VERTICES) {
            vertices[numVertices++] = Vertex(data);
            std::cout << "Vertex " << data << " created." << std::endl;
        } else {
            std::cout << "Vertex " << data << " already exists or graph is full." << std::endl;
        }
    }

    bool vertexExists(char data) {
        return findVertexIndex(data) != -1;
    }

    void addEdge(char from, char to, int weight) {
        int fromIndex = findVertexIndex(from);
        int toIndex = findVertexIndex(to);

        if (fromIndex != -1 && toIndex != -1) {
            vertices[fromIndex].addEdge(to, weight);
            vertices[toIndex].addEdge(from, weight); // Grafos no dirigidos
            std::cout << "Edge added between " << from << " and " << to << " with weight " << weight << "." << std::endl;
        } else {
            std::cout << "One or both vertices do not exist." << std::endl;
        }
    }

    void deleteVertex(char data) {
        int index = findVertexIndex(data);
        if (index != -1) {
            // Eliminar todas las aristas que apunten a este vértice
            for (int i = 0; i < numVertices; ++i) {
                vertices[i].removeEdge(data);
            }
            // Eliminar el vértice
            for (int i = index; i < numVertices - 1; ++i) {
                vertices[i] = vertices[i + 1];
            }
            numVertices--;
            std::cout << "Vertex " << data << " deleted." << std::endl;
        } else {
            std::cout << "Vertex " << data << " does not exist." << std::endl;
        }
    }

    void deleteEdge(char from, char to) {
        int fromIndex = findVertexIndex(from);
        int toIndex = findVertexIndex(to);

        if (fromIndex != -1 && toIndex != -1) {
            // Eliminar la arista desde 'from' hasta 'to'
            vertices[fromIndex].removeEdge(to);
            vertices[toIndex].removeEdge(from);
            std::cout << "Edge deleted between " << from << " and " << to << "." << std::endl;
        } else {
            std::cout << "One or both vertices do not exist." << std::endl;
        }
    }

    void showList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << vertices[i].data << ": ";
            for (int j = 0; j < vertices[i].numEdges; ++j) {
                std::cout << vertices[i].edges[j] << "(" << vertices[i].weights[j] << ") ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(char startVertex) {
        std::queue<int> q;
        bool visited[MAX_VERTICES] = {false};

        int startIndex = findVertexIndex(startVertex);
        if (startIndex == -1) {
            std::cout << "Start vertex not found." << std::endl;
            return;
        }

        q.push(startIndex);
        visited[startIndex] = true;

        while (!q.empty()) {
            int currentIndex = q.front();
            q.pop();
            std::cout << "Checking adjacent vertices from that vertex: " << vertices[currentIndex].data << std::endl;


            for (int i = 0; i < vertices[currentIndex].numEdges; ++i) {
                int nextIndex = findVertexIndex(vertices[currentIndex].edges[i]);
                if (!visited[nextIndex]) {
                    std::cout << "Visit and enqueue " << vertices[nextIndex].data << std::endl;
                    q.push(nextIndex);
                    visited[nextIndex] = true;
                }
            }
        }
    }

    void dfsRecursive(int startIndex, bool visited[]) {
        visited[startIndex] = true;
        std::cout << "Visiting vertex " <<vertices[startIndex].data  << std::endl;

        for (int i = 0; i < vertices[startIndex].numEdges; ++i) {
            int nextIndex = findVertexIndex(vertices[startIndex].edges[i]);
            if (!visited[nextIndex]) {
                std::cout << "Going to vertex " << vertices[startIndex].edges[i] << " from vertex "
                          << vertices[startIndex].data << std::endl;
                dfsRecursive(nextIndex, visited);
            }
        }
    }

    // Algoritmo DFS
    void dfs(char startVertex) {
        bool visited[MAX_VERTICES] = {false};

        int startIndex = findVertexIndex(startVertex);
        if (startIndex == -1) {
            std::cout << "Start vertex not found." << std::endl;
            return;
        }

        dfsRecursive(startIndex, visited);
    }

    void dijkstra(char startVertex) {
        int startIndex = findVertexIndex(startVertex);
        if (startIndex == -1) {
            std::cout << "Start vertex not found." << std::endl;
            return;
        }

        const int INF = 1000000; // Representa infinito para distancias

        // Inicializar distancias de los nodos
        int distance[MAX_VERTICES];
        bool visited[MAX_VERTICES];
        std::string path[MAX_VERTICES];

        for (int i = 0; i < numVertices; ++i) {
            distance[i] = INF;
            visited[i] = false;
            path[i] = "";
        }
        distance[startIndex] = 0;
        path[startIndex] = startVertex;

        // Algoritmo de Dijkstra
        for (int count = 0; count < numVertices - 1; ++count) {
            // Encontrar el vértice con la distancia mínima
            int minDistance = INF;
            int minIndex = -1;

            for (int v = 0; v < numVertices; ++v) {
                if (!visited[v] && distance[v] <= minDistance) {
                    minDistance = distance[v];
                    minIndex = v;
                }
            }

            // Marcar el vértice como visitado
            visited[minIndex] = true;

            // Actualizar las distancias de los vértices adyacentes
            for (int v = 0; v < vertices[minIndex].numEdges; ++v) {
                char dest = vertices[minIndex].edges[v];
                int weight = vertices[minIndex].weights[v];
                int destIndex = findVertexIndex(dest);
                if (!visited[destIndex] && distance[minIndex] != INF && distance[minIndex] + weight < distance[destIndex]) {
                    distance[destIndex] = distance[minIndex] + weight;
                    path[destIndex] = path[minIndex] + " -> " + dest;
                }
            }
        }

        // Imprimir las distancias más cortas
        std::cout << "Shortest distances from vertex " << startVertex << ":" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "To vertex " << vertices[i].data << ": " << distance[i] << " Path: " << path[i] << std::endl;
        }
    }

    void menu()
    {
        std::cout << "\n\tREPRESENTACION DE GRAFOS NO DIRIGIDOS PONDERADOS\n\n";
        std::cout << " 1. INSERTAR UN NODO " << std::endl;
        std::cout << " 2. INSERTAR UNA ARISTA " << std::endl;
        std::cout << " 3. ELIMINAR UN NODO " << std::endl;
        std::cout << " 4. ELIMINAR UNA ARISTA " << std::endl;
        std::cout << " 5. MOSTRAR GRAFO " << std::endl;
        std::cout << " 6. RECORRER GRAFO EN AMPLITUD " << std::endl;
        std::cout << " 7. RECORRER GRAFO EN PROFUNDIDAD " << std::endl;
        std::cout << " 8. ALGORITMO DE DIJKSTRA " << std::endl;
        std::cout << " 0. SALIR " << std::endl;
        std::cout << "\n INGRESE OPCION: ";
    }

    void menuOpciones(){
        int op; // opcion del menu
        system("color 0b");
        do
        {
            menu();
            std::cin >> op;
            switch (op)
            {
                case 1:
                    char vertex;
                    std::cout << "type the vertex to create: "; std::cin >> vertex;
                    createVertex(vertex);
                    break;
                case 2:
                    char from; char to; int w;
                    std::cout<<"type the first vertex: " ; std::cin >> from; std::cout<< std::endl;
                    std::cout<<"type the second vertex: " ; std::cin >> to; std::cout<< std::endl;
                    std::cout<<"type the edge's weight :" ; std:: cin >> w; std::cout<< std::endl;
                    addEdge(from, to, w);
                    break;
                case 3:
                    char dVertex;
                    std::cout << "type the vertex to delete: "; std::cin >> dVertex;
                    deleteVertex(dVertex);
                    break;
                case 4:
                    char dfVertex; char dsVertex;
                    std::cout << "type the first vertex to delete: "; std::cin >> dfVertex;
                    std::cout << "type the second vertex to delete: "; std::cin >> dsVertex;
                    deleteEdge(dfVertex,dsVertex);
                    break;
                case 5: showList();
                    break;
                case 6:
                    char bfsVertex;
                    std::cout << "type the vertex to initialize BFS: "; std::cin >> bfsVertex;
                    bfs(bfsVertex);
                    break;
                case 7:
                    char dfsVertex;
                    std::cout << "type the vertex to initialize DFS: "; std::cin >> dfsVertex;
                    dfs(dfsVertex);
                    break;
                case 8:
                    char dijVertex;
                    std::cout << "type the vertex to initialize Dijkstra: "; std::cin >> dijVertex;
                    dijkstra(dijVertex);
                    break;
                default: std::cout << "OPCION NO VALIDA...!!!";
                    break;
            }
            std::cout << std::endl << std::endl;
            system("pause"); system("cls");
        } while (op != 0);
        getchar();
    }
};