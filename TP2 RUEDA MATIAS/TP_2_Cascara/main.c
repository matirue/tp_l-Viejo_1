#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 20


int main()
{
      int salir=0;
      EPersona pers[TAM];

      inicializar(pers, TAM); /**< 0 para inactivo, 1 para activo */

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                system("cls");
                printf("          DAR DE ALTA          ");
                printf("\n\n");
                alta(pers, TAM);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("          DAR DE BAJA          ");
                printf("\n\n");
                Baja(pers, TAM);
                system("pause");
                break;

            case 3:
                system("cls");
                printf("          LISTA POR NOMBRE          ");
                printf("\n");
                ListarPersonas(pers, TAM);
                printf("\n\n");
                system("pause");
                break;

            case 4:
                system("cls");
                printf("          GRAFICO DE EDAD          \n");
                printf("\n");
                GRAFICO(pers, TAM);
                printf("\n\n");
                system("pause");
                break;

            case 5:
                salir=1;
                break;

            default:
                printf("\n\n    OPCION INEXISTENTE   ");

        }
    }while(salir!=1);

    return 0;
}
