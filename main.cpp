#include <iostream>
#include "Models/BinarySearchTree.h"
#include "Models/Queues.h"
#include "Models/Stacks.h"
#include "Models/LinkedList.h"
#include "Models/AvlTree.h"
#include "Models/BinaryTree.h"
#include "Models/UndirectedWeightedGraph.cpp"
#include "Models/UndirectedGraph.h"
#include "Models/DirectedGraph.h"
#include "Models/DirectedWeightedGraph.h"
#include "Models/DFA.h"
/*int op;
    do
    {
        std::cout<<"\n MENU PRINCIPAL \n";
        std::cout<<"1.- Árbol AVL \n";
        std::cout<<"2.- Árbol Binario de Búsqueda \n";
        std::cout<<"3.- Árbol Binario \n";
        std::cout<<"4.- Grafo no dirigido ponderado \n";
        std::cout<<"5.- Grafo no dirigido  \n";
        std::cout<<"6.- Grafo dirigido ponderado \n";
        std::cout<<"7.- Grafo dirigido \n";
        std::cout<<"Digite alguna opción para ejecutarla o \"0\" para salir... ";
        std::cin>>op;
        while(std::cin.fail()){
            std::cout<<"Se introdujo un valor no numérico, intente de nuevo. \n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin>>op;
        }
        switch (op) {
            case 1:
                AvlTree().Menu();
                break;
            case 2:
                BinarySearchTree().Menu();
                break;
            case 3:
                BinaryTree().ShortDemo();
                break;
            case 4:
                UndirectedWeightedGraph().menuOpciones();
                break;
            case 5:
                int n;
                std::cout<<"Digite la cantidad de vértices que tendrá el grafo: ";
                std::cin>>n;
                UndirectedGraph(n).MenuOpciones();
            case 6:
                DirectedWeightedGraph(0).Menu();
                break;
            case 7:
                DirectedGraph(0).Menu();
                break;
            case 0:
                std::cout<<"Hasta luego.";
                break;
            default:
                std::cout<<"No existe esa opción, intente de nuevo...";
                break;
        }
    }
    while (op != 0); */
int main() {
    DFA automaton;
    std::string myPath = "C:\\Users\\antho\\CLionProjects\\si310-labs\\Models\\";
    // ejemplo en clases
   /* automaton.AddState("1");
    automaton.AddState("2");
    automaton.AddState("3", true);
    automaton.AddState("4");
    automaton.AddState("5");

    automaton.AddTransition("1", 'a', "2");
    automaton.AddTransition("1", 'b', "3");
    automaton.AddTransition("2", 'a', "4");
    automaton.AddTransition("2", 'b', "3");
    automaton.AddTransition("3", 'a', "2");
    automaton.AddTransition("3", 'b', "3");
    automaton.AddTransition("4", 'a', "5");
    automaton.AddTransition("4", 'b', "3");
    automaton.AddTransition("5", 'a', "5");
    automaton.AddTransition("5", 'b', "5");

    automaton.DefineInitialState("1");

    std::vector<char> alphabet = {'a', 'b'};
    automaton.DefineAlphabet(alphabet); */


    //automaton.WriteConfig(myPath + "configuracion.txt");
    automaton.ReadConfig(myPath + "altconfig.txt");


    std::string cadena;
    std::cout << "Ingrese una cadena para verificar si es aceptada por el AFD: ";
    std::cin >> cadena;
    automaton.CheckInput(cadena);

    

    return 0;
}






