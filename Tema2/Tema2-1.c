 #include <stdio.h>

FILE* file;

typedef struct{
    int nrMatricol;
    char nume[50];
    char prenume[50];
    int varsta;
    int grupa;
    char specializare[50];
    float medie;
} student;

void modificareStudent() {
    student s;
    int nrMat = -1;
    int pos = 0;
    int nArt = 0;
    
    file = fopen("informatii.txt" ,"rb+");
    
    if(file == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    
    printf("\nIntroduceti numarul matricol: ");
    scanf("%d", &nrMat);
    while(nrMat !=- 1) {
        do {
            nArt = fread(&s, sizeof(s), 1, file);
            if(s.nrMatricol == nrMat) {
                pos = ftell(file) - sizeof(s);
                break;
            }
        } while(s.nrMatricol != nrMat && nArt == 1);
        if(nArt < 1) {
            printf("\nNu exista acest student\n");
            break;
        }
        printf("\nIntroduceti media: ");
        scanf("%f", &s.medie);
        fseek(file, pos, 0);
        fwrite(&s, sizeof(s), 1, file);
    }
}

void listareStudenti(){
    file = fopen("informatii.txt", "rb");
    if(file == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    printf("Listare studenti\n");
    
    student student;
    int sizeOfStudenti = fread(&student, sizeof(student), 1, file);
    while (sizeOfStudenti == 1) {
        printf("%d ", student.nrMatricol);
        printf("%s ", student.nume);
        printf("%s ", student.prenume);
        printf("%d ", student.varsta);
        printf("%d ", student.grupa);
        printf("%s ", student.specializare);
        printf("%f\n", student.medie);
        sizeOfStudenti = fread(&student, sizeof(student), 1, file);
    }
}

void adaugareStudent(){
    file = fopen("informatii.txt", "ar+");
    if(file == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    student studentNou;
    
    printf("Adaugare student\n");
    printf("Numar matricol: \n");
    scanf("%d", &studentNou.nrMatricol);
    printf("Nume: \n");
    scanf("%s", studentNou.nume);
    printf("Prenume: \n");
    scanf("%s", studentNou.prenume);
    printf("Varsta: \n");
    scanf("%d", &studentNou.varsta);
    printf("Specializare: \n");
    scanf("%s", studentNou.specializare);
    printf("Grupa: \n");
    scanf("%d", &studentNou.grupa);
    printf("Medie: \n");
    scanf("%f", &studentNou.medie);
    
    fwrite(&studentNou, sizeof(studentNou), 1, file);
}


void afisareMeniu() {
    int optiuneSelectata;
    
    printf("Selectati optiunea dorita\n");
    printf("1 -> Listare studenti\n");
    printf("2 -> Adaugare student\n");
    printf("3 -> Modificare medie student\n");
    
    scanf("%d", &optiuneSelectata);
    
    switch (optiuneSelectata) {
        case 1:
            listareStudenti();
            break;
            
        case 2:
            adaugareStudent();
        break;
            
        case 3:
            modificareStudent();
        break;
            
        default:
            exit(1);
            break;
    }
    
}

int main(int argc, const char * argv[]) {
    
    afisareMeniu();
    
    fclose(file);
    return 0;
}
