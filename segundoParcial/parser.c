#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "algo.h"

int parser_VacunaFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char auxId[51];
    char auxPais[51];
    char auxVac1dosis[51];
    char auxVac2dosis[51];
    char auxSinVacunar[51];
    int retorno = 0;
    int flagOnce = 1;
    ePais* pVacuna;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",auxId,auxPais,auxVac1dosis,auxVac2dosis,auxSinVacunar);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",auxId,auxPais,auxVac1dosis,auxVac2dosis,auxSinVacunar);

            pVacuna = vacuna_newParametros(auxId,auxPais,auxVac1dosis,auxVac2dosis,auxSinVacunar);

            if(pVacuna != NULL)
            {
                retorno = 1;
                ll_add(pArrayListEmployee,pVacuna);
            }
        }
    }

    return retorno;
}
