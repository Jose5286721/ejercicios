#include<iostream>
//Importamos las librerias necesarias
using namespace std;

//Declaramos las variables y funciones
int n;
void cargarVector(int *vect, int largo);
void imprimirVector(int *vect, int largo);
void obtenerMayor(int *vect, int largo);
void obtenerMenor(int *vect, int largo);
void obtenerPromedio(int *vect, int largo);

//Defino el inicio del programa
int main(){
	cout<<"Introduzca el largo del vector \n";
	cin>>n;
    int array[n];
    cargarVector(array,n);	
    imprimirVector(array,n);
    obtenerMayor(array,n);
    obtenerMenor(array,n);
    obtenerPromedio(array,n);
    return 0;
}

//Funcion para cargar los valores del vector
void cargarVector(int *vect,int largo){
	for(int cont = 0;cont<largo; cont++){
		cout<<"Introduzca el valor "<<cont<<" \n";
		cin>>vect[cont];
	}
}

//Funcion para imprimir el vector
void imprimirVector(int *vect, int largo){
	for(int cont = 0;cont<largo ;cont++){
		cout<<" VALOR ["<<cont<<"] = "<<vect[cont]<<"\n";
	}
}

//Funcion para obtener el mayor valor del vector
void obtenerMayor(int *vect, int largo){
	int mayor = vect[0];
	for(int cont=0;cont<largo;cont++){
		if(mayor < vect[cont]){
			mayor = vect[cont];
		}
	}
	cout<<"El mayor valor es: "<<mayor<<"\n";
}
//Funcion para obtener el menor valor
void obtenerMenor(int *vect, int largo){
	int menor = vect[0];
	for(int cont=0;cont<largo;cont++){
		if(menor > vect[cont]){
			menor = vect[cont];
		}
	}
	cout<<"El menor valor es: "<<menor<<"\n";
}

//Funcion para obtener el promedio del vector
void obtenerPromedio(int *vect, int largo){
	int sumatoria = 0;
	for(int cont=0;cont<largo;cont++){
		sumatoria+=vect[cont];
	}
	cout<<"El promedio es: "<<(sumatoria/largo)<<"\n";
}
