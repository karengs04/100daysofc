/******************************************************************************

Autor:Karen Yamili Guevara Salazar
Fecha:3/04/2020
*******************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 20

typedef struct T_pila
{
	int tope;
	int arre[MAX];
}T_pila;
int pila_vacia(T_pila *pila);
int pila_llena(T_pila *pila);
int aleatorio(int a, int b);
void imprimir_pila(T_pila *pila);
void push(T_pila *pila,int x);
int pop(T_pila *pila,int x);
T_pila *iniciando_pila();

int main()
{

	srand(time(NULL));
	printf("Iniciando pila\n");
	T_pila *pila=iniciando_pila();
	printf("CICLO DE MAX VUELAS(PUSH)\n");
	for (int i = 0; i < MAX; ++i)
	{
		int x= aleatorio(0,99);
		push(pila,x);
	}
	imprimir_pila(pila);
	int result=pila_llena(pila);
	if (result==1)
	{
		printf("Pila llena\n");
	}
	else
	{
		printf("Pila no llena\n");
	}
	printf("CICLO DE MAX/2 VUELTAS(POP)\n");
	for (int i = 0; i < MAX/2; ++i)
	{
		int x=pop(pila,x);
		printf("El elemento extraido es: %i\n",x);
	}
	imprimir_pila(pila);
	printf("CICLO DE MAX/4 VUELTAS(PUSH)\n");
	for (int i = 0; i < MAX/4; ++i)
	{
		int x=aleatorio(0,99);
		push(pila,x);
	}
	imprimir_pila(pila);
	printf("Vaciar pila\n");
	while(pila->tope!=0)
	{
		int x=pop(pila,x);
		printf("El elemeto extraido es: %i\n",x );
	}
	result=pila_vacia(pila);
	if (result==1)
	{
		printf("Pila vacia\n");
	}
	else
	{
		printf("Pila no vacia\n");
	}
	free(pila);
}
T_pila *iniciando_pila() //inicia la pila
{
	T_pila *pila=malloc(sizeof(T_pila)); //coloca el tamano de la pila
	pila->tope=0;
	for (int i = 0; i < MAX; ++i)
	{
		pila->arre[i]=0;
	}
	return pila;
}
int pila_vacia(T_pila *pila)
{
	if (pila->tope==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pila_llena(T_pila *pila)
{
	if (pila->tope==MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(T_pila *pila, int x) //coloca elementos en la pila.
{
	if (pila_llena(pila)!=1)
	{
		pila->tope++;
		pila->arre[pila->tope]=x;
	}
	else
	{
		printf("Desbordamiento-Pila llena\n"); // si la pila esta llena coloca este mensaje indicando que ya no puede colocar mas.
	}
}
int pop(T_pila *pila, int x) //quita elementos de la pila
{
	if (pila_vacia(pila)!=1)
	{
		x=pila->arre[pila->tope];
		pila->arre[pila->tope]=0;
		pila->tope--;
		return x;
	}
	else
	{
		printf("Subdesbordamiento-Pila vacia\n");
	}
}
void imprimir_pila(T_pila *pila)
{
	printf("\n");
	for (int i = 0; i < MAX; ++i)
	{
		printf("Arre[%i]=%i\n",i,pila->arre[i]);
	}
	printf("\n");
}
int aleatorio(int a, int b)
{
	int dato=rand()%(b-a+1)+a;
	return dato;
}
