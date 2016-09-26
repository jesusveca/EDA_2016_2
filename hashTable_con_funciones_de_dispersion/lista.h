#include <iostream>

using namespace std;


template< class T>
class CNode {
	
public:
	T m_dato;
	CNode<T> * m_next;
	
	CNode(T dato){
		m_dato=dato;
		m_next=NULL;
	}
};

template<class T>
class CList{
	
public:
	
	CNode<T>* m_head;
	bool flag=0;
	int numeroElementos=0;
	
	CList(){
		m_head=NULL;
	};
	
	bool find( T elemento, CNode<T> ** &x)  {
		for(x = & m_head;(*x) && (*x)->m_dato<elemento;x=&(*x)->m_next);
		return (*x) && (*x)->m_dato==elemento;
	}
	
	void insertar(T val){
		CNode<T> **temp;
		if(!find(val, temp)){
			CNode<T> *a = new CNode<T>(val);
			numeroElementos++;
			a->m_next = *temp;
			(*temp) = a;
		}
		
	}
	
	void eliminar(T val){
		CNode<T>  **temp;
		
		if((find(val,temp))){
			CNode<T>  *to_erase = (*temp);
			if(to_erase->m_next != NULL){
				(*temp) = to_erase->m_next;
			}
			else{
				(*temp) = NULL;
			}
			delete to_erase;
			numeroElementos--;
		}
		
	}
	
	void voltear_lista(){
		CNode<T> *temporal=m_head;
		CNode<T> *prev=NULL;
		CNode<T> *next=NULL;
		
		while(temporal!=NULL){
			next=temporal->m_next;
			temporal->m_next=prev;
			prev=temporal;
			temporal=next;
		}
		m_head=prev;
		
	}
	
	void print_list()
	{
		CNode<T> *me=m_head;
		while(me && me->m_next!=nullptr){
			cout<<me->m_dato<<"->";
			me=me->m_next;
		}
		cout<<me->m_dato;
	}
	
	
};
