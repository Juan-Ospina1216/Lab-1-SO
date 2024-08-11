#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
    char cadena[MAX];
    char mayus[MAX];
    int cont;
}Cadena;

void encontrarMayus(Cadena *cad) {
    cad->cont = 0;
    int marcados[26] = {0};
    for (int i = 0; i < MAX; i++) {
        char letra = cad->cadena[i];
        if (letra >= 'A' && letra <= 'Z') {
            int pos = letra - 'A'; // Operacion en ASCII
            if(marcados[pos] == 0){ // No incluye los repetidos
                cad->mayus[cad->cont] = letra;
                cad->cont++;
                marcados[pos] = 1;
            }
        }
    }
}

int main(){
    Cadena cad;
    printf("Ingrese una cadena: ");
    fgets(cad.cadena, MAX, stdin);
    encontrarMayus(&cad);

    if (cad.cont > 0){
        printf("Se encontraron %d letras mayusculas que son: ", cad.cont);
        for (int i = 0; i < cad.cont; i++) {
            printf("%c ", cad.mayus[i]);
        }
    } else{
        printf("No se encontraron letras mayusculas");
    }    
    return 0;
}