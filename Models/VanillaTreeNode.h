#include "../Types/types.h"
class VanillaTreeNode {
private:
    TipoElemento dato;
    VanillaTreeNode *izdo;
    VanillaTreeNode *dcho;

public:
    VanillaTreeNode(TipoElemento valor);

    VanillaTreeNode(VanillaTreeNode* ramaIzdo, TipoElemento valor, VanillaTreeNode* ramaDcho);

    // operaciones de acceso
    TipoElemento valorNodo();
    VanillaTreeNode* subárbolIzdo();
    VanillaTreeNode* subárbolDcho();
    void Visit() const;
    // operaciones de modificación
    void nuevoValor(TipoElemento d);
    void ramaIzdo(VanillaTreeNode* n);
    void ramaDcho(VanillaTreeNode* n);
};



