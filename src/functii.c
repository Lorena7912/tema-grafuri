#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tipuri_de_date.h"
#include "../headers/liste.h"
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
  if (citire == NULL)
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
    printf("%f %s\n", punctaj, nume);
  }
  fclose(c);
  return lista_echipe;
}
