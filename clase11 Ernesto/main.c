#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "contratacion.h"
#include "utn.h"
#define LEN_PANTALLAS 10
#define LEN_CONTRATACIONES 1000

int main()
{
    Pantalla pantallas[LEN_PANTALLAS];
    Contratacion contrataciones[LEN_CONTRATACIONES];
    int menu;
    int auxiliarId;



    pantalla_init(pantallas,LEN_PANTALLAS);
    contratacion_init(contrataciones, LEN_CONTRATACIONES);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,QTY);
                break;
            case 5:
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);
                break;
        }

    }while(menu != 9);

    return 0;
}
