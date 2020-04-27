#ifndef _NODO_H
#define _NODO_H
typedef int Dato;

class Nodo{
private:
    Nodo* enlace;
    Dato Identificador;
    double Dist = 0;
    double DistAcum = 0;
    
public:
    Nodo(Dato t){
        Identificador = t;
        enlace = 0;
    }
    Nodo(Dato p, Nodo* n){
        Identificador = p;
        enlace = n;
    }
    Nodo(Dato p, Nodo* n, double nDist, double nDistAcum){
        Identificador = p;
        enlace = n;
        Dist = nDist;
        DistAcum = nDistAcum;
    }
    Dato datoNodo() const{return Identificador;}
    Nodo* enlaceNodo() const{return enlace;}
    void ponerEnlace(Nodo* sgte){enlace = sgte;}
    void ponerDato(Dato dat){Identificador = dat;}
    
	void actualizarDistancia(double nuevaDist){
		Dist = nuevaDist;
	}
	void actualizarDistanciaAcumulada(double nuevaDistAcum){
		DistAcum = nuevaDistAcum;
	}
	double obtenerDistancia(){
		return Dist;
	}
	double obtenerDistanciaAcum(){
		return DistAcum;
	}
};
#endif
