#include<stdio.h>
#include<string.h>

#define MAX 30
#define MAX_CHARS_NR_INMATRICULARE 10
#define MAX_CHARS_TIP_MASINA 30
#define MAX_CHARS_CULOARE_MASINA 10


struct Masina *pointerMasina[MAX], *qretrive(void);
struct Masina {
    char numar[MAX_CHARS_NR_INMATRICULARE];
    char tip[MAX_CHARS_TIP_MASINA];
    char culoare[MAX_CHARS_CULOARE_MASINA];
    int combustibil;
};

int freePosition = 0;
int firstPosition = 0;

void salvareMasina(struct Masina *q) {
  if(freePosition==MAX) {
    printf("\nLista plina\n");
    return;
  }
  pointerMasina[freePosition]=q;
  freePosition++;
}

struct Masina *afisareMasina(void) {
  if(firstPosition==freePosition) {
    printf("Lista goala\n\n");
    return NULL;
  }
  firstPosition++;
  return pointerMasina[firstPosition-1];
}

void adaugare() {
    struct Masina *masina;
    
    masina=(struct Masina*)malloc(sizeof(struct Masina));
    
    if(!masina) {
      printf("\nMemorie insuficienta...\n");
      return;
    }
    
    printf("Numar inmatriculare: ");
    scanf("%s", &masina->numar);
    
    printf("Tip masina: ");
    scanf("%s", &masina->tip);
    
    printf("Culoarea masinii: ");
    scanf("%s", &masina->culoare);
    
    printf("Tip combustibil(1 - Benzina / 2 - Motorina): ");
    scanf("%d", &masina->combustibil);
    
    salvareMasina(masina);
    printf("\n");
 }

void stergere() {
    struct Masina *ptrmasina;
    if((ptrmasina=afisareMasina())==NULL) return;
    printf("Masina stearsa: \n");
    printf("%s, %s, %s, %d \n", ptrmasina->numar, ptrmasina->tip, ptrmasina->culoare, ptrmasina);
    printf("\n");
}

void listare(int tipCombustibil) {
    int index=1;
    printf("--Numar, Tip, Culoare, Tip combustibil-- \n");
    for(int t=firstPosition;t<freePosition;++t)
        if (tipCombustibil == 0) {
            printf("%d. %s, %s, %s, %d, %d \n", index, pointerMasina[t]->numar, pointerMasina[t]->tip, pointerMasina[t]->culoare, pointerMasina[t]->combustibil, pointerMasina[t]);
            index++;
        }
        else if (tipCombustibil == pointerMasina[t]->combustibil) {
            printf("%d. %s, %s, %s, %d, %d \n", index, pointerMasina[t]->numar, pointerMasina[t]->tip, pointerMasina[t]->culoare, pointerMasina[t]->combustibil, pointerMasina[t]);
            index++;
        }
    printf("\n");
}

void afisareMeniu() {
    int raspuns;
    
    printf("Meniu: \n");
    printf("1. Adaugare masina \n");
    printf("2. Stergere masina \n");
    printf("3. Listare masini \n");
    printf("4. Listare masini benzina \n");
    printf("5. Listare masini motorina \n");
    printf("6. Lungime coada \n");
    printf("7. Exit \n");
    printf("Alegeti optiunea dorita: ");
    scanf("%d", &raspuns);
    printf("\n");
    switch (raspuns) {
        case 1:
            adaugare();
            break;
        
        case 2:
            stergere();
            break;
            
        case 3:
            printf("Listare: \n");
            listare(0);
            break;
            
        case 4:
            printf("Listare masini benzina: \n");
            listare(1);
            break;
        
        case 5:
            printf("Listare masini motorina: \n");
            listare(2);
            break;
            
        case 6:
            printf("Lungime coada: %d \n\n", freePosition - firstPosition);
            break;
            
        case 7:
            exit(0);
            break;
            
        default:
            exit(0);
            break;
     }
    
    afisareMeniu();
}

void main() {
    for(int t=0;t<MAX;++t)
        pointerMasina[t]=NULL;
    afisareMeniu();
}

