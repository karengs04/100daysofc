#include <stdio.h>
int llenar(int cont);
int sumas(int suma);
void leer();
void vaciar();
int arreglo[10],i,cont;
int suma,opc;
int main()
{

	for (i = 1; i<=10; ++i)
	{
		arreglo[i] = 0;
	}

	do
	{
		printf("1.llenar\n2. leer\n3. vaciar\n4.sumar\n5.salir\n");scanf("%d",&opc);
		switch(opc)
		{
			case 1 :
			llenar(cont);
			break;
			case 2 :
			leer();
			break;
			case 3 :
			vaciar();
			break;
			case 4 :
			sumas(suma);
			break;

		}
	}while(opc !=5);
	return 0;
}
int llenar(int cont)
{
	for (int i = 1; i <= 10 ; ++i)
	{
		printf("Ingresa los datos para el arreglo %d\n",i ); scanf("%d",&arreglo[i]);
		cont++;
	}
	//return 0;
}
void leer()
{
	for (i=1; i<= 10;i++)
	{
		printf("arreglo %d : %d \n",i, arreglo[i]);
	}
	//return 0;
}
void vaciar()
{
	suma=0;
	for (i = 1; i<=10; ++i)
	{
		arreglo[i] = 0;
	}
	//return 0;
}
int sumas(int suma)
{
	for (int i = 1; i <=10; ++i)
	{
		suma=suma+arreglo[i];
	}
	leer();
	//return 0;
	printf("el total de la suma es= %d\n",suma);
}