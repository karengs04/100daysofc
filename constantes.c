#include <stdio.h>
#define cajas 4
#define unidades_por_caja 25
#define precio_por_unidad 100
#define precio_por_caja unidades_por_caja*precio_por_unidad
#define impuestos 1.16
int main ()
{
	float precio;
	precio= (cajas*precio_por_caja)*(impuestos);
	printf("El precio total es de %.3f\n",precio );
	return 0;
}