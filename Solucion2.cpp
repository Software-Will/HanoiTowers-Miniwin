#include <iostream>
#include "miniwin.h"
#include "Tablero.h"
#include "Discos.h"
#include "Solucion2.h"
using namespace std;
using namespace miniwin;

// Instanciar Objeto Tablero para los discos -> No se puede definir de la misma manera que otras clases
Tablero *objTabS2 = new Tablero();
Discos *objDiscosS2 = new Discos();

// Definicion de los metodos Movimientos
// Disco3(Pilar1) -> Pilar2 | (vacio)
void Solucion2::movimiento1(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 3; i++)
    {
        objDiscosS2->disco3(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 3)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco2(0, 5);
        }
        y_aux = y - i;
    }

    // Para Derecha
    for (int j = 0; j <= 1; j++)
    {
        objDiscosS2->disco3(x + j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 1)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco2(0, 5);
        }
        x_aux = x + j;
    }

    // Para bajar
    for (int k = 0; k <= 5; k++)
    {
        objDiscosS2->disco3(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco2(0, 5);
            objDiscosS2->disco1(0, 6);
        }
    }
}

// Disco2(Pilar1) -> Pilar3 | (vacio)
void Solucion2::movimiento2(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 4; i++)
    {
        objDiscosS2->disco2(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 4)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco3(1, 6);
        }
        y_aux = y - i;
    }

    // Para Derecha
    for (int j = 0; j <= 2; j++)
    {
        objDiscosS2->disco2(x + j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 2)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco3(1, 6);
        }
        x_aux = x + j;
    }

    // Para bajar
    for (int k = 0; k <= 5; k++)
    {
        objDiscosS2->disco2(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco3(1, 6);
        }
    }
}

// Disco3(Pilar2) -> Pilar3 | (Disco2:Disco3)
void Solucion2::movimiento3(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 5; i++)
    {
        objDiscosS2->disco3(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco2(2, 6);
        }
        y_aux = y - i;
    }

    // Para Derecha
    for (int j = 0; j <= 1; j++)
    {
        objDiscosS2->disco3(x + j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 1)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco2(2, 6);
        }
        x_aux = x + j;
    }

    // Para bajar
    for (int k = 0; k <= 4; k++)
    {
        objDiscosS2->disco3(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 4)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(0, 6);
            objDiscosS2->disco2(2, 6);
        }
    }
}

// Disco1(Pilar1) -> Pilar2 | (vacio)
void Solucion2::movimiento4(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 5; i++)
    {
        objDiscosS2->disco1(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco3(2, 5);
            objDiscosS2->disco2(2, 6);
        }
        y_aux = y - i;
    }

    // Para Derecha
    for (int j = 0; j <= 1; j++)
    {
        objDiscosS2->disco1(x + j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 1)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco3(2, 5);
            objDiscosS2->disco2(2, 6);
        }
        x_aux = x + j;
    }

    // Para bajar
    for (int k = 0; k <= 5; k++)
    {
        objDiscosS2->disco1(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco2(2, 6);
            objDiscosS2->disco3(2, 5);
        }
    }
}

// Disco3(Pilar3) -> Pilar1 | (vacio)
void Solucion2::movimiento5(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 4; i++)
    {
        objDiscosS2->disco3(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 4)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(2, 6);
        }
        y_aux = y - i;
    }

    // Para Izquierda
    for (int j = 0; j <= 2; j++)
    {
        objDiscosS2->disco3(x - j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 2)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(2, 6);
        }
        x_aux = x - j;
    }

    // Para bajar
    for (int k = 0; k <= 5; k++)
    {
        objDiscosS2->disco3(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(2, 6);
        }
    }
}

// Disco2(Pilar3) -> Pilar2 | (Disco1:Disco2)
void Solucion2::movimiento6(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 5; i++)
    {
        objDiscosS2->disco2(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco3(0, 6);
        }
        y_aux = y - i;
    }

    // Para Izquierda
    for (int j = 0; j <= 1; j++)
    {
        objDiscosS2->disco2(x - j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 1)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco3(0, 6);
        }
        x_aux = x - j;
    }

    // Para bajar
    for (int k = 0; k <= 4; k++)
    {
        objDiscosS2->disco2(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 4)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco3(0, 6);
        }
    }
}

// Disco3(Pilar1) -> Pilar2 | (Disco1:Disco2:Disco3)
void Solucion2::movimiento7(int x, int y)
{
    int y_aux, x_aux;
    // Para subir
    for (int i = 0; i <= 5; i++)
    {
        objDiscosS2->disco3(x, y - i);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (i < 5)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(1, 5);
        }
        y_aux = y - i;
    }

    // Para Derecha
    for (int j = 0; j <= 1; j++)
    {
        objDiscosS2->disco3(x + j, y_aux);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (j < 1)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(1, 5);
        }
        x_aux = x + j;
    }

    // Para bajar
    for (int k = 0; k <= 3; k++)
    {
        objDiscosS2->disco3(x_aux, y_aux + k);
        refresca();  // Cada que ocurra el for necesitamos refrescar la consola
        espera(250); // es como un setTime en javascript -> milisegundos
        if (k < 3)
        {
            borra(); // Elimina los rastros que deja el disco
            objTabS2->tablero();
            objDiscosS2->disco1(1, 6);
            objDiscosS2->disco2(1, 5);
        }
    }
}

void Solucion2::solucion2()
{
    movimiento1(0, 4); // Disco3
    movimiento2(0, 5); // Disco2
    movimiento3(1, 6); // Disco3
    movimiento4(0, 6); // Disco1
    movimiento5(2, 5); // Disco3
    movimiento6(2, 6); // Disco2
    movimiento7(0, 6); // Disco3
}