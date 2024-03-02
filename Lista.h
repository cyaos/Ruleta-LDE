#ifndef PROBANDOTEMP_LISTA_H
#define PROBANDOTEMP_LISTA_H

#include <string>
#include <ctime>
#include "Premio.h"

template <class Tipo>
class Lista {
private:
    class Nodo {
    private :
        Nodo* siguiente;
        Nodo* anterior;
        Tipo* contenido;

    public:
        Nodo(Tipo*);
        ~Nodo();
        Nodo* getAnterior();
        Nodo* getSiguiente();
        void setAnterior(Nodo*);
        void setSiguiente(Nodo*);
        Tipo* getContenido();
    };
    Nodo* primero;
    Nodo* ultimo;
    int tam;
public:
    Lista();
    ~Lista();
    void push(Tipo*);
    void pushInicio(Tipo*);
    void pop(int);
    void shuffleLista();
    void eliminarDato(Tipo*);
    void mostrarLista(Tipo*);
};

#endif