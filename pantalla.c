#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int proximoId();
static int buscadorID(Pantalla *array, int ID, int size);
static int buscarLugarLibre(Pantalla *array, int size);

int pantalla_init(Pantalla *array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

static int buscadorID(Pantalla *array, int ID, int size)
{

    int i;
    int retorno=-1;

    if(size>0&&array!=NULL)
    {
        retorno=-2;
        for(i=0; i<size; i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==ID)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

static int buscarLugarLibre(Pantalla *array, int size)
{
    int i;
    int retorno;
    if(size>0&&array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno =i;
            }
        }
    }
    return retorno;

}

int pantalla_alta(Pantalla *array, int size)
{

    int retorno=-1;
    int i;
    char buffer[50];

    if(size>0 && array !=NULL)
    {
        i=buscarLugarLibre(array, size);
        if(i>0)
        {
            if(!getValidString("Nombre: \n", "\n Error", "\nError, el maximo de caracteres es de 40", buffer, 40, 2))
            {

                strcpy(array[i].nombre,buffer);
                array[i].isEmpty=0;
                array[i].idPantalla=proximoId();
                retorno=0;
            }
            else
            {
                retorno =-3;
            }
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}

int pantalla_baja(Pantalla *array, int size, int ID)
{

    int indiceaEliminar;
    int retorno=-1;
    indiceaEliminar=pantalla_buscadorID(array, size, ID);
    if(indiceaEliminar>=0)
    {
        array[indiceaEliminar].isEmpty=-1;
    }
    return retorno;
}

int pantalla_modificacion(Pantalla *array, int size, int ID)
{

    int retorno=-1;
    int indiceaModificar;
    char *buffer;

    indiceaModificar=pantalla_buscadorID(array, size, ID);
    if(indiceaModificar>=0)
    {
        if(!getValidString("Nombre: \n", "\n Error", "\nError, el maximo de caracteres es de 40", buffer, 40, 2))
        {

            strcpy(array[indiceaModificar].nombre,buffer);
            retorno=0;
        }
        else
        {
            retorno=-2;
        }

    }
    return retorno;
}

int pantalla_mostrar(Pantalla *array, int size)
{

    int retorno=-1;
    int i;
    if(size>0 && array!=NULL)
    {
        for(i=0; i<size; i++)
        {
            printf("[DEGUB] - %d %s %d", array[i].idPantalla, array[i].nombre, array[i].isEmpty);
            retorno=0;
        }
    }
    return retorno;

}


int pantalla_ordenar(Pantalla *array, int size, int orden)
{
    int i;
    int retorno =-1;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(size>0&&array!=NULL)
    {

        do
        {
            flagSwap=0;
            for(i=0; i<size; i++)
            {
                if((strcmp(array[i].nombre, array[i+1].nombre)>0 && orden) || (strcmp(array[i].nombre, array[i+1].nombre) <0&& !orden))
                {

                    auxiliarEstructura = array[i];
                    array[i]=array[i+1];
                    array[i+1]=auxiliarEstructura;
                    flagSwap=1;

                }
            }
            retorno=0;
        }
        while(flagSwap);
    }
    return retorno;
}

static int proximoId()
{
    static int proximoId=-1;
    proximoId++;
    return proximoId;
}
