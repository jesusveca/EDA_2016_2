#include "hashTable.h"
#include <time.h>
using namespace std;

int main(int argc, const char * argv[]) {
	
//	hashTable<string> tablita;
	
	clock_t t;
	t = clock();
	
	hashTable<int> tablita;
	
	/*tablita.insertar(20);
	 tablita.insertar(30);
	 tablita.insertar(10);
	 tablita.insertar(21);
	 tablita.insertar(31);
	 tablita.insertar(11);
	 tablita.insertar(22);
	 tablita.insertar(32);
	 tablita.insertar(12);
	 tablita.imprimir();
	 //tablita.buscar(30);
	 cout<<endl;
	 tablita.eliminar(10);
	 tablita.eliminar(20);
	 tablita.eliminar(30);
	 cout<<endl;
	 */
	generate_A();
	generate_B();
	//string a= "45";
	//tablita.insertar(a);
	srand(time(NULL));
	for (int i=0;i<1000000;i++){
		//tablita.insertar(i);
		tablita.insertar(rand()%1000000000+100);
	}
	tablita.imprimir();
//	tablita.buscar(a);
	cout<<endl;
	t = clock() - t;
	printf ("segundos (%f segundos :).\n",t,((float)t)/CLOCKS_PER_SEC);
	
	/*tablita.eliminar(10);
	 tablita.imprimir();
	 cout<<endl;
	 tablita.insertar(10);
	 tablita.imprimir();
	 cout<<endl;
	 tablita.buscar(40);
	 cout<<endl;
	 */
	return 0;
}
