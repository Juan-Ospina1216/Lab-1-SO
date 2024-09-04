#include <stdio.h>


int point11(){

  int num1 = 10;
  float num2 = 12.89083;
  float Cnum1;
  int Cnum2;
  // implicito de entero a flotante.
  Cnum1 = num1; // cambio de tipo de dato de entero a decimal, siendo 10 antes y ahora es 10.0
  printf("%f\n",Cnum1);
  //Explicito  de flotante a entero.
  Cnum2 = (int) num2;
  printf("%d\n", Cnum2);

  return 0;
}

int main(int argc, char const *argv[])
{
    point11();
    return 0;
}
