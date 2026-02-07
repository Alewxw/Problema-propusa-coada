#include <stdlib.h>
#include <stdio.h>
#include "coada.h"

void printer_init ( printer *x )
{
    x->primul = NULL;
    x->ultimul = NULL;
}

void coada_enqueue(printer *x)
{
    document d;

    printf("Titlu: ");
    fgets(d.titlu, sizeof(d.titlu), stdin);
    d.titlu[strcspn(d.titlu, "\n")] = 0;

    printf("Continut: ");
    fgets(d.continut, sizeof(d.continut), stdin);
    d.continut[strcspn(d.continut, "\n")] = 0;

    // creează un nod nou
    CoadaNode *nou = malloc(sizeof(CoadaNode));
    if (!nou) {
        printf("Eroare alocare memorie!\n");
        return;
    }

    nou->doc = d;
    nou->next = NULL;

    // dacă coada e goală
    if (x->ultimul == NULL) {
        x->primul = x->ultimul = nou;
    } else {
        x->ultimul->next = nou;
        x->ultimul = nou;
    }
}

void coada_deque (printer *x)
{
    CoadaNode *aux = x->primul;
    x->primul = x->primul->next;

    if (x->primul == NULL)
        x->ultimul = NULL;

    printf("%s %s\n", aux->doc.titlu, aux->doc.continut);

    free(aux);
}

void coada_prio ( printer *x, int k )
{
    if ( x->primul == NULL ) return ;

    if ( k == 1 ) return;

    int i = 1;
    CoadaNode *prev = NULL, *curr = x->primul;

    while ( curr != NULL && i < k )
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if ( curr == NULL ) return ;

    prev->next = curr->next;

    if ( curr == x->ultimul ) x->ultimul = prev;

    curr->next = x->primul;
    x->primul = curr;

}

void procesare ( printer *x )
{
    for ( CoadaNode *aux = x->primul ; aux != NULL ; aux = aux->next )
        coada_deque(x);
}
