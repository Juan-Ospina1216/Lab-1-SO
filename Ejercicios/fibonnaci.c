#include <stdio.h>
#include <stdlib.h>

// Iterativo
void fibonnaciIte(int num){
    int next = 0;
    if (num <= 1){
        printf("La serie de fibonnaci es: %d", next);
    } else{
        int a = 0;
        int b = 1;
        printf("La serie de Fibonacci Iterativamente de los primeros %d numeros son: ", num);
        for(int i = 0; i <= num-1; i++){
            if (i <= 1) {
                printf("%d ", i);
            } else {
                next = a + b;
                a = b;
                b = next;
                printf("%d ", next);
            }
        }
    }

}

// Recursivo
int fibonnaciRec(int num) {
    int res = 0;
    if (num <= 1) {
        res = num;
    } else {
        res = fibonnaciRec(num - 1) + fibonnaciRec(num - 2);
    }
    return res;
}


int main(){
    int num = 0;
    printf("Escribe la cantidad de numeros que quieres ver de la serie fibonnaci: ");
    scanf("%d", &num);

    printf("La serie de Fibonacci Recursivamente de los primeros %d numeros son: ", num);
    for (int i = 0; i <= num-1; i++) {
        printf("%d ", fibonnaciRec(i));
    }
    printf("\n");
    fibonnaciIte(num);

}
