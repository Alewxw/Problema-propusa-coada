#ifndef COADA_H
#define COADA_H

typedef struct {
    char titlu[1001];
    char continut[1001];
} document;

typedef struct CoadaNode {
    document doc;
    struct CoadaNode *next;
} CoadaNode;

typedef struct {
    CoadaNode *primul;
    CoadaNode *ultimul;
} printer;

void printer_init(printer *x);
void coada_enqueue(printer *x);
void coada_deque (printer *x);
void coada_prio ( printer *x, int k );
void procesare ( printer *x );

#endif // COADA_H
