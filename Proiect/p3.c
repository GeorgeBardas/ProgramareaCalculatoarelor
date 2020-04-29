#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int N = 22;
const int NR_NOTE = 5;
const int MAX_CHARS_NUME = 30;

typedef char Nume;

struct Student
{
    Nume nume[MAX_CHARS_NUME], prenume[MAX_CHARS_NUME];
    int note[NR_NOTE];
    struct Student *next, *prev;
};

struct Student *construireListaStudenti(struct Student*l)
{
    struct Student *aux;
    aux = (struct Student*)malloc(sizeof(struct Student));
    
    printf("Nume: ");
    scanf("%s", &aux->nume);
    
    printf("Prenume: ");
    scanf("%s", &aux->prenume);
    
    for(int i=0;i<NR_NOTE;i++){
        printf("Nota %d: ", i + 1);
        scanf("%d", &aux->note[i]);
    }
    
    aux->next = l;
    aux->prev = NULL;
    if(l)
        l->prev = NULL;
    return aux;
}

void afisareStudenti(struct Student*l)
{
    struct Student *p;
    for(p=l;p;p=p->next) {
        printf("%s %s ", p->nume, p->prenume);
        for(int i=0;i<NR_NOTE;i++)
            printf("%d ", p->note[i]);
        printf("\n");
    }
}

void afisareSortat(struct Student*l, bool absolvent) {
    struct Student *p;
    int sum;
    
    for(p=l;p;p=p->next) {
        sum = 0;
        for(int i=0;i<NR_NOTE;i++)
            sum += p->note[i];
        if (sum / NR_NOTE > 5 && absolvent) printf("%s %s ", p->nume, p->prenume);
        else if (sum / NR_NOTE < 5 && !absolvent) printf("%s %s ", p->nume, p->prenume);
        printf("\n");
    }
}

double calculMedie(struct Student*l) {
    struct Student *p;
    int sum = 0;
    
    for(p=l;p;p=p->next) {
        sum = 0;
        for(int i=0;i<NR_NOTE;i++)
            sum += p->note[i];
    }
    
    return sum/NR_NOTE;
}

struct Student *initLista(struct Student *l, int numarValori)
{
    l = NULL;
    
    printf("Introduceti %d student(i): \n", N);
    for (int i=0;i<numarValori;i++)
        l = construireListaStudenti(l);
    return(l);
}

void afisareMeniu(struct Student *student) {
    int optiune;

    printf("\n\nSelectati o optiune: \n");
    printf("1.Afisare studenti\n");
    printf("2.Afisare media grupei\n");
    printf("3.Afisare studenti promovati\n");
    printf("4.Afisare studenti ce nu au promovat\n");
    printf("5.Exit\n");
    scanf("%d", &optiune);
    
    switch (optiune) {
        case 1:
            afisareStudenti(student);
            break;
            
            case 2:
            printf("%lf", calculMedie(student));
            break;
            
            case 3:
            afisareSortat(student, true);
            break;
            
            case 4:
            afisareSortat(student, false);
            break;
            
            case 5:
            exit(0);
            break;
            
        default:
            break;
    }
    afisareMeniu(student);
}

int main() {
    struct Student *student;
    student = initLista(student, N);
    afisareMeniu(student);
    
    return 0;
}
