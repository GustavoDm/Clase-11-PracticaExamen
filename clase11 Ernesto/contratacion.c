#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "contratacion.h"
#include "pantalla.h"
#include "utn.h"

static int proximoId(void);

int contratacion_init(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int contratacion_alta(Contratacion* array,int limite, Pantalla *pantallas, LEN_PANTALLAS)
{
    int retorno = -1;
    int i;
    int cuilCliente;
    int fechaContratacion;
    int posicionPantalla;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nIngrese los numeros de cuil: (no use -, solo numeros)\n ","\nEso no es un cuil","El maximo es 40",cuilCliente,40,2))
            {
                if(!getValidInt("\nIngrese la cantidad de dias de contratacion: ","\nEl dato ingresado no es valido","El maximo es 40",fechaContratacion,40,2))
                {

                 if(!getValidInt("\nIngrese el ID de la pantalla a contratar", "Ese no es un ID valido", "El maximo es 40", idPantalla, 40, 2))

                            retorno = 0;

                            array[i].cuilCliente = cuilCliente;
                            array[i].idContratacion = proximoId();
                            array[i].isEmpty = 0;


                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
