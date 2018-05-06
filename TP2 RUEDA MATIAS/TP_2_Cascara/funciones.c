#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


/**************************************MENU************************************************************/
int menu()
{
    int opcion;

    printf("---------BIENVENIDO---------");
    printf("\n\n");
    printf("1-AGREGAR PERSONA\n");
    printf("2-BORRAR PERSONA\n");
    printf("3-IMPRIMIR LISTA ORDENADA POR NOMBRE\n");
    printf("4-IMPRIMIR GRAFICO DE EDADES\n");
    printf("5-SALIR\n");
    printf("\n\n");

    printf(" Elija una operacion: ");
    scanf("%d",&opcion);

    while(opcion<=0 ||opcion>=6)
    {
        printf("\n\n  ERROR. Operacion invalida ");
        printf("\n\n       Vuelva a ingresar una operacion: ");
        scanf("%d",&opcion);
    }

    return opcion;
}
/**************************************FIN DE MENU*****************************************************/

/** \brief Inicializa el estado de un array de productos
 * \param pers[] Es el array en el cual buscar
 * \param cantidad Es el largo del array
 * \return void
 */

void inicializar(EPersona pers[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        pers[i].estado = 0;  /**< 0 para inactivo, 1 para activo */
    }
}
/******************************************************************************************************/

/******************************************************************************************************/
/**
 * \brief Busca el primer lugar no utilizado en el array.
 * \param pers el array se pasa como parametro.
 * \param cantidad Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 **/

int obtenerEspacioLibre (EPersona pers[], int cantidad)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(pers[i].estado==0)    //recordar q estado=0 es inactivo
            {
                indice=i;
                break;
            }
        }
        return indice;
}

/******************************************************************************************************/
/**
 * \brief Busca la primer ocurrencia de un producto mediante su codigo
 * \param pers Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param dniAux Es el DNI que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */

int buscarPorDni (EPersona pers[], int cantidad, int dniAux)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(pers[i].estado==1 && pers[i].dni==dniAux)
                {
                    indice=i;
                    break;
                }
        }
    return indice;
}
/******************************************************************************************************/

void alta(EPersona pers[], int cantidad)
{
    int  existe, lugar;
    char dniAux[8];
    char nomAux[51];
    char edadAux[3];

    lugar=obtenerEspacioLibre(pers, cantidad);

    if(lugar==-1)
        {
            printf("\n\n Sistema completamente. No se puede seguir dando de alta a mas personas.\n\n");
        }
    else
        {     /*****************DNI******************/


            while( (getStringNumeros("\n\n Ingrese DNI: ", dniAux)==0) || (atoi(dniAux)<000000000 || atoi(dniAux)>999999999) )
                {
                    printf("\n\n ERROR. DNI invalido.  \n\n");

                }
            pers[lugar].dni=atoi(dniAux);

            existe=buscarPorDni(pers, cantidad, pers[lugar].dni);

            if(existe!=-1)
                {
                    printf("\n\n El DNI %d ya existe en el sistema \n", pers[lugar].dni);

                    mostrarPersonaPorDNI (pers[existe]);
                }
            else
                {
                    pers[lugar].estado=1;


                       /*******************NOMBRE******************/
                       while(getStringLetras("\n Ingrese nombre: ",nomAux)==0)
                        {
                            printf("\n\n ERROR. Nombre invalido... El nombre contener solo letras: ");

                        }
                       strcpy(pers[lugar].nombre, nomAux);

                      /***************EDAD*************************/
                      while((getStringNumeros("\n Ingrese edad: ",edadAux)==0)||((atoi(edadAux))<1 || (atoi(edadAux)) >110 ))
                        {
                            printf("\n\n ERROR. Edad invalida: \n");
                            printf("\n -La edad debe estar compuesta por numeros.");
                            printf("\n -La edad ingresada esta fuera de rango. \n\n");
                        }
                      pers[lugar].edad=atoi(edadAux);


                    printf("\n\n\n  ALTA EXITOSA   \n\n\n");

                }
          }

}
/******************************************************************************************************/
void ListarPersonas (EPersona pers[], int cantidad)
{
    int i;
    printf("\n\n  DNI   \t   NOMBRE   \t   EDAD   \n");
    burbujeoOedenarNombre(pers, cantidad);
    for(i=0;i<cantidad;i++)
        {
            if(pers[i].estado==1)
                {
                     mostrarPersonaPorDNI(pers[i]);
                }
        }
}

/** \brief ordeno por nombre
 * \param pers El array a recoorer
 * \param cant Largo del array
 * \return void
 */

void burbujeoOedenarNombre(EPersona pers[], int cant)
{
    EPersona persAux;
    int i,j;

    for(i=0;i<cant-1;i++)
        {
            for(j=i+1;j<cant;j++)
                {
                    if(strcmp(pers[i].nombre,pers[j].nombre)>0)
                        {
                            persAux=pers[i];
                            pers[i]=pers[j];
                            pers[j]=persAux;
                        }
                }
        }
}
/******************************************************************************************************/

void mostrarPersonaPorDNI (EPersona pers)
{
    printf("  %d   \t   %s   \t   %d   \n", pers.dni, pers.nombre, pers.edad);
}

