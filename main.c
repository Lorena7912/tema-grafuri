#include <stdio.h>
#include <stdlib.h>
#include "./headers/tipuri_de_date.h"
#include "./headers/functii.h"
#include "./headers/liste.h"
#define NR_ECHIPE 32
int main (int args,char *argv[])
{  /*Graph *g=creeaza_graf();*/
    int nr_echipe=NR_ECHIPE;
    Echipa *lista_echipe=citeste_echipele(argv[1]);
    printf("Echipa de eliminat este:%s\n",lista_echipe->next->nume);
    
    return 0;
}