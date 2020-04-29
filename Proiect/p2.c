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

void afisare(struct lista*l)
{
    struct lista *p;
    printf("NULL");
    for(p=l;p;p=p->next)
        printf("<=>%lf",p->k);
    printf("<=>NULL\n");
}

struct lista *initListaTastatura(struct lista *l)
{
    int ci, k = 1;
    char c1, ck, cc[5];
    l = NULL;
    
    while (k!=-1)
    {
        printf("VALOARE : ");
        scanf("%s",cc);c1=getchar();
        if (strcmp(cc, "n")) k=1;
        else k = -1;
        ci = atoi(cc);
        if (k != -1)
        l = construireLista(ci,l);
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
    int max=-32800;
    for(p=l;p;p=p->next)
    if(p->k>max)
        max=p->k;
    return max;
}

int main() {
    struct lista *lista1, *lista2;
    
//    lista1 = initListaTastatura(lista1); // --- INITIALIZARE DE LA TASTATURA PANA LA CARACTERUL "n" ---
//    lista2 = initListaTastatura(lista2);
    
    lista1 = initListaAutomat(lista1, N); // --- INITIALIZARE AUTOMATA PANA LA O CONSTANTA ---
    lista2 = initListaAutomat(lista2, M);
    
    printf("%lf\n", maxLista(concatListe(lista1, lista2)));
    
    return 0;
}
