//
// Created by dylan_tmut0bm on 30/3/2024.
//

#include "Vertex.h"

Vertex::Vertex(char name) {
    this->name = name;
    next = nullptr;
}

Vertex::Vertex() {
    next = nullptr;
}