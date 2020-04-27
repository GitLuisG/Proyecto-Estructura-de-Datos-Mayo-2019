#include<iostream>
#include "Nodo.h"

using namespace std;
typedef int Dato;


class Pila{
 	private:
 		Nodo* primero;
 	public:
 		Pila(){
		 	primero=NULL;
		}
	void InsertarAlInicio(Dato x);
	Dato Cima();
	Dato Eliminar();
	void CrearPila();
	void Visualizar();
	bool EsVacia();
	void VaciarPila();

};


Dato Pila::Cima(){
	return primero->datoNodo();
}

Dato Pila::Eliminar(){
	Dato dato;

	dato=primero->datoNodo();
	Nodo* aux=primero;
	primero=primero->enlaceNodo();

	delete aux;
	return dato;
}

void Pila::Visualizar(){
    Nodo* n;
    int k=0;

    n=primero;

    while(n!=NULL){

        k++;
        cout << " | " <<  n -> datoNodo() << " | ->" ;
        n=n->enlaceNodo();
    }
}


void Pila::InsertarAlInicio(Dato x){

	if (primero==NULL){
		primero=new Nodo(x);

	}else{
		primero=new Nodo(x,primero);
	}
}

void Pila::CrearPila(){
	Dato x;
	cout << "finaliza con -1  " << endl;
	cin >>x;
	while(x!=-1){
		InsertarAlInicio(x);
		cin>>x;
	}
}

bool Pila::EsVacia(){
	if(primero==NULL){
		return true;
	}else{
		return false;
	}
}


void Pila::VaciarPila(){

	Nodo* n;

	n=primero;

	while(n->enlaceNodo()!=NULL){
		primero=primero->enlaceNodo();
		delete n;
		n=primero;
	}
}
