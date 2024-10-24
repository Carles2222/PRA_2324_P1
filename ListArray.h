#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* array;         // Puntero al array que almacenará los elementos
    int capacity;     // Capacidad del array
    int count;        // Número actual de elementos en la lista

public:
    // Constructor
    ListArray(int size = 10) {
        capacity = size;
        count = 0;
        array = new T[capacity];
    }

    // Destructor
    ~ListArray() {
        delete[] array;
    }

    // Inserta un elemento en la lista
    void insert(const T& item) override {
        if (count >= capacity) {
            // Si el array está lleno, redimensionamos el array
            resize();
        }
        array[count++] = item;  // Añadimos el nuevo elemento al final
    }

    // Elimina un elemento de la lista
    void remove(const T& item) override {
        for (int i = 0; i < count; ++i) {
            if (array[i] == item) {
                // Desplazamos los elementos hacia la izquierda para llenar el hueco
                for (int j = i; j < count - 1; ++j) {
                    array[j] = array[j + 1];
                }
                count--;  // Reducimos el tamaño
                return;
            }
        }
    }

    // Obtiene el elemento en la posición index
    T get(int index) const override {
        if (index >= 0 && index < count) {
            return array[index];
        }
        throw std::out_of_range("Índice fuera de rango");
    }

    // Devuelve el tamaño actual de la lista
    int size() const override {
        return count;
    }

    // Comprueba si la lista está vacía
    bool isEmpty() const override {
        return count == 0;
    }

private:
    // Redimensiona el array cuando está lleno
    void resize() {
        capacity *= 2;  // Duplicamos la capacidad
        T* newArray = new T[capacity];
        for (int i = 0; i < count; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};

