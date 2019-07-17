/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
  
    Lista 01 - Exercício 05 - Manipulacao de caracteres
  
    Instrucoes
    ----------
  
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
  
* ================================================================== *
    Dados do aluno:
  
    RA:759544
    Nome:Vinícius Pereira Aiala
  
* ================================================================== */
 
 
/* <<< COMPLETE AQUI >>> */

//Este programa imprime a primeira letra em minúsculo, o valor do segundo caractere de acordo com a tabela ASCII e a posição correspondente no alfabeto da terceira letra
#include <stdio.h>

int main()
{
    //Declaração de variáveis
    char car_1, car_2, car_3, minusc, posi;

    //Comando de entrada
    scanf("%c%c%c", &car_1, &car_2, &car_3);

    //Conversões
    minusc = car_1 + 32;
    posi = car_3 - 64;

    //Comando de saída
    printf("%c\n%d\n%d\n", minusc, car_2, posi);
    
    return 0;
}