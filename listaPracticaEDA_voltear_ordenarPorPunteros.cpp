#include <iostream>

using namespace std;
template <class T>
class nodo{
public:
	T dato;
	nodo<T> * next;
	nodo(T dato){
		this->dato=dato;
		next=nullptr;
	}
};

template <class T>
class lista{
public:
	nodo<T> * head;
	lista(){
		head=nullptr;
	}

	int size(){
		int count=0;
		nodo<T> *cnt=head;
		while(cnt){
			count++;
			cnt=cnt->next;
		}
		return count;
	}
	
	bool find(T elemento, nodo<T> ** &x){
		for(x=&head; (*x) /*&& (*x)->dato<elemento*/; x= &(*x)->next );
		return (*x) && (*x)->dato==elemento;
	}
	
	void insertar(T elemento){
		nodo<T> ** tmp;
		if(!find(elemento, tmp)){
			nodo<T> * a= new nodo<T>(elemento);
			a->next=*tmp;
			*tmp=a;
		}
	}
	
	void eliminar(T elemento){
		nodo<T> ** tmp;
		if(find(elemento, tmp)){
			nodo<T> * erase=*tmp;
			if(erase->next!=nullptr){
				*tmp=erase->next;
			}
			else{
				*tmp=nullptr;
			}
			delete erase;
		}
	}
	
	void voltear(){
		nodo<T> *tmp=head;
		nodo<T> *prev=nullptr;
		nodo<T> *next=nullptr;
		
		while(tmp!=nullptr){
			next=tmp->next;
			tmp->next=prev;
			prev=tmp;
			tmp=next;
		}
		head=prev;
	}
	
	void ordenar(){
		int tamano=size();
		if(head!=nullptr){
			nodo<T> * actual=head; nodo<T> * prev=nullptr; nodo<T> * aux=nullptr;
			int indicador=0;
			for(int i=0;i<tamano;i++){
				while (actual->next!=nullptr) {
					aux=actual->next;
					if(actual->dato>aux->dato){
						indicador=1;
						actual->next=aux->next;
						aux->next=actual;
						if(prev!=nullptr)
							prev->next=aux;
						prev=aux;
						if(head==actual)
							head=aux;
					}
					else{
						prev=actual;
						actual=actual->next;
					}
				}
				if(indicador==0)
					break;
				else{
					prev=nullptr;
					indicador=0;
					actual=head;
				}
			}
		}
	}
	
	
	
	void imprimir(){
		nodo<T> * m_head=head;
		while(m_head){
			cout<<m_head->dato<<"->";
			m_head=m_head->next;
		}
		cout<<endl;
	}
	
};


int main(){
	lista<int> l;
	l.insertar(10);
	l.insertar(1);
	l.insertar(5);
	l.imprimir();
	
//	l.eliminar(10);
	l.voltear();
	l.imprimir();
	
	l.ordenar();
	l.imprimir();
	return 0;
}