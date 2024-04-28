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
        std::cerr << "Error al abrir el archivo de configuracion." << std::endl;
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