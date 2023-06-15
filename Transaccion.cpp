#include <random>
#include <ctime>
#include "Transaccion.h"
using namespace std;

Transaccion::Transaccion() {
    numTrans = 0;
    monto = 0;
    dia = 0;
    mes = 0;
    anioTrans = 0;
    tipoTrans = '\0';
    text = "";
    ArchivoTransacciones.setNombreArchivo("ArchivoTransacciones.txt");
    ArchivoTransacciones.setlinea("");
    ArchivoTransacciones.settexto("");
}

void Transaccion::deposito(int _monto, int _dia, int _mes, int _anioTrans) {
    monto = _monto;
    dia = _dia;
    mes = _mes;
    anioTrans = _anioTrans;
    tipoTrans = 'D';
    srand(static_cast<unsigned>(std::time(nullptr)));
    numTrans = rand() % 900 + 100;
    text = to_string(numTrans) + "-" + to_string(monto) + "-" + to_string(dia) + "-" + to_string(mes) + "-" + to_string(anioTrans) + "-" + tipoTrans;
    ArchivoTransacciones.guardar("ArchivoTransacciones.txt",text);
}

void Transaccion::extraccion(int _monto, int _dia, int _mes, int _anioTrans) {
    monto = _monto;
    dia = _dia;
    mes = _mes;
    anioTrans = _anioTrans;
    tipoTrans = 'E';
    srand(static_cast<unsigned>(std::time(nullptr)));
    numTrans = rand() % 900 + 100;
    text = to_string(numTrans) + "-" + to_string(monto) + "-" + to_string(dia) + "-" + to_string(mes) + "-" + to_string(anioTrans) + "-" + tipoTrans;
    ArchivoTransacciones.guardar("ArchivoTransacciones.txt",text);
}

void Transaccion::listaTransacciones(string parametro) {
    ArchivoTransacciones.listaEspecifica(parametro);
}

void Transaccion::setNumTrans(int _numTrans) {
    numTrans = _numTrans;
}
void Transaccion::setMonto(int _monto) {
    monto = _monto;
}
void Transaccion::setDia(int _dia) {
    dia = _dia;
}
void Transaccion::setMes(int _mes) {
    mes = _mes;
}
void Transaccion::setAnioTrans(int _anioTrans) {
    anioTrans = _anioTrans;
}
void Transaccion::setTipoTrans(char _tipoTrans) {
    tipoTrans = _tipoTrans;
}

int Transaccion::getNumTrans() {
    return numTrans;
}
int Transaccion::getMonto() {
    return monto;
}
int Transaccion::getDia() {
    return dia;
}
int Transaccion::getMes() {
    return mes;
}
int Transaccion::getAnioTrans() {
    return anioTrans;
}
char Transaccion::getTipoTrans() {
    return tipoTrans;
}
