#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
/***************************************************************************************/
int menu(char *items, int minimo, int maximo)
{
    char dato[10];
    int opc;
    printf("%s", items);
    printf("\n Elege una operacion: ");
    scanf("%s", dato);

    opc=validaOpcionesInt(dato, minimo, maximo);

    return opc;
}

/***************************************************************************************/
/**
 * \brief Validacion de numeros enteros en un rango.
 * \param dato Es el array a recorrer
 * \param minimo Es el valor minimo del rango.
 * \param maximo Es el valor maximo del rango.
 * \return Retorna el numero ingresado en entero
 */
int validaOpcionesInt(char *dato, int minimo, int maximo)
{
    int opciones, cant, i;
    int flag=0;

    cant = strlen(dato);

    for(i=0; i<cant; i++){
        if(isalpha(dato[i])){
            flag = 1;
            break;
        }
    }

    while(flag==1 || atoi(dato)>maximo || atoi(dato)<minimo)
        {
          printf("\n Reingrese (entre %d y %d): ", minimo, maximo);
          scanf("%s", dato);
          cant = strlen(dato);

          for(i=0; i<cant; i++)
            {
              if(isalpha(dato[i]))
              {
                flag = 1;
                break;
              }
              else
              {
                flag = 0;
              }
            }
       }

    opciones=atoi(dato);
    return opciones;
}
/***************************************************************************************/
/**
 * \brief Validacion de numeros decimales en un rango
 * \param dato Es el array a recorrer
 * \param minimo Es el valor minimo del rango
 * \param maximo Es el valor maximo del rango
 * \return Retorna el numero decimal convertido a float
 */
float validaPuntaje(char *dato, float minimo, float maximo)
{
    float auxFloat;
    int cant, i;
    int flag=0;

    cant = strlen(dato);

    for(i=0; i<cant; i++)
        {
          if(isalpha(dato[i]))
          {
            flag = 1;
            break;
          }
        }

    while(flag==1 || atof(dato)>maximo || atof(dato)<minimo)
        {
          printf("\n\n ERROR, solo caracteres numericos (entre %.2f y %.2f): ", minimo, maximo);
          scanf("%s", dato);
          cant = strlen(dato);

          for(i=0;i<cant; i++)
            {
              if(isalpha(dato[i]))
              {
                flag = 1;
                break;
              }
              else
              {
                flag = 0;
              }
            }
        }
    auxFloat = atof(dato);

    return auxFloat;
}
/***************************************************************************************/
/**
 *\brief Validaicon de numeros decimales.
 * \param dato Es el dato a validar
 * \return Retorna el numero decimal como float.
 */
float validaFloat(char *dato)
{
    float auxFloat;
    int cant, i, flag=0;

    cant = strlen(dato);

    for(i=0; i<cant; i++)
        {
          if(isalpha(dato[i]))
          {
            flag = 1;
            break;
          }
        }

    while(flag==1)
        {
          printf("\n Solo caracteres numericos: ");
          scanf("%s", dato);
          cant = strlen(dato);

         for(i=0; i<cant; i++)
            {
             if(isalpha(dato[i]))
             {
                flag = 1;
                break;
             }
             else
             {
                flag = 0;
             }
            }
        }
    auxFloat = atof(dato);

    return auxFloat;
}
/***************************************************************************************/
/**
 * \brief Valida cadena de letras
 * \param auxDato Es el array a validar
 * \param cantCaracteres Es la cantidad de caracteres permitidos
 * \return -
 */
void validaCadenaDeLetras(char *auxDato, int cantCaracteres){

    int i, cant;
    int flag=0;

    while(flag==0)
        {
            cant=strlen(auxDato);
            for(i=0; i<cant; i++)
                {
                    if(!isdigit(auxDato[i]))
                    {
                      flag=1;
                    }
                    else
                    {
                      flag=0;
                      break;
                    }
                }

            if(flag==0 || cant>cantCaracteres)
                {
                    flag=0;
                    printf("\n Ingrese caracteres alfabetico (maximo:%d ): ", cantCaracteres);
                    fflush(stdin);
                    scanf("%[^\n]", auxDato);
                }
       }
}
/***************************************************************************************/
/**
 * \brief Valida array alfanumerico
 * \param auxDato Es el array a validar
 * \param cantCaracteres Es la cantidad caracteres permitidos.
 * \return -.
 */
