#ifndef INT_HEAD
#define INT_HEAD
#include <iostream>
#include "Lista.h"
#include <string>
#include "Premio.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Sorteo {
private:
    Lista<Premio> Ruleta;
public:
    Sorteo();
    ~Sorteo();
    void menu();
    void mostrarDato();
    void eliminarDato();
    void crearDato();
    void mostrarLista();
    void shuffleDato();

};


#endif
