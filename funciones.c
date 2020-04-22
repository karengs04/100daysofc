#include <stdio.h>
void primitos(int num, int p, int i);
int main()
{
    int num=0;
    int i=0;
    int p=0;

        printf("\nIngresa un numero para ver si es primo o nel: \n");
        scanf(" %d",&num);
        if (num>0)
        {
        primitos(num,p,i);
        }
        else
        {
            printf("Numero no valio que se mayor a 0, plis\n");
        }
    return 0;
}
void primitos(int num, int p, int i)
{
    p=0;
            i=2;
            while(i<num  && p!=1)
            {
                if(num%i==0) p=1;
                i++;
            }
            if (p==0)
            {
                printf("\nEl numero %d es primo\n",num);
            }
            else
            {
                printf("\nEl numero %d no es primo\n",num);
            }
}