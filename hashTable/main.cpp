#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <random>
#include <chrono>


double A;
using namespace std;
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


int main(){
	// digamos que clave es 6;
	int size =131;
	int clave=6;
	double m;
	m=size;
	A=0.5*(sqrt(5)-1);
	double x=clave*A;
	int e=x;
	x=x-e;
	e=floor(m*x);
	cout<<" valor final "<<e<<endl;
}
