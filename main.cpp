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

void catalogoLibro();
void agregarNuevoLibro();
void listaDeTodosLosLibrosOcupados();
void listaDeTodosLosLibrosDisponibles();
void modificarLibroPorISBN();

void registrarPrestamo();

void devolverLibro();

Cliente clientes[100];
Libro libros[300];
int nClientes=0;
int nLibros=0;

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
				registrarPrestamo();
				break;
			}
			
			case 4:{
				devolverLibro();
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
		cout<<"*Ingrese 1 para REGISTRAR cliente"<<endl<<endl;
		cout<<"*Ingrese 2 para MODIFICAR cliente"<<endl<<endl;
		cout<<"*Ingrese 3 para ver todos los clientes registrados"<<endl<<endl;
		cout<<"*Ingrese 4 para ver buscar un cliente por DPI"<<endl<<endl;
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
				modificarClientePorDPI();
				break;
			}
			
			case 3:{
				listaDeTodosLosClientes();
				break;
			}
			
			case 4:{
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
	cout<<"*Ingrese el APELLIDO del cliente\n->";
	cin.clear();
	cin>>apellido;
	clientes[nClientes].setApellido(apellido);
	
	cout<<"\n\n*Cliente agregado correctamente\n";
	system("pause");
	
	nClientes++;
}

void listaDeTodosLosClientes(){
	
	for(int i=0;i<nClientes;i++){
		cout<<"#Cliente: "<<i+1<<endl;
		cout<<"*DPI: "<<clientes[i].getDPI()<<endl;
		cout<<"*Nombre: "<<clientes[i].getNombre()<<endl;
		cout<<"*Apellido: "<<clientes[i].getApellido()<<endl;
		if(clientes[i].disponible()==1){
			cout<<"*No posee ISBN asociado (puede solicitar un libro)"<<endl<<endl;
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
			cout<<"*Ingrese el APELLIDO del cliente\n->";
			cin.clear();
			cin>>apellido;
			clientes[i].setApellido(apellido);
			
			encontrado=true;
			
			cout<<"\n\n*Datos modificados correctamente"<<endl;

		}
	}
	
	if(!encontrado){
		cout<<"*El libro con dpi "<<dpiBuscar<<" No existe."<<endl<<endl;
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
		cout<<"*Ingrese 1 REGISTRAR libro"<<endl<<endl;
		cout<<"*Ingrese 2 para modificar libro"<<endl<<endl;
		cout<<"*Ingrese 3 para ver todos los libros disponibles"<<endl<<endl;
		cout<<"*Ingrese 4 para ver todos los libros ocupados"<<endl<<endl;
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
				modificarLibroPorISBN();
				break;
			}
			
			case 3:{
				listaDeTodosLosLibrosDisponibles();
				break;
			}
			
			case 4:{
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
	
	cout<<"\n\n*Libro agregado correctamente\n";
	system("pause");
	nLibros++;
}

void listaDeTodosLosLibrosOcupados(){
	
	for(int i=0;i<nLibros;i++){
		if(libros[i].disponible()==0){
			cout<<"#Libro: "<<i+1<<endl;
			cout<<"*ISBN: "<<libros[i].getISBN()<<endl;
			cout<<"*Titulo: "<<libros[i].getTitulo()<<endl;
			cout<<"*Fecha de Renta: "<<libros[i].getDia()<<"/"<<libros[i].getMes()<<"/"<<libros[i].getAnio()<<endl;
			cout<<"*DPI de cliente asociado: "<<libros[i].getDPIasociado()<<endl<<endl<<endl;
		}
	}
	
	system("pause");
	system("cls");
}

void listaDeTodosLosLibrosDisponibles(){
	
	for(int i=0;i<nLibros;i++){
		if(libros[i].disponible()==1){
			cout<<"#Libro: "<<i+1<<endl;
			cout<<"*ISBN: "<<libros[i].getISBN()<<endl;
			cout<<"*Titulo: "<<libros[i].getTitulo()<<endl<<endl<<endl;
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
						
			encontrado=true;
			cout<<"\n\n*Datos modificados correctamente"<<endl;

		}
	}
	
	if(!encontrado){
		cout<<"*El cliente con dpi "<<ISBNBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void registrarPrestamo(){
	
	string DPIBuscar;
	string ISBNBuscar;
	
	string dia, mes, anio;
	
	bool encontrado=false;
	bool encontrado2=false;
	
	cout<<"*Ingrese el DPI del CLIENTE\n->";
	cin.clear();
	cin>>DPIBuscar;
	
	system("cls");
	
	for(int i=0;i<nClientes;i++){
		
		if(DPIBuscar==clientes[i].getDPI()){
			
			if(clientes[i].disponible()==1){
				
				cout<<"*Ingrese el ISBN del libro que desea rentar\n->";
				cin.clear();
				cin>>ISBNBuscar;
				
				for(int j=0;j<nLibros;j++){
					
					if(ISBNBuscar==libros[j].getISBN()){
					
						if(libros[j].disponible()==1){
							clientes[i].setISBNasociado(libros[j].getISBN());
							libros[j].setDPIasociado(clientes[i].getDPI());
							
							cout<<"*Ingrese el dia\n->";
							cin.clear();
							cin>>dia;		
							libros[j].setDia(dia);
							
							cout<<"*Ingrese el mes\n->";
							cin.clear();
							cin>>mes;		
							libros[j].setMes(mes);
							
							cout<<"*Ingrese el anio\n->";
							cin.clear();
							cin>>anio;		
							libros[j].setAnio(anio);
							
							cout<<"*Prestamo registrado correctamente"<<endl;
							
							encontrado2=true;
						}else{
							cout<<"*El libro ya ha sido restado\n";
							encontrado2=true;	
						}

					}
					
				}
				
			}else{
				cout<<"*El cliente ya rento un libro, no puede tomar prestado mas...\n";
				encontrado2=true;
			}
			encontrado=true;	
			
		}
	}
	
	if(!encontrado){
		cout<<"*El cliente con dpi "<<DPIBuscar<<" No existe."<<endl<<endl;
	}
	
	if(!encontrado2){
		cout<<"*El libro con isbn "<<ISBNBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

void devolverLibro(){
	string isbnBuscar;
	string dpiBuscar;
	bool encontrado=false;
	bool encontrado2=false;
	
	cout<<"*Ingrese el isbn de libro a devolver\n->";
	cin.clear();
	cin>>isbnBuscar;
	
	system("cls");
	
	for(int i=0;i<nLibros;i++){
		
		if(isbnBuscar==libros[i].getISBN()){
			
			if(libros[i].disponible()!=1){
				
				cout<<"*Ingrese el dpi del cliente que poseia el libro\n->";
				cin.clear();
				cin>>dpiBuscar;
				
				for(int j=0;j<nClientes;j++){
					
					if(dpiBuscar==clientes[j].getDPI()){
						
						if(clientes[j].disponible()!=1){
							libros[i].setDPIasociado("");
							libros[i].setDia("");
							libros[i].setMes("");
							libros[i].setAnio("");
							
							clientes[j].setISBNasociado("");
					
							cout<<"*Libro devuelto correctamente"<<endl;
						}else{
							cout<<"*El cliente ingresado no solicito el libro prestado..."<<endl;
						}
						
						encontrado2=true;
					}
					
				}

			}else{
				cout<<"*El libro aun esta en la biblioteca..."<<endl;
				encontrado=false;
			}
			
			encontrado=true;

		}
	}
	
	if(!encontrado){
		cout<<"*El libro con isbn "<<isbnBuscar<<" No existe."<<endl<<endl;
	}
	
	system("pause");
	system("cls");
}

