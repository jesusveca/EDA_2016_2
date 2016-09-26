#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<math.h>
#include <iostream>
#include <random>
#include <chrono>
#include "lista.h"

double A;

//const int size = 11;
const int size = 73;

template<class T>
class hashTable{
	
public:
	int contador_global;
	CList<T>* tabla = new CList<T>[size];
	
	int hashFuncion(int clave){
		return clave % size;
		
		/*
		 double m;
		 m=size;
		 A=0.5*(sqrt(5)-1);
		 double x=clave*A;
		 int e=x;
		 x=x-e;
		 e=floor(m*x);
		 return e;
		 */
		
		
	}
	
	void insertar(int clave){
		int indice = hashFuncion(clave);
		tabla[indice].insertar(clave);
		tabla[indice].flag=1;
	}
	
	void eliminar(int clave){
		int indice = hashFuncion(clave);
		tabla[indice].eliminar(clave);
		if (tabla[indice].numeroElementos==0){
			tabla[indice].flag=0;
		}
	}
	
	void buscar(int clave){
		// CNode temp solo para darle un parametro a la busqueda la lista enlazada
		CNode<T> **temp;
		
		int indice = hashFuncion(clave);
		if (tabla[indice].find(clave,temp)==true){
			cout<<endl<<"	!! SI se encontro el valor, en indice: "<<indice<<endl;
		}
		else {
			cout<<endl<<"	!! NO se encontro el valor"<<endl;
			
		}
	}
	
	void imprimir(){
		int choques_totales=0;
		int contador = 0;
		while (contador<size){
			if (contador<10)	cout<<"[  "<<contador<<"] ";
			else if (contador>=10 && contador<100)	cout<<"[ "<<contador<<"] ";
			else	cout<<"["<<contador<<"] ";
			
			if (tabla[contador].flag==1)
				tabla[contador].print_list();
			
			//cout<<"						#choques : "<<tabla[contador].numeroElementos;
			if (tabla[contador].numeroElementos>1)
				choques_totales+=tabla[contador].numeroElementos-1;
			contador++;
			cout<<endl;
		}
		cout<<endl<<" RESUMEN DE CHOQUES : "<<choques_totales<<endl;
	}
	// para saber cuanto nodos estan ocupados
	void verificar_indices(){
		int contador_local =0;
		for (int i=0;i<size;i++){
			if(tabla[i].flag==1)
				contador_local++;
		}
		contador_global=contador_local;
	}
	
};



double generate_A(){
	std::mt19937_64 rng; //generador de numeros primos
	//64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
	
	//inicializando el generador del numero aleatorio con semillas dependiente del tiempo
	//entero de ancho exactamente de 64 bits
	uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	
	//
	std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
	rng.seed(ss);
	// Inicializar una distribución uniforme entre 0 y 1
	// busca numeros entre 0 y 1 ,
	// basados en la distribucion real uniforme
	// 1/(0,1)
	std::uniform_real_distribution<double> unif(0, 1);
	// listos para generar el numero buscado
	// const int nSimulations = 10;
	//        for (int i = 0; i < nSimulations; i++)
	//        {
	
	double currentRandomNumber = unif(rng);
	std::cout << currentRandomNumber << std::endl;
	//        }
	A=currentRandomNumber;
	return currentRandomNumber;
}
