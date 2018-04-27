#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#include "pantalla.h"

typedef struct{

int cuilCliente;
int idPantalla;
int fechaContratacion;
char *archivo;
int idContratacion;
int isEmpty;

}Contratacion;


int contratacion_init(Contratacion* array,int limite);
int contratacion_alta(Contratacion* array,int limite, Pantalla *pantallas, int size)

#endif // CONTRATACION_H_INCLUDED
