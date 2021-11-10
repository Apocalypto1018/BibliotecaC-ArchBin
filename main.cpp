#include <iostream>
#include <string>
#include "cliente.h"
#include "libro.h"

using namespace std;

void catalogoClientes();
void agregarNuevoCliente();
void listaDeTodosLosClientes();
void buscarClientePorDPI();
void modificarClientePorDPI();
void borrarCliente();

void catalogoLibro();
void agregarNuevoLibro();
void listaDeTodosLosLibrosOcupados();
void listaDeTodosLosLibrosDisponibles();
void modificarLibroPorISBN();
void borrarLibro();

Cliente clientes[100];
Libro libros[300];
int nClientes=0;
int nLibros=0;

int vLeliminados[100];
int cVEliminados=0;

int main(){
	int salir=0, opc=0;

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
				catalogoClientes();	
				break;
			}
			
			case 2:{
				catalogoLibro();
				break;
			}
			
			case 3:{
				
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
	
	return 0;
}

void catalogoClientes(){
	
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
				salir=1;
				system("cls");
				break;
			}
			
			case 1:{
				agregarNuevoCliente();
				break;
			}
			
			case 2:{
				borrarCliente();
				break;
			}
			
			case 3:{
				modificarClientePorDPI();
				break;
			}
			
			case 4:{
				listaDeTodosLosClientes();
				break;
			}
			
			case 5:{
				buscarClientePorDPI();
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

void agregarNuevoCliente(){
	
	string nombre;
	string apellido;
	string dpi;

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
	
	nClientes++;
}

void listaDeTodosLosClientes(){
	
	for(int i=0;i<nClientes;i++){
		cout<<"#Cliente: "<<i+1<<endl;
		cout<<"*DPI: "<<clientes[i].getDPI()<<endl;
		cout<<"*Nombre: "<<clientes[i].getNombre()<<endl;
		cout<<"*Apellido: "<<clientes[i].getApellido()<<endl;
		if(clientes[i].disponible()==1){
			cout<<"*No posee ISBN asociado (esta disponible)"<<endl<<endl;
		}else{
			cout<<"* ISBN asociado: "<<clientes[i].getISBNasociado()<<endl<<endl;
		}
	}
	
	system("pause");
	system("cls");
}

void buscarClientePorDPI(){
	string dpi;
	bool encontrado=false;
	
	cout<<"*Ingrese el dpi del cliente a buscar\n->";
	cin.clear();
	cin>>dpi;
	
	system("cls");
	
	for(int i=0;i<nClientes;i++){
		if(dpi==clientes[i].getDPI()){
			cout<<"#Datos del cliente solicitado: "<<endl;
			cout<<"*DPI: "<<clientes[i].getDPI()<<endl;
			cout<<"*Nombre: "<<clientes[i].getNombre()<<endl;
			cout<<"*Apellido: "<<clientes[i].getApellido()<<endl;
			if(clientes[i].disponible()==1){
				cout<<"*No posee ISBN asociado (esta disponible)"<<endl<<endl;
			}else{
				cout<<"* ISBN asociado: "<<clientes[i].getISBNasociado()<<endl<<endl;
			}
			
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El cliente con dpi "<<dpi<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void modificarClientePorDPI(){
	
	string dpiBuscar;
	
	string nombre;
	string apellido;
	string ISBNasociado;
	
	int opc;
	
	bool encontrado=false;
	
	cout<<"*Ingrese el dpi del cliente a modificar\n->";
	cin.clear();
	cin>>dpiBuscar;
	
	system("cls");
	
	for(int i=0;i<nClientes;i++){
		if(dpiBuscar==clientes[i].getDPI()){

			//nombre
			cout<<"*Ingrese el NOMBRE del cliente\n->";
			cin.clear();
			cin>>nombre;
			clientes[i].setNombre(nombre);
			//apellido
			cout<<"*Ingrese el APPELLIDO del cliente\n->";
			cin.clear();
			cin>>apellido;
			clientes[i].setApellido(apellido);
			//ISBN
			cout<<"*Ingrese el 1 para dejar el ISBN como esta, o 0 para indicar vacio por defecto\n->";
			cin.clear();
			cin>>opc;
			
			if(opc==0){
				clientes[i].setNombre("");
			}
			
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El libro con dpi "<<dpiBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void borrarCliente(){
	
	string dpiBuscar;
	
	bool encontrado=false;
	
	cout<<"*Ingrese el dpi del cliente a modificar\n->";
	cin.clear();
	cin>>dpiBuscar;
	
	system("cls");
	
	for(int i=0;i<nClientes;i++){
		if(dpiBuscar==clientes[i].getDPI()){
			
			clientes[i].~Cliente();
			cout<<"*El cliente ha sido eliminado correctamente"<<endl;
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El cliente con dpi "<<dpiBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
	
}

void catalogoLibro(){
	
	int opc=0;
	int salir=0;
	
	do{
		system("cls");
		cout<<"       CATALOGO LIBRO"<<endl<<endl<<endl;
		cout<<"*Ingrese 1 para alta"<<endl<<endl;
		cout<<"*Ingrese 2 para baja"<<endl<<endl;
		cout<<"*Ingrese 3 para modificar libro"<<endl<<endl;
		cout<<"*Ingrese 4 para ver todos los libros disponibles"<<endl<<endl;
		cout<<"*Ingrese 5 para ver todos los libros ocupados"<<endl<<endl;
		cout<<"*Ingrese 0 para SALIR\n->";
		cin.clear();
		cin>>opc;
	
		system("cls");
		
		switch(opc){
			case 0:{
				salir=1;
				system("cls");
				break;
			}
			
			case 1:{
				agregarNuevoLibro();
				break;
			}
			
			case 2:{
				borrarLibro();
				break;
			}
			
			case 3:{
				modificarLibroPorISBN();
				break;
			}
			
			case 4:{
				listaDeTodosLosLibrosDisponibles();
				break;
			}
			
			case 5:{
				listaDeTodosLosLibrosOcupados();
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

void agregarNuevoLibro(){
	
	string ISBN;
	string titulo;

	//ISBN
	cout<<"*Ingrese el ISBN del LIBRO\n->";
	cin.clear();
	cin>>ISBN;
	libros[nLibros].setISBN(ISBN);
	
	//titulo
	cout<<"*Ingrese el TITULO del LIBRO\n->";
	cin.clear();
	cin>>titulo;
	libros[nLibros].setTitulo(titulo);
	
	nLibros++;
}

void listaDeTodosLosLibrosOcupados(){
	
	for(int i=0;i<nLibros;i++){
		if(libros[nLibros].disponible()==1){
			cout<<"#Libro: "<<i+1<<endl;
			cout<<"*ISBN: "<<libros[i].getISBN()<<endl;
			cout<<"*Titulo: "<<libros[i].getTitulo()<<endl;
		}
	}
	
	system("pause");
	system("cls");
}

void borrarLibro(){
	
	string ISBNBuscar;
	
	bool encontrado=false;
	
	cout<<"*Ingrese el ISBN del libro a eliminar\n->";
	cin.clear();
	cin>>ISBNBuscar;
	
	system("cls");
	
	for(int i=0;i<nLibros;i++){
		if(ISBNBuscar==libros[i].getISBN()){
			
			libros[i].~Libro();
			
			vLeliminados[cVEliminados]=i;
			cVEliminados++;
			
			cout<<"*El libro se ha borrado con exito\n";
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El libro con isbn "<<ISBNBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void listaDeTodosLosLibrosDisponibles(){
	
	for(int i=0;i<nLibros;i++){
		if(libros[nLibros].disponible()!=1){
			cout<<"#Libro: "<<i+1<<endl;
			cout<<"*ISBN: "<<libros[i].getISBN()<<endl;
			cout<<"*Titulo: "<<libros[i].getTitulo()<<endl;
		}
	}
	
	system("pause");
	system("cls");
}

void modificarLibroPorISBN(){
	string ISBNBuscar;
	
	string titulo;
	
	int opc;
	
	bool encontrado=false;
	
	cout<<"*Ingrese el ISBN del libro a modificar\n->";
	cin.clear();
	cin>>ISBNBuscar;
	
	system("cls");
	
	for(int i=0;i<nLibros;i++){
		if(ISBNBuscar==libros[i].getISBN()){

			//titulo
			cout<<"*Ingrese el NOMBRE del cliente\n->";
			cin.clear();
			cin>>titulo;
			libros[i].setTitulo(titulo);
			
			//DPI
			cout<<"*Ingrese el 1 para dejar el DPI como esta, o 0 para indicar vacio por defecto\n->";
			cin.clear();
			cin>>opc;
			
			if(opc==0){
				libros[i].setDPIasociado("");
			}
			
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El cliente con dpi "<<ISBNBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

