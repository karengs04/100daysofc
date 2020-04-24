/******************************************************************************

Autor:Karen Yamili Guevara Salazar
Fecha:1/04/2020
*******************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct alumno 
{
	char nombre[9];
	int matricula;
	int promedio;
    struct alumno *siguiente;
    struct alumno *anterior;
};
typedef struct alumno Alumno; //se define la varible de tipo Alumno que estaran en los nodos
struct T_lista
{
	Alumno *cabecera;
	Alumno *ultimo;
	int tamanio;
};
typedef struct T_lista T_lista; // tipo de variable de la lista
T_lista *iniciar_lista_doble(int cant);
void imprimir_lista_doble_ida(T_lista *lista);
void imprimir_lista_doble_vuelta(T_lista *lista);
Alumno *llenar_nodo(Alumno *nuevo,char nombre[10],int matricula);
T_lista *insertar_en_posicion(T_lista *lista,int pos, Alumno *nuevo);
T_lista *borrar_posicion(T_lista *lista,int pos);
int aleatorio(int a, int b);
void libera_memoria(Alumno *cabecera);
int main()
{
	srand(time(NULL));
	T_lista *lista=(T_lista*)malloc(sizeof(T_lista));//se asigna espacio de memoria para lista
	lista->tamanio=aleatorio(5,30); printf("%i\n",lista->tamanio); 
	lista=iniciar_lista_doble(lista->tamanio);
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	Alumno *nuevo41=(Alumno*)malloc(sizeof(Alumno));//genera uno nuevo
	nuevo41=llenar_nodo(nuevo41,"Nuevo41",41);
	printf("\nSe inserta al final\n"); 
	lista=insertar_en_posicion(lista,lista->tamanio-1,nuevo41); //inserta al final
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	Alumno *nuevo42=(Alumno*)malloc(sizeof(Alumno));
	nuevo41=llenar_nodo(nuevo42,"Nuevo42",42);
	printf("\nSe inserta al inicio\n"); 
	lista=insertar_en_posicion(lista,0,nuevo41);//inserta al inicio
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	int pos=(lista->tamanio)/2;
	printf("Borrar al de  enmedio\n");
	lista=borrar_posicion(lista,pos); //Borra segun la posicion indicada
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	printf("\nBorrar al primero\n");
	lista=borrar_posicion(lista,0); //Borra el primer
	imprimir_lista_doble_vuelta(lista);
	printf("\nBorrar al ultimo\n");
	lista=borrar_posicion(lista,lista->tamanio-1);//Borra el ultimo
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	libera_memoria(lista->cabecera);
	free(lista);
	printf("Memoria Liberada\n");
	return 0;
}
T_lista *iniciar_lista_doble(int cant)
{
	Alumno *nuevo=NULL,*auxiliar;
	T_lista *lista=(T_lista*)malloc(sizeof(T_lista)); 
	for (int i = cant; i > 0; i--)
	{
		nuevo=(Alumno*)malloc(sizeof(Alumno));
		nuevo=llenar_nodo(nuevo,"Karen",i);
		if (i==cant)	
		{	
			nuevo->siguiente=NULL;
			lista->ultimo=nuevo;
		}
		else
		{
			nuevo->siguiente=auxiliar;
		}
		auxiliar->anterior=nuevo;
		auxiliar=nuevo; 
	}
	lista->cabecera=nuevo;
	lista->tamanio=cant;
	return lista;
}
void imprimir_lista_doble_ida(T_lista *lista)
{
	Alumno *ap=lista->cabecera;
	int y=0;
 	printf("|Posicion|Nombre|Matricula|promedio|\n");
	while (ap != NULL)
	{
		printf("%i        %s   %i 	    %i\n",y,ap->nombre,ap->matricula,ap->promedio); 
		ap=ap->siguiente;
		y++;
	}
}
void imprimir_lista_doble_vuelta(T_lista *lista)
{
	Alumno *ap=lista->ultimo;
	int y=(lista->tamanio)-1;
 	printf("|Posicion|Nombre|Matricula|promedio|\n");
	while (ap != NULL)
	{
		printf("%i        %s   %i 	    %i\n",y,ap->nombre,ap->matricula,ap->promedio); 
		ap=ap->anterior;
		y--;
	}
}
Alumno *llenar_nodo(Alumno *nuevo,char nombre[9],int matricula)
{
	strcpy(nuevo->nombre, nombre);
	nuevo->matricula=matricula;
	nuevo->promedio=rand()%11;
	return nuevo;
}
T_lista *insertar_en_posicion(T_lista *lista,int pos, Alumno *nuevo)
{
	Alumno *auxiliar=lista->cabecera,*ult=NULL,*cola=lista->ultimo;
	int i;
	for (i = 0; i < pos; ++i)
	{
		auxiliar=auxiliar->siguiente;
		ult=auxiliar->anterior;
	}
	if (i==0) 
	{
		nuevo->siguiente=auxiliar;
		auxiliar->anterior=nuevo;
		lista->cabecera=nuevo;
		lista->tamanio=lista->tamanio+1;
		return lista; 
	}
	else 
	{
		if (auxiliar==cola)
		{
			cola->siguiente=nuevo;
			nuevo->anterior=cola;
			nuevo->siguiente=NULL;
			lista->ultimo=nuevo;
			lista->tamanio=lista->tamanio+1;
			return lista;
		}
		else
		{
			ult->siguiente=nuevo;
			nuevo->anterior=ult;
			nuevo->siguiente=auxiliar;
			auxiliar->anterior=nuevo;
			lista->tamanio=lista->tamanio+1;
			return lista;
		}
	}
}
T_lista *borrar_posicion(T_lista *lista,int pos)
{
	Alumno *auxiliar=lista->cabecera,*atras=NULL,*del=NULL;
	int i;
	for (i = 0; i < pos; ++i)
	{
		auxiliar=auxiliar->siguiente;
		del=auxiliar->siguiente;
		atras=auxiliar->anterior;
	}
	if (i==0)
	{
		lista->cabecera=auxiliar->siguiente;
		(lista->cabecera)->anterior=NULL;
		free(auxiliar);
		lista->tamanio=lista->tamanio-1;
		return lista;
	}
	else 
	{
		if (auxiliar==lista->ultimo)
		{
			atras->siguiente=NULL;
			lista->ultimo=atras,
			free(auxiliar);
			lista->tamanio=lista->tamanio-1;
			return lista;
		}
		else
		{
			atras->siguiente=del;
			del->anterior=atras;
			free(auxiliar);
			lista->tamanio=lista->tamanio-1;
			return lista;
		}
	}
}
int aleatorio(int a, int b)
{
	int tamanio;
	tamanio=rand()%(b-a+1)+a;
	return tamanio;
}
void libera_memoria(Alumno *cabecera)
{
	Alumno *adios=NULL;
	while (cabecera!=NULL)
	{
		adios=cabecera->siguiente;
		free(cabecera);
		cabecera=adios;
	}
}
