#include <string>
#include "Tarjeta.h"
using namespace std;

Tarjeta::Tarjeta(){
    limite = 0;
    tipo_t = "";
}

void Tarjeta::tarjeta_oro() {
    limite = 50000;
    tipo_t = "Oro";
}

void Tarjeta::tarjeta_black() {
    limite = 250000;
    tipo_t = "Black";
}

void Tarjeta::setLimite(int _limite) {
    limite = _limite;
}
void Tarjeta::setTipoT(string _tipo_t) {
    tipo_t = _tipo_t;
}

int Tarjeta::getLimite() {
    return limite;
}
string Tarjeta::getTipoT() {
    return tipo_t;
}