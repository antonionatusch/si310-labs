#include "Stacks.h"
#include <iostream>
using namespace std;

Stacks::Stacks(int n) {
    top = -1;
    this->capacity = n;
    stack = new int [n];

    for(int i = 0; i < n; i++){
        stack[i] = 0;
    }
}

Stacks::~Stacks() {
    delete []stack;
}

void Stacks::Display() {

    if(IsEmpty()){
        cout << "Stack is Empty!!" << endl;
        return;
    }

    for(int i = top; i > -1 ; i--){
        cout << stack[i] << " ";
    }
    cout << endl;

}

void Stacks::Push(int data) {

    if(IsFull()){
        cout << "Stack Overflow!!" << endl;
        return;
    }

    top++;
    stack[top] = data;
}

int Stacks::Pop() {

    if(IsEmpty()){
        return -1;
    }

    int x = stack[top];
    stack[top] = 0;
    top--;

    return x;
}

int Stacks::Peek() {
    return IsEmpty() ? -1 : stack[top];
}

bool Stacks::IsEmpty() const {
    return top == -1;
}

bool Stacks::IsFull() const  {
    return top == capacity - 1;
}

int Stacks::Count() const {
    return IsEmpty() ? -1 : top + 1;
}

void Stacks::Clear() {
    for(int i = top; i > -1; i--){
        stack[i] = 0;
    }
}