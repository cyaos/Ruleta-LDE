
#include "Lista.h"
#include "Sorteo.h"
using namespace std;

int main() {
    Sorteo* a = new Sorteo();
    a->menu();
    delete a;
    return 0;
}
