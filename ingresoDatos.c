#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresoDatos.h"
#include "validacionDatos.h"


/** \brief pide un numero al usuario, valida que est� dentro del rango de un int, que no haya caracteres
 *         que no sean numericos y que el numero entre dentro de un rango establecido por el usuario
 *
 * \param mensaje[] char mensaje que ser� mostrado al usuario
 * \param max int Numero maximo que puede aceptar la funcion
 * \param min int Numero minimo que acepta la funcion
 * \return int n�mero ingresado por el usuario
 *
 */
int ingresaEntero(char mensaje[], int max, int min)
{
    int numero;
    char buffer[6];

    int banderaLargo;
    int banderaSoloNumeros;
    int banderaRango;

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer);

    do
    {
        banderaSoloNumeros = 0;
        banderaLargo = 0;
        banderaRango = 0;

        if(validaSoloNumeros(buffer) == 0)
        {
            banderaSoloNumeros = 1;
            puts("Error. Ingreso caracteres invalidos.");
        }

        if(banderaSoloNumeros == 0 && validaLargoCadena(buffer, 6) == 0)
        {
            banderaLargo = 1;
            puts("Error. Demasiados digitos.");
        }

        numero = atoi(buffer);
        if(banderaSoloNumeros == 0 && banderaLargo == 0 && validaRangoEntero(numero, max, min) == 0)
        {
            banderaRango = 1;
            puts("Error. Numero fuera de rango.");
        }

        if(banderaSoloNumeros == 1 || banderaLargo == 1 || banderaRango == 1)
        {
            puts("Ingrese el numero nuevamente: ");
            fflush(stdin);
            gets(buffer);
        }
    }
    while(banderaSoloNumeros == 1 || banderaLargo == 1 || banderaRango == 1);

    return numero;
}


/** \brief pide un numero al usuario y lo retorna
 *
 * \param mensaje[] char mensaje que ser� mostrado al usuario
 * \return float n�mero ingresado por el usuario
 *
 */
float ingresaFlotante(char mensaje[])
{
    float numero;
    char buffer[15];

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaSoloNumeros(buffer) == 0)
    {
        puts("Ingreso caracteres invalidos. Reingrese el numero: ");
        fflush(stdin);
        gets(buffer);
    }

    numero = atof(buffer);

    return numero;
}


/** \brief pide un carcater al usuario y lo retorna
 *
 * \param mensaje[] char mensaje que ser� mostrado al usuario
 * \return char caracter ingresado por el usuario
 *
 */
char ingresaCaracter(char mensaje[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}


/** \brief
 *
 * \return char
 *
 */
char pideYValidaSiNo()
{
    char letra;
    fflush(stdin);
    letra = getchar();

    while(letra != 's' && letra != 'n')
    {
        puts("Ingrese una opcion correcta: s/n");
        fflush(stdin);
        letra = getchar();
    }
    return letra;
}
