#include<iostream>
#include<stdlib.h>
//Importamos las librerias
using namespace std;
//Declaramos las variables y metodos;
int **matrizNegocio, **matrizVentas, numTiendas, numArticulos;

void cargarMatriz();
void cargaCantidadVendidas();
void imprimirMatrizPrecios();
void obtenerVentasDeCadaTienda();
void inicializarCantidadVendidas();
void obtenerVentasDeCadaArticulo();
void obtenerVentasTotales();

//Indicamos el orden de ejecucion del programa
int main(){
	cout<<"Introduzca la cantidad de tiendas \n";
	cin>>numTiendas;
	cout<<"Introduzca la cantidad de articulos \n";
	cin>>numArticulos;
	matrizNegocio = new int*[numTiendas];
	for(int i = 0; i<numTiendas; i++){
		matrizNegocio[i] = new int[numArticulos];
	}
	matrizVentas = new int*[numTiendas];
	for(int i = 0; i<numTiendas; i++){
		matrizVentas[i] = new int[numArticulos];
	}
	inicializarCantidadVendidas();
	cargarMatriz();
	imprimirMatrizPrecios();
	cargaCantidadVendidas();
	obtenerVentasDeCadaTienda();
	obtenerVentasDeCadaArticulo();
	obtenerVentasTotales();
	return 0;
}

//Metodo que obtiene las ventas totales
void obtenerVentasTotales(){
	int ventasTotales = 0;
	for(int i = 0;i<numTiendas;i++){
		for(int j = 0;j<numArticulos;j++){
			ventasTotales += *(*(matrizNegocio+i)+j) * *(*(matrizVentas+i)+j);
		}
	}
	cout<<"Las ventas totales del dia : "<<ventasTotales<<" uM \n";
}
//Metodo que obtiene las ventas de cada articulo
void obtenerVentasDeCadaArticulo(){
	for(int j = 0; j<numArticulos; j++){
		int contadorVentasArticulo = 0;
		for(int i=0; i<numTiendas; i++){
			contadorVentasArticulo+= *(*(matrizNegocio+i)+j) * *(*(matrizVentas+i)+j);
		}
		cout<<"Las ventas del articulo "<<j<<" : "<<contadorVentasArticulo<<" \n";
		contadorVentasArticulo = 0;
	}
}
//Metodo que inicializa en 0 las cantidades vendidas en el dia
void inicializarCantidadVendidas(){
	for(int i=0;i<numTiendas;i++){
		for(int j=0;j<numArticulos;j++){
			*(*(matrizVentas+i)+j) = 0;
		}
	}
}
//Metodo que obtiene las ventas totales de cada tienda
void obtenerVentasDeCadaTienda(){
		for(int i=0;i<numTiendas;i++){
			int contadorVentas = 0;
			for(int j=0;j<numArticulos;j++){
				contadorVentas += *(*(matrizNegocio+i)+j) * *(*(matrizVentas+i)+j);
			}
			cout<<"Las ventas del dias de la tienda "<<i<<" es de : "<<contadorVentas<<"\n";
			contadorVentas = 0;
		}
}
//Metodo que imprime la matriz donde se almacenan los precios
void imprimirMatrizPrecios(){
	for(int i=0;i<numTiendas;i++){
		for(int j=0;j<numArticulos;j++){
			cout<<"El costo del articulo "<<j<<" para la tienda "<<i<<" = "<<*(*(matrizNegocio+i)+j)<<" uM \n";
		}
	}
}
//Metodo que carga las cantidades vendidas de cada articulo de cada tienda
void cargaCantidadVendidas(){
	for(int i=0;i<numTiendas;i++){
		for(int j=0;j<numArticulos;j++){
			cout<<"Introduzca la cantidad vendida del articulo "<<j<<" para la tienda "<<i<<" \n";
			cin>>*(*(matrizVentas+i)+j);
		}
	}
}
//Metodo que carga los precios de los productos de cada tienda
void cargarMatriz(){
	for(int i=0;i<numTiendas;i++){
		for(int j=0;j<numArticulos;j++){
			cout<<"Introduzca el costo del articulo "<<j<<" para la tienda "<<i<<" \n";
			cin>>*(*(matrizNegocio+i)+j);
			while(*(*(matrizNegocio+i)+j) <= 0){
				cout<<"Introduzca de nuevo el costo \n";
				cin>>*(*(matrizNegocio+i)+j);
			}
		}
	}
}
