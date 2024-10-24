#include <iostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;  // Apuntador al primer nodo
    Node<T>* tail;  // Apuntador al último nodo
    int size;       // Tamaño de la lista

public:
    ListLinked() : head(nullptr), tail(nullptr), size(0) {}

    ~ListLinked() {
        clear();  // Liberar memoria de todos los nodos
    }

    // Añade un elemento al frente de la lista
    void addFront(const T& value) override {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;  // Si la lista estaba vacía
        }
        size++;
    }

    // Añade un elemento al final de la lista
    void addBack(const T& value) override {
        Node<T>* newNode = new Node<T>(value, nullptr);
        if (tail != nullptr) {
            tail->next = newNode;  // Enlazar el nuevo nodo
        } else {
            head = newNode;  // Si la lista estaba vacía
        }
        tail = newNode;
        size++;
    }

    // Elimina el primer elemento de la lista
    void removeFront() override {
        if (head == nullptr) {
            throw std::out_of_range("La lista está vacía.");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = nullptr;  // Si la lista se vació
        }
    }

    // Devuelve el tamaño de la lista
    int getSize() const override {
        return size;
    }

    // Elimina todos los elementos de la lista
    void clear() override {
        while (head != nullptr) {
            removeFront();
        }
    }

    // Muestra los elementos de la lista (opcional para debug)
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }
};

