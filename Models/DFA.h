//
// Created by Antonio on 27/04/2024.
//

#ifndef SI310_LABS_DFA_H
#define SI310_LABS_DFA_H

#include "iostream"
#include "fstream"
#include "vector"
#include "map"
#include "string"

class DFA {
private:
    std::vector<std::string> states;
    std::vector<char> alphabet;
    std::map<std::pair<std::string, char>, std::string> transitions;
    std::string initialState;
    std::vector<std::string> finalStates;
public:
    explicit DFA();
    ~DFA();
    void AddState(const std::string& state, bool isFinal = false);
    void AddTransition(const std::string& originState, char symbol, const std::string destinyState);
    void DefineInitialState(const std::string& initialState);
    void DefineAlphabet(const std::vector<char>& alphabet);
    bool IsAValidChain(const std::string& chain);
    void ReadConfig(const std::string& fileName);
    void WriteConfig(const std::string& fileName);
    void CheckInput(const std::string& userInput);
};


#endif //SI310_LABS_DFA_H
