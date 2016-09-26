#include "hashTable.h"
using namespace std;

int main(int argc, const char * argv[]) {
	
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
	srand(time(NULL));
	for (int i=0;i<100;i++){
		//tablita.insertar(i);
		tablita.insertar(rand()%10000);
	}
	tablita.imprimir();
	cout<<endl;
	
	
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