void validaAlfaNumerico(char *auxDato, int cantCaracteres)
{
    int cant;

    cant = strlen(auxDato);

    while(cant>cantCaracteres)
        {
           printf("\n Ingrese caracteres alfanumericos (maximo:%d ): ", cantCaracteres);
           fflush(stdin);
           scanf("%[^\n]", auxDato);

           cant=strlen(auxDato);
        }
}
/***************************************************************************************/


/***************************************************************************************/
void agregarPelicula(EMovie pelicula, int cantCaracteres, FILE *bin)
{
    char auxdato[cantCaracteres*10];

    printf("\n Ingresar codigo de pelicula: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.codigo = validaOpcionesInt(auxdato, 1, 9999);

    printf("\n Ingesar titulo de la pelicula: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaAlfaNumerico(auxdato, cantCaracteres);
    strcpy(pelicula.titulo, auxdato);

    printf("\n Ingresar genero de la pelicula: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaCadenaDeLetras(auxdato, cantCaracteres);
    strcpy(pelicula.genero, auxdato);

    printf("\n Ingresar duracion de la pelicula (en minutos): ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.duracion = validaOpcionesInt(auxdato, 1, 200);

    printf("\n Ingesar una breve descripcion de la pelicula: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaCadenaDeLetras(auxdato, cantCaracteres*3);
    strcpy(pelicula.descripcion, auxdato);

    printf("\n Asigne un puntaje a la pelicula (1: bajo - 10: alto): ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.puntaje = validaPuntaje(auxdato, 1, 10);

    printf("\n Ingesar link de imagen: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaAlfaNumerico(auxdato, cantCaracteres*10);
    strcpy(pelicula.linkImagen, auxdato);

    fflush(stdin);
    fseek(bin, 0L, SEEK_END);
    fwrite(&pelicula, sizeof(pelicula), 1, bin);
}
/***************************************************************************************/
/**
 * \brief muestra en pantalla las peliculas cargadas en un archivo binario
 * \param pelicula Es la estructura a recorrer
 * \param bin Es el puntero del archivo
 * \return -
 */
void imprimePeliculas(EMovie pelicula, FILE *bin)
{
    int cant;
    rewind(bin);

    while(!feof(bin))
        {
            cant = fread(&pelicula,sizeof(pelicula), 1, bin);

            if(cant!=1)
                {
                    if(feof(bin))
                     break;
                }
            else
            {
                printf("No leyo el ultimo registro\n");
                break;
            }
        }

        if(pelicula.codigo != 0)
            printf("\nCodigo: %04d\t% 25s.\tDuracion: %d min.\tGenero: %s.\tPuntaje: %.2f.\nDescripcion: %s.\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.puntaje, pelicula.descripcion, pelicula.linkImagen);

}
/***************************************************************************************/

void borrarPelicula(EMovie pelicula, FILE *bin)
{
    char auxdato[10], seguir;
    int auxCodigo, cant, flag=0;

    imprimePeliculas(pelicula, bin);

    printf("\n Ingresar codigo de pelicula a eliminar: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    auxCodigo = validaOpcionesInt(auxdato, 1, 9999);
    system("cls");

    rewind(bin);

    while(!feof(bin))
        {
            cant = fread(&pelicula,sizeof(pelicula), 1, bin);

            if(pelicula.codigo == auxCodigo)
                {
                    flag=1,
                    printf("\n Codigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);
                    printf("\n\n  Confirma baja? (presionar 's' para confirmar):  ");
                    seguir = tolower(getche());
                    printf("\n\n");

                    if(seguir == 's')
                    {
                       pelicula.codigo = 0;
                       fflush(stdin);
                       fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                       fwrite(&pelicula.codigo, sizeof(pelicula), 1, bin);
                       printf("\n\n Baja exitosa. \n\n");
                    }
                    else
                    {
                        printf("\n\n Baja cancelada.  \n\n");
                    }
                    break;

                 }

        }

        if(flag == 0)
            {
                printf("\n\n La pelicula ingresada no existe en el sistema.   \n\n");
            }
}
/***************************************************************************************/

void modificaPelicula(EMovie pelicula, int cantCaracteres, FILE *bin)
{
    char auxdato[cantCaracteres*10], seguir='s';
    int auxCodigo, cant, flag=0, opcion;

    imprimePeliculas(pelicula, bin);

    printf("\n Ingresar codigo de pelicula a modificar: ");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    auxCodigo = validaOpcionesInt(auxdato, 1, 9999);
    system("cls");

    rewind(bin);

    while(!feof(bin))
        {
            cant = fread(&pelicula,sizeof(pelicula), 1, bin);

            if(pelicula.codigo == auxCodigo)
                {
                    printf("Pelicula encontrada: \n");
                    flag=1,
                    printf("\n Codigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);

                 while(seguir=='s')
                 {
                     opcion = menu("\t\t\tModificacion de pelicula elegida\n\n1- Titulo\n2- Genero\n3- Duracion\n4- Descripcion\n5- Puntaje\n6- Link de imagen\n7- Salir\n", 1, 7);
                     system("cls");

                     switch(opcion)
                     {
                      case 1:
                         printf("\n Ingesar titulo de la pelicula: ");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         validaAlfaNumerico(auxdato, cantCaracteres);
                         strcpy(pelicula.titulo, auxdato);
                         break;

                     case 2:
                         printf("\n Ingresar genero: ");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         validaCadenaDeLetras(auxdato, cantCaracteres);
                         strcpy(pelicula.genero, auxdato);
                         break;

                     case 3:
                         printf("\n Ingresar duracion en minutos: ");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         pelicula.duracion = validaOpcionesInt(auxdato, 1, 200);
                         break;

                     case 4:
                         printf("\n Ingesar breve descripcion de la pelicula: ");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         validaCadenaDeLetras(auxdato, cantCaracteres*3);
                         strcpy(pelicula.descripcion, auxdato);
                         break;

                     case 5:
                         printf("\n Ingresar puntaje: ");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         pelicula.puntaje = validaPuntaje(auxdato, 1, 10);
                         break;

                     case 6:
                         printf("\n Ingesar link de imagen: \n");
                         fflush(stdin);
                         scanf("%[^\n]", auxdato);
                         validaAlfaNumerico(auxdato, cantCaracteres*10);
                         strcpy(pelicula.linkImagen, auxdato);
                         break;

                     case 7:
                         fflush(stdin);
                         fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                         fwrite(&pelicula, sizeof(pelicula), 1, bin);
                         seguir = 'n';
                         break;

                }

            }
            break;
        }
    }

    if(flag == 0)
        {
            printf("no se encontro la pelicula.\n\n");
        }
}
/***************************************************************************************/
/**
 * \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 * \param pelicula Es la estructura a recorrer
 * \param nombreDeArchivo Es el array de caracteres que da nombre al archivo html
 * \param bin Es el untero del archivo
 * \return -
 */
void generarPagina(EMovie pelicula, char *nombreDeArchivo, FILE *bin)
{

    int cant;
    FILE *html;

    html=fopen(nombreDeArchivo, "w");

    if(html == NULL)
    {
        printf("\n\n No se pudo abrir el archivon  \n\n");
    }
    else
    {
        fprintf(html, "<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n\n\n\n");

        rewind(bin);

        while(!feof(bin))
            {
                cant = fread(&pelicula,sizeof(pelicula), 1, bin);
            if(cant!=1)
            {
                if(feof(bin))
                    break;

                else
                {
                    printf("\n\n  No leyo el ultimo registro \n\n");
                    break;
                }
            }
            if(pelicula.codigo != 0)
                fprintf(html, "            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n				<ul>\n                    <li>Codigo: %04d</li>\n					<li>Genero: %s</li>\n					<li>Puntaje: %.2f</li>\n					<li>Duracion:%d minutos</li>\n				</ul>\n                <p>%s.</p>\n            </article>\n\n\n\n", pelicula.linkImagen, pelicula.titulo, pelicula.codigo, pelicula.genero, pelicula.puntaje, pelicula.duracion, pelicula.descripcion);
           }

            fprintf(html, "\n\n\n        </div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>");
    }

    fclose(html);

    printf("\n\n         Listado creado con exito     \n\n");


}
/***************************************************************************************/


#endif

