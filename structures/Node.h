#include "../Types/types.h"

struct Node {
    TipoElemento data;
    Node *next;

    Node(TipoElemento dato): data(dato), next(nullptr) {}
    Node(): next(nullptr) {};
};

