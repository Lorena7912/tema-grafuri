
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tipuri_de_date.h"
#include "../headers/functii.h"
#define LUNGIME_MAXIMA 50
void addAtEnd(Echipa **head, int i, char *nume, float punctaj) /// in lista tinem minte echipele si o actualizam pe masura meciurilor
///(eliminam echipele din lista + actualizam numarul de victorii) pe masura ce facem deQueue mai intai din coada castigatorilor, dupa aceea din coada invinsilor
/// nu mai duplicam nodurile!!!
{
  Echipa *node = (Echipa *)malloc(sizeof(Echipa));
  node->nume = (char *)malloc((strlen(nume) + 1) * sizeof(char));
  strcpy(node->nume, nume);
  node->punctaj = punctaj;
  node->victorii = 0;
  node->next = NULL;

  if (*head == NULL)
  {
    *head = node;
    return;
  }

  Echipa *p;
  for (p = *head; p->next != NULL; p = p->next);

  p->next = node;
}
