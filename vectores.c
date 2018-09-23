#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectores.h"
#include "validacionDatos.h"


/** \brief solicita una cadena al usuario, valida que no desborde el espacio en memoria y guarda la cadena en un vector
 *
 * \param cadena[] char direcci�n de memoria del vector en que se guarda la cadena
 * \param mensaje[] char mensaje a ser mostrado al usuario
 * \param int dimension del vector que recibe la cadena
 * \return void
 *
 */
void ingresaCadena(char cadena[], char mensaje[], int dimension)
{
    puts(mensaje);
    char buffer[1024];
    fflush(stdin);

    gets(buffer);
    while(strlen(buffer) >= dimension)
    {
        printf("Error. %s", mensaje);
        fflush(stdin);
        gets(buffer);
    }
    strcpy(cadena, buffer);
}



/** \brief pide secuencialmente el ingreso de numeros hasta completar el vector
 *
 * \param int[] vector a ser rellenado
 * \param char[] mensaje que se mostrara al usuario
 * \param int tamano del vector
 * \return void
 *
 */
void cargaSecuencialVectorEnteros(int vector[], char mensaje[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf(mensaje);
        scanf("%d", &vector[i]);
    }
}


/** \brief permite cargar valores en un vector en una posicion a eleccion, mientras el usuario lo desee
 *
 * \param int[] vector a completar
 * \param char[] mensaje de pedido de valor
 * \param int tamano del vector
 * \param int valor ilogico en relacion a la informacion que llenara el vector
 * \return void
 *
 */
void cargaAleatoriaVectorEnteros(int vector[], char mensaje[], int tam, int valorIlogico)
{
    int i;
    for(i =0; i < tam; i++)
    {
        vector[i] = valorIlogico;
    }

    int posicion;
    char reemplazo;
    char seguir;

    do
    {
        printf("Eliga una posicion entre 0 y %d: ", tam-1);
        scanf("%d", &posicion);
        posicion = validaMaximoMinimoEnteros(posicion, tam-1, 0, "La posicion no existe. Elija otra: ");

        if(vector[posicion] != valorIlogico)
        {
            printf("Ya se ha guardado un valor en esta posicion. Desea reemplazarlo? s/n");
            fflush(stdin);
            scanf("%c", &reemplazo);
            reemplazo = validaSiNo(reemplazo);

            if(reemplazo == 's')
            {
                puts(mensaje);
                scanf("%d", &vector[posicion]);
            }
        }
        else
        {
            puts(mensaje);
            scanf("%d", &vector[posicion]);
        }

        puts("Desea ingresar otro valor? s/n");
        fflush(stdin);
        scanf("%c", &seguir);
        validaSiNo(seguir);

    }
    while(seguir == 's');
}



/** \brief permite ingresar secuencialmente cadenas de caracteres
 *
 * \param char[][21] vector en que se alojaran las cadenas
 * \param int cantidad de filas del vector
 * \return void
 *
 */
void ingresaVectorDeCadenas(char listadoCadenas[][50], char mensaje[], int filas)
{
    char buffer[1024];

    int i;
    for(i = 0; i < filas; i++)
    {
        puts(mensaje);
        gets(buffer);

        while(strlen(buffer) > 49)
        {
            puts("Error: la cadena desborda el espacio disponible. ");
            puts(mensaje);
            gets(buffer);
        }
        strcpy(listadoCadenas[i], buffer);
    }
}
