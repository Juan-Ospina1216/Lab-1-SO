#include <stdio.h>
#include <stdlib.h>

int bisiesto(int year);

typedef struct ano{  //struct para cada ano con atributos de ano y bool que indica si es bisiesto o no
	int year;
	int es_bisiesto;
}ano;

ano*agregar_ano(ano*arreglo_ano, int n, int es_bisiesto, int*tam);

int main(){
	int n;
	int tam = 1;  //crece por cada elemento que se arregla al arreglo
	int i=0;
	int es_bisiesto;
	ano *arreglo_ano = (ano*)malloc(tam * sizeof(ano));
	do{
		printf("Ingrese un ano (D.C.): ");
		scanf("%d", &n);
		if(n != -1){
			
			arreglo_ano = agregar_ano(arreglo_ano, n, bisiesto(n), &tam);
		
			switch(arreglo_ano[i].es_bisiesto){
				case 0: printf("%d no es un ano bisiesto\n", arreglo_ano[i].year);
					break;
				case 1: printf("%d es un ano bisiesto\n", arreglo_ano[i].year);
					break;
			}
		}
		i++;
	}while(n != -1);
}

int bisiesto(int year){
	//determina si un ano es o no bisiesto e imprime un booleano
	int x;
	int es_bisiesto = 0;
	x = year % 4;
	if(x == 0){
		es_bisiesto = 1;
	}
	return es_bisiesto;
}

ano*agregar_ano(ano*arreglo_ano, int n, int es_bisiesto, int*tam){
	
	//crea una instancia de ano y lo agrega al arreglo arreglo_ano
	
	arreglo_ano = (ano*)realloc(arreglo_ano, (*tam)*sizeof(ano));
	
	if(arreglo_ano != NULL){
		arreglo_ano[(*tam) - 1].year = n;
		arreglo_ano[(*tam) - 1].es_bisiesto = es_bisiesto;
	}
	
	(*tam)++;  //puntero a la variable tam
	return arreglo_ano;
}

