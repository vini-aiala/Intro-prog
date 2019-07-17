/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
  
    Lista 01 - Exercício 04 - Calculo de Expressao
  
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

//Este programa calcula o resultado da equação e separa a parte inteira da fracionária

#include <stdio.h>

int main()
{
    //Declaração de variáveis
    int a, b, c, r, s, result_int;
    float d, result_frac;

    //Comando de entrada
    scanf("%d %d %d", &a, &b, &c);

    //Resolução
    r = (a + b) * (a + b);
    s = (b + c) * (b + c);
    d = (float) (r + s) / 7;

    //Separação
    result_int = d / 1;
    result_frac = d - result_int;

    //Comando de saída
    printf("%d\n%.3f\n", result_int, result_frac);

    return 0;
}