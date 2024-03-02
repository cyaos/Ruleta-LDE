#include "Premio.h"

Premio::Premio(string def, string tip, int val, int id) {
    this->desc = def;
    this->tipo = tip;
    this->valor = val;
    this->ID = id;
}

Premio::Premio(const Premio &nuevo) {
    this->desc = nuevo.desc;
    this->tipo = nuevo.tipo;
    this->valor = nuevo.valor;
    this->ID = nuevo.ID;
}

std::ostream& operator<<(std::ostream& salida, const Premio* obj){
    salida << "[ "<< obj->tipo << " : " << obj->desc << " , valorado en " << obj->valor << " ]" << endl;
    return salida;
}

bool operator > (const Premio& este, const Premio* otro){
    if (este.valor > otro->valor){
        return true;
    } else {
        return false;
    }
}

bool operator == (const Premio& este, const Premio* otro){
    if (este.ID == otro->ID){
        return true;
    } else {
        return false;
    }
}

Premio::~Premio() {

}

