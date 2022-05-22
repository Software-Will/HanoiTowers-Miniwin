#include <iostream>
#include "miniwin.h"
#include "Discos.h"
using namespace std;
using namespace miniwin;

// Definicion de Metodos
void Discos::disco1(int x, int y) // Disco Abajo
{
    color(AZUL);
    rectangulo_lleno(x * 200, y * 50, x * 200 + 200, y * 50 + 50);
}

void Discos::disco2(int x, int y) // Disco Medio
{
    color(AMARILLO);
    rectangulo_lleno(x * 200 + 25, y * 50, x * 200 + 175, y * 50 + 50); // Se le resta 25
}

void Discos::disco3(int x, int y) // Disco Arriba
{
    color(ROJO);
    rectangulo_lleno(x * 200 + 50, y * 50, x * 200 + 150, y * 50 + 50); // Se le resta 50
}