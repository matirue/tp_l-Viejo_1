#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado; /**< 0 para inactivo, 1 para activo */
    int dni;

}EPersona;

/**
 * \brief Busca el primer lugar no utilizado en el array.
 * \param pers el array se pasa como parametro.
 * \param cantidad Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 */
int obtenerEspacioLibre (EPersona [], int);


/**
 * \brief Busca la primer ocurrencia de un producto mediante su codigo
 * \param pers Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param dniAux Es el DNI que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */
int buscarPorDni(EPersona [], int, int);



int menu();
void inicializar(EPersona [], int );
char getChar(char []);
int getInt(char []);
int getStringNumeros(char [], char []);
void getString (char [], char []);
int esNumerico(char []);
int esSoloLetra(char []);
int getStringLetras(char [], char []);
void getStringMod (char [], char []);
void alta(EPersona [], int);
void mostrarPersonaPorDNI (EPersona );
void ListarPersonas (EPersona [], int);
void burbujeoOedenarNombre(EPersona [], int);
void Baja (EPersona [], int);
void GRAFICO (EPersona [], int);

#endif // FUNCIONES_H_INCLUDED
