
/*****************************************************************************************************
*
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*
* 1. Ingresar 1er operando (A=x)
* 2. Ingresar 2do operando (B=y)
* 3. Calcular la suma (A+B)
* 4. Calcular la resta (A-B)
* 5. Calcular la division (A/B)
* 6. Calcular la multiplicacion (A*B)
* 7. Calcular el factorial (A!)
* 8. Calcular todas las operaciones
* 9. Salir
*
*  • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
*    que contenga las funciones para realizar las 4 operaciones.
*
*  • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
*    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado).
*
*  • Deberán contemplarse los casos de error (división por cero, etc).
*
*  • Documentar todas las funciones.
*
*****************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    float a, b;
    float solSuma, solResta, solMulti, solDivi;
    int solFactorial;

    char seguir='s';
    int opcion=0;

    printf("        BIENVENIDO!!   \n\n");



    do
    {
         printf("\n1- Ingresar 1er operando (A=x)\n");
         scanf("%f",&a);

         setbuf(stdin,NULL);

         printf("2- Ingresar 2do operando (B=y)\n");
         scanf("%f",&b);

    //system("clear");
        //printf("Usted cargo los operadores A= %.1f y B= %.1f. \n",a,b);
        printf("\n ¿Que operacion desea realizar? \n");
        printf("\n1- Calcular la suma (A+B)\n");
        printf("2- Calcular la resta (A-B)\n");
        printf("3- Calcular la division (A/B)\n");
        printf("4- Calcular la multiplicacion (A*B)\n");
        printf("5- Calcular el factorial (A!)\n");
        printf("6- Calcular todas las operacione\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                //system("clear");
                if(Sumar(a,b,&solSuma)==0)
                    {
                        printf("\n\n El resultado de la suma es: %.1f \n\n",solSuma);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                break;


            case 2:

                if(Restar(a,b,&solResta)==0)
                    {
                        printf("\n\n El resultado de la resta es: %.1f \n\n",solResta);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                break;

            case 3:

                if(Dividir(a,b,&solDivi)==0)
                    {
                        printf("\n\n El resultado de la division es: %.2f \n\n",solDivi);
                    }
                else
                    {
                        printf("\n\n   ERROR, solucion fuera de rango. \n");
                    }



                break;
            case 4:

                if(Multiplicar(a,b,&solMulti)==0)
                    {
                        printf("\n\n El resultado de la multiplicacion es: %.1f \n\n",solMulti);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                break;

            case 5:

                if(Factorial(a,&solFactorial)==0)
                    {
                        printf("\n\n El resultado del factorial es: %d \n\n",solFactorial);
                    }
                else //if(Factorial(a,&solFactorial)==1)
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                break;

            case 6:


                /****SUMA****/

                 if(Sumar(a,b,&solSuma)==0)
                    {
                        printf("\n\n El resultado de la suma es: %.1f \n\n",solSuma);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }


                /****RESTA****/

                 if(Restar(a,b,&solResta)==0)
                    {
                        printf("\n\n El resultado de la resta es: %.1f \n\n",solResta);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                /****DIVISION****/

                 if(Dividir(a,b,&solDivi)==0)
                    {
                        printf("\n\n El resultado de la division es: %.2f \n\n",solDivi);
                    }
                 else
                    {
                        printf("\n\n   ERROR, solucion fuera de rango. \n");
                    }

                /****MULTIPLICACION****/

                 if(Multiplicar(a,b,&solMulti)==0)
                    {
                        printf("\n\n El resultado de la multiplicacion es: %.1f \n\n",solMulti);
                    }
                 else
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }

                /****FACTORIAL****/

                 if(Factorial(a,&solFactorial)==0)
                    {
                        printf("\n\n El resultado del factorial es: %d \n\n",solFactorial);
                    }
                 else //if(Factorial(a,&solFactorial)==1)
                    {
                        printf("\n\n  ERROR, solucion fuera de rango. \n");
                    }


                break;


            case 7:
                seguir = 'n';
                break;

        }


            printf("\n\n  ¿Desea realizar otra operacion? (s/n)  \n");

            setbuf(stdin,NULL);

            scanf("%c",&seguir);

            seguir=tolower(seguir);


            system("clear"); //system("cls");


        }while(seguir=='s');


    return 0;
}
