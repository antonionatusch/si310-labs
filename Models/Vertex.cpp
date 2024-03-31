#include "Vertex.h"

Vertex::Vertex(char name) {
    this->name = name;
    next = nullptr;
}

Vertex::Vertex() {
    next = nullptr;
}