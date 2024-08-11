#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double base;
    int exp;
} Potencia;

double potenciaPositiva(Potencia num){
    double res = 0;
    if(num.exp == 0){
        res = 1;
    } else if (num.exp == 1){
        res = num.base;
    } else {
        Potencia potPos;
        potPos.base = num.base;
        potPos.exp = num.exp - 1;
        res = num.base * potenciaPositiva(potPos);
    }
    return res;   
}

double potenciaNegativa(Potencia num){
    double res = 0;
    if(num.exp == 0){
        res = 1;
    } else {
        Potencia potNeg;
        potNeg.base = num.base;
        potNeg.exp = num.exp + 1;
        res = 1.0 / num.base * potenciaNegativa(potNeg);
    }
    return res;   
}

int main(){
    Potencia num;
    double res = 0;
    printf("Escribe el numero como base: ");
    scanf("%lf", &num.base);
    printf("Escribe el numero como exponente: ");
    scanf("%d", &num.exp);

    if (num.exp < 0){
        res = potenciaNegativa(num);
    } else {
        res = potenciaPositiva(num);
    }
    printf("El numero %f elevado a la potencia %d es: %f \n", num.base, num.exp, res);
    
    return 0;
}

