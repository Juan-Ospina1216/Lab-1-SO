#include <stdio.h>


int point10(){
  int numeros[3];
  int Mayor = 0;

  numeros[0] = 102;
  numeros[1] = 12;
  numeros[2] = 45;

  for (int i = 0; i < 3; i++){
    if (numeros[i] > Mayor){
      Mayor = numeros[i];
    }
  }
  return Mayor;
}


int main(int argc, char const *argv[])
{
    printf("el numero mayor es %d", point10());
    return 0;
}
