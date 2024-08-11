#include <stdio.h>
#include <stdlib.h>

int primo(int n);

int main(){
	int n;
	int es_primo;
	do{
		es_primo = -1;
		printf("Ingrese un numero (0 para terminar el programa): ");
		scanf("%d", &n);
		
		if(n != 0){
			es_primo = primo(n);	
		}
		
		switch(es_primo){
			case 0: printf("%d no es primo\n", n);
				break;
			case 1: printf("%d es primo\n", n);
				break;
		}
		
	}while(n != 0);
	
}

int primo(int n){
	//retorna 1 si es primo y 0 si no lo es
	
	int primo = 1;
	
	for(int i = 1; i < n + 1; i++){
		if(n % i == 0){
			if(i != n && i != 1){ //verifica si es divisible por un numero diferente de 1 o el mismo
				primo = 0;
			}
		}
	}
	return primo;
}









