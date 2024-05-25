#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tipuri_de_date.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, Echipa *v)
{
    Echipa *newNode = (Echipa *)malloc(sizeof(Echipa));
    newNode->i = v->i;
    newNode->victorii = v->victorii;
    newNode->nume = (char *)malloc((strlen(v->nume) + 1) * sizeof(char));
    strcpy(newNode->nume, v->nume);
    newNode->punctaj = newNode->punctaj;
    newNode->next = NULL;
    // nodurile noi se adauga la finalul cozii
    // daca nu exista niciun nod in coada
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    // daca exita un singur element in coada
    if (q->front == NULL)
        q->front = q->rear;
}

int isEmpty(Queue *q) ///verificata
{
    return (q->front == NULL);
}
Echipa *deQueue(Queue *q) ///verificata
{
    if (isEmpty(q))
        return NULL; ///!
    Echipa *aux=q->front;
    ///atribuim lui val elementele lui q->front
    Echipa *val = (Echipa *)malloc(sizeof(Echipa));
    val->i=aux->i;
    val->victorii=aux->victorii;
    val->punctaj=aux->punctaj;
    val->nume=(char*)malloc((strlen(aux->nume)+1)*sizeof(char));
    strcpy(val->nume,aux->nume);
    val->next = NULL; ///pentru a "izola elementul"

    q->front=(q->front)->next;
    free(aux);
    return val;

}