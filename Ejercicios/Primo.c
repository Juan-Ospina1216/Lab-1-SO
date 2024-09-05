#include <stdio.h>
#include <stdlib.h>

int primo(int n);
int primer_punto();
int segundo_punto();
int tercer_punto();

int main(){
	int sol;
	int es_primo;
	do{
		printf("\n0.Salir\n1.Verificar primo\n2.Verificar primos en arreglo\n3.Primos en rango\n");
		scanf("%d", &sol);
	
		switch(sol){
			case 1: primer_punto();
				break;
			case 2: segundo_punto();
				break;
			case 3: tercer_punto();
				break;
		}
	
	}while(sol!=0);
	
}

int primer_punto(){
	
	int n;
	
	do{
		int es_primo;
		es_primo = -1;
		printf("\nIngrese un numero (0 para terminar el programa): ");
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

int segundo_punto(){
	
	int tam;
	int n;
	
	printf("\nCuantos numeros vas a agregar: ");
	scanf("%d", &tam);
	int*arr = (int*)malloc(tam * sizeof(int));
	
	printf("\nIngresa los %d numeros: \n", tam);
	for(int i = 0; i < tam; i++){
		scanf("%d", &n);
		arr[i] = n;
	}
	
	for(int i = 0; i < tam; i++){
		
		int num = primo(arr[i]);
		if(num == 1){
			printf("%d ", arr[i]);
		}
		
	}
	
	return 0;
}

int tercer_punto(){
	printf("\nIngrese un limite inferior: ");
	int lim_inf;
	int lim_sup;
	scanf("%d", &lim_inf);
	printf("\nIngrese un limite superior: ");
	scanf("%d", &lim_sup);
	
	int es_primo;
	for(int i = lim_inf; i < lim_sup; i++){
		es_primo = primo(i);
		if(es_primo == 1){
			printf("%d ", i);
		}
	}
	
	
	return 0;
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









