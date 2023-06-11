#include <iostream>
#include "Archivo.h"
using namespace std;

class Transaccion{
private:
    int numTrans;
    int monto;
    int dia;
    int mes;
    int anioTrans;
    char tipoTrans;
    Archivo ArchivoTransacciones;

public:
    Transaccion();
    void extraccion (int, int, int, int);
    void deposito (int, int, int, int);

    void setNumTrans(int);
    void setMonto(int);
    void setDia(int);
    void setMes(int);
    void setAnioTrans(int);
    void setTipoTrans(char);

    int getNumTrans();
    int getMonto();
    int getDia();
    int getMes();
    int getAnioTrans();
    char getTipoTrans();
};