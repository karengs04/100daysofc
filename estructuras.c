#include <stdio.h>
struct datos_personales
{
	char nombre[20];
	int edad;
	float peso;
	char direccion;
};
struct datos_personales paciente[4];
int main ()
{	
	for (int i=1; i<=4; i++)
	{
	printf("Nombre\n"); scanf("%s",&paciente[i].nombre);
	printf("Edad\n"); scanf("%d",&paciente[i].edad);
	printf("Peso\n"); scanf ("%f",&paciente[i].peso);
	}
	for (int i = 1; i <=4 ; ++i)
	{
		printf("Paciente %d\n",i);
		printf("Nombre: %s\n",paciente[i].nombre);
		printf("Edad: %d\n",paciente[i].edad);
		printf("Peso: %.2f\n",paciente[i].peso);
	}
}