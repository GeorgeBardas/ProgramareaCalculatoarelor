#include<stdio.h>
#include<stdlib.h>

int n, nrPoz = 0, nrNeg = 0, sumaPoz = 0, sumaNeg = 0, i, a;

int main(){
    printf("Numarul de numere = ");
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        printf("Numarul %d = ", i);
        scanf("%d", &a);
        if(a>0) {
            sumaPoz += a;
            nrPoz++;
        } else {
            sumaNeg += a;
            nrNeg++;
        }
    }

    printf("Medie numere pozitive: %d \n", sumaPoz/nrPoz);
    printf("Medie numere negative: %d", sumaNeg/nrNeg);

    return 0;

}
