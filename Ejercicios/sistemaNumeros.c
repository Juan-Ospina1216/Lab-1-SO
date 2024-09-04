#include <stdio.h>


int point12(){

  for (int i = 1;i<=10;i++) {
    printf("OCTAL: %o\n", i);
    printf("DECIMAL: %d\n", i);
    printf("HEXADECIMAL: %X\n\n", i);

  }

  return 0;
}


int main(int argc, char const *argv[])
{
    point12();
    return 0;
}
