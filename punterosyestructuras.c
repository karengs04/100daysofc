#include <stdio.h>

struct estructura_amigo {
        char nombre[30];
        char apellido[40];
        char telefono[10];
        int edad;
        };

struct estructura_amigo amigo = {
       "Juanjo",
       "Lopez",
       "592-0483",
       30
       };

struct estructura_amigo *p_amigo;

int main()
      {
      p_amigo = &amigo;
      printf( "%s tiene ", p_amigo->apellido );
      printf( "%i años ", p_amigo->edad );
      printf( "y su teléfono es el %s.\n" , p_amigo->telefono );
      }