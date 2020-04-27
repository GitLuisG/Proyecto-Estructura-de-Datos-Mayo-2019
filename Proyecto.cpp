#include <iostream>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <tgmath.h>
#include "ListaCircular.cpp"
#include "Nodo.h"
using namespace std;
char Arreglo1[500];
char Arreglo2[500];
double Contenido[50];
double Contenido2[50];
double A[100][100];
double B[100][100];
double C[100][100];
double  X , Y;
double dist1[100][100];
double dist2 = 0;
double temp[100][100];
int filas1 = 0;
int filas2 = 0;
int temp2 = 0;
int verificador = 0,verificador2 = 0;
int cont = 0, contador2 = 0;

int main(int argc, char const *argv[]) {

ifstream Archivo("EstRch.txt");

cout << "\nPrimer archivo\n" << endl;

while (!Archivo.eof()) {
   cont+=1;
   if (cont > 9) {
       verificador+=1;
   if (verificador > 1) {
       filas1+=1;
       Archivo >> Arreglo1;
      Contenido[filas1 - 1] = atof(Arreglo1);
     
      }
       else if (verificador == 1) {
          Archivo >> Arreglo1;
      }
        if (verificador == 3) {
            verificador = 0;
        }
   }
     else{
        Archivo >> Arreglo1;
     }
   }

     filas1 = filas1 / 2;

for (int i = 0; i < filas1; i++){
		for (int j = 0; j < 2; j++){
			A[i][j] = Contenido[temp2];
			temp2++;
			filas2++;
			if (j == 0) {
				cout << "X: " << A[i][j] << " ";
			}
			else {
				cout << "Y: " << A[i][j] << endl;
			}
		}
	}

temp2 = 0;

Archivo.close();
filas1 = 0;
cout << " " << endl;
cout << "\nSegundo Archivo \n" << endl;
ifstream Archivo2("Problem10-Fisher.txt");

while (!Archivo2.eof()) {
      contador2+=1;
       if (contador2 > 28) {
           verificador2+=1;
         if (verificador2 > 1) {
            filas1+=1;
            Archivo2 >> Arreglo2;
             Contenido2[filas1 - 1] = atof(Arreglo2);

          }
           else if (verificador2 == 1) {
                Archivo2 >> Arreglo2;

           }
    if (verificador2 == 3) {
       verificador2 = 0;

    }

    }
     else {

     Archivo2 >> Arreglo2;

 	}
   }
   filas1 = filas1 / 2;
  for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			B[i][j] = Contenido2[temp2];
			temp2++;
			if (j == 0) {
				cout << "X: " << B[i][j] << " ";
			}
			else {
				cout << "Y: " << B[i][j] << endl;
			}
		}
	}
	cout << "\nDistancia entre puntos\n" << endl;
		for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < filas1; j++)
		{
				if(j == i){
					X = (B[j][0] - B[i][0]);
    				Y = ( B[j][1] - B[i][1]);
    				temp[i][j] = sqrt(X*X + Y*Y);
				}else{
					X = (B[j][0] - B[i][0]);
    				Y = ( B[j][1] - B[i][1]);
    				temp[i][j] = sqrt(X * X + Y * Y);
				}
		}
	}
		for (int i = 0; i < filas1; i++){
		for (int j = 0; j < filas1; j++){

			cout << temp[i][j] << "  |  ";
			if(j == filas1-1){
				cout << "Fila:" << i << endl;
				cout << "\n\n\n";
			}
		}
	}
	cout << "\nDistancia entre puntos de ambos archivos\n" << endl << endl;
	filas2 = filas2/2;
	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < filas2; j++)
		{
			X = (A[j][0] - B[i][0]);
    		Y = (A[j][1] - B[i][1]);
			dist1[i][j] = sqrt(X * X + Y * Y);
		}
	}
	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < filas2; j++)
		{
			cout << dist1[i][j] << "  |  ";
			if(j == filas2-1){
				cout << "Fila:" << i << endl;
				cout << "\n\n\n";
			}
		}
	}
Archivo2.close();

ListaCircular  Obj, Obj1, Obj2, Obj3;
cout<<filas1;
int Permutaciones[filas1];
int i=0;
bool ban1 = true, ban2 = false, primero1 = true, primero2 = true, primero3 = true;
double suma1 = 0, suma2 = 0, suma3 = 0;

srand(time(NULL));

