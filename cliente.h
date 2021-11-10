#include <iostream>
#include <string.h>

class Cliente{
	
	public:
		Cliente();
		Cliente(std::string ADPI, std::string Anombre, std::string Aapellido, std::string AISBNasociado);
		
		void setDPI(std::string ADPI);
		void setNombre(std::string Anombre);
		void setApellido(std::string Aapellido);
		void setISBNasociado(std::string AISBNasociado);
		
		std::string getDPI();
		std::string getNombre();
		std::string getApellido();
		std::string getISBNasociado();
		
	private:
		std::string DPI;
		std::string nombre;
		std::string apellido;	
		std::string ISBNasociado;	
};

Cliente::Cliente(){
	
}

Cliente::Cliente(std::string ADPI, std::string Anombre, std::string Aapellido, std::string AISBNasociado){
	DPI=ADPI;
	nombre=Anombre;
	apellido=Aapellido;
	ISBNasociado=AISBNasociado;
}

void Cliente::setDPI(std::string ADPI){
	DPI=ADPI;
}

void Cliente::setNombre(std::string Anombre){
	nombre=Anombre;
}

void Cliente::setApellido(std::string Aapellido){
	apellido=Aapellido;
}

void Cliente::setISBNasociado(std::string AISBNasociado){
	ISBNasociado=AISBNasociado;
}

std::string Cliente::getDPI(){
	return DPI;
}

std::string Cliente::getNombre(){
	return nombre;
}

std::string Cliente::getApellido(){
	return apellido;
}

std::string Cliente::getISBNasociado(){
	return ISBNasociado;
}
