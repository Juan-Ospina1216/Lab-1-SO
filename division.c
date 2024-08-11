#include <stdio.h>
#include <stdlib.h>

typedef struct nota{ 
	float porcentaje;
	float calificacion;
	struct nota*sgte;
}nota;

nota*insertar_nota(float cal, nota*arreglo_notas, float porc);

int main(){
	float arreglo_porcentajes[6] = {0.05, 0.25, 0.15, 0.2, 0.15, 0.2};   //arreglo de los porcentajes del curso
	float cal, porcentaje;
	
	nota*cabeza_lista = NULL;
	
	for(int i=0; i < 6; i++){  //recorre el arreglo de los diferentes porcentajes de la asignatura
		
		porcentaje = arreglo_porcentajes[i] * 100;
		
		printf("Digita nota Actividad %.0f%%: ", porcentaje);
		scanf("%f", &cal);
		
		cabeza_lista = insertar_nota(cal, cabeza_lista, arreglo_porcentajes[i]); //la cabeza de la lista es el ultimo elemento agregado (como una pila)
	}
	
	float definitiva = 0;
	nota*nota_actual = cabeza_lista;

	do{
		//Recorre la lista de notas para calcular la definitiva
		definitiva += (nota_actual->calificacion) * (nota_actual->porcentaje);
		//printf("%f %f\n", nota_actual->calificacion, nota_actual->porcentaje);
		
		nota_actual = nota_actual->sgte;  //se actualiza con cada nota para ir recorriendo la lista
		
	}while(nota_actual != NULL);
	
	printf("Su nota definitiva de Sistemas Operativos es: %.3f%", definitiva);	
	return 0;
}

nota*insertar_nota(float cal, nota*cabeza_lista, float porc){
	
	//crea una instancia del struct para cada nota y lo agrega a una lista enlazada
	
	nota*nota_nueva = (nota*)malloc(sizeof(nota));
	
	if (nota_nueva != NULL){
		nota_nueva->porcentaje = porc;
		nota_nueva->calificacion = cal;
		nota_nueva->sgte = cabeza_lista;
		cabeza_lista = nota_nueva;
	}

	return cabeza_lista;
}
