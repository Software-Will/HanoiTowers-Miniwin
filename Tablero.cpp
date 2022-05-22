#include <iostream>
#include "miniwin.h"
#include "Tablero.h"
using namespace std;
using namespace miniwin;

// Definicion de metodos
// Todo se encuentra parametrizado
void Tablero::fondo(int x, int y) // Fondo de la ventana
{
    color(NEGRO);
    rectangulo_lleno(x, y, x + 600, y + 400);
}

void Tablero::base(int x, int y) // Base del juego
{
    color(BLANCO);
    rectangulo_lleno(x * 600, y * 50, (x * 600) + 600, y * 50 + 50);
}

void Tablero::pilar(int x, int y) // Pilara para discos
{
    color(BLANCO);
    rectangulo_lleno((x * 200) + 90, y * 50, (x * 200) + 110, (y * 50) + 250);
};

// Inicializacion del tablero -> Solo para realizar un llamado
void Tablero::tablero()
{
	int ancho = 600;
	int alto = 400;
	vredimensiona(ancho, alto);
    fondo(0, 0);
    base(0, 7);
    pilar(0, 2);
    pilar(1, 2);
    pilar(2, 2);
}
