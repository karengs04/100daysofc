#include <stdio.h>
float a, b, c;
int main()
{
	printf("Calcula el numero mayor de tres numeros\n");
	printf("Por favor, coloca un numero\n"); scanf("%f",&a);
	printf("Coloca otro numero\n"); scanf("%f", &b);
	printf("Coloca otro por fis\n"); scanf("%f",&c);
		if (a<=b && c<=b)
		{
			printf("El numero %.2f es mayor\n",b);
		}
		else if (b<=a && c<=a)
		{
			printf("El numero %.2f es mayor\n",a);
		}
		else if(a<=c && b<=c)
		{
			printf("El numero %.2f es mayor\n",c);
		}
	else
	{
		printf("Por favor, la proxima vez que SOLO sean numeros\n");
	}
	return 0;
}