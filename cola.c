// Autor: Karen Yamili Guevara Salazar
// 29/03/2020
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 40
typedef struct cola //estructura de cola circular
{
	int front;
	int last;
	int datos[MAX];
}Cola;
Cola *create_cola();
int cola_llena(Cola *cola);
int cola_vacia(Cola*cola);
int encolar(Cola *cola,int data);
int despachar (Cola *cola);
void imprimir_cola(Cola *cola);
int aleatorio(int x, int y);
void simulador(Cola *cola,int vel,int cant_operaciones);

int main ()
{
	srand(time(NULL));
	printf("¿Tiene espacio?\n");
	Cola *cola=create_cola();
	int cant = aleatorio(MAX/2, MAX); //cantidad aleatoria de elemntos a llenar
	for (int i = 0; i < cant ; ++i)
	{
		encolar(cola,aleatorio(10,99)); //encola la cantidad de elementos
	}
	printf("| S I M U L A C I O N |\n");
	int cant_operaciones=35,vel=10; //asigna la cantidad de operaciones y velocidad de despacho
	simulador(cola,vel,cant_operaciones); 
	printf("| F I N  D E  L A  S I M U L A C I O N |\n");
	vel=50;
	printf("| S I M U L A C I O N VEL=50 |\n");
	simulador(cola,vel,cant_operaciones);
	printf("| F I N  D E  L A  S I M U L A C I O N |\n");
	vel=85;
	printf("| S I M U L A C I O N VEL=85 |\n");
	simulador(cola,vel,cant_operaciones);
	printf("| F I N  D E  L A  S I M U L A C I O N |\n");
	free(cola);
	return 0;
}
Cola *create_cola()
{
	Cola *new_cola = (Cola *) malloc (sizeof(Cola)); //crea y asigna memoria a nueva cola
	new_cola->front = -1;
	new_cola->last = -1;
	return new_cola;
}
int cola_llena (Cola *cola)
{
	int front=cola->front, last=cola->last; //asigna valor a frente y final
	if ((last==MAX-1 && front==0) || last+1==front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int encolar(Cola *cola,int data)
{
	if (cola_llena(cola)==1) //verifica si esta llena
	{
		printf("FULL COLA\n");
		return -1;
	}
	else if (cola_vacia(cola)==1) //verifica si esta vacia
	{
		cola->last++;
		cola->front++;
		cola->datos[cola->last]=data;
	}
	else
	{
		if (cola->last== MAX-1) //si no esta vacia pero tampoco llena, checa si final esta en el ultimo indice
		{
			cola->last=0;
			cola->datos[cola->last]=data;
		}
		else
		{
			cola->last++;
			cola->datos[cola->last]=data;
		}
	}
	return 1;
}

int cola_vacia (Cola *cola)
{
	int front=cola->front, last=cola->last;
	if (front==-1 && last==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int despachar(Cola *cola)
{
	if(cola_vacia(cola)==1) //verifica si la cola esta vacia
	{
		printf("Empty\n");
		return 2;
	}
	else
	{
		int data= cola->datos[cola->front]; //extrae el dato
		cola->datos[cola->front]=0;
		if (cola->front==MAX-1)
		{
			cola->front=0;
		}
		else if (cola->front==cola->last)
		{
			cola->front=-1;
			cola->last=-1;
		}
		else
		{
			cola->front++;
		}
		return data;
	}
}
int aleatorio(int x,int y)
{
	int data=rand()%(y-x+1)+x;
	return data;
}
void imprimir_cola(Cola *cola)
{
	for (int i = 0; i < MAX; ++i) //imprime todos los numeros en una linea
	{
		printf("%i,",cola->datos[i]);
	} printf("\n");
	for (int a = 0; a < MAX; ++a)
	{
		if (a==cola->front)
		{
			printf("Fr");
		}
		else if (a==cola->last)
		{
			printf("La");
		}
		else
		{
			printf("   "); //si no se topa con frente o la imprime espacio
		}
	} printf("\n");
}
void simulador (Cola *cola,int vel,int cant_operaciones)
{
	for (int i = 0; i < cant_operaciones; ++i) //ciclo que da vuelta por cada operacion
	{
		if (aleatorio(0,100)<vel) //si el aleatorio es menor a la velociad, se despacha
		{
			int data=despachar(cola);
			imprimir_cola(cola);
		}
		else
		{
			int b=aleatorio(10,99);
			encolar(cola,b);
			imprimir_cola(cola);
		}
	}
}
