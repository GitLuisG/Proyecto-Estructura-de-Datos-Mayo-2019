typedef int Dato;

#include "Nodo.h"
#include <iostream>

#include "Nodo.h"

#ifndef _LISTA_CIRCULAR_H
#define _LISTA_CIRCULAR_H

using namespace std;

class ListaCircular{
	protected:
	    Nodo* primero;
	    double pila = 400;
	public:
	    ListaCircular(){
	    	primero=NULL;
	    }
	
	void InsertarAlPrincipio(Dato x);
	Nodo* Ultimo();
	void crearLista(Dato x);
	void visualizar();
	void InsertarAlFinal(Dato x);
	Nodo* BuscarElemento(Dato x);
	void InsertarEnMedio(Dato anterior, Dato x);
	void EliminarNodo(Dato x);
	Dato DatoPrimero();
	
	double getDistancia(Dato d);
	double getDistanciaAcumulada(Dato d);
	void visualizarInfo();
	void setDistancia(double d);
	void setDistanciaAcum(double d);
	void setDistancia(Dato id, double d);
	void setDistanciaAcum(Dato id, double d);
	void actualizarPila(double distanciaRecorrida);
	double getPila();
};

void ListaCircular::InsertarAlPrincipio(Dato x){

    if(primero==NULL){
        primero= new Nodo(x);
        primero->ponerEnlace(primero);
    } else{
	    Nodo* ultimo;
	    ultimo= Ultimo();
	    primero= new Nodo(x,primero);
	    ultimo->ponerEnlace(primero);
    }

}

void ListaCircular::crearLista(Dato x){
    cout << " Finaliza con -1"<< endl;
    cout << " "; cin >> x;
    while(x!=-1){
        InsertarAlPrincipio(x);
        cout << " "; cin >> x;
    }

}

Nodo* ListaCircular::Ultimo(){

    Nodo* n=primero;
    while(n->enlaceNodo()!=primero){
        n=n->enlaceNodo();
    }

    return n;
}

void ListaCircular::visualizar(){

    Nodo* n;
    n=primero;
	cout << "\n " << n->datoNodo() << " -> ";

    n=n->enlaceNodo();

    while(n!=primero){
        cout << " " << n->datoNodo() << " -> ";
        n=n->enlaceNodo();
    }
}

void ListaCircular::InsertarAlFinal(Dato x){

    Nodo* ultimo=Ultimo();
    Nodo* nuevo=new Nodo(x,primero);
    ultimo->ponerEnlace(nuevo);
}

Nodo* ListaCircular::BuscarElemento(Dato x){

    Nodo* n;
    n=primero;

    if(n->datoNodo()==x)
        return n;
    n=n->enlaceNodo();

    while(n!=primero)
        if(n->datoNodo()==x){
    return n;
    }else{
        n=n->enlaceNodo();
    }
    if(n==primero){
        return NULL;
    }
}


void ListaCircular::InsertarEnMedio(Dato x, Dato ante){

    Nodo* nuevo;
    Nodo* anterior;

    anterior=BuscarElemento(ante);
    nuevo= new Nodo(x,anterior->enlaceNodo());
    anterior->ponerEnlace(nuevo);
}


void ListaCircular::EliminarNodo(Dato x){

    Nodo* buscado;
    buscado=BuscarElemento(x);

    Nodo* anterior=primero;

    while(anterior->enlaceNodo()!=buscado)
        anterior=anterior->enlaceNodo();
    anterior->ponerEnlace(buscado->enlaceNodo());
    if(buscado==primero){
        primero=primero->enlaceNodo();
    }
    delete buscado;
}

Dato ListaCircular::DatoPrimero(){
	return primero -> datoNodo();
}

double ListaCircular::getDistancia(Dato d){
	return BuscarElemento(d) -> obtenerDistancia();
}

double ListaCircular::getDistanciaAcumulada(Dato d){
	return BuscarElemento(d) -> obtenerDistanciaAcum();
}

void ListaCircular::setDistancia(double d){
	primero -> actualizarDistancia(d);
}

void ListaCircular::setDistanciaAcum(double d){
	primero -> actualizarDistanciaAcumulada(d);
}

void ListaCircular::setDistancia(Dato id, double d){
	BuscarElemento(id) -> actualizarDistancia(d);
}

void ListaCircular::setDistanciaAcum(Dato id, double d){
	BuscarElemento(id) -> actualizarDistanciaAcumulada(d);
}

void ListaCircular::visualizarInfo(){
    Nodo* n;
    n=primero;
	cout << "\n" << n->datoNodo() << " | Distancia: " << n->obtenerDistancia() << " | Distancia Acumulada: " 
		 << n->obtenerDistanciaAcum() << " -> " << endl;
	
    n=n->enlaceNodo();
	
    while(n!=primero){
        cout << n->datoNodo() << " | Distancia: " << n->obtenerDistancia() << " | Distancia Acumulada: " 
		 	 << n->obtenerDistanciaAcum() << " -> " << endl;
        n=n->enlaceNodo();
    }
}

void ListaCircular::actualizarPila(double distanciaRecorrida){
	pila -= distanciaRecorrida;	
}

double ListaCircular::getPila(){
	return pila;
}

#endif // _LISTA_H


