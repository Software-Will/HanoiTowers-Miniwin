#include <iostream>
#include "miniwin.h"
using namespace std;
using namespace miniwin;

// Componentes para la torre de hanoi
void fondo(int x, int y)
{
	color(NEGRO);
	rectangulo_lleno(x, y, x + 600, y + 400);
}

void base(int x, int y)
{
	color(BLANCO);
	rectangulo_lleno(x * 600, y * 50, (x * 600) + 600, y * 50 + 50);
}

void pilar(int x, int y)
{
	color(BLANCO);
	rectangulo_lleno((x * 200) + 90, y * 50, (x * 200) + 110, (y * 50) + 250);
};

void disco1(int x, int y)
{
	color(AZUL);
	rectangulo_lleno(x * 200, y * 50, x * 200 + 200, y * 50 + 50);
}

void disco2(int x, int y)
{
	color(AMARILLO);
	rectangulo_lleno(x * 200 + 25, y * 50, x * 200 + 175, y * 50 + 50); // Se le resta 25
}

void disco3(int x, int y)
{
	color(ROJO);
	rectangulo_lleno(x * 200 + 50, y * 50, x * 200 + 150, y * 50 + 50); // Se le resta 50
}

void tablero()
{
	fondo(0, 0);
	base(0, 7);
	pilar(0, 2);
	pilar(1, 2);
	pilar(2, 2);
}

// Movimientos
// Disco3 -> Pilar3 | (vacio)
void movimiento1(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 3; i++)
	{
		disco3(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 3)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco2(0, 5);
		}
		y_aux = y - i;
	}

	// Para Derecha
	for (int j = 0; j <= 2; j++)
	{
		disco3(x + j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 2)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco2(0, 5);
		}
		x_aux = x + j;
	}

	// Para bajar
	for (int k = 0; k <= 5; k++)
	{
		disco3(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco2(0, 5);
			disco1(0, 6);
		}
	}
}

// Disco2 -> Pilar2 | (vacio)
void movimiento2(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 4; i++)
	{
		disco2(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 4)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco3(2, 6);
		}
		y_aux = y - i;
	}

	// Para Derecha
	for (int j = 0; j <= 1; j++)
	{
		disco2(x + j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 1)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco3(2, 6);
		}
		x_aux = x + j;
	}

	// Para bajar
	for (int k = 0; k <= 5; k++)
	{
		disco2(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco3(2, 6);
		}
	}
}

// Disco3(Pilar3) -> Pilar2 | (Disco2:Disco3)
void movimiento3(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 5; i++)
	{
		disco3(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco2(1, 6);
		}
		y_aux = y - i;
	}

	// Para Izquierda
	for (int j = 0; j <= 1; j++)
	{
		disco3(x - j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 1)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(0, 6);
			disco2(1, 6);
		}
		x_aux = x - j;
	}

	// Para bajar
	for (int k = 0; k <= 4; k++)
	{
		disco3(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 4)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco2(1, 6);
			disco1(0, 6);
		}
	}
}

// Disco1 -> Pilar3 | (vacio)
void movimiento4(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 5; i++)
	{
		disco1(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco3(1, 5);
			disco2(1, 6);
		}
		y_aux = y - i;
	}

	// Para Derecha
	for (int j = 0; j <= 2; j++)
	{
		disco1(x + j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 2)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco3(1, 5);
			disco2(1, 6);
		}
		x_aux = x + j;
	}

	// Para bajar
	for (int k = 0; k <= 5; k++)
	{
		disco1(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco2(1, 6);
			disco3(1, 5);
		}
	}
}

// Disco3 -> Pilar1 | (vacio)
void movimiento5(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 4; i++)
	{
		disco3(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 4)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(1, 6);
		}
		y_aux = y - i;
	}

	// Para Izquierda
	for (int j = 0; j <= 1; j++)
	{
		disco3(x - j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 1)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(1, 6);
		}
		x_aux = x - j;
	}

	// Para bajar
	for (int k = 0; k <= 5; k++)
	{
		disco3(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(1, 6);
		}
	}
}

// Disco2(Pilar2) -> Pilar3 | (Disco1:Disco2)
void movimiento6(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 5; i++)
	{
		disco2(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco3(0, 6);
		}
		y_aux = y - i;
	}

	// Para Derecha
	for (int j = 0; j <= 1; j++)
	{
		disco2(x + j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 1)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco3(0, 6);
		}
		x_aux = x + j;
	}

	// Para bajar
	for (int k = 0; k <= 4; k++)
	{
		disco2(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 4)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco3(0, 6);
		}
	}
}

// Disco3(Pilar1) -> Pilar3 | (Disco1:Disco2:Disco3)
void movimiento7(int x, int y)
{
	int y_aux, x_aux;
	// Para subir
	for (int i = 0; i <= 5; i++)
	{
		disco3(x, y - i);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (i < 5)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(2, 5);
		}
		y_aux = y - i;
	}

	// Para Derecha
	for (int j = 0; j <= 2; j++)
	{
		disco3(x + j, y_aux);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (j < 2)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(2, 5);
		}
		x_aux = x + j;
	}

	// Para bajar
	for (int k = 0; k <= 3; k++)
	{
		disco3(x_aux, y_aux + k);
		refresca();	 // Cada que ocurra el for necesitamos refrescar la consola
		espera(250); // es como un setTime en javascript -> milisegundos
		if (k < 3)
		{
			borra(); // Elimina los rastros que deja el disco
			tablero();
			disco1(2, 6);
			disco2(2, 5);
		}
	}
}

// Pilar1 -> Pilar3
void solucion1()
{
	movimiento1(0, 4); // Disco3
	movimiento2(0, 5); // Disco2
	movimiento3(2, 6); // Disco3
	movimiento4(0, 6); // Disco1
	movimiento5(1, 5); // Disco3
	movimiento6(1, 6); // Disco2
	movimiento7(0, 6); // Disco3
}

// Pilar1 -> Pilar2

// Ejecucion
//! Refactorizar el codigo - Habilitar POO
int main()
{
	int ancho = 600;
	int alto = 400;
	vredimensiona(ancho, alto);
	tablero();
	disco1(0, 6);
	disco2(0, 5);
	disco3(0, 4);
	solucion1();
	refresca();
	return 0;
}
