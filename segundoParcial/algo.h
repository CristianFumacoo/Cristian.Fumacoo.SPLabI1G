#include "LinkedList.h"

typedef struct
{
    int id;
    char pais[21];
    int dosis1;
    int dosis2;
    int sinVacunar;
}ePais;

void mostrarVacuna(ePais*);
void mostrarVacunas(LinkedList*);

/** \brief Genera un numero random del 1 al 60
 *
 * \param void* recibe el objeto donde se hara
 * \return void
 *
 */
void numRandom(void*);

/** \brief Genera un numero random del 1 al 40
 *
 * \param void* recibe el objeto donde se hara
 * \return void
 *
 */
void numRandom2(void*);

int vacuna_setId(ePais*,int);
int vacuna_getId(ePais*,int*);

int vacuna_setPais(ePais*,char*);
int vacuna_getPais(ePais*,char*);

int vacuna_setDosis1(ePais*,int);
int vacuna_getDosis1(ePais*,int*);

int vacuna_setDosis2(ePais*,int);
int vacuna_getDosis2(ePais*,int*);

int vacuna_setSinVacunar(ePais*,int);
int vacuna_getSinVacunar(ePais*,int*);

/** \brief Calcula el porcentaje de las personas sin vacunar
 *
 * \param void* recibe una estructura
 * \return void
 *
 */
void calcularSinVacunar(void*);

/** \brief Calcula el objeto donde el porcentaje de la segunda dosis sea mayor a 30
 *
 * \param void* recibe una estructura
 * \return int
 *
 */
int dosis2Mayor30(void*);

/** \brief Calcula la cantidad de no vacunados sea mayor a la de vacunados.
 *
 * \param void* recibe una estructura
 * \return int
 *
 */
int paisEnElHorno(void*);

/** \brief Calcula los paises menos vacunados
 *
 * \param void* recibe una estructura
 * \return int
 *
 */
int menosVacunados(void*);

/** \brief Ordena de menor a mayor por porcentaje de primer dosis
 *
 * \param void* recibe una estructura
 * \param void* recibe una estructura
 * \return int retorna 1 si es mayor, -1 si es menor, 0 si es igual
 *
 */
int ordenarPorPrimerDosis(void*,void*);

/** \brief Compara los parametros para ordenar
 *
 * \param void* recibe una estructura
 * \param void* recibe una estructura
 * \return int Devuelve 1 si es mayor, -1 si es menor, 0 si es igual
 *
 */
int ordenarPorSinVacunar(void*,void*);

/** \brief Muestra los paises con mas personas sin vacunar
 *
 * \param LinkedList*
 * \return void
 *
 */
void mostrarMasCastigados(LinkedList*);


ePais* vacuna_new();
ePais* vacuna_newParametros(char*,char*,char*,char*,char*);
