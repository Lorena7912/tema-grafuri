#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../headers/tipuri_de_date.h"
#include "../headers/liste.h"
#include "../headers/cozi.h"
#define NR_ECHIPE 32
#define LUNGIME_MAXIMA 50

void elim_c(char *s)
{
  int i = strlen(s);
  i--;
  while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\r') && i >= 0) ///!elimin si \r (cr),daca exista
  {
    s[i] = '\0';
    i--;
  }
}
Echipa *citeste_echipele(char *citire)
{
  Echipa *lista_echipe = NULL;
  FILE *c = fopen(citire, "rt");
  if (c == NULL)
  {
    printf("Eroare la deschiderea fisierului de citire!");
    exit(1);
  }

  for (int i = 0; i < NR_ECHIPE; i++)
  {
    float punctaj;
    char nume[LUNGIME_MAXIMA];
    fscanf(c, "%f ", &punctaj);
    fgets(nume, LUNGIME_MAXIMA, c);
    elim_c(nume);
    addAtEnd(&lista_echipe, i, nume, punctaj);
  }
  fclose(c);
  return lista_echipe;
}

Graph *createGraph()
{
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->a = (int **)malloc(NR_ECHIPE * sizeof(int *));
  g->V = NR_ECHIPE;
  for (int i = 0; i < NR_ECHIPE; i++)
    g->a[i] = (int *)calloc(NR_ECHIPE, sizeof(int));
  return g;
}

void meciuri(Echipa *lista_echipe, Graph *g, Queue *castigatori, Queue *invinsi)
{

  Echipa *aux;
  int nr_echipe = NR_ECHIPE;

  for (Echipa *p = lista_echipe; p != NULL; p = p->next) /// toate echipele incep din coada de castigatori
    enQueue(castigatori, p);

  while (nr_echipe > 1)
  {
    Echipa *echipa1 = deQueue(castigatori);
    Echipa *echipa2 = deQueue(castigatori);

    nr_echipe = nr_echipe - 2;
    if (echipa1->punctaj > echipa2->punctaj || (fabs(echipa1->punctaj - echipa2->punctaj) < 0.001 && strcmp(echipa1->nume, echipa2->nume) > 0))
    {
      enQueue(castigatori, echipa1);
      enQueue(invinsi, echipa2);
      g->a[echipa2->i][echipa1->i] = 1;
    }
    else if (echipa1->punctaj < echipa2->punctaj || (fabs(echipa1->punctaj - echipa2->punctaj) < 0.001 && strcmp(echipa2->nume, echipa1->nume) > 0))

    {
      enQueue(castigatori, echipa2);
      enQueue(invinsi, echipa1);
      g->a[echipa1->i][echipa2->i] = 1;
    }

    nr_echipe++; // a fost adaugata inapoi una dintre echipe in coada de castigatori
  }
}

void afisare_graf(char *argv2, Graph *g)
{
  FILE *graf = fopen(argv2, "wt");
  if (graf == NULL)
  {
    printf("Eroare la deschiderea fisierului pentru graf!\n");
    exit(1);
  }
  for (int i = 0; i < NR_ECHIPE; i++)
  {
    for (int j = 0; j < NR_ECHIPE; j++)
      fprintf(graf, "%d ", g->a[i][j]);
    fprintf(graf, "\n");
  }
  fclose(graf);
}

void clasament(char *argv3, Graph *g, Queue *invinsi, Queue *castigatori)
{
  FILE *scor = fopen(argv3, "wt");
  if (scor == NULL)
  {
    printf("Eroare la deschiderea fisierului pentru scor!");
    exit(1);
  }
  int victorii[NR_ECHIPE] = {0};
  int level = 0;
  for (Echipa *p = invinsi->front; p != NULL; p = p->next)
  {
    for (int j = 0; j < NR_ECHIPE; j++)
    {
      victorii[p->i] = victorii[p->i] + g->a[j][p->i]; /// numarul de muchii(/victoriile) se afla pe coloane
    }
    if (level < victorii[p->i])
      level = victorii[p->i];
  }

  level++; ///deoarece echipa castigatoare nu se afla in coada invinsilor
  victorii[castigatori->front->i]=level;
  float q = 0.15;
  float prestigiu;
  level++;///pentru checker
  for (Echipa *p = invinsi->front; p != NULL; p = p->next)
  {
    
    prestigiu = (q *pow((2 - q), victorii[p->i]))/ (pow(2, level) + pow((2 - q), level) * (q - 1));
                
    fprintf(scor, "%.4f %s\n", prestigiu, p->nume);
  }
  prestigiu = (q * pow((2 - q), victorii[castigatori->front->i])) / (pow(2, level) + pow((2 - q), level) * (q - 1));
  fprintf(scor, "%.4f %s\n", prestigiu, castigatori->front->nume);
  fclose(scor);
}