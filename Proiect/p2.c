#include <stdio.h>

int N = 22;
int M = 5;

struct lista
{
    double k;
    struct lista *next, *prev;
};

struct lista *construireLista(int k,struct lista*l)
{
    struct lista *aux;
    aux=(struct lista*)malloc(sizeof(struct lista));
    aux->k=k;
    aux->next=l;
    aux->prev=NULL;
    if(l)
        l->prev=NULL;
    return aux;
}

struct lista *initListaTastatura(struct lista *l, int numarValori)
{
    double val;
    l = NULL;
    
    printf("Initializare lista cu %d valori: \n", numarValori);
    for (int i=0;i<numarValori;i++)
    {
        printf("Valoare %d: ", i+1);
        scanf("%lf", &val);
        l = construireLista(val,l);
    }

    return(l);
}

struct lista *initListaAutomat(struct lista *l, int numarValori)
{
    l = NULL;
    
    for (int i=0;i<numarValori;i++)
    {
        l=construireLista(i,l);
    }
    return(l);
}

struct lista *concatListe(struct lista *l1,struct lista *l2)
{
    struct lista *l;
    if (!l1)
        return(l2);
    else
        if (!l2)
            return(l1);
        else
            {
                l=l1;
             while(l->next)
                 l=l->next;
             l->next=l2;
             return(l1);
             }
}

double maxLista(struct lista *l)
{
    struct lista *p;
    int max=l->k;
    for(p=l;p;p=p->next)
    if(p->k > max)
        max=p->k;
    return max;
}

double minLista(struct lista *l)
{
    struct lista *p;
    int min=l->k;
    for(p=l;p;p=p->next)
    if(p->k < min)
        min = p->k;
    return min;
}

int main() {
    struct lista *lista1, *lista2, *listConcat;
    
    lista1 = initListaTastatura(lista1, N); // --- INITIALIZARE DE LA TASTATURA A LISTEI CU x VALORI ---
    lista2 = initListaTastatura(lista2, M);
    
//    lista1 = initListaAutomat(lista1, N); // --- INITIALIZARE AUTOMATA PANA LA O CONSTANTA ---
//    lista2 = initListaAutomat(lista2, M);
    
    listConcat = concatListe(lista1, lista2);
    
    printf("Valoarea maxima din cele doua liste concatenate = %lf\n", maxLista(listConcat));
    printf("Valoarea minima din cele doua liste concatenate = %lf\n", minLista(listConcat));
    
    return 0;
}
