#include <stdio.h>

int vect[100], n;

int maxim(int i, int k){
    if(i>=k) return vect[k];
    int j=(i+k)/2;
    int maxStg=maxim(i,j);
    int maxDrp=maxim(j+1,k);
    
    return maxStg < maxDrp? maxDrp : maxStg;
}

int minim(int i, int k){
    if(i>=k) return vect[k];
    int j=(i+k)/2;
    int maxStg=minim(i,j);
    int maxDrp=minim(j+1,k);
    
    return maxStg > maxDrp ? maxDrp : maxStg;
}

int main() {
    printf("n=");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &vect[i]);
    
    printf("Valorea maxima din vector: %d\n", maxim(1, n));
    printf("Valorea minima din vector: %d\n", minim(1, n));
    
    return 0;
}
