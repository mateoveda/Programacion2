#include <iostream>
#include <string>
#include "Tarjeta.h"
#include "Transaccion.h"
using namespace std;

class Archivo;
class Cliente{
private:
    Transaccion transacciones;
    Archivo ArchivoClientes;
    string numeroCliente;
    string nombre;
    string apellido;
    string tipo;
    int anioCliente;
    string estado;

public:
    Tarjeta tarjetas;
    Cliente();
    void setNumCliente(string);
    void setNombre(string);
    void setApellido(string);
    void setTipo(string);
    void setAnio(int);
    void setEstado(string);

    string getNumeroCliente();
    string getNombre();
    string getApellido();
    string getTipo();
    int getAnioCliente();
    string getEstado();
    void registrar();
    void cambiarEstado(string);
    void realizarExtraccion(int, int, int, int);
    void realizarDeposito(int, int, int, int);
    void listaClientes();
    void transaccionesCliente(string);

};