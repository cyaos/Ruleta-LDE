
#include "Sorteo.h"

Sorteo::Sorteo(){
}

void Sorteo::menu(){
    char decision;
    do{
        cout << "MENU. [1] Nuevo premio [2] Eliminar premio [3] Ver premios [4] Barajar [5] Girar [X] Salir >>> ";
        cin >> decision;

        switch (decision) {
            case '1':
                crearDato();
                continue;
            case '2':
                eliminarDato();
                continue;
            case '3':
                mostrarLista();
                continue;
            case '4':
                shuffleDato();
                continue;
            case '5':
                mostrarDato();
                continue;
            case 'X':
                return;
            default:
                cout << "Esa opcion no existe." << endl;
        }
    } while (decision != 4);
}

void Sorteo::crearDato() {
    string tipo;
    string desc;
    int valor;
    int ID;
    cin.ignore();
    cout << "Ingrese descripción del premio >>> ";
    getline(cin, desc);
    cout << "Ingrese tipo de premio >>> ";
    getline(cin, tipo);
    cout << "Ingrese valor monetario en colones >>> ";
    cin >> valor;
    cout << "Ingrese un ID UNICO para este premio >>> ";
    cin >> ID;

    Ruleta.push(new Premio(desc, tipo, valor,ID));

}

void Sorteo::mostrarDato() {
    int indice = 0;
    while (indice > 500 || indice < 1) {
        cout << "Ingrese un índice de fuerza (numero entero entre 1 y 500) >>> ";
        cin >> indice;
    }
    Ruleta.pop(indice);
}

void Sorteo::eliminarDato() {
    int indice;
    cout << "Ingrese el índice >>> ";
    cin >> indice;

    Ruleta.eliminarDato(new Premio("0","0",0,indice));

}

void Sorteo::shuffleDato(){
    Ruleta.shuffleLista();
}

void Sorteo::mostrarLista() {
    int valor;
    cout << "Ver solo premios cuyo valor monetario sea mayor que >>> " ;
    cin >> valor;
    Ruleta.mostrarLista(new Premio("0", "0", valor, 0));
}

Sorteo::~Sorteo(){

}