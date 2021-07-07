#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int retorno;

    printf("BIENVENIDO A MIS VACUNAS\n");
    printf("1.Cargar vacunas\n");
    printf("2.Mostrar vacunas\n");
    printf("3.Asignar estadisticas\n");
    printf("4.Filtrar paises exitosos\n");
    printf("5.Filtrar por países en el horno\n");
    printf("6.Ordenar por nivel de vacunación\n");
    printf("7.Mostrar mas Castigado\n");
    printf("8.Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&retorno);

    return retorno;
}
