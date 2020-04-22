#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct alumnos
{
	char nombre[15];
	int matricula;
	int promedio;
}alumnos;
void iniciar(alumnos *arre,int cant);
void imprimir(int cant,alumnos *arre);
int main()
{
	srand(time(NULL));
	int cant=rand()%26+5;alumnos *arre=(alumnos*)malloc(cant*sizeof(alumnos));
	printf("cantidad: %i\n",cant );
	iniciar(arre,cant);
	imprimir(cant,arre);
	printf("Memoria liberada\n");
	free(arre);
	return 0;
}
void iniciar(alumnos *arre,int cant)
{
	for (int i = 0; i < cant ; ++i )
	{
		strcpy((arre+i)->nombre, "Shawn");
		(arre+i)->matricula=i+1;
		(arre+i)->promedio=rand()%11;
	}
}
void imprimir(int cant,alumnos *arre)
{
	for (int i = 0; i < cant; ++i)
	{
		printf("Nombre: %s\n",(arre+i)->nombre);
		printf("Matricula: %i\n",(arre+i)->matricula);
		printf("Promedio: %i\n",(arre+i)->promedio);
	}
}