#include "../Types/types.h"

class Node {
    TipoElemento data;
    Node *left;
    Node *right;

public:

    explicit Node(TipoElemento &data);
    void Visit() const;

    //Ya que son miembros privados, se debe acceder a ellos mediante funciones
    Node* GetLeft();
    Node* GetRight();
    TipoElemento GetData() const;

    //Ya que son privados, se debe asignar con un set los valores
    void SetLeft(Node* left);
    void SetRight(Node *right);
};


