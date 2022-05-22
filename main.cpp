#include <iostream>
#include "miniwin.h"
#include "Tablero.h"
#include "Discos.h"
#include "Solucion1.h"
#include "Solucion2.h"
using namespace std;
using namespace miniwin;

// Instancia de Objetos -> No se puede definir de la misma manera que en otras instancias de otras clases
Tablero *objTab = new Tablero();	  // Para definir la ventana y sus componentes
Discos *objDiscos = new Discos();	  // Para definir los discos
Solucion1 *objSol1 = new Solucion1(); // Para realizar los movimientos de la solucion 1 -> Del Pilar 1  al Pilar 3
Solucion2 *objSol2 = new Solucion2(); // Para realizar los movimientos de la solucion 2 -> Del Pilar 1  al Pilar 2

void solucion(int op)
{
	// Switch para definir la solucion que desea visualizar
	switch (op)
	{
	case 1: // Pilar1 -> Pilar3
		objSol1->solucion1();
		break;
	case 2: // Pilar 1 -> Pilar2
		objSol2->solucion2();
		break;
	}
}

// Ejecucion
int main()
{
	int op = 1; // op : 1 or 2
	// Inicializacion de componentes
	objTab->tablero();
	objDiscos->disco1(0, 6);
	objDiscos->disco2(0, 5);
	objDiscos->disco3(0, 4);
	solucion(op); // Visualizacion op1 - op2
	refresca();
	return 0;
}

//@WillCD
