#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
    numeroCliente = "";
    nombre = "";
    apellido = "";
    tipo = "";
    anioCliente = 0;
    estado = "";
    ArchivoClientes.setlinea("");
    ArchivoClientes.setNombreArchivo("ArchivoClientes.txt");
    ArchivoClientes.settexto("");
}

void Cliente::setNumCliente(string _numCliente){
    numeroCliente = _numCliente;
}
void Cliente::setNombre(string _nombre){
    nombre = _nombre;
}
void Cliente::setApellido(string _apellido){
    apellido = _apellido;
}
void Cliente::setTipo(string _tipo){
    tipo = _tipo;
}
void Cliente::setAnio(int _anio){
    anioCliente = _anio;
}
void Cliente::setEstado(string _estado){
    estado = _estado;
}

string Cliente::getNumeroCliente(){
    return numeroCliente;
}
string Cliente::getNombre(){
    return nombre;
}
string Cliente::getApellido(){
    return apellido;
}
string Cliente::getTipo(){
    return tipo;
}
int Cliente::getAnioCliente(){
    return anioCliente;
}
string Cliente::getEstado(){
    return estado;
}

void Cliente::registrar(){
    string variable = numeroCliente + "-" + nombre + "-" + apellido + "-" + tipo + "-" + to_string(anioCliente) + "-ALTA";
    ArchivoClientes.guardar(ArchivoClientes.getNombreArchivo(),variable);
}

void Cliente::cambiarEstado(string buscar) {
    ArchivoClientes.modificarLinea(ArchivoClientes.getNombreArchivo(),numeroCliente,buscar,estado);
}

void Cliente::realizarDeposito(int monto, int dia, int mes, int anio) {
    transacciones.deposito(monto, dia, mes, anio);
}

void Cliente::realizarExtraccion(int monto, int dia, int mes, int anio) {
    transacciones.extraccion(monto, dia, mes, anio);
}

void Cliente::listaClientes() {
    ArchivoClientes.leerTodo("ArchivoClientes.txt");
}

void Cliente::transaccionesCliente(string NumCliente){
    transacciones.listaTransacciones(NumCliente);
}


