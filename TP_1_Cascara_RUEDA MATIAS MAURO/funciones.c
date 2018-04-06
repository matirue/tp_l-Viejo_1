#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#include <ctype.h>


/**
* \brief Recibe los operadores a y b ingresados por el usuario, realiza la SUMA y devuelve el resultado.
* \param Toma 'a' como 'x', y a 'b' como 'y'.
* \param solucion Realiza la suma.
* \return Devuelve el resultado de la operacion.
**/

float Sumar (float x, float y, float *sol)
{
    float solucion;
    int retorna;
    solucion=x+y;

     if(solucion<-3.4028235E+38  || solucion>3.4028235E+38)
        {
           retorna=1;
        }
     else
        {
            *sol=solucion;
            retorna=0;
        }

    return retorna;
}


/**
* \brief Recibe los operadores a y b ingresados por el usuario, realiza la Resta y devuelve el resultado.
* \param Toma 'a' como 'x', y a 'b' como 'y'.
* \param solucion Realiza la resta.
* \return Devuelve el resultado de la operacion.
**/

float Restar (float x, float y, float *sol)
{
    float solucion;
    int retorna;
    solucion=x-y;


     if(solucion<-3.4028235E+38  || solucion>3.4028235E+38)
        {
           retorna=1;
        }
     else
        {
            *sol=solucion;
            retorna=0;
        }

    return retorna;
}



/**
* \brief Recibe los operadores a y b ingresados por el usuario, realiza la Division y devuelve el resultado.
* \param Toma 'a' como 'x', y a 'b' como 'y'.
* \param solucion Realiza la division.
* \return Devuelve el resultado de la operacion.
**/

float Dividir (float x, float y, float *sol)
{
    float solucion;
    int retorna;

    while(y==0)
        {
            printf("\n\n Error, el operador 'b' no puedeser cero. Reingrese otro valor: ");
            scanf("%f",&y);
        }

    solucion=x/y;

        if(solucion<-3.4028235E+38  || solucion>3.4028235E+38)
           {
               retorna=1;
           }
        else
           {
               *sol=solucion;
                retorna=0;
           }

    return retorna;
}



/**
* \brief Recibe los operadores a y b ingresados por el usuario, realiza la Multiplicacion y devuelve el resultado.
* \param Toma 'a' como 'x', y a 'b' como 'y'.
* \param solucion Realiza la multiplicacion.
* \return Devuelve el resultado de la operacion.
**/


float Multiplicar (float x, float y, float *sol)
{
    float solucion;
    int retorna;
    solucion=x*y;

    if(solucion<-3.4028235E+38  || solucion>3.4028235E+38)
        {
           retorna=1;
        }
     else
        {
            *sol=solucion;
            retorna=0;
        }

    return retorna;
}

/**
* \brief Recibe los operadores a ingresado por el usuario, realiza el Factorial y devuelve el resultado.
* \param Toma 'a' como 'x'.
* \param solucion Realiza el factorial.
* \return Devuelve el resultado de la operacion.
**/

int Factorial (float x, int *sol)
{
    int fact=1 , i;
    int retorna;
    //x=(int)x;

     while(x<0)
        {
            printf("\n\n ERRROR, no se puede calcular el factorial un negativo. Reingrese el operador 'A': ");
            scanf("%f",&x);
        }

     if(x>1)
        {
            while(x>=2)
                {
                    fact=fact*x;
                    x--;
                }
             *sol=fact;
             retorna=0;
        }
      else if(x==1)
        {
            *sol=0;
            retorna=0;
        }


        if(fact<-32768 || fact>32768)
            {

                retorna=1;
            }




     return retorna;
}
