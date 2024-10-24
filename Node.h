#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;      // Almacena el valor del nodo
    Node* next;  // Puntero al siguiente nodo

    // Constructor por defecto
    Node() : next(nullptr) {}

    // Constructor con un valor
    Node(const T& data) : data(data), next(nullptr) {}

    // Destructor
    ~Node() {
        next = nullptr;  // No es necesario liberar memoria manualmente
    }
    
    // Imprimir el nodo (sobrecarga del operador <<)
    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
        os << node.data;
        return os;
    }
};

#endif  // NODE_H

