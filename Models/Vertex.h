//
// Created by dylan_tmut0bm on 30/3/2024.
//

#ifndef SI310_LABS_VERTEX_H
#define SI310_LABS_VERTEX_H


class Vertex {
public:
    char name;
    Vertex *next;

    explicit Vertex(char name);
    Vertex();
};

#endif //SI310_LABS_VERTEX_H
