//
// Created by Antonio on 26/04/2024.
//

#include "DFA.h"
DFA::DFA() {}
DFA::~DFA(){}

void DFA::AddState(std::string state, bool isFinal) {
    states.insert(state);
    if (isFinal)
        finalStates.insert(state);
}

void DFA::AddTransition(std::string originState, char symbol, std::string destinyState) {
    transitions[{originState, symbol}] = destinyState;
}

void DFA::DefineInitialState(std::string initialState) {
    this->initialState = initialState;
}

void DFA::DefineAlphabet(const std::unordered_set<char> &alphabet) {
    this->alphabet = alphabet;
}

bool DFA::ProcessChain(const std::string &chain) {
    std::string currentState = initialState;
    char currentSymbol;
    std::istringstream ss(chain);
    while (ss.get(currentSymbol))
    {
        if (alphabet.find(currentSymbol) == alphabet.end())
        {
            std::cerr << "Error: el símbolo '" << currentSymbol << "' no pertenece al alfabeto del autómata.\n";
            return false;
        }
        currentState = goTo(currentState, currentSymbol);
    }
    return finalStates.find(currentState) != finalStates.end();
}

std::string DFA::goTo(std::string currentState, char symbol) const {
    auto transition = transitions.find({currentState, symbol});
    return transition == transitions.end() ? "" : transition->second;
}

void DFA::WriteConfig(const std::string &fileName) const {
    auto defaultPath = "C:\\Users\\antho\\CLionProjects\\si310-labs\\Models\\"; // cambiar el path a su espacio de preferencia
    std::ofstream file(defaultPath + fileName);

    if (!file.is_open())
    {
        std::cerr<<"Hubo un error al abrir el file para escribir la config del AFD. \n";
        return;
    }
    file << "Estados:\n";
    for (const auto& state : states)
    {
        file << state << (finalStates.count(state) ? " (final)" : "") << '\n';
    }

    file << "Transiciones:\n";
    for (const auto& transition : transitions)
    {
        file << transition.first.first << " -> '" << transition.first.second << "' -> " << transition.second << '\n';
    }
    file << "Estado actual: " << initialState << '\n';
    file << "Alfabeto: ";
    for (char symbol : alphabet)
    {
        file << symbol << ' ';
    }
    file << '\n';
    file.close();
}


void DFA::ValidateInput(const std::string& wordToValidate) {
    if (ProcessChain(wordToValidate)) {
        std::cout << "La cadena es aceptada por el AFD.\n";
    } else {
        std::cout << "La cadena no es aceptada por el AFD.\n";
    }
}

