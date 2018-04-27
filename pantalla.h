#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct{

char nombre[50];
int idPantalla;
int isEmpty;

}Pantalla;

int pantalla_init(Pantalla *array, int size);
int pantalla_alta(Pantalla *array, int size);
int pantalla_baja(Pantalla *array, int size, int ID);
int pantalla_modificacion(Pantalla *array, int size, int ID);
int pantalla_ordenar(Pantalla *array, int size, int orden);
int pantalla_mostrar(Pantalla *array, int size);

#endif // PANTALLA_H_INCLUDED
