//
// Created by Antonio on 05/04/2024.
//

#include "VanillaTreeNode.h"
VanillaTreeNode::VanillaTreeNode(TipoElemento valor) {
    this->dato = valor;
    izdo = dcho = NULL;
}

VanillaTreeNode::VanillaTreeNode(VanillaTreeNode *ramaIzdo, TipoElemento valor, VanillaTreeNode *ramaDcho) {
    this->dato = valor;
    izdo = ramaIzdo;
    dcho = ramaDcho;
}

TipoElemento VanillaTreeNode::valorNodo() {return dato;}

VanillaTreeNode *VanillaTreeNode::subárbolIzdo() {return izdo;}

VanillaTreeNode *VanillaTreeNode::subárbolDcho() {return dcho;}

void VanillaTreeNode::nuevoValor(TipoElemento d) {this->dato = d;}

void VanillaTreeNode::ramaIzdo(VanillaTreeNode *n) {izdo = n;}

void VanillaTreeNode::ramaDcho(VanillaTreeNode *n) {dcho = n;}

void VanillaTreeNode::Visit() const {std::cout<<dato<< " ";}


