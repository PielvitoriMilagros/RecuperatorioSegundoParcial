
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"


typedef struct
{
    char letra;
    char nombre[22];
    int vocal;
    int consonante;

} Eletra;


/** \brief lee el archivo y carga el arraylist
 * \param this ArrayList* lista de letras
 * \param string nombre del archivo de donde se extraera la informacion
 */
void  altaLetras(ArrayList* lista, char* nombreArchivo);

/** \brief carga el arraylist
 * \param lista ArrayList* lista de letras
 * \param lista ArrayList* lista de letras auxiliar
 */
void  completarDatos(ArrayList* lista,ArrayList* listaAux);

/** \brief comprueba elementos del arraylist
 * \param lista ArrayList* lista de letras
 * \param palabra input realizado por el usuario
 */
void  comprobarExistencia(ArrayList* lista, char palabra[]);

void generar(ArrayList* lista);

int ordenarPorLetra(void* a,void* b);

/**
 * Crea nuevo array para el ordenamiento
 * \param this ArrayList* lista de letras
 * \param opcion tipo de ordenamiento segun menu
 */
void generarLista(ArrayList* lista, char);
/*

void ordenarLista(ArrayList* lista);
void eliminarRepetidos(ArrayList* lista);
//void encontrarBorrarRepetido(ArrayList* lista, numeroNatural* numero);
void completarNumero(ArrayList* lista,ArrayList* listaAux);
void informarCantidad(ArrayList* lista);
*/
/**
 * Valida que el ingreso sea un número
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es número, !1 si no lo es
 */
int validaNumero(char dato[],int largo);

/**
 * Valida que el ingreso sea una letra
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es letra, !1 si no lo es
 */
int validaLetra(char dato[],int largo);
/**
 * Solicita el ingreso y valida que sea int
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param min Numero minimo que se puede ingresar
 * @param max Numero maximo que se puede ingresar
 * @param largo Largo maximo que puede tener el ingreso
 * @return el numero ingresado
 */
int getInt(char mensaje[],char error[],int min,int max,int largo);

/**
 * Solicita el ingreso y valida que sea char
 * @param input el dato a validar
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param largo Largo maximo que puede tener el ingreso
 */
void getChar(char input[],char mensaje[],char error[],int largo);




#endif // FUNCIONES_H_INCLUDED

