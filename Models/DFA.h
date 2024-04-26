//
// Created by Antonio on 26/04/2024.
//

#ifndef SI310_LABS_DFA_H
#define SI310_LABS_DFA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
namespace std {
    template<>
    struct hash<std::pair<std::string, char>> {
        size_t operator()(const std::pair<std::string, char>& p) const {
            // Combina los hash de las cadenas y el carácter
            size_t hashValue = hash<std::string>{}(p.first);
            hashValue ^= hash<char>{}(p.second) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
            return hashValue;
        }
    };
}
class DFA {
public:
    explicit DFA();
    ~DFA();

    // Métodos para definir el autómata
    void AddState(std::string state, bool isFinal = false);
    void AddTransition(std::string originState, char symbol, std::string destinyState);
    void DefineInitialState(std::string initialState);
    void DefineAlphabet(const std::unordered_set<char>& alphabet);

    // Métodos para procesar cadenas
    bool ProcessChain(const std::string& chain);

    // Métodos para leer/escribir configuración en archivo
    void WriteConfig(const std::string& fileName) const;
    void ReadConfig(const std::string& fileName);

private:
    std::unordered_set<std::string> states;
    std::unordered_set<std::string> finalStates;
    std::unordered_map<std::pair<std::string, char>, std::string> transitions;
    std::string initialState;
    std::unordered_set<char> alphabet;

    // Función auxiliar para avanzar al siguiente estado
    std::string goTo(std::string currentState, char symbol) const;
};


#endif //SI310_LABS_DFA_H
