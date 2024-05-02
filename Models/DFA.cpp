//
// Created by Antonio on 27/04/2024.
//

#include "DFA.h"
DFA::DFA() {
}
DFA::~DFA() {}

void DFA::ReadConfig(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error al abrir el file de configuracion." << std::endl;
        exit(1);
    }

    std::string token;
    file >> token; // Leer estados
    while (file >> token && token != "Alfabeto") {
        this->states.push_back(token);
    }

    while (file >> token && token != "Transiciones") {
        // Leer el alfabeto
        for (char caracter : token) {
            this->alphabet.push_back(caracter);
        }
    }

    std::string originState, symbol, destinyState;
    while (file >> originState) {
        if (originState == "EstadoInicial") {
            break;
        }
        while(file >> symbol >> destinyState){
            this->transitions[{originState, symbol[0]}] = destinyState;
            break;
        }
    }

    file  >> token;
    this->initialState = token; // El último estado leído es el estado inicial

    while (file >> token && token != "EstadosAceptacion") {
        // No hacemos nada, simplemente leemos los tokens hasta encontrar "EstadosAceptacion"
    }

    while (file >> token) {
        this->finalStates.push_back(token);
    }

    file.close();
}

void DFA::WriteConfig(const std::string &fileName) {
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error al abrir el file para escribir la configuración." << std::endl;
        exit(1);
    }

    file << "Estados" << std::endl;
    for (const std::string& estado : this->states) {
        file << estado << std::endl;
    }

    file << "Alfabeto" << std::endl;
    for (char caracter : this->alphabet) {
        file << caracter << std::endl;
    }

    file << "Transiciones" << std::endl;
    for (const auto& transicion : this->transitions) {
        file << transicion.first.first << " " << transicion.first.second << " " << transicion.second << std::endl;
    }

    file << "EstadoInicial" << std::endl;
    file << this->initialState << std::endl;

    file << "EstadosAceptacion" << std::endl;
    for (const std::string& estado : this->finalStates) {
        file << estado << std::endl;
    }

    file.close();
}

void DFA::DefineAlphabet(const std::vector<char> &alphabet) {
    this->alphabet = alphabet;
}

void DFA::DefineInitialState(const std::string &initialState) {
    this->initialState = initialState;
}

void DFA::AddTransition(const std::string &originState, char symbol, const std::string destinyState) {
    this->transitions[{originState, symbol}] = destinyState;
}

void DFA::AddState(const std::string &state, bool isFinal) {
    this->states.push_back(state);
    if (isFinal)
        this->finalStates.push_back(state);
}

bool DFA::IsAValidChain(const std::string &chain) {
    std::string estadoActual = this->initialState;

    for (char simbolo : chain) {

        auto it = this->transitions.find({estadoActual, simbolo});
        if (it == this->transitions.end()) {
            return false;
        }
        estadoActual = it->second;
    }

    for (const std::string& estado : this->finalStates) {
        if (estado == estadoActual) {
            return true;
        }
    }

    return false;
}

void DFA::CheckInput(const std::string &userInput) {
    if (IsAValidChain(userInput))
        std::cout<<"Palabra válida. \n";
    else
        std::cout<<"Palabra rechazada. \n";
}

void DFA::AddStates(int n) {
    std::string userInitialState;
    for (int i = 0; i < n; ++i)
    {
        std::string newState;
        char tmp;
        std::cout<<"Estado "<<i+1<<": "; std::cin>>newState;
        std::cout<<"Es final/de aceptación? Digite 's' para sí, 'n' para no.";
        std::cin>>tmp;

        if(tolower(tmp) == 's')
            AddState(newState, true);
        else if (tolower(tmp) == 'n')
            AddState(newState);

    }
    std::cout<<"Digite cuál será su estado inicial: "; std::cin>>userInitialState;
    DefineInitialState(userInitialState);

}

void DFA::AddTransitions(int n) {
    for (int i = 0; i < n; ++i)
    {
        std::string originState, destinyState;
        char symbol;
        std::cout<<"Transición: "<<i+1<<std::endl;

        std::cout<<"Digite el estado de origen: "; std::cin>>originState;
        std::cout<<"Digite el símbolo: "; std::cin>>symbol;
        std::cout<<"Digite el estado de destino: "; std::cin>>destinyState;

        AddTransition(originState, symbol, destinyState);

    }
}

void DFA::WriteSymbols(int n) {
    std::vector<char> userAlphabet;
    for (int i = 0; i < n; ++i)
    {
        char tmp;
        std::cout<<"Símbolo "<<i+1<<": "; std::cin>>tmp;
        userAlphabet.push_back(tmp);
    }
    DefineAlphabet(userAlphabet);
}

void DFA::Menu() {
    char op;
    DFA automaton;
    do
    {
        std::cout<<"MENU DE AFD \n";
        std::cout<<"1.- Escribir la configuración del autómata por teclado \n";
        std::cout<<"2.- Leer la configuración de un archivo \n";
        std::cout<<"3.- Validar cadena \n";
        std::cin>>op;

        switch (op)
        {
            case '1':
                int userStates, userTransitions, userSymbols;
                std::string userInitialState, configName;
                std::cout<<"Introduzca la cantidad de estados: "; std::cin>>userStates;
                automaton.AddStates(userStates);
                std::cout<<"\n Introduzca la cantidad de símbolos"; std::cin>>userSymbols;
                automaton.WriteSymbols(userSymbols);
                std::cout<<"\n Introduzca la cantidad de transiciones: "; std::cin>>userTransitions;
                automaton.AddTransitions(userTransitions);

                std::cout<<"\n Desea escribir la configuración en un txt? Si es así, escriba el nombre del archivo o presione 'n' para continuar. \n"; std::cin>>configName;

                if(configName == "n")
                    break;
                else
                {
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::string userPath;
                    std::cout<<"Ocupa un path personalizado? Si es así, escríbalo o escriba 'n' para terminar la escritura. ";  std::cin>>userPath;

                    if (userPath == "n")
                    {
                        automaton.WriteConfig(configName);
                        break;
                    }
                    else
                    {
                        automaton.WriteConfig(userPath + configName);
                        break;
                    }

                }
        }
    }
    while(op != 's');
}