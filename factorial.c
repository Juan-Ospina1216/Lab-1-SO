#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(){
	int n;
	int fact;
	do{
		printf("Ingrese un numero entero (-1 para terminar el programa): ");
		scanf("%d", &n);
		if(n != -1){
			fact = factorial(n);
			printf("El factorial de %d es: %d\n", n, fact);
		}
	}while(n != -1);
	
}

int factorial(int n){
	//funcion recursiva para calcular el factorial
	int fact;
	if(n == 1 || n == 0){
		fact = 1;
	}else{
		fact = n * factorial(n-1);
	}
	return fact;
}
