#include <iostream>
#include <string.h>

class Libro{
	
	public:
		Libro();
		~Libro();
		
		int disponible();
		
		void setISBN(std::string AISBN);
		void setTitulo(std::string Atitulo);
		void setDia(std::string Adia);
		void setMes(std::string Ames);
		void setAnio(std::string Aanio);
		void setDPIasociado(std::string ADPIasociado);
		
		std::string getISBN();
		std::string getTitulo();
		std::string getDia();
		std::string getMes();
		std::string getAnio();
		std::string getDPIasociado();
		
	private:
		std::string ISBN;
		std::string titulo;
		std::string dia;
		std::string mes;	
		std::string anio;
		std::string DPIasociado;	
};

Libro::Libro(){
	
}

Libro::~Libro(){
	
}

Libro::disponible(){
	if(DPIasociado.length() == 0){
		return 1;
	}else{
		return 0;
	}
}

void Libro::setISBN(std::string AISBN){
	ISBN= AISBN;
}

void Libro::setTitulo(std::string Atitulo){
	titulo= Atitulo;
}

void Libro::setDia(std::string Adia){
	dia=Adia;
}

void Libro::setMes(std::string Ames){
	mes=Ames;
}

void Libro::setAnio(std::string Aanio){
	anio=Aanio;
}

void Libro::setDPIasociado(std::string ADPIasociado){
	DPIasociado=ADPIasociado;
}

std::string Libro::getISBN(){
	return ISBN;
}

std::string Libro::getTitulo(){
	return titulo;
}

std::string Libro::getDia(){
	return dia;
}

std::string Libro::getMes(){
	return mes;
}

std::string Libro::getAnio(){
	return anio;
}

std::string Libro::getDPIasociado(){
	return DPIasociado;
}




