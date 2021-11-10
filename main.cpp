#include <iostream>
#include <string>
#include <fstream>
#include "cliente.h"

using namespace std;

void catalogoClientes(int);
int nClientesRegistrados();
void agregarNuevoCliente(int nClientes);

FILE* archivo;

Cliente clientes[200];

int main(){
	
	int salir=0, opc=0;
	int nClientes=0;

	do{
		system("cls");
		cout<<"       Bienvenido a Biblioteca TECA"<<endl<<endl<<endl;
		cout<<"*Ingrese 1 para Visualizar las opciones del catalogo de 'CLIENTE'"<<endl<<endl;
		cout<<"*Ingrese 2 para Visualizar las opciones del catalogo de 'EJEMPLARES'"<<endl<<endl;
		cout<<"*Ingrese 3 para Registrar un PRESTAMO DE LIBRO"<<endl<<endl;
		cout<<"*Ingrese 4 para Registrar una DEVOLUCION DE UN LIBRO"<<endl<<endl;
		cout<<"*Ingrese 0 para SALIR\n->";
		cin.clear();
		cin>>opc;
		
		system("cls");
		
		switch(opc){
			
			case 0:{
				cout<<"*Saliendo..."<<endl;
				salir=1;
				system("pause");
				system("cls");
				break;
			}
			
			case 1:{
				nClientes=nClientesRegistrados();
				catalogoClientes(nClientes);	
				system("pause");
				break;
			}
			
			default:{
				cout<<"*Error! parametro no valido"<<endl;
				system("pause");
				system("cls");
				break;
			}
		}
		
	}while(salir!=1);
	
	fclose(archivo);
	return 0;
}

void catalogoClientes(int nClientes){
	
	int opc=0;
	int salir=0;
	
	do{
		system("cls");
		cout<<"       CATALOGO CLIENTE"<<endl<<endl<<endl;
		cout<<"*Ingrese 1 para alta"<<endl<<endl;
		cout<<"*Ingrese 2 para baja"<<endl<<endl;
		cout<<"*Ingrese 3 para modificar cliente"<<endl<<endl;
		cout<<"*Ingrese 4 para ver todos los clientes registrados"<<endl<<endl;
		cout<<"*Ingrese 5 para ver buscar un cliente por DPI"<<endl<<endl;
		cout<<"*Ingrese 0 para SALIR\n->";
		cin.clear();
		cin>>opc;
	
		system("cls");
		
		switch(opc){
			case 0:{
				cout<<"*Saliendo..."<<endl;
				salir=1;
				system("pause");
				system("cls");
				break;
			}
			
			case 1:{
				nClientes=nClientesRegistrados();
				cout<<"La cantidad de clientes actuales son: "<<nClientes<<endl;
				agregarNuevoCliente(nClientes);
				break;
			}
			
			default:{
				cout<<"*Error! parametro no valido"<<endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}while(salir!=1);
}

int nClientesRegistrados(){
	fstream archivo("clientes.dat", ios::binary | ios::in | ios::out | ios::trunc);

	int nClientes=0;
		
	while (!archivo.is_open()){
		archivo.read(reinterpret_cast<char*>(&clientes[nClientes]),sizeof(Cliente));
		nClientes++;
	}
	
	archivo.close();
	return nClientes;
}

void agregarNuevoCliente(int nClientes){
	fstream archivo("clientes.dat", ios::binary | ios::in | ios::out | ios::trunc);
	
	string nombre;
	string apellido;
	string dpi;
	
	if(!archivo.is_open()){ 
		cout<<"Fichero no encontrado"<<endl;
		system("pause");
		
	}else{
		//DPI
		cout<<"*Ingrese el DPI del cliente\n->";
		cin.clear();
		cin>>dpi;
		clientes[nClientes].setDPI(dpi);
		//nombre
		cout<<"*Ingrese el NOMBRE del cliente\n->";
		cin.clear();
		cin>>nombre;
		clientes[nClientes].setNombre(nombre);
		//apellido
		cout<<"*Ingrese el APPELLIDO del cliente\n->";
		cin.clear();
		cin>>apellido;
		clientes[nClientes].setApellido(apellido);

		archivo.write(reinterpret_cast<char*>(&clientes[nClientes]),sizeof(Cliente));
	}

	cin.clear();
	archivo.close();
}



