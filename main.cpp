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
                cout << "Ingrese el apellido del cliente: " <<endl;
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
                            cout<<"Se ha registrado exitosamente el cliente num. "<<numCliente<<": "<<nombre<<" "<<apellido<<endl;
                            clientes.registrar();
                            break;

                        case '2':
                            clientes.setTipo("oro");
                            cout<<"Se ha registrado exitosamente el cliente num. "<<numCliente<<": "<<nombre<<" "<<apellido<<endl;
                            clientes.registrar();
                            break;

                        case '3':
                            if (2023-anioCliente < 3){
                                cout<<"No cumple con la antiguedad necesaria"<<endl;
                                cout<<"Por favor:"<<endl;
                            } else {
                                clientes.setTipo("black");
                                cout<<"Se ha registrado exitosamente el cliente num. "<<numCliente<<": "<<nombre<<" "<<apellido<<endl;
                                clientes.registrar();
                            }
                            break;
                        case '4':
                            cout << "" << endl;
                            break;
                        default:
                            cout << "La opcion ingresada es incorrecta, por favor, lea con más detenimiento nuestras opciones e ingrese una opción valida" << endl;
                    } break;
                } while (opTipo != '4');

                break;
            case '2': //alta-baja
                cout << "Ingrese el numero del cliente: "<<endl;
                cin >> numCliente;
                clientes.setNumCliente(numCliente);
                do {
                    cout << "Seleccione el nuevo estado del cliente" << endl;
                    cout << "1. ALTA" << endl;
                    cout << "2. BAJA" << endl;
                    cout << "3. Salir" << endl;
                    cout << "" << endl;
                    cin >> opTipo;
                    switch (opTipo) {
                        case '1':
                            clientes.setEstado("ALTA");
                            clientes.cambiarEstado("BAJA");
                            cout << "Se ha cambiado correctamente el estado del cliente N:"<< numCliente << endl;
                            break;
                        case '2':
                            clientes.setEstado("BAJA");
                            clientes.cambiarEstado("ALTA");
                            cout << "Se ha cambiado correctamente el estado del cliente N:"<< numCliente << endl;
                            break;
                        case '3':
                            cout << "" << endl;
                            break;
                        default:
                            cout << "La opcion ingresada no es correcta, por favor seleccione una opcion valida:" << endl;
                    }
            case '3': //extraccion

                if(clientes.empty()){
                    cout << "No hay clientes registrados aun" << endl;
                } else {
                    cout << "Ingrese el numero del cliente: "<<endl;
                    cin >> numCliente;
                    for (int i=0; i<clientes.size(); i++){
                        if(clientes[i].getNumeroCliente().compare(numCliente)){
                            cout << "ingrese el monto a extraer: " << endl;
                            cin >> _monto;
                            cout << "ingrese el dia: " << endl;
                            cin >> _dia;
                            cout << "ingrese el mes: " << endl;
                            cin >> _mes;
                            cout << "ingrese el anio: " << endl;
                            cin >> _anio;
                            clientes[i].realizarExtraccion(_monto, _dia, _mes, _anio);
                        }
                    }
                }
                break;
            case '4': //deposito
                if(clientes.empty()){
                    cout << "No hay clientes registrados aun" << endl;
                } else {
                    cout << "Ingrese el numero del cliente: "<<endl;
                    cin >> numCliente;
                    for (int i=0; i<clientes.size(); i++){
                        if(clientes[i].getNumeroCliente().compare(numCliente)){
                            cout << "ingrese el monto a depositar: " << endl;
                            cin >> _monto;
                            cout << "ingrese el dia: " << endl;
                            cin >> _dia;
                            cout << "ingrese el mes: " << endl;
                            cin >> _mes;
                            cout << "ingrese el anio: " << endl;
                            cin >> _anio;
                            clientes[i].realizarDeposito(_monto, _dia, _mes, _anio);
                        }
                    }
                }
                break;
            case '5':
                do{
                    cout << "* * * CONSULTAS VARIAS * * *" << endl;
                    cout<<"1. Cliente por numero"<<endl;
                    cout<<"2. Todos los Clientes"<<endl;
                    cout<<"3. Transacciones por Cliente"<<endl;
                    cout<<"4. Transacciones por periodo de tiempo"<<endl;
                    cout<<"5. Volver "<<endl;
                    cout<<"Ingrese una opcion: "<<endl;
                    cin>>opVarias;
                    cout<<""<<endl;
                    switch (opVarias) {
                        case '1': //cliente por numero
                            if(clientes.empty()){
                                cout << "No hay clientes registrados aun" << endl;
                            } else {
                                cout << "Ingrese el numero del cliente que busca: " << endl;
                                cin >> numCliente;
                                for (int i = 0; i < clientes.size(); i++) {
                                    if (clientes[i].getNumeroCliente().compare(numCliente)) {
                                        cout<<"Nombre: "<<clientes[i].getNombre()<<endl;
                                        cout<<"Apellido: "<<clientes[i].getApellido()<<endl;
                                        cout<<"Numero de cliente: "<<clientes[i].getNumeroCliente()<<endl;
                                        cout<<"Tipo de contrato: "<<clientes[i].getTipo()<<endl;
                                        cout<<"Anio de suscripcion: "<<clientes[i].getAnioCliente()<<endl;
                                        cout<<"Estado actual: "<<clientes[i].getEstado()<<endl;
                                        if(clientes[i].getTipo().compare("Plata")){
                                            cout<<"Tarjeta: No (Plata)"<<endl;
                                        } else{
                                            cout<<"Tarjeta: Si"<<endl;
                                            cout<<"Tipo: "<<clientes[i].tarjetas.getTipoT()<<endl;
                                            cout<<"Limite: "<<clientes[i].tarjetas.getLimite()<<endl;
                                        }
                                    }
                                }
                            }
                            break;
                        case '2': //lista clientes
                            if(clientes.empty()){
                                cout << "No hay clientes registrados aun" << endl;
                            } else {
                                for (int i = 0; i < clientes.size(); i++){
                                    cout<<clientes[i].getNombre()<<" "<<clientes[i].getApellido()<<"; Num. "<<clientes[i].getNumeroCliente()<<"; Tipo: "<<clientes[i].getTipo()<<endl;
                                }
                            }
                            break;
                        case '3': //transacciones por cliente
                            if(clientes.empty()){
                                cout << "No hay clientes registrados aun" << endl;
                            } else {
                                for (int i = 0; i < clientes.size(); i++){
                                    //get from Transacciones.txt
                                }
                            }
                            break;
                        case '4':
                            do{
                                cout<<"Como desea su informe?"<<endl;
                                cout<<"1. Por semestre"<<endl;
                                cout<<"2. Por anio"<<endl;
                                cout<<"3. Volver"<<endl;
                                cin>>opTiempo;

                                if(clientes.empty()){
                                    cout << "No hay clientes registrados aun" << endl;
                                } else {
                                    for (int i = 0; i < clientes.size(); i++){
                                        cout<<"Ingrese su fecha de referencia (maxima):"<<endl;
                                        //get from Transacciones.txt
                                    }
                                }
                            } while (opTiempo != 3);
                            break;
                        default:
                            cout<<"Opcion invalida"<<endl;
                    }
                } while (opVarias != 5);
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (option != '6');

    for(int i=0; i<clientes.size(); i++){
        cout << clientes[i].getNombre() << endl;
        cout << clientes[i].getApellido() << endl;
        cout << clientes[i].getNumeroCliente() << endl;
        cout << clientes[i].getTipo() << endl;
        cout << clientes[i].getAnioCliente() << endl;
        cout << clientes[i].getEstado() << endl;
        cout << clientes[i].tarjetas.getTipoT() << endl;
    }

    return 0;
}
