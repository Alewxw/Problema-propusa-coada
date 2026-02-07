#include <stdio.h>
#include <stdlib.h>
#include <string.h>as
#include "stive.h"
#include "coada.h"

int main(void)
{
    /*printer p;
    printer_init(&p);
    coada_enqueue(&p);
    coada_enqueue(&p);
    coada_enqueue(&p);
    procesare(&p);*/

    stiva s;
    int n, v[1001];
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; i ++ )
        scanf("%d", &v[i]);

    stiva_init(&s, n-1);
    stiva_push(&s, v, n);

    stiva_afis(&s);
    stiva_pop(&s);
    printf("\n");
    stiva_afis(&s);


    return 0;
}
