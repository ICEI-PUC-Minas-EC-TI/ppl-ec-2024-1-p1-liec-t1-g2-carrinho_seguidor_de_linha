#include <stdio.h>

int main(void){
    char nome[31];
    printf("Digite seu nome (maximo de 30 caracteres): \n");
    scanf("%[^\n]", nome);
    printf("Bom dia, %s, \n", nome);
    return 0;
}

