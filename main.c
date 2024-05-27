#include <stdio.h>
#include <stdlib.h>
#include "./headers/tipuri_de_date.h"
#include "./headers/functii.h"
#include "./headers/liste.h"
#include "./headers/cozi.h"
#define NR_ECHIPE 32
int main(int args, char *argv[])
{
    int nr_echipe = NR_ECHIPE;
    Echipa *lista_echipe = citeste_echipele(argv[1]);
    Queue *q = createQueue();
    Graph *g = createGraph();
    Queue *castigatori = createQueue();
    Queue *invinsi = createQueue();
    meciuri(lista_echipe, g,castigatori,invinsi);
    afisare_graf(argv[2], g); // ./clasament Input GrafOut ScorOut
    clasament(argv[3], g, invinsi, castigatori);
    return 0;
}