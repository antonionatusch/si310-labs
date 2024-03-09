#include "../structures/Node.h"
#include "../Types/types.h"

class LinkedList {
private:
    Node *head;
public:
    LinkedList(); void Crear(TipoElemento array[], int n);
    void InsertarAlPrincipio(TipoElemento data); void InsertarAlFinal(TipoElemento data);
    void Mostrar();
};
