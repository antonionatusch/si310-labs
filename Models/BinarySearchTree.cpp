#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//Privado
TreeNode* BinarySearchTree::Insert(TreeNode *r, TipoElemento &data) {

    if(r == nullptr){
        return new TreeNode(data);
    }

    if(data < r->GetData()){
        TreeNode *left = Insert(r->GetLeft(), data);
        r->SetLeft(left);
    }
    else if(data > r->GetData()){
        TreeNode* right = Insert(r->GetRight(), data);
        r->SetRight(right);
    }

    return r;

}



void BinarySearchTree::Preorder(TreeNode *r) {
    if(r != nullptr){
        r->Visit();
        BinarySearchTree::Preorder(r->GetLeft());
        BinarySearchTree::Preorder(r->GetRight());
    }
}

void BinarySearchTree::InOrder(TreeNode *r) {
    if(r != nullptr){
        BinarySearchTree::InOrder(r->GetLeft());
        r->Visit();
        BinarySearchTree::InOrder(r->GetRight());
    }
}

void BinarySearchTree::PostOrder(TreeNode *r) {
    if(r != nullptr){
        BinarySearchTree::PostOrder(r->GetLeft());
        BinarySearchTree::PostOrder(r->GetRight());
        r->Visit();
    }
}

int BinarySearchTree::Height(TreeNode *r) {
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

bool BinarySearchTree::isFull(TreeNode *r) {
    if (r == nullptr)
        return true;
    else
        if (Height(r->GetLeft()) != Height(r->GetRight()))
            return false;
    return isFull(r->GetLeft()) && isFull(r->GetRight());


}

int BinarySearchTree::NodeCount(TreeNode *r) {
    if (r == nullptr)
        return 0;
    else
        return 1 + NodeCount(r->GetLeft()) + NodeCount(r->GetRight());
}

TreeNode *BinarySearchTree::Find(TreeNode *subRoot, TipoElemento &searched) {
    if (subRoot == nullptr)
        return nullptr;
    else if (searched == subRoot->GetData())
        return subRoot;
    else if (searched < subRoot->GetData())
        return Find(subRoot->GetLeft(), searched);
    else
        return Find(subRoot->GetRight(), searched);
}

TreeNode *BinarySearchTree::Replace(TreeNode *current) {
    TreeNode *a, *p;
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

TreeNode *BinarySearchTree::Delete(TreeNode *subRoot, TipoElemento &data) {
    if(isEmpty())
        std::cout<<"No se ha encontrado el nodo con el dato provisto.";
    else if (data < subRoot->GetData())
    {
        TreeNode* newLeft;
        newLeft = Delete(subRoot->GetLeft(), data);
        subRoot->SetLeft(newLeft);
    }
    else if (data > subRoot->GetData()){
        TreeNode* newRight;
        newRight = Delete(subRoot->GetRight(), data);
        subRoot->SetRight(newRight);
    } // proceso de búsqueda según el libro: si el dato es menor, va iterando recursivamente ya sea en el subárbol izq o derecho hasta encontrarlo
    else // cuando encuentra el nodo:
    {
        TreeNode *nodeToDelete;
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

//Público
void BinarySearchTree::Insert(TipoElemento data) {
    root = Insert(root, data);
}

void BinarySearchTree::PreOrder() {
    Preorder(root);
}

void BinarySearchTree::InOrder() {
    InOrder(root);
}

void BinarySearchTree::PostOrder() {
    PostOrder(root);
}

void BinarySearchTree::MultiInsert(int n) {
    TipoElemento tmp;
    for (int i = 0; i < n; i++){
        std::cout<<"Elemento "<<i+1<<": ";
        std::cin>>tmp;
        Insert(tmp);
    }
}

bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

int BinarySearchTree::Height() {
    return Height(root);
}

bool BinarySearchTree::isFull() {
    return isFull(root);
}

int BinarySearchTree::NodeCount() {
    return NodeCount(root);
}

TreeNode *BinarySearchTree::Find(TipoElemento searched) {
    return Find(root, searched);
}

void BinarySearchTree::Delete(TipoElemento data) {
    root = Delete(root, data);
}

void BinarySearchTree::Menu() {
    char op;
    BinarySearchTree bst;

    do
    {
        std::cout<<"MENU DE ÁRBOL BINARIO DE BÚSQUEDA \n";
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
                bst.MultiInsert(n);
                break;

            case '2':
                std::cout<<"Recorriendo PreOrden... \n";
                bst.PreOrder();
                break;

            case '3':
                std::cout<<"Recorriendo InOrden... \n";
                bst.InOrder();
                break;

            case '4':
                std::cout<<"Recorrido PostOrden... \n";
                bst.PostOrder();
                break;

            case '5':
                std::cout<<"La altura del árbol es... "<<bst.Height()<<"\n";
                break;

            case '6':
                int keyToDelete;
                std::cout<<"Digite la clave a eliminar: ";
                std::cin>>keyToDelete;
                std::cout<<"Previamente, la clave se encontraba en el nodo con dirección: "<<bst.Find(keyToDelete)<<"\n";
                std::cout<<"Eliminando... \n"; bst.Delete(keyToDelete);
                std::cout<<"Si tiene dirección 0, se eliminó correctamente. \n Dirección: "<<bst.Find(keyToDelete)<<"\n";
            case '7':
                std::cout<<"La cantidad de nodos presente en el árbol es: "<<bst.NodeCount()<<"\n";
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