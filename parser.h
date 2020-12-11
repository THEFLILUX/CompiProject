#ifndef COMPILADORESPARSERH
#define COMPILADORESPARSERH

#include <iostream>
#include <string>
using namespace std;

bool parser (string numero);
bool Z1 (string& numero);
bool Z2 (string& numero);
bool Z3 (string& numero);
bool Z4 (string& numero);
bool Z5 (string& numero);
bool Z6 (string& numero);
bool Z7 (string& numero);
bool Z8 (string& numero);
bool Z9 (string& numero);
bool Z10 (string& numero);
bool Z11 (string& numero);
bool Z12 (string& numero);
bool Z13 (string& numero);
bool Z14 (string& numero);
bool U (string& numero);
void error();
bool scanner(string& numero,string token);

void error(){
    cout << "¡Numero Rechazado!" << endl;
    cout << "\n*** ERROR"<< endl;
    exit(1);
}

bool scanner (string& numero,string token) {
    int cont = 0;
    int s = (int)numero.size()-1;
    for(int j = (int)token.size()-1; j >= 0; j--){
        if(numero[s] == token[j]){
            cont++;
        }
        s--;
    }

    if(cont == token.size()){
        for(int i = token.size(); i > 0;i--){
            numero.pop_back();
        }
        return true;
    } else {
        return false;
    }

}

bool parser(string numero) {
    return  Z2(numero) ||
            Z7(numero) ||
            Z8(numero) ||
            Z9(numero) ||
            Z10(numero) ||
            Z11(numero) ||
            Z12(numero) ||
            Z13(numero) ||
            Z14(numero) ||
            U(numero);
}

bool Z1 (string& numero){
    if (scanner(numero,"ein") || scanner(numero,"zwei")
    || scanner(numero,"drei") || scanner(numero,"vier")
    || scanner(numero,"fünf") || scanner(numero,"sechs")
    || scanner(numero,"sieben") || scanner(numero,"acht")
    || scanner(numero,"neun")){
        return true;
    } else {
        return false;
    }
}
bool Z2 (string& numero){
    if(scanner(numero,"zehn")){
        if (numero.empty())
            return true;
        else {
            return Z3(numero);
        }
    } else if (scanner(numero,"elf") || scanner(numero,"zwölf")) {
        return true;
    } else {
        return false;
    }
}
bool Z3 (string& numero){
    if (scanner(numero,"drei") || scanner(numero,"vier")
    || scanner(numero,"fünf") || scanner(numero,"sech")
    || scanner(numero,"sieb") || scanner(numero,"acht")
    || scanner(numero,"neun")){
        return true;
    } else {
        return false;
    }
}
bool Z4 (string& numero){
    if (scanner(numero,"zwan") || scanner(numero,"vier")
    || scanner(numero,"fünf") || scanner(numero,"sech")
    || scanner(numero,"sieb") || scanner(numero,"acht")
    || scanner(numero,"neun")){
        return true;
    } else {
        return false;
    }
}
bool Z5 (string& numero){
    if (scanner(numero,"hundert")){
        return true;
    } else {
        return false;
    }
}
bool Z6 (string& numero){
    if (scanner(numero,"tausend")){
        return true;
    } else {
        return false;
    }
}
bool Z7 (string& numero){
    if (scanner(numero,"zig")){
        return Z4(numero);
    } else if (scanner(numero,"ssig")){
        if (scanner(numero,"drei"))
            return true;
        else
            return false;
    } else {
        return false;
    }
}
bool Z8 (string& numero){
    if (Z7(numero)){
        return U(numero);
    } else {
        return false;
    }
}
bool Z9 (string& numero){
    if (Z5(numero)){
        return Z1(numero);
    } else {
        return false;
    }
}
bool Z10 (string& numero){
    if (Z5(numero)){
        return Z2(numero);
    } else {
        return false;
    }
}
bool Z11 (string& numero){
    if(Z1(numero) || Z2(numero) || Z7(numero) || Z8(numero)) {
        return Z5(numero) || Z9(numero);
    } else {
        return false;
    }
}
bool Z12 (string& numero){
    if(Z1(numero) ||  Z2(numero) ||  Z7(numero) ||  Z8(numero)) {
        return Z10(numero);
    } else {
        return false;
    }
}
bool Z13 (string& numero){
    if (Z6(numero)){
        if(Z1(numero) || Z2(numero)|| Z7(numero) || Z8(numero)|| Z9(numero) || Z11(numero))
            return true;
        else
            return false;
    } else {
        return false;
    }
}
bool Z14 (string& numero){
    if(Z1(numero) || Z2(numero) || Z7(numero) || Z8(numero) || Z9(numero) || Z11(numero)) {
        return Z6(numero) || Z13(numero);
    } else {
        return false;
    }
}
bool U (string& numero){
    if(scanner(numero,"und")){
        return Z1(numero);
    } else {
        return false;
    }
}

#endif //COMPILADORESPARSERH
