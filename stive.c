#include <stdlib.h>
#include <stdio.h>
#include "stive.h"

void stiva_init ( stiva *s, int init_size )
{
    s->top = 0;
    s->data = malloc(init_size*sizeof(int));
}

void stiva_push ( stiva *s, int v[], int n )
{
    for ( int i = 0 ; i < n - 1 ; i ++ )
    {
        if ( v[i] > v[i+1] ) s->data[s->top++] = v[i];
        else s->data[s->top++] = v[i+1];
    }
}

void stiva_pop  ( stiva *s )
{
    if ( s->top == 0 ) return ;

    s->data[s->top--] = NULL;
}

void stiva_afis ( stiva *s )
{
    for ( int i = 0 ; i < s->top ; i ++ )
        printf("%d ", s->data[i]);
}
