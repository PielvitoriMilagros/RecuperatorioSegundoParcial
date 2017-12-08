#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir='s',opcion=0,palabra[20];

    ArrayList* listaOriginal=al_newArrayList();
    ArrayList* listaCompleta=al_newArrayList();

    while(seguir=='s')
    {
        system("cls");
        printf("\n1- ALTAS\n");
        printf("2- COMPLETAR\n");
        printf("3- COMPROBAR\n");
        printf("4- GENERAR Y LISTAR\n");
        printf("5- SALIR\n");

        opcion=getInt("Ingrese una opcion: ","Opcion incorrecta\n",1,5,1);

        switch(opcion)
        {
        case 1:
            altaLetras(listaOriginal,"datos.csv");
            break;
        case 2:
            completarDatos(listaOriginal,listaCompleta);
            break;
        case 3:
            getChar(palabra,"\nIngrese una palabra a validar (max 20 caracteres): ","Deben ser menos de 20 letras",20);
            comprobarExistencia(listaCompleta,palabra);
            system("pause");
            break;
        case 4:
            generar(listaCompleta);
            system("pause");
            break;
        default:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
