#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void intercambiar(int *num1,int *num2);
int main()
{
	srand(time(NULL));

	int x=rand()%100;printf("X es:%d\n",x);
	int y=rand()%100;printf("Y es:%d\n",y);
	intercambiar(&x, &y);
	printf("Ahora x es:%d\n",x);
	printf("Ahora y es:%d\n",y);
	return 0;
}
void intercambiar(int *num1,int *num2)
{
	int inter=*num1;
	*num1=*num2;
	*num2=inter;	
}





