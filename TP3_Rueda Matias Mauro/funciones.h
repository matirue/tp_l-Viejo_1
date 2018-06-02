#define CANTCARACTERES 25


typedef struct{
    int codigo;
    char titulo[CANTCARACTERES];
    char genero[CANTCARACTERES];
    int duracion;
    char descripcion[CANTCARACTERES*3];
    float puntaje;
    char linkImagen[CANTCARACTERES*10];
}EMovie;


int menu(char* , int, int);
int validaOpcionesInt(char* , int, int);

float validaFloat(char* );
float validaPuntaje(char* , float, float);
void validaCadenaDeLetras(char*, int);
void validaAlfaNumerico(char*, int);

void agregarPelicula(EMovie pelicula, int , FILE*);
void borrarPelicula(EMovie pelicula, FILE*);
void modificaPelicula(EMovie pelicula, int, FILE*);
void imprimePeliculas(EMovie pelicula, FILE*);















void generarPagina(EMovie pelicula, char *nombreDeArchivo, FILE *bin);

