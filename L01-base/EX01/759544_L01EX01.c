/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
 
    Lista 01 - Exercício 01 - Operações Aritméticas
 
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

//Este programa calcula as operações propostas

#include <stdio.h>

int main()
{
    //Declaração de variáveis
    int num_1, num_2, soma, sub1_2, sub2_1, prod, quo1_2, quo2_1, resto1_2, resto2_1;
    float div1_2, div2_1;

    //Comando de entrada
    scanf("%d%d", &num_1, &num_2);

    //Operações
    soma = num_1 + num_2;
    sub1_2 = num_1 - num_2;
    sub2_1 = num_2 - num_1;
    prod = num_1 * num_2;
    div1_2 = (float) num_1 / num_2;
    div2_1 = (float) num_2 / num_1;
    quo1_2 = num_1 / num_2;
    quo2_1 = num_2 / num_1;
    resto1_2 = num_1 % num_2;
    resto2_1 = num_2 % num_1;

    //Comando de saída
    printf("%d\n%d\n%d\n%d\n%.2f\n%.2f\n%d\n%d\n%d\n%d\n", soma, sub1_2, sub2_1, prod, div1_2, div2_1, quo1_2, quo2_1, resto1_2, resto2_1);


    return 0;
}