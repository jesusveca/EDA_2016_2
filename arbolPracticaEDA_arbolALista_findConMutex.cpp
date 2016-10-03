#include <iostream>
#include <thread>
#include <queue>

using namespace std;
mutex mut;

template <class T>
class nodo{
public:
	T dato;
	nodo<T> * hijos[2];
	nodo(T dato){
		this->dato=dato;
		hijos[0]=nullptr;
		hijos[1]=nullptr;
	}
};

template <class T>
class arbol{
public:
	nodo<T> * raiz;
	arbol(){
		raiz=nullptr;
	}

	bool find(T elemento, nodo<T> ** &x){
		x=&raiz;
		while((*x)){
			if((*x)->dato==elemento)	return 1;
			mut.lock();
			x=&(*x)->hijos[elemento>(*x)->dato];
			mut.unlock();
		}
		return 0;
	}
	
	bool insertar(T elemento){
		nodo<T> ** tmp;
		if(find(elemento, tmp))	return 0;
		*tmp=new nodo<T>(elemento);
		return 1;
	}

	nodo<T> ** elegir(){
		nodo<T> ** p = &(raiz->hijos[0]);
		while((*p)->hijos[1])
			p=&(*p)->hijos[1];
		return p;
	}
	
	bool borrar (T elemento){
		nodo<T> ** p;
		if(!find(elemento, p))	return 0;
		bool l,r;
		l=(*p)->hijos[0];
		r=(*p)->hijos[1];
		if(l & r){
			nodo<T> ** q=elegir();
			(*q)->dato=(*p)->dato;
			p=q;
		}
		nodo<T> * t=*p;
		*p=(*p)->hijos[(*p)->hijos[1]!=0];
		delete t;
		return 1;
	}

	bool eliminar(T elemento){
		nodo<T> **p;
		if (!find(elemento, p))	return 0;
		bool l,r;
		l=(*p)->hijos[0];
		r=(*p)->hijos[1];
		
		if(l & r){
			nodo<T> ** n= elegir();
			(*n)->dato=(*p)->dato;
			p=n;
		}
		nodo<T> * t=*p;
		(*p)=(*p)->hijos[(*p)->hijos[1]!=0];
		delete t;
		return 1;
	}
	
	
	
	void arbolLista(){
		nodo<T> * temporal=raiz;
		nodo<T> **p;
		
		nodo<T> **x=&raiz;
		while((*x)->hijos[1])
			x=&(*x)->hijos[1];
		nodo<T> *cola=(*x);
		
		for(;temporal!=nullptr;temporal=temporal->hijos[1]){
			while(temporal->hijos[0]){
				for(p=&temporal;(*p)->hijos[0];p=&(*p)->hijos[0]);
				cola->hijos[1]=(*p);
				while(cola->hijos[1]){
					cola=cola->hijos[1];
				}
				(*p)=nullptr;
			}
		}
		imprimir_();
	}
	
	
	void imprimir_(){
		if (!raiz)  return;
		queue<nodo<T>*> nivel_actual, nivel_sig;
		nivel_actual.push(raiz);
		bool end = true;
		while (!nivel_actual.empty())
		{
			nodo<T>* Nodo_actual = nivel_actual.front();
			nivel_actual.pop();
			if (Nodo_actual and Nodo_actual->dato>0){
				
				if(Nodo_actual){
					std::cout <<""<<Nodo_actual->dato << "  ";
					nivel_sig.push(Nodo_actual->hijos[0]);
					nivel_sig.push(Nodo_actual->hijos[1]);
					end = false;
				}
				
				else{
					std::cout <<"#"<<Nodo_actual->dato << "  ";
					nivel_sig.push(Nodo_actual->hijos[0]);
					nivel_sig.push(Nodo_actual->hijos[1]);
					end = false;
				}
				
			}
			else{
				nivel_sig.push(NULL);nivel_sig.push(NULL);
			}
			if (nivel_actual.empty())
			{
				std::cout << std::endl;
				if (end)
					return;
				std::swap(nivel_actual, nivel_sig);
				end = true;
			}
		}
		
	}

	
	
	
};


void insert(arbol<int> *a, int dato){
	a->insertar(dato);
	//
}


int main() {
	arbol<int> arbolito;
	arbolito.insertar(10);
	arbolito.insertar(2);
	arbolito.insertar(15);

	arbolito.insertar(20);
	arbolito.insertar(12);

	arbolito.imprimir_();
	
//	arbolito.borrar(12);
	
	arbolito.imprimir_();
	arbolito.arbolLista();
	
//	arbol<int> a;
//	
//	thread threads[6];
//	int arr[6] = {4, 3, 6, 2, 1, 8};
//	for(int i = 0; i < 6; i++){
//		threads[i] = thread(insert,&a,arr[i]);
//	}
//	
//	for(int i = 0; i < 6; i++){
//		threads[i].join();
//	}
//	a.imprimir_();
	
    return 0;
}
