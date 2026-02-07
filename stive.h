#ifndef STIVE_h
#define STIVE_H

typedef struct stiva{
    int top;
    int *data;
}stiva;

void stiva_init ( stiva *s, int init_size );
void stiva_push ( stiva *s, int v[], int n );
void stiva_pop  ( stiva *s );
void stiva_afis ( stiva *s );

#endif // __stive
