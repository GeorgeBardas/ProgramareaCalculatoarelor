#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_LINII 100
#define MAX_COLOANE 100
#define MAX_K 100

int n, m, k, matrice[MAX_LINII][MAX_COLOANE];

void citesteN(int max){
    printf("n = ");
    scanf("%d", &n);
    if(n > max) printf("Valoare prea mare \n");
}
void citesteM(int max){
    printf("m = ");
    scanf("%d", &m);
    if(m > max) printf("Valoare prea mare \n");
}
void citesteK(int max){
    printf("k = ");
    scanf("%d", &k);
    if(k > max) printf("Valoare prea mare \n");
}

void citesteMatrice(int m, int n){
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d", &matrice[i][j]);
}

void afisare(int matrice[MAX_LINII][MAX_COLOANE], int k){
    int suma;
    for(int i=1;i<=m;i++){
        suma = 0;
        for(int j=1;j<=n;j++)
            if(matrice[i][j] != 0) suma++;
        if(suma >= k){
            for(int y=1;y<=n;y++) printf("%d ", matrice[i][y]);
            printf("\n");
        }
    }
}

int main(){
    citesteN(MAX_LINII);
    citesteM(MAX_COLOANE);
    citesteK(MAX_K);
    citesteMatrice(n, m);

    afisare(matrice, k);

    return 0;
}
