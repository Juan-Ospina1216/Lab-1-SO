#include <stdio.h>

int point9(char c){
  if (c >= 'a' && c <= 'z'){
    return 1;
  }else{
    return 0;
  }
}


int main(int argc, char const *argv[])
{
    char letra = 'p';
    if (point9(letra)){
        printf("Si pertenece");

    }else{
        printf("No pertenece");
    }
    return 0;
}
