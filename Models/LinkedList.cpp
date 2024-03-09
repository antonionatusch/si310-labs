#include "LinkedList.h"
#include "../Types/types.h"

LinkedList::LinkedList() : head(nullptr){}

void LinkedList::Crear(TipoElemento *array, int n) {
    struct Node *temp, *last;
    head = new Node;
    head->data = array[0];
    head->next = nullptr;

    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = array[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    
}

void LinkedList::InsertarAlPrincipio(TipoElemento data) {
    Node *p = new Node;
    p->data=data;
    p->next=head;
    head=p;
}

void LinkedList::InsertarAlFinal(TipoElemento data) {
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;

    if(head==nullptr)
    {
        head=p;
    }
    else
    {
        Node *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = p;
    }

}

void LinkedList::Mostrar() {
    Node *p = new Node;
    p = head;

    while(p != nullptr)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
}