while(i<filas1){
	verificador2= rand()%filas1;
	verificador =0;
	
	for (int k =0; k <=i; k++){
		if(verificador2 == Permutaciones[k])
		{
			verificador= 1;
			break;
		}
	}
	if (verificador ==0) {
	 Permutaciones[i]=verificador2;
	 
	 	if(ban1 == true){
			Obj1.InsertarAlPrincipio(Permutaciones[i]);
			if(primero1){
				Obj1.setDistancia(0);
				primero1 = false;
			}
			else{
				Obj1.setDistancia(temp[Permutaciones[i]][0]);
				suma1 += temp[Permutaciones[i]][0];
				Obj1.setDistanciaAcum(suma1);
			}
			ban1 = false;
			ban2 = true;
		 } else if(ban2 == true){
			Obj2.InsertarAlPrincipio(Permutaciones[i]);
			if(primero2){
				Obj2.setDistancia(0);
				primero2 = false;
			}
			else{
				Obj2.setDistancia(temp[Permutaciones[i]][0]);
				suma2 += temp[Permutaciones[i]][0];
				Obj2.setDistanciaAcum(suma2);
			}
			ban2 = false;
		 } else if(ban1 == false && ban2 == false){
			Obj3.InsertarAlPrincipio(Permutaciones[i]);
			if(primero3){
				Obj3.setDistancia(0);
				primero3 = false;
			}
			else{
				Obj3.setDistancia(temp[Permutaciones[i]][0]);
				suma3 += temp[Permutaciones[i]][0];
				Obj3.setDistanciaAcum(suma3);
			}
			ban1 = true;
		 }
	 
		i++;
	}

}

cout<<"\nlista 1\n";
Obj1.visualizarInfo();
cout<<"\nlista 2\n";
Obj2.visualizarInfo();
cout<<"\nlista 3\n";
Obj3.visualizarInfo();

int z = 0;
i=0;
ban1 = true, ban2 = false;

cout << endl;
for(int l = 0; l < 45; l++){
	for(int m = 0; m < 17; m++){
		cout << dist1[l][m] << ", ";
	}
	cout << "\n" << endl;
}

while(true){
	if(i == filas1){
		i = 0;
	}
	
	if(z == filas2){
		break;
	}
	
	if(ban1 == true){
		Obj1.actualizarPila(Obj1.getDistancia(Permutaciones[i]));
		
		if(Obj1.getPila() <= 300){
			Obj1.setDistancia(Obj1.DatoPrimero(), dist1[z][0]);
			Obj1.InsertarAlPrincipio(z + Obj1.Ultimo() -> datoNodo());
			Obj1.setDistancia(dist1[z][0]);
			suma1 += dist1[z][0];
			Obj1.setDistanciaAcum(suma1);
			Obj1.actualizarPila(Obj1.getDistancia(z + Obj1.Ultimo() -> datoNodo()));
			z++;
			//break;
		}
		
		ban1 = false;
		ban2 = true;
	} else if(ban2 == true){
		Obj2.actualizarPila(Obj2.getDistancia(Permutaciones[i]));
		
		if(Obj2.getPila() <= 300){
			Obj2.setDistancia(Obj2.DatoPrimero(), dist1[z][0]);
			Obj2.InsertarAlPrincipio(z + Obj2.Ultimo() -> datoNodo());
			Obj2.setDistancia(dist1[z][0]);
			suma2 += dist1[z][0];
			Obj2.setDistanciaAcum(suma2);
			Obj2.actualizarPila(Obj2.getDistancia(z + Obj2.Ultimo() -> datoNodo()));
			z++;
			//break;
		}
		
		ban2 = false;
	} else if(ban1 == false && ban2 == false){
		Obj3.actualizarPila(Obj3.getDistancia(Permutaciones[i]));
		
		if(Obj3.getPila() <= 300){
			Obj3.setDistancia(Obj3.DatoPrimero(), dist1[z][0]);
			Obj3.InsertarAlPrincipio(z + Obj3.Ultimo() -> datoNodo());
			Obj3.setDistancia(dist1[z][0]);
			suma3 += dist1[z][0];
			Obj3.setDistanciaAcum(suma3);
			Obj3.actualizarPila(Obj3.getDistancia(z + Obj3.Ultimo() -> datoNodo()));
			z++;
			//break;
		}
		
		ban1 = true;
	}
	
	i++;
}

cout << "\nPila1" << endl;
cout << Obj1.getPila() << endl;
cout << "\nPila2" << endl;
cout << Obj2.getPila() << endl;
cout << "\nPila3" << endl;
cout << Obj3.getPila() << endl;

cout<<"\nlista 1\n";
Obj1.visualizarInfo();
cout<<"\nlista 2\n";
Obj2.visualizarInfo();
cout<<"\nlista 3\n";
Obj3.visualizarInfo();

 return 0;
}

