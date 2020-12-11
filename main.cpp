#include "parser.h"

using namespace std;

int main() {
    string numero;
    cout << "Insertar numero en aleman: "; cin >>  numero;
    if(parser(numero)){
        cout << "¡Numero Aceptado!" << endl;
    } else {
        error();
    }
    return 0;
}