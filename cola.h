#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

using namespace std;

struct nodo {
   	string DPI;
	string nombre;
	string apellido;	
	string ISBNasociado;
    struct nodo *sig; 
};


struct nodo *raiz=NULL; 
struct nodo *fondo=NULL; 

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void insertar(Cliente cliente) 
{
    struct nodo *nuevo; 
    nuevo= static_cast<struct bstree *>(malloc(sizeof (*nodo)));
    
    nuevo->DPI=cliente.getDPI();
    nuevo->nombre=cliente.getNombre();
    nuevo->apellido=cliente.getApellido();
    nuevo->ISBNasociado=cliente.getISBNasociado();
    
    nuevo->sig=NULL;
    
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

void imprimir()
{
    struct nodo *reco = raiz; 
	
    cout<<"Listado de todos los clientes.\n";
    while (reco != NULL)
    {
    	cout<<"*ADPI: "<<reco->DPI<<endl;
    	cout<<"*Nombre: "<<reco->nombre<<endl;
    	cout<<"*Apellido: "<<reco->apellido<<endl;
    	cout<<"*Codigo de libro asociado: "<<reco->DPI<<endl;
    }
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}
