#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANTCARACTERES 25
#define ARCHIVO "./bin.dat"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie pelicula;
    FILE *bin;

    if ((bin = fopen(ARCHIVO, "rb+"))==NULL)
        {
           if ((bin = fopen(ARCHIVO,"wb+"))==NULL)
           {
              printf("\n\n No se pudo abrir el archivo \n\n");
              exit(1);
           }
       }


    while(seguir=='s')
    {
        opcion=menu("\t\t\tMenu Principal\n\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir\n", 1, 5);
        system("cls");

        switch(opcion)
        {
            case 1:
                agregarPelicula(pelicula, CANTCARACTERES, bin);
                system("cls");
                break;

            case 2:
                borrarPelicula(pelicula, bin);
                break;

            case 3:
                modificaPelicula(pelicula, CANTCARACTERES, bin);
                break;

            case 4:
                generarPagina(pelicula, "Peliculas.html", bin);
                break;

            case 5:
                seguir='n';
                break;
        }
    }

    fclose(bin);
    return 0;
}
