/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
  
    Lista 01 - Exercício 02 - Semanas de Gravidez
  
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

//Este programa converte o número de semanas pelo seu correspondente em meses

#include <stdio.h>

int main()
{
    //Declaração de variáveis
    int semanas, meses, resto_semanas;

    //Comando de entrada
    scanf("%d", &semanas);

    //Conversão
    meses = semanas / 4;
    resto_semanas = semanas % 4;

    //Comando de saída
    printf("%d\n%d\n", meses, resto_semanas);

    return 0;
}