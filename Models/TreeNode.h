#include "../Types/types.h"

class TreeNode {
    TipoElemento data;
    TreeNode *left;
    TreeNode *right;
    int bf;

public:

    explicit TreeNode(TipoElemento &data);
    explicit TreeNode(TipoElemento &data, bool bfEnabled);
    void Visit() const;

    //Ya que son miembros privados, se debe acceder a ellos mediante funciones
    TreeNode* GetLeft();
    TreeNode* GetRight();
    TipoElemento GetData() const;

    //Ya que son privados, se debe asignar con un set los valores
    void SetLeft(TreeNode* left);
    void SetRight(TreeNode *right);
};


