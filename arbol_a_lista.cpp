#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class nodo{
public:
    T m_dato;
    nodo<T> * m_child[2];
    
    nodo(T x){
        m_dato=x;
        m_child[0]=NULL;
        m_child[1]=NULL;
    }
    
};

template <class T>
struct CListTrait{
    typedef  T U;
    typedef  less<T> C;
    typedef  greater<T> D;
};


template <class Tr>
class arbol{
private:
    typedef typename Tr::U T;//tipo de dato comparaciones
    typedef typename Tr::C C;
    typedef typename Tr::D D;
public:
    T m_dato;
    nodo<T> * m_root;
    less<T>     m_cmp;
    
    arbol(){
        m_root=NULL;
    }
    
    bool find(T x,nodo<T> ** &p){
        for(p=&m_root;(*p) && (*p)->m_dato!=x;p=&((*p)->m_child[m_cmp((*p)->m_dato,x)]));
        return (*p);
    }
    
    
    
    bool insertar(T x){
        nodo<T> ** p;
        if (find(x, p)) return 0;
        *p = new nodo<T>(x);
        return 1;
    }
    nodo<T> ** rep(nodo<T> ** p)
    {
        p = &((*p)->m_child[0]);
        while ((*p)->m_child[1])
            p = &((*p)->m_child[1]);
        return p;
    }
    
    bool borrar(T x){
        nodo<T> ** p;
        if (!find(x, p)) return 0;
        // Caso 2:tiene 2 hijos
        if ((*p)->m_child[0] && (*p)->m_child[1]) {
            nodo<T> ** q = rep(p);
            (*p)->m_dato = (*q)->m_dato;
            p = q;
        }
        nodo<T> * t = *p;
        // Caso 1:tiene 1 hijo
        *p = (*p)->m_child[(*p)->m_child[1]!=nullptr];
        delete t;
        return 1;
        
    }
    
    
//    nodo<T> * arbol_lista(nodo<T> *raiz){
//        
//
//        if (raiz == nullptr)
//            return 0;
//        
//        if(raiz->m_child[0]!=nullptr){
//            
//            nodo<T> * left= arbol_lista(raiz->m_child[0]);
//            for (; left->m_child[1] ; left=left->m_child[1]);
//            
//            left->m_child[1] = raiz;
////            raiz->m_child[0] = left;
//        }
//        
//        if(raiz->m_child[1]!=nullptr){
//            
//            nodo<T> *right = arbol_lista(raiz->m_child[1]);
//            for(;right->m_child[0];right=right->m_child[1]);
//            
//            right->m_child[0]=raiz;
//            raiz->m_child[1]=right;
//        }
//        
//        
//        while (raiz->m_child[0] != nullptr)
//            raiz = raiz->m_child[0];
//        
//        return (raiz);
//    }
    
//    
//    void imprimir(){
//        inorder(m_root);
//        cout<<endl;
//    }
//    
//    void inorder(nodo<T> *p){
//        if(p!=NULL){
//            inorder((p)->m_child[0]);
//            cout<<(p)->m_dato<<"   ";
//            inorder((p)->m_child[1]);
//        }
//        
//    }
//    
    
    
    void printTreeAmplitud(nodo<T> * p)
    {
        //vector se asemeja a una cola
        vector<nodo<T>*> l;
        l.push_back(p);
        while (!l.empty()) {
            nodo<T> * t = l.front();
            l.erase(l.begin());
            cout << t->m_dato <<"   ";
            if(t->m_child[0]) l.push_back(t->m_child[0]);
            if(t->m_child[1]) l.push_back(t->m_child[1]);
        }
        cout<<endl;
    }
    
    void imprimir_(){
        if (!m_root)  return;
        queue<nodo<T>*> nivel_actual, nivel_sig;
        nivel_actual.push(m_root);
        bool end = true;
        while (!nivel_actual.empty())
        {
            nodo<T>* Nodo_actual = nivel_actual.front();
            nivel_actual.pop();
            if (Nodo_actual and Nodo_actual->m_dato>0)
            {
                if(Nodo_actual){
                    std::cout <<""<<Nodo_actual->m_dato << "  ";
                    nivel_sig.push(Nodo_actual->m_child[0]);
                    nivel_sig.push(Nodo_actual->m_child[1]);
                    end = false;
                }
                
                else{
                    std::cout <<"#"<<Nodo_actual->m_dato << "  ";
                    nivel_sig.push(Nodo_actual->m_child[0]);
                    nivel_sig.push(Nodo_actual->m_child[1]);
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
    
    void imprimir_lista(){
        nodo<T>* ptr=m_root;
        while(ptr){
            cout<<ptr->m_dato<<" ";
            ptr=ptr->m_child[0];
        }
        cout<<endl;
    }

    
    void arbol_a_lista(){
        
        nodo<T>*izq=m_root;
        nodo<T>** ptr;
        
        nodo<T>** x=&m_root;
        while((*x)->m_child[0])     x=&(*x)->m_child[0];
        nodo<T> *cola=(*x);
        
        for(; izq!=nullptr; izq=izq->m_child[0]){
            while (izq->m_child[1]) {
                for(ptr=&izq;(*ptr)->m_child[1];ptr=&((*ptr)->m_child[1]));
                cola->m_child[0]=(*ptr);
                while(cola->m_child[0])     cola=cola->m_child[0];
                (*ptr)=nullptr;
            }
        }
        imprimir_lista();
    }
};






int main(int argc, const char * argv[]) {
    arbol<CListTrait<int> > arbolito;
    
    arbolito.insertar(50);
    arbolito.insertar(20);
    arbolito.insertar(100);
    arbolito.insertar(10);
    arbolito.insertar(30);
    arbolito.insertar(70);
    arbolito.insertar(120);
    arbolito.insertar(25);
    arbolito.insertar(40);
    arbolito.insertar(60);
    arbolito.insertar(80);
    arbolito.imprimir_();
    
    
    
    
    
    
//    arbolito.insertar(100);
//    arbolito.insertar(50);
//    arbolito.insertar(200);
//    arbolito.insertar(10);
//    arbolito.insertar(75);
//    arbolito.insertar(150);
//    arbolito.insertar(250);
//    
//    arbolito.insertar(5);
//    arbolito.insertar(25);
//    arbolito.insertar(60);
//    
//    arbolito.insertar(80);
//    arbolito.insertar(110);
//    arbolito.insertar(170);
//    
//    arbolito.insertar(220);
//    
//    arbolito.insertar(1);
//    arbolito.insertar(7);
//    arbolito.insertar(15);
//    arbolito.insertar(40);
//    arbolito.insertar(77);
//    arbolito.insertar(90);
//    arbolito.insertar(120);
//    arbolito.insertar(210);
//    arbolito.insertar(230);
    
    
    
//    arbolito.m_lista();
    cout<<endl;
    arbolito.arbol_a_lista();
    
    
    
    //    arbolito.imprimir();
    //    arbolito.printTreeAmplitud(arbolito.m_root);
    
    
//    arbolito.imprimir_();
    
    //    arbolito.borrar(10);
//    arbolito.imprimir_();
    
    cout<<endl<<endl;
    //    arbolito.printTreeAmplitud(arbolito.m_root);
    
//
//    nodo<int> * n = arbolito.arbol_lista(arbolito.m_root);
    
    cout<<endl;
//    arbolito.imprimir_();
//    nodo<int> * n = arbolito.m_root;
    
    
//    cout<<endl<<endl;
//    while(n)
//    {
//        cout<<n->m_dato<<endl;
//        n = n->m_child[1];
//    }
//    
//    cout<<endl;
    return 0;
}
