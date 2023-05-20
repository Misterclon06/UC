#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200

typedef struct {

    char name[15];
    int notas[3];

} alumno;

alumno alumnos[MAX];
int i = 0;

int promedio(int nota[3]);
void leer();
void intercambiar(alumno *a, alumno *b);
void ordenar();
void escribir();

int main()
{
    leer();
    ordenar();
    escribir();

    system("pause");

    return 0;
}

void leer()
{

    FILE *reg;

    reg = fopen("notas_alumnos.txt", "r+");

while (!feof(reg))
{

    fscanf(reg, "%s %d %d %d", &alumnos[i].name, &alumnos[i].notas[0], &alumnos[i].notas[1], &alumnos[i].notas[2]);
    i++;
}
    fclose(reg);
}



int promedio(int nota[3])
{
    float prom;
    
    prom = (nota[0] + nota[1] + nota[2])/3;

    return (prom);
}

void intercambiar(alumno *a, alumno *b)
{
    alumno aux = *a;
    *a = *b;
    *b = aux;
}

void ordenar()
{
    for (int k = 0; k != i; k++)
    {
        for (int indice = 0; indice < i; indice++)
        {
            int indicesig = indice + 1;

            if (promedio(alumnos[indice].notas) < promedio(alumnos[indicesig].notas))
            {
                intercambiar(&alumnos[indice], &alumnos[indicesig]);
            }
        }
    }
}

void escribir()
{
    char line [MAX][3][15];
    
    for (int n = 0; n != i; n++)
    {
        itoa(n+1, line[n][0], 10);
        strcpy(line[n][1], alumnos[n].name);
        gcvt(promedio(alumnos[n].notas), 5, line[n][2]);
    }

    FILE *list = fopen("resultados.txt", "a");

    for (int k = 0; k != i; k++)
    {
        fprintf(list, "%s %s %s \n", line[k][0],  line[k][1],  line[k][2]);
    }
    fclose(list);
    
}
