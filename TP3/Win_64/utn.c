#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

/** \brief Lista el menu de opciones y pide la respuesta a ingresar mediante un menu y la retorna
 *
 * \return int respuesta
 * \return char* mensaje
 * \return char* mensajeError
 */
int utn_opcionesMenu(int respuesta, char* mensaje, char* mensajeError)
{
    system("cls");
    printf("\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n 3. Alta de empleado");
    printf("\n 4. Modificar datos de empleado");
    printf("\n 5. Baja de empleado");
    printf("\n 6. Listar empleados");
    printf("\n 7. Ordenar empleados");
    printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n 10. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &respuesta);

    while(respuesta > 10 || opcrespuestaion < 1)
    {
        printf(mensajeError);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &respuesta);
    }
    return respuesta;
}

