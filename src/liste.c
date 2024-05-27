
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tipuri_de_date.h"
#include "../headers/functii.h"
#define LUNGIME_MAXIMA 50
void addAtEnd(Echipa **head, int i, char *nume, float punctaj) 
{
    Echipa *node = (Echipa *)malloc(sizeof(Echipa));
    node->nume = (char *)malloc((strlen(nume) + 1) * sizeof(char));
    strcpy(node->nume, nume);
    node->punctaj = punctaj;
    node->i=i;
    node->next = NULL;

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    Echipa *p;
    for (p = *head; p->next != NULL; p = p->next)
        ;

    p->next = node;
}

void elim_echipa(Echipa **lista_echipe, Echipa *echipa)
{
    if (*lista_echipe == NULL)
        return;
    Echipa *copie = *lista_echipe;
    if (strcmp((*lista_echipe)->nume, echipa->nume) == 0)
    {
        *lista_echipe = (*lista_echipe)->next;
        free(copie);
        return;
    }
    Echipa *prev = *lista_echipe;
    while (copie != NULL)
        if (strcmp(copie->nume, echipa->nume) != 0)
        {
            prev = copie;
            copie = copie->next;
        }
        else
        {
            prev->next = copie->next;
            free(copie);
            return;
        }
}