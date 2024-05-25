#include <stdio.h>
#include <stdlib.h>
#include "./headers/tipuri_de_date.h"
#include "./headers/functii.h"
#include "./headers/liste.h"
#include "./headers/cozi.h"
#define NR_ECHIPE 32
int main (int args,char *argv[])
{  /*Graph *g=creeaza_graf();*/
    int nr_echipe=NR_ECHIPE;
    Echipa *lista_echipe=citeste_echipele(argv[1]);
    /*meciuri();
    afisare_graf();
    prestigiu();*/
    Queue *q=createQueue();
    enQueue(q,lista_echipe);
        enQueue(q,lista_echipe->next);
    printf("%s\n",q->front->nume);
    return 0;
}