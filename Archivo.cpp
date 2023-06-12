#include "Archivo.h"
#include <iostream>
#include <fstream>
#include <string>

Archivo::Archivo(){
    texto = "";
    nombreArchivo = "";
    linea = "";
}
string Archivo::getNombreArchivo(){
    return nombreArchivo;
}

string Archivo::getTexto() {
    return texto;
}

void Archivo::setNombreArchivo(string NombreArchivo) {
    nombreArchivo = NombreArchivo;
}

void Archivo::setlinea(string Linea) {
    linea = Linea;
}

void Archivo::settexto(string Texto){
    texto = Texto;
}

void Archivo::guardar(string NombreArchivo, string Texto) {
    ofstream archivo(NombreArchivo);
    archivo << Texto << endl;
    archivo.close();
}

void Archivo::leerTodo(string NombreaArchivo){
    ifstream archivo(NombreaArchivo);
    while(getline(archivo,linea)){
        cout<<linea<<"\n";
    }
}

void Archivo::modificarLinea(string NombreArchivo, string CodigoCliente, string buscar, string reemplazar) {
    texto = "";
    linea = "";
    ifstream archivo(NombreArchivo);
    while(getline(archivo,linea)){
        if(linea.find(CodigoCliente) != string::npos){
            size_t posicion = linea.find(buscar);
            linea.replace(posicion, buscar.length(), reemplazar);
        }
        texto = texto + linea + "\n";
    }
    archivo.close();
    ofstream archivoSalida(NombreArchivo);
    archivoSalida << texto << endl;
    archivo.close();
}

void Archivo::listaFecha(int, int, int) {

}

void Archivo::listaEspecifica(string CodigoCliente) {
    texto = "";
    linea = "";
    nombreArchivo = "ArchivoClientes.txt";
    ifstream archivo(nombreArchivo);
    while(getline(archivo,linea)){
        if(linea.find(CodigoCliente) != string::npos){
            getline(archivo,linea);
            texto = texto + linea + "\n";
        }
    }
    cout << texto << "\n";
}