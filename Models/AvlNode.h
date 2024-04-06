#include "../Types/types.h"

class AvlNode {
private:
    TipoElemento data;
    AvlNode *left;
    AvlNode *right;
    int balanceFactor;

public:
    explicit AvlNode(TipoElemento &data);

    // operaciones de acceso
    AvlNode* GetLeft();
    AvlNode* GetRight();
    TipoElemento GetData() const;
    void Visit();
    int GetBalanceFactor();
    //Ya que son privados, se debe asignar con un set los valores
    void SetLeft(AvlNode* left);
    void SetRight(AvlNode *right);
    void SetData(TipoElemento newData);
    void SetBalanceFactor(int newBalanceFactor);


};



