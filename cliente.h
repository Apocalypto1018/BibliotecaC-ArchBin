#include <iostream>
#include <string.h>

class Cliente{
	
	public:
		Cliente();
		~Cliente();
		Cliente(std::string ADPI, std::string Anombre, std::string Aapellido, std::string AISBNasociado);
		
		int disponible();
		
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

Cliente::~Cliente(){
	
}

Cliente::Cliente(std::string ADPI, std::string Anombre, std::string Aapellido, std::string AISBNasociado){
	DPI=ADPI;
	nombre=Anombre;
	apellido=Aapellido;
	ISBNasociado=AISBNasociado;
}

Cliente::disponible(){
	if(ISBNasociado.length() == 0){
		return 1;
	}else{
		return 0;
	}
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