/******************************************************************************************************/
void Baja (EPersona pers[], int cantidad)
{
    int existe;
    char confirmar;
    char dniAux[8];
    int dniDel;
    int stop=0;

    while( (getStringNumeros("\n\n Ingrese DNI que desea eliminar: ", dniAux)==0) || (atoi(dniAux)<000000000 || atoi(dniAux)>999999999) )
                {
                    printf("\n\n ERROR. DNI invalido.  \n\n");

                }

    dniDel=atoi(dniAux);

    existe=buscarPorDni(pers, cantidad, dniDel);

    if(existe==-1)
        {
            printf("\n\n No existe el DNI ingresado. \n\n");
        }
    else
        {
            printf("\n");
            mostrarPersonaPorDNI(pers[existe]);

            do{

                    confirmar=getChar("\n\n Confirmar baja? (s/n):  ");
                    if(confirmar=='s')
                     {
                        pers[existe].estado=0;
                        printf("\n\nBAJA EXITOSA\n\n");
                        stop=1;
                     }
                    else if(confirmar=='n')
                     {
                        printf("\n\nBaja cancelada.\n\n");
                        stop=1;
                     }
                    else
                     {
                        printf("\n\nRespuesta erronea.\n\n");
                     }
            } while(stop!=1);
        }

}

/********************************************************************************************************************/
/******************************************************************************************************/
void GRAFICO (EPersona pers[], int cantidad)
{
    int i, mayor;
    int contMayores=0, contMedio=0, contMenor=0;
    int flag=0;

    for (i=0;i<cantidad;i++)
    {
         if (pers[i].estado==1)
         {
           if(pers[i].edad>35)
           {
              contMayores++;
           }
           if(pers[i].edad<36 && pers[i].edad>18)
           {
              contMedio++;
           }
           if(pers[i].edad<19)
           {
              contMenor++;
           }
         }
    }

    mayor=contMayores;

    if (mayor<contMedio)
    {
       mayor=contMedio;
    }
    if(mayor<contMenor)
    {
       mayor=contMenor;
    }

    for(i=mayor;i>0;i--)
    {
       flag = 0;

       if(contMenor>=i)
       {
          printf("*");
       }
       if(contMedio>=i)
       {
          printf("\t*");
          flag=1;
       }
       if(contMayores>=i)
       {
         if (flag ==0)
         {
             printf("\t\t*");
         }
         else
         {
             printf("\t*");
         }
    }
    printf("\n");
        }
    printf("<=18\t19-35\t>=36 \n\n");
}
/******************************************************************************************************/
/******************************************************************************************************/
/**
* \brief Solicita una leta al usuario y la devuelve.
* \param algo Es el mensaje a mostrar.
* \return Devuelve la letra ingresada.
**/
char getChar(char algo[])
{
    char dato;
    printf("%s",algo);
    //setbuf(stdin,NULL);
    fflush(stdin);
    scanf("%c",&dato);
    dato=tolower(dato);
    return dato;
}

/**
* \brief Le pide un numero al ususario y devuelve un resultado.
* \param sms Es el mensaje a ser mostrado.
* \return Devuelve el numero (x) ingresado por el usuario.
**/
int getInt(char sms[])
{
    int x;
    printf("%s",sms);
    scanf("%d",&x);
    return x;
}

/**
* \brief Pide un texto numerico al usuario y lo devuelve
* \param sms Es el texto a ser mostrado
* \param num Es el Array donde se cargara el texto pedido
* \return 1 si el texto contiene solo numeros, 0 caso contrario
*/
int getStringNumeros(char sms[], char num[])
{
    char aux[256];
    getString(sms, aux);
    if(esNumerico(aux))
      {
         strcpy(num,aux);
         return 1;
      }
    return 0;
 }

 /** FC PEDIR TEXTO
 * \brief Pide un texto al usuario y lo devuelve
 * \param sms Es el texto a ser mostrado
 * \param input Es el Array donde se cargara el texto pedido
 * \return void
 */
 void getString (char sms[], char a[])
 {
    printf("%s", sms);
    scanf("%s", a);

 }

/** VERIFICAR NUMERO
 * \brief verifica si el valor recibido es numerico
 * \param  x Array  con la cadena a ser analizado
 * \return 1 si es numerico y 0 si no lo es.
 */

 int esNumerico(char x[])
 {
     int i=0;
     while(x[i]!='\0') //recorre la cadena de caracteres hasta que encuentre el \0
        {
            if (x[i]<'0' || x[i]>'9')
                {
                    return 0;
                }
              i++;
        }
     return 1;
 }

 /** \brief Verifica si el valor recibido contiene solo letras
  * \param dato Array con la cadena a ser analizada
  * \return 1 si contiene solo ' ' y 0 si no lo es
  */
  int esSoloLetra(char dato[])
  {
      int i=0;
      while(dato[i] != '\0')
        {
            if ((dato[i]!=' ') && (dato[i]<'a' || dato[i]>'z') && (dato[i]<'A' || dato[i]>'Z'))
                {
                    return 0;
                }
             i++;
        }
        return 1;
  }

       /** VALIDA SI ES TODO LETRA
      * \brief Pide un texto solo letras al usuario y lo devuelve
      * \param sms Es el texto a ser mostrado
      * \param a Es el Arrat donde se cargara el texto pedido
      * \return 1 si el texto contiene solo letras
      */
      int getStringLetras(char sms[], char a[])
      {
          char aux[256];
          getStringMod(sms, aux);
          if(esSoloLetra(aux))
            {
                strcpy(a,aux);
                return 1;
            }
          return 0;
      }
 /** FC PEDIR TEXTO CON ESPACIO (NOMBRES Y APELLIDOS)
 * \brief Pide un texto al usuario y lo devuelve
 * \param sms Es el texto a ser mostrado
 * \param input Es el Array donde se cargara el texto pedido
 * \return void
 */
       void getStringMod (char sms[], char a[])
       {
         printf("%s", sms);
         fflush(stdin);
         scanf("%[^\n]", a);

       }


/******************************************************************************************************/

/******************************************************************************************************/


