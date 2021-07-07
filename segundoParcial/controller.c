#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algo.h"
#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno= 0;

    pArchivo=fopen(path,"r");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_VacunaFromText(pArchivo,pArrayListEmployee);
    }
    fclose(pArchivo);

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    ePais* v;
    int id;
    int dosis1;
    int dosis2;
    int sinVacunar;

    char auxId[101];
    char auxPais[101];
    char auxDosis1[101];
    char auxDosis2[101];
    char auxSinVacunar[101];

    FILE* pFile=fopen(path,"w");

    if(pFile!=NULL && pArrayList !=NULL)
    {
        fprintf(pFile,"id,pais,dosis1,dosis2,sinVacunar\n");
        for(int i= 0; i < ll_len(pArrayList); i++)
        {
            v=ll_get(pArrayList,i);

            vacuna_getId(v,&id);
            vacuna_getPais(v,&auxPais);
            vacuna_getDosis1(v,&dosis1);
            vacuna_getDosis2(v,&dosis2);
            vacuna_getSinVacunar(v,&sinVacunar);

            sprintf(auxId, "%d", id);
            sprintf(auxDosis1,"%d",dosis1);
            sprintf(auxDosis2,"%d",dosis2);
            sprintf(auxSinVacunar,"%d",sinVacunar);
            fprintf(pFile,"%s,%s,%s,%s,%s\n",auxId,auxPais,auxDosis1,auxDosis2,auxSinVacunar);
            printf("%s,%s,%s,%s,%s\n",auxId,auxPais,auxDosis1,auxDosis2,auxSinVacunar);
        }
        fclose(pFile);
        retorno = 1;
    }

    return retorno;
}
