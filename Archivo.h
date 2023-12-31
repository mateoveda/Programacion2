#pragma once

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Archivo{
protected:
    string texto;
    string nombreArchivo;
    string linea;
public:
    Archivo();
    string getNombreArchivo();
    string getTexto();
    void setNombreArchivo(string);
    void setlinea(string);
    void settexto(string);
    void guardar(string, string);
    void leerTodo(string);
    void modificarLinea(string, string, string, string);
    void listaFecha(int,int,int);
    void listaEspecifica(string);
};