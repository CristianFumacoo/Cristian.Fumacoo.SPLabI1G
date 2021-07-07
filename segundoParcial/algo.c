#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"
#include "LinkedList.h"


int vacuna_setId(ePais* this,int id)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->id = id;
            retorno = 1;
        }
    return retorno;
}

int vacuna_setPais(ePais* this,char* pais)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(this->pais,pais);
            retorno = 1;
        }
    return retorno;
}

int vacuna_setDosis1(ePais* this,int dosis)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->dosis1 = dosis;
            retorno = 1;
        }
    return retorno;
}

int vacuna_setDosis2(ePais* this,int dosis)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->dosis2 = dosis;
            retorno = 1;
        }
    return retorno;
}

int vacuna_setSinVacunar(ePais* this,int sinVacunar)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->sinVacunar = sinVacunar;
            retorno = 1;
        }
    return retorno;
}
/*****          FIN DE LOS SETTERS                  ****/

int vacuna_getId(ePais* this,int* id)
{
    int retorno = 0;

        if(this != NULL)
        {
            *id = this->id;
            retorno = 1;
        }
    return retorno;
}

int vacuna_getPais(ePais* this,char* pais)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(pais,this->pais);
            retorno = 1;
        }
    return retorno;
}

int vacuna_getDosis1(ePais* this,int* dosis)
{
    int retorno = 0;

        if(this != NULL)
        {
            *dosis = this->dosis1;
            retorno = 1;
        }
    return retorno;
}

int vacuna_getDosis2(ePais* this,int* dosis)
{
    int retorno = 0;

        if(this != NULL)
        {
            *dosis = this->dosis2;
            retorno = 1;
        }
    return retorno;
}

int vacuna_getSinVacunar(ePais* this,int* sinVacunar)
{
    int retorno = 0;

        if(this != NULL)
        {
            *sinVacunar = this->sinVacunar;
            retorno = 1;
        }
    return retorno;
}

ePais* vacuna_new()
{
    ePais* this;

    this = malloc(sizeof(ePais));

    return this;
}


ePais* vacuna_newParametros(char* idStr,char* paisStr,char* dosis1,char* dosis2,char* sinVacunar)
{
    ePais* this;
    this = vacuna_new();

    if(vacuna_setId(this,atoi(idStr))&&
       vacuna_setPais(this,paisStr)&&
       vacuna_setDosis1(this,atoi(dosis1))&&
       vacuna_setDosis2(this,atoi(dosis2))&&
       vacuna_setSinVacunar(this,atoi(sinVacunar)))
    {
         return this;
    }

    return NULL;
}

void numRandom(void* num)
{
    int max = 60;
    int min = 1;
    ePais* v;
    v = (ePais*) num;

    v->dosis1 = rand() % (max - min + 1) + min;
}

void numRandom2(void* num)
{
    int max = 40;
    int min = 1;
    ePais* v;
    v = (ePais*) num;

    v->dosis2 = rand() % (max - min + 1) + min;
}

void calcularSinVacunar(void* this)
{
    ePais* v;
    v = (ePais*) this;

    v->sinVacunar = 100 - (v->dosis1 + v->dosis2);
}

int dosis2Mayor30(void* this)
{
    int retorno = 0;
    ePais* v;
    v = (ePais*) this;

    if(v->dosis2 >= 30)
    {
        retorno = 1;
    }

    return retorno;
}

int paisEnElHorno(void* this)
{
    int retorno = 0;
    ePais* v;
    v = (ePais*) this;
    int suma = v->dosis1 + v->dosis2;

    if(v->sinVacunar > suma)
    {
        retorno = 1;
    }

    return retorno;
}

void mostrarMasCastigados(LinkedList* this)
{
    ePais* auxV = ll_get(this,0);
    ePais* aux;

    mostrarVacuna(auxV);
    for(int i = 1;i < ll_len(this);i++)
    {
        aux = ll_get(this,i);
        if(auxV->sinVacunar == aux->sinVacunar)
        {
            mostrarVacuna(aux);
        }
        else
        {
            break;
        }
    }
}

int ordenarPorPrimerDosis(void* this,void* this2)
{
    int retorno = 0;
    ePais* v;
    ePais* v2;
    v = (ePais*) this;
    v2 = (ePais*) this2;

    if(v->dosis1 > v2->dosis1)
    {
        //printf("Fue mayor\n");
        retorno = 1;
    }
    else if(v->dosis1 < v2->dosis1)
    {
        //printf("Fue menor\n");
        retorno = -1;
    }
    return retorno;
}

int ordenarPorSinVacunar(void* this,void* this2)
{
    int retorno = 0;
    ePais* v;
    ePais* v2;
    v = (ePais*) this;
    v2 = (ePais*) this2;

    if(v->sinVacunar > v2->sinVacunar)
    {
        //printf("Fue mayor\n");
        retorno = 1;
    }
    else if(v->sinVacunar < v2->sinVacunar)
    {
        //printf("Fue menor\n");
        retorno = -1;
    }
    return retorno;
}

void mostrarVacuna(ePais* v)
{
    if(v != NULL)
    {
        printf("\n%d %10s %10d %10d %10d\n",v->id,v->pais,v->dosis1,v->dosis2,v->sinVacunar);
    }
}
void mostrarVacunas(LinkedList* list)
{
    int tam;
    ePais* aux = NULL;
    if(list != NULL)
    {
        tam = (ePais*) ll_len(list);
        printf("%s%10s%12s%11s%10s\n","ID","PAIS","DOSIS 1","DOSIS 2","SIN VACUNAR");
        for(int i = 0;i<tam;i++)
        {
            aux = ll_get(list,i);
            if(aux != NULL)
            {
                mostrarVacuna(aux);
            }
        }
        printf("............................\n\n");
    }
}


