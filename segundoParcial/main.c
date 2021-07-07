#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algo.h"
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"

int main()
{
    LinkedList* this = ll_newLinkedList();
    LinkedList* paisesDosis = ll_newLinkedList();
    LinkedList* paisesEnElHorno = ll_newLinkedList();
    LinkedList* paisesSinVacunar = ll_newLinkedList();
    char nombreArchivo[100];
    char respuesta = 's';
    srand(time(NULL));

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese nombre del archivo sin extension: ");
            fflush(stdin);
            scanf("%s",&nombreArchivo);

            if(controller_loadFromText(strcat(nombreArchivo,".csv"),this))
            {
                printf("Archivo cargado correctamente.\n");
            }
            else
            {
                printf("Error.\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(ll_len(this) != 0)
            {
                mostrarVacunas(this);
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(ll_len(this) != 0)
            {
                ll_map(this,numRandom);
                ll_map(this,numRandom2);
                ll_map(this,calcularSinVacunar);
                printf("Se hizo con exito.\n");
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(ll_len(this) != 0)
            {
                paisesDosis = ll_filter(this,dosis2Mayor30);
                controller_saveAsText("paisesExitosos.csv",paisesDosis);
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if(ll_len(this) != 0)
            {
                paisesEnElHorno = ll_filter(this,paisEnElHorno);
                controller_saveAsText("paisesEnElHorno.csv",paisesEnElHorno);
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if(ll_len(this) != 0)
            {
                ll_sort(this,ordenarPorPrimerDosis,1);
                mostrarVacunas(this);
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if(ll_len(this) != 0)
            {
                paisesSinVacunar = ll_clone(this);
                ll_sort(paisesSinVacunar,ordenarPorSinVacunar,0);
                mostrarMasCastigados(paisesSinVacunar);
            }
            else
            {
                printf("No tengo datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            printf("\nNos vemos!\n");
            respuesta = 'n';
            break;
        default:
            printf("Error...\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(respuesta == 's');


    return 0;
}







