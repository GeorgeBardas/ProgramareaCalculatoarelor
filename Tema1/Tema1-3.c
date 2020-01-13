#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a, b, c, delta;

int main(){
    printf("a= "); scanf("%d", &a);
    printf("b= "); scanf("%d", &b);
    printf("c= "); scanf("%d", &c);

    if(a==0)
        if(b==0)
            if(c==0)
                printf("Infinitate de solutii");
            else
                printf("Ec imposibila");
        else
            printf("Solutie = &d", -c/b);
    else {
        delta = (pow(b,2)-(4*a*c));
        if(delta < 0)
            printf("Nu sunt solutii");
        else if(delta == 0)
            printf("Ecuatie cu solutii egale : %d", -b/(2*a));
        else{
            printf("x1 = %d \n", (-b+sqrt(delta))/(2*a));
            printf("x2 = %d", (-b-sqrt(delta))/(2*a));
        }
    }

    return 0;

}
