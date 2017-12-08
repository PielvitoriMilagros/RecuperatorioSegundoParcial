#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/** \brief lee el archivo y carga el arraylist
 * \param this ArrayList* lista de letras
 * \param string nombre del archivo de donde se extraera la informacion
 */
void  altaLetras(ArrayList* lista, char* nombreArchivo)
{
    int flag=0;
    Eletra* letra;
    char auxLetra[2],auxVocal[2],auxCons[2],auxLinea[1000];
    FILE* pFile=fopen(nombreArchivo,"r");
    rewind(pFile);
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flag==0)
            {
                fscanf(pFile,"%[^\n]\n",auxLinea);
            }
            letra=(Eletra*)malloc(sizeof(Eletra));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxLetra,letra->nombre,auxVocal,auxCons);
            letra->letra=auxLetra[0];
            letra->vocal=atoi(auxVocal);
            letra->consonante=atoi(auxCons);
            lista->add(lista,(void*)letra);
            flag=1;
        }
        printf("Lista cargada.");
        fclose(pFile);
    }
    else
        printf("No se pudo cargar lista.");
    getch();

}

/** \brief carga el arraylist
 * \param lista ArrayList* lista de letras
 * \param lista ArrayList* lista de letras auxiliar
 */
void completarDatos(ArrayList* lista,ArrayList* listaAux)
{
    printf("Cantidad de letras en la lista: %d\n",lista->len(lista));
    Eletra* letra;
    int i;
    for(i=0; i<lista->len(lista); i++)
    {
        letra=lista->get(lista,i);
        if(letra->letra=='a' || letra->letra=='e' || letra->letra=='i' || letra->letra=='o' || letra->letra=='u')
        {
            letra->vocal=1;
            letra->consonante=0;
        }
        else
        {
            letra->vocal=0;
            letra->consonante=1;
        }
        listaAux->add(listaAux,(void*)letra);
    }
    printf("Carga completa\n");
    system("PAUSE");

}


/** \brief comprueba elementos del arraylist
 * \param lista ArrayList* lista de letras
 * \param palabra input realizado por el usuario
 */
void  comprobarExistencia(ArrayList* lista, char palabra[])
{
    int i,j,largo=strlen(palabra),flag;
    Eletra* letra;
    ArrayList* repLista=al_clone(lista);

    for(i=0; i<largo; i++)
    {
        flag=0;
        for(j=0; j<repLista->len(repLista); j++)
        {
            letra=repLista->get(repLista,j);
            if(letra->letra==palabra[i])
            {
                flag=1;
                repLista->remove(repLista,j);
                break;
            }
        }
        if(flag==0)
        {
            printf("La letra %c no existe la cantidad de veces necesaria en la lista\n",palabra[i]);
            break;
        }
    }
    if(flag==1)
    {
        printf("Todas las letras existen para la palabra ingresada\n");
    }
}



/**
 * Despliega menu de opcion para ordenamiento
 * \param this ArrayList* lista de letras
 */
void generar(ArrayList* lista)
{
    char opcion;
    if(!lista->isEmpty(lista))
    {
        printf ("a-Ordenado de manera descendente, letras repetidas con todas sus ocurrencias\n"
                "b-Ordenado de manera ascendente, letras sin que haya repetidas\n"
                "\nElija una opcion: ");
        opcion=getch();
        switch(opcion)
        {
        case 'a':
            generarLista(lista,'a');
            break;

        case 'b':
            generarLista(lista,'b');
            break;
        default:
            printf("Opcion incorrecta");
            break;
        }
    }
    else
        printf("\nLa lista no esta cargada");
}

/**
 * Crea nuevo array para el ordenamiento
 * \param this ArrayList* lista de letras
 * \param opcion tipo de ordenamiento segun menu
 */
void generarLista(ArrayList* lista, char opcion)
{
    int contador=0, i, j;

    ArrayList* lista2=al_newArrayList();
    ArrayList* lista3=al_newArrayList();
    Eletra* repetidas = (Eletra*) malloc (sizeof(Eletra));
    Eletra* letra= (Eletra*) malloc (sizeof(Eletra));

    for(i=0; i<lista->len(lista); i++)
    {
        letra=lista->get(lista,i);
        for (j=0; j<lista->len(lista); j++)
        {
            repetidas = lista->get(lista,j);
            if(letra->letra== repetidas->letra)
                contador++;
        }
        printf("%d   ",contador);
        if(contador==1)
            lista3->add(lista3,(void*)letra);
        else if(contador>1)
            lista2->add(lista2,(void*)letra);

        contador=0;
    }
    if(opcion=='b')
    {
        lista3->sort(lista3,ordenarPorLetra,0);
        printf("\nLetra\tNombre\tVocal\tConsonante\n");
        for(i=0; i<lista3->len(lista3); i++)
        {
            letra=lista3->get(lista3,i);
            printf("%c\t%s\t%c\t%c\n",letra->letra,letra->nombre,letra->vocal,letra->consonante);
        }
    }
    else
    {
        lista2->sort(lista2,ordenarPorLetra,1);
        printf("\nLetra\tNombre\tVocal\tConsonante\n");
        for(i=0; i<lista2->len(lista2); i++)
        {
            repetidas=lista2->get(lista2,i);
            printf("%c\t%s\t%c\t%c\n",repetidas->letra,repetidas->nombre,repetidas->vocal,repetidas->consonante);
        }
    }
}

int ordenarPorLetra(void* a,void* b)
{
    int retorno=-1;
    Eletra* letra1= (Eletra*) malloc (sizeof(Eletra));
    Eletra* letra2= (Eletra*) malloc (sizeof(Eletra));
    if(letra1->letra>letra2->letra)
        retorno=1;
    return retorno;
}


/**
 * Valida que el ingreso sea un número
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es número, !1 si no lo es
 */
int validaNumero(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
    {
        if(!(isdigit(dato[i])))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}

/**
 * Solicita el ingreso y valida que sea int
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param min Numero minimo que se puede ingresar
 * @param max Numero maximo que se puede ingresar
 * @param largo Largo maximo que puede tener el ingreso
 * @return el numero ingresado
 */
int getInt(char mensaje[],char error[],int min,int max,int largo)
{

    int flag,valido,num;
    char auxNum[largo];
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        scanf("%s",auxNum);
        valido=validaNumero(auxNum,largo);
        if(valido!=0)
        {
            num=atoi(auxNum);
            if(num>=min && num<=max)
            {
                return num;
            }
            else
            {
                printf(error);
                flag++;
            }
        }
        else
        {
            printf(error);
            flag++;
        }
    }
    while(flag!=0);
}

/**
 * Solicita el ingreso y valida que sea char
 * @param input el dato a validar
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param largo Largo maximo que puede tener el ingreso
 */
void getChar(char input[],char mensaje[],char error[],int largo)
{
    int flag,valido;
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        gets(input);
        valido=validaLetra(input,largo);
        if(valido==0)
        {
            printf(error);
            flag++;
        }
    }
    while(flag!=0);
}



/**
 * Valida que el ingreso sea una letra
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es letra, !1 si no lo es
 */
int validaLetra(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
    {
        if((isdigit(dato[i])) && ((dato[i]<'a' || dato[i]>'z')) && (dato[i]!=" "))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}

