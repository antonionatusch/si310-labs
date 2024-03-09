#include "Queues.h"
#include <iostream>
using namespace std;

Queues::Queues(int capacity) {
    head = -1;
    tail = -1;
    size = 0;
    this->capacity = capacity;
    queue = new int [capacity];

    for(int i = 0; i < capacity; i++){
        queue[i] = 0;
    }
}

Queues::~Queues() {
    delete[] queue;
}

void Queues::Enqueue(int data) {

    if(IsFull()){
        cout << "Queue is Full!!" << endl;
        return;
    }

    if(IsEmpty()){
        head = 0;
        tail = 0;
    }
    else{
        tail++;
    }

    size++;
    queue[tail] = data;

}

void Queues::ShowQueue() {
    if(IsEmpty()){
        cout << "The queue is empty!!!" << endl;
        return;
    }
    for(int i = 0; i < capacity; i++){
        cout << queue[i] << " ";
    }
    cout << endl;
}

int Queues::Dequeue() {

    if(IsEmpty()){
        cout << "The queue is empty!!!" << endl;
        return -1;
    }

    int data = queue[head++];
    queue[head - 1] = 0;
    size--;

    if(head > tail){
        head = -1;
        tail = -1;
        size = 0;
    }

    return data;

}

bool Queues::IsEmpty() const {
    return (head && tail == -1);
}

bool Queues::IsFull() const {
    return tail == capacity - 1;
}

int Queues::Size() const {
    return IsEmpty() ? -1 : size;
}