#include "Lista.h"
#include <iostream>
using namespace std;

template<class Tipo>
Lista<Tipo>::Lista() {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->tam = 0;
}


template<class Tipo>
Lista<Tipo>::Nodo::~Nodo() {
}

template <class Tipo>
void Lista<Tipo>::pushInicio(Tipo* nuevo) {
    Nodo* aux = this->primero;
    this->primero = new Nodo(nuevo);
    this->primero->setSiguiente(aux);
    this->tam++;

    if (this->ultimo == nullptr){
        this->ultimo = this->primero;
        this->primero->setAnterior(this->ultimo);
    }
    if (this->tam == 2){
        this->ultimo->setAnterior(this->primero);
    }

    this->ultimo->setSiguiente(this->primero);
}


template <class Tipo>
void Lista<Tipo>::push(Tipo* nuevo) {
    int actual = 0;
    int posicion;
    Nodo* aux = primero;
    srand(static_cast<unsigned int>(time(nullptr)));
    if (this->primero == this->ultimo || !this->primero) {
        pushInicio(nuevo);
        return;
    } else {
        Nodo* nuevoN = new Nodo(nuevo);
        posicion = (rand() % tam-1) + 1;
        while (aux != this->ultimo){
            if (actual == posicion){
                nuevoN->setSiguiente(aux->getSiguiente());
                nuevoN->setAnterior(aux);
                aux->setSiguiente(nuevoN);
                nuevoN->getSiguiente()->setAnterior(nuevoN);
                tam++;
                return;
            }
            actual++;
            aux = aux->getSiguiente();
        }
    }
}

template <class Tipo>
void Lista<Tipo>::Nodo::setSiguiente(Nodo* ent) {
    this->siguiente = ent;
}

template <class Tipo>
void Lista<Tipo>::Nodo::setAnterior(Nodo* ent) {
    this->anterior = ent;
}

template <class Tipo>
Lista<Tipo>::Nodo::Nodo(Tipo* n) {
    this->contenido = n;
    this->siguiente = nullptr;
}

template <class Tipo>
Lista<Tipo>::~Lista() {
    Nodo* aux = this->primero;
    Nodo* aux2;
    for (int i = 0; i < this->tam; i++) {
        aux2 = aux;
        aux = aux->getSiguiente();
        delete aux2;
    }
}



template <class Tipo>
void Lista<Tipo>::pop(int indice) {
    Nodo* aux = this->primero;

    for (int i = 0; i <= indice; i++) {
        aux = aux->getSiguiente();
    }

    cout << aux->getContenido();
    return;

}

template <class Tipo>
void Lista<Tipo>::shuffleLista() {
    Nodo* aux;
    Tipo* auxNuevo;
    Tipo* aux2;
    int posicion;
    srand(static_cast <unsigned int> (time(nullptr)));
    for (int j = 0; j < 100; j++) {
        aux = this->primero;
        posicion = (rand() % this->tam-2) + 1 ;
        for (int i = 0; i < this->tam; i++){
            if (i == posicion){
                auxNuevo = new Tipo(*aux->getContenido());
                eliminarDato(aux->getContenido());
                push(auxNuevo);
                return;
            }
            aux = aux->getSiguiente();
        }


    }
}
template <class Tipo>
void Lista<Tipo>::mostrarLista(Tipo * indice) {

    Nodo* aux = this->primero;

    if (!this->primero){
        return;
    }

    for (int i = 0; i < this->tam; i++){
        if (*aux->getContenido() > indice){
            cout << aux->getContenido();
        }
        aux = aux->getSiguiente();
    }

}

template <class Tipo>
void Lista<Tipo>::eliminarDato(Tipo * elim) {
    Nodo* aux = this->primero;

    for (int i = 0; i < this->tam; i++){
        if (*aux->getContenido() == elim){
            if (aux == this->primero){
                this->primero = this->primero->getSiguiente();
                this->primero->setAnterior(this->ultimo);
                this->ultimo->setSiguiente(this->primero);
                delete aux;
                this->tam--;
                return;
            }
            if (aux == this->ultimo){
                this->ultimo = this->ultimo->getAnterior();
                this->ultimo->setSiguiente(this->primero);
                delete aux;
                this->tam--;
                return;
            }
            aux->getSiguiente()->setAnterior(aux->getAnterior());
            aux->getAnterior()->setSiguiente(aux->getSiguiente());
            this->tam--;
            delete aux;
            return;
        }
        aux = aux->getSiguiente();
    }
}


template <class Tipo>
typename Lista<Tipo>::Nodo* Lista<Tipo>::Nodo::getSiguiente() {
    return this->siguiente;
}


template <class Tipo>
typename Lista<Tipo>::Nodo* Lista<Tipo>::Nodo::getAnterior() {
    return this->anterior;
}

template <class Tipo>
Tipo* Lista<Tipo>::Nodo::getContenido() {
    return this->contenido;
}

template class
Lista<Premio>;
