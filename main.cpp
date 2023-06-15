#include <iostream>
#include <string>
#include <fstream>
#include "Cliente.h"

using namespace std;

int main() {
    Cliente clientes;
    char option, opVarias, opTiempo, opTipo, opEstado;
    int anioCliente, _dia, _mes, _anio, _monto;
    string numCliente, nombre, apellido, tipo, estado, informeClientes, informeTransacciones;
    do {
        cout << "* * * * M E N U * * * *" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Modificar el estado del cliente" << endl;
        cout << "3. Generar extraccion" << endl;
        cout << "4. Generar deposito" << endl;
        cout << "5. Consultas varias" << endl;
        cout << "6. Salir" << endl;
        cout << "" << endl;
        cout << "Ingrese una opcion:" << endl;
        cin >> option;

        switch (option) {
            case '1': //registro
                cout << "Ingrese el numero del cliente: " << endl;
                cin >> numCliente;
                clientes.setNumCliente(numCliente);
                cout << "Ingrese el nombre del cliente: " << endl;
                cin >> nombre;
                clientes.setNombre(nombre);
                cout << "Ingrese el apellido del cliente: " << endl;
                cin >> apellido;
                clientes.setApellido(apellido);
                cout << "Ingrese el anio del cliente: " << endl;
                cin >> anioCliente;
                clientes.setAnio(anioCliente);
                do {
                    cout << "Seleccione el tipo de cliente" << endl;
                    cout << "1. Plata" << endl;
                    cout << "2. Oro" << endl;
                    cout << "3. Black" << endl;
                    cout << "4. Salir" << endl;
                    cout << "" << endl;
                    cin >> opTipo;

                    switch (opTipo) {
                        case '1':
                            clientes.setTipo("plata");
                            cout << "Se ha registrado exitosamente el cliente num. " << numCliente << ": " << nombre
                                 << " " << apellido << endl;
                            cout << "" << endl;
                            clientes.registrar();
                            opTipo = '4';
                            break;

                        case '2':
                            clientes.setTipo("oro");
                            cout << "Se ha registrado exitosamente el cliente num. " << numCliente << ": " << nombre
                                 << " " << apellido << endl;
                            cout << "" << endl;
                            clientes.registrar();
                            opTipo = '4';
                            break;

                        case '3':
                            if (2023 - anioCliente < 3) {
                                cout << "No cumple con la antiguedad necesaria" << endl;
                                cout << "Por favor:" << endl;
                            } else {
                                clientes.setTipo("black");
                                cout << "Se ha registrado exitosamente el cliente num. " << numCliente << ": " << nombre
                                     << " " << apellido << endl;
                                clientes.registrar();
                                opTipo = '4';
                                cout << "" << endl;
                            }
                            break;
                        case '4':
                            cout << "" << endl;
                            break;
                        default:
                            cout << "La opcion ingresada es incorrecta, por favor" << endl;
                            cout << "lea con más detenimiento nuestras opciones e ingrese una opción valida" << endl;
                            cout << "" << endl;
                    }
                } while (opTipo != '4');
                break;

            case '2': //alta-baja
                cout << "Ingrese el numero del cliente: " << endl;
                cin >> numCliente;
                clientes.setNumCliente(numCliente);
                do {
                    cout << "Seleccione el nuevo estado del cliente" << endl;
                    cout << "1. ALTA" << endl;
                    cout << "2. BAJA" << endl;
                    cout << "3. Salir" << endl;
                    cout << "" << endl;
                    cin >> opEstado;
                    switch (opEstado) {
                        case '1':
                            clientes.setEstado("ALTA");
                            clientes.cambiarEstado("BAJA");
                            cout << "Se ha cambiado correctamente el estado del cliente N:" << numCliente << endl;
                            cout << "" << endl;
                            opEstado = '3';
                            break;
                        case '2':
                            clientes.setEstado("BAJA");
                            clientes.cambiarEstado("ALTA");
                            cout << "Se ha cambiado correctamente el estado del cliente N:" << numCliente << endl;
                            cout << "" << endl;
                            opEstado = '3';
                            break;
                        case '3':
                            cout << "" << endl;
                            break;
                        default:
                            cout << "La opcion ingresada no es correcta, por favor seleccione una opcion valida:"
                                 << endl;
                            break;
                    }
                }while(opEstado != '3');
                break;

            case '3': //extraccion
                cout << "Ingrese el numero del cliente: " << endl;
                cin >> numCliente;
                cout << "ingrese el monto a extraer: " << endl;
                cin >> _monto;
                cout << "ingrese el dia: " << endl;
                cin >> _dia;
                cout << "ingrese el mes: " << endl;
                cin >> _mes;
                cout << "ingrese el anio: " << endl;
                cin >> _anio;
                clientes.realizarExtraccion(numCliente, _monto, _dia, _mes, _anio);
                cout << "Se realizó la extracción correctamente" << endl;
                cout << "" << endl;
                break;

            case '4': //deposito
                cout << "Ingrese el numero del cliente: " << endl;
                cin >> numCliente;
                cout << "ingrese el monto a depositar: " << endl;
                cin >> _monto;
                cout << "ingrese el dia: " << endl;
                cin >> _dia;
                cout << "ingrese el mes: " << endl;
                cin >> _mes;
                cout << "ingrese el anio: " << endl;
                cin >> _anio;
                clientes.realizarDeposito(numCliente, _monto, _dia, _mes, _anio);
                cout << "Se realizó la extracción correctamente" << endl;
                cout << "" << endl;
                break;

            case '5':
                do {
                    cout << "* * * CONSULTAS VARIAS * * *" << endl;
                    cout << "1. Cliente por numero" << endl;
                    cout << "2. Todos los Clientes" << endl;
                    cout << "3. Transacciones por Cliente" << endl;
                    cout << "4. Transacciones por periodo de tiempo" << endl;
                    cout << "5. Volver " << endl;
                    cout << "Ingrese una opcion: " << endl;
                    cin >> opVarias;
                    switch (opVarias) {
                        case '1':
                            cout << "Ingrese el numero de cliente" << endl;
                            cin >> numCliente;
                            cout << "" << endl;
                            clientes.transaccionesCliente(numCliente);
                            break;
                        case '2':
                            cout << "Lista de clientes: " << endl;
                            clientes.listaClientes();
                            cout << "" << endl;
                            break;
                        case '3':
                            cout << "Ingrese el numero de cliente" << endl;
                            cin >> numCliente;
                            cout << "" << endl;
                            clientes.transaccionesCliente(numCliente);
                            break;
                        case '4':
                            do {
                                cout << "Como desea su informe?" << endl;
                                cout << "1. Por semestre" << endl;
                                cout << "2. Por anio" << endl;
                                cout << "3. Volver" << endl;
                                cin >> opTiempo;
                                cout << "" << endl;
/*
                                if (clientes.empty()) {
                                    cout << "No hay clientes registrados aun" << endl;
                                } else {
                                    for (int i = 0; i < clientes.size(); i++) {
                                        cout << "Ingrese su fecha de referencia (maxima):" << endl;
                                        //get from Transacciones.txt
                                    }
                                }
                                */
                            } while (opTiempo != 3);
                            break;
                        case '5':
                            break;
                        default:
                            cout << "La opcion ingresada es incorrecta, por favor, revise nuevamente nuestras opciones" << endl;
                            cout << "" << endl;
                    }
                }while(opVarias != '5');
                break;

            case '6':
                break;

            default:
                cout << "La opción ingresada es incorrecta, por favor, verifique estar colocando una opcion legitima" << endl;
                cout << "" << endl;
                break;
        }
    }while(option != '6');
    cout << "Muchas gracias, por usar nuestro sistema de gestion VRP" << endl;
}