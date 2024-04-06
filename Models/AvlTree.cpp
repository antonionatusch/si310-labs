//
// Created by Antonio on 31/03/2024.
//

#include "AvlTree.h"
AvlTree::AvlTree() {
    root = nullptr;
}

// Privado
AvlNode *AvlTree::LLRotation(AvlNode *first, AvlNode *next) {
    first->SetLeft(next->GetRight());
    next->SetRight(first);
    if (next->GetBalanceFactor() == -1)
    {
        first->SetBalanceFactor(0);
        next->SetBalanceFactor(0);
    }
    else
    {
        first->SetBalanceFactor(-1);
        next->SetBalanceFactor(1);
    }
    return next;
}

AvlNode *AvlTree::RRRotation(AvlNode *first, AvlNode *next) {
    first->SetRight(next->GetLeft());
    next->SetLeft(first);

    if(next->GetBalanceFactor() == 1)
    {
        first->SetBalanceFactor(0);
        next->SetBalanceFactor(0);
    }
    else
    {
        first->SetBalanceFactor(1);
        next->SetBalanceFactor(-1);
    }
    return next;
}

AvlNode *AvlTree::LRRotation(AvlNode *first, AvlNode *next) {
    AvlNode* further;

    further = next->GetRight();
    first->SetLeft(further->GetRight());
    further->SetRight(first); // hasta aca, lo deja en rotación derecha derecha

    next->SetRight(further->GetLeft());
    further->SetLeft(next);

    if(further->GetBalanceFactor() == 1)
        next->SetBalanceFactor(-1);
    else
        next->SetBalanceFactor(0);

    if(further->GetBalanceFactor() == -1)
        first->SetBalanceFactor(1);
    else
        first->SetBalanceFactor(0);

    further->SetBalanceFactor(0); // se entiende que ya está equilibrado el nodo
    return further;
}

AvlNode *AvlTree::RLRotation(AvlNode *first, AvlNode *next) {
    AvlNode* further;

    further = next->GetLeft();
    first->SetRight(further->GetLeft());
    further->SetLeft(first);

    next->SetLeft(further->GetRight());
    further->SetRight(next);

    if (further->GetBalanceFactor() == 1)
        first->SetBalanceFactor(-1);
    else
        first->SetBalanceFactor(0);

    if(further->GetBalanceFactor() == -1)
        first->SetBalanceFactor(1);
    else
        first->SetBalanceFactor(0);
    further->SetBalanceFactor(0);
    return further;

}

AvlNode *AvlTree::AvlInsert(AvlNode *r, TipoElemento data, bool &heightChanged) {
    AvlNode* next;

    if (r == nullptr)
    {
        r = new AvlNode(data);
        heightChanged = true;
    }
    else if (data < r->GetData())
    {
        AvlNode* newLeft;
        newLeft = AvlInsert(r->GetLeft(), data, heightChanged);
        r->SetLeft(newLeft);
        if (heightChanged)
        {   // comprobamos primero si cambio de altura

            switch (r->GetBalanceFactor()) {

                case 1:
                    r->SetBalanceFactor(0);
                    heightChanged = false;
                    break;
                case 0:
                    r->SetBalanceFactor(-1);
                    break;
                case -1:
                    next = r->GetLeft();
                    if (next->GetBalanceFactor() == -1)
                        r = LLRotation(r, next);
                    else
                        r = LRRotation(r, next);
                    heightChanged = false;

            }
        }
    }
    else if (data > r->GetData())
    {
        AvlNode* newRight;
        newRight = AvlInsert(r->GetRight(), data, heightChanged);
        r->SetRight(newRight);

        if (heightChanged)
        {
            switch (r->GetBalanceFactor()) {
                case 1:
                    next = r->GetRight();
                    if (next->GetBalanceFactor() == 1)
                        r = RRRotation(r, next);
                    else
                        r = RLRotation(r, next);
                    heightChanged = false;
                    break;
                case 0:
                    r->SetBalanceFactor(1);
                    break;
                case -1:
                    r->SetBalanceFactor(0);
                    break;

            }
            
            
            
        }

    }
    else
        std::cout<<"No puede haber claves repetidas";
    return r;
}

void AvlTree::Preorder(AvlNode *r) {
    if (r != nullptr)
    {
        r->Visit();
        Preorder(r->GetLeft());
        Preorder(r->GetRight());
    }
}

void AvlTree::InOrder(AvlNode *r) {

    if (r != nullptr)
    {
        InOrder(r->GetLeft());
        r->Visit();
        InOrder(r->GetRight());
    }
}

void AvlTree::PostOrder(AvlNode *r) {

    if (r != nullptr)
    {
        PostOrder(r->GetLeft());
        PostOrder(r->GetRight());
        r->Visit();
    }

}

AvlNode *AvlTree::Replace(AvlNode *current) {
    AvlNode *a, *p;
    p = current;
    a = current->GetLeft(); // rama de nodos menores
    while (a->GetRight() != nullptr)
    {
        p = a;
        a = a->GetRight();
    }
    // copia en current el valor (data) del nodo apuntado por a
    current->SetData(a->GetData());
    if (p == a) // si a es el hijo izquierdo de current
        p->SetLeft(a->GetLeft());
    else
        p->SetRight(a->GetRight());
    return a;
}

AvlNode *AvlTree::Delete(AvlNode *subRoot, TipoElemento &data) {
    if(isEmpty())
        std::cout<<"No se ha encontrado el nodo con el dato provisto.";
    else if (data < subRoot->GetData())
    {
        AvlNode* newLeft;
        newLeft = Delete(subRoot->GetLeft(), data);
        subRoot->SetLeft(newLeft);
    }
    else if (data > subRoot->GetData()){
        AvlNode* newRight;
        newRight = Delete(subRoot->GetRight(), data);
        subRoot->SetRight(newRight);
    } // proceso de búsqueda según el libro: si el dato es menor, va iterando recursivamente ya sea en el subárbol izq o derecho hasta encontrarlo
    else // cuando encuentra el nodo:
    {
        AvlNode *nodeToDelete;
        nodeToDelete = subRoot;
        if (nodeToDelete->GetLeft() == nullptr)
            subRoot = nodeToDelete->GetRight();
        else if (nodeToDelete->GetRight() == nullptr)
            subRoot = nodeToDelete->GetLeft();
        else
        {   // si tiene rama izq y derecha
            Replace(nodeToDelete);
        }
    }
    return subRoot;
}

AvlNode *AvlTree::Find(AvlNode *subRoot, TipoElemento &searched) {
    if (subRoot == nullptr)
        return nullptr;
    else if (searched == subRoot->GetData())
        return subRoot;
    else if (searched < subRoot->GetData())
        return Find(subRoot->GetLeft(), searched);
    else
        return Find(subRoot->GetRight(), searched);
}

int AvlTree::Height(AvlNode *r) {
    if (r == nullptr)
        return 0;
    else
    {
        int leftHeight = Height(r->GetLeft());
        int rightHeight = Height(r->GetRight());
        if (leftHeight > rightHeight)
            return leftHeight + 1; // +1 por la raiz
        else
            return rightHeight + 1;
    }
}

bool AvlTree::isFull(AvlNode *r) {
    if (r == nullptr)
        return true;
    else
    if (Height(r->GetLeft()) != Height(r->GetRight()))
        return false;

    return isFull(r->GetLeft()) && isFull(r->GetRight());

}

int AvlTree::NodeCount(AvlNode *r) {
    if (r == nullptr)
        return 0;
    else
        return 1 + NodeCount(r->GetLeft()) + NodeCount(r->GetRight());
}


// Público
void AvlTree::Insert(TipoElemento data) {
    bool heightChanged = false;
    root = AvlInsert(root, data, heightChanged);
}

void AvlTree::MultiInsert(int n) {
    TipoElemento tmp;
    for (int i = 0; i < n; i++){
        std::cout<<"Elemento "<<i+1<<": ";
        std::cin>>tmp;
        Insert(tmp);
    }
}

void AvlTree::Preorder() {
    Preorder(root);
}

void AvlTree::InOrder() {
    InOrder(root);
}

void AvlTree::PostOrder() {
    PostOrder(root);
}

AvlNode *AvlTree::Find(TipoElemento searched) {
    return Find(root, searched);
}

bool AvlTree::isEmpty() {
    return root == nullptr;
}

void AvlTree::Delete(TipoElemento data) {
    Delete(root, data);
}

int AvlTree::isFull() {
    return isFull(root);
}

int AvlTree::Height() {
    return Height(root);
}

int AvlTree::NodeCount() {
    return NodeCount(root);
}

void AvlTree::Menu() {
    char op;
    AvlTree avl;
    do
    {
        std::cout<<"MENU DE ÁRBOL AVL \n";
        std::cout<<"1.- Insertar elementos \n";
        std::cout<<"2.- Recorrido PreOrden \n";
        std::cout<<"3.- Recorrido InOrden \n";
        std::cout<<"4.- Recorrido PostOrden \n";
        std::cout<<"5.- Averiguar la altura del árbol \n";
        std::cout<<"6.- Borrar un elemento dada una clave \n";
        std::cout<<"7.- Encontrar la cantidad de nodos \n";
        std::cout<<"Digite una opción para ejecutarla o s para salir...\n";
        std::cin>>op;

        switch (op)
        {
            case '1':
                int n;
                std::cout<<"Digite la cantidad de elementos a insertar: ";
                std::cin>>n;
                avl.MultiInsert(n);
                break;

            case '2':
                std::cout<<"Recorriendo PreOrden... \n";
                avl.Preorder();
                break;

            case '3':
                std::cout<<"Recorriendo InOrden... \n";
                avl.InOrder();
                break;

            case '4':
                std::cout<<"Recorrido PostOrden... \n";
                avl.PostOrder();
                break;

            case '5':
                std::cout<<"La altura del árbol es... "<<avl.Height()<<"\n";
                break;

            case '6':
                int keyToDelete;
                std::cout<<"Digite la clave a eliminar: ";
                std::cin>>keyToDelete;
                std::cout<<"Previamente, la clave se encontraba en el nodo con dirección: "<<avl.Find(keyToDelete)<<"\n";
                std::cout<<"Eliminando... \n"; avl.Delete(keyToDelete);
                std::cout<<"Si tiene dirección 0, se eliminó correctamente. \n Dirección: "<<avl.Find(keyToDelete)<<"\n";
            case '7':
                std::cout<<"La cantidad de nodos presente en el árbol es: "<<avl.NodeCount()<<"\n";
            case 's':
                std::cout<<"Hasta luego...";
                break;
            default:
                std::cout<<"Opción no existente, intente de nuevo...";
                break;
        }

    }
    while(op != 's');

}






