/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
  
    Lista 01 - Exercício 04 - Calculo de Importacao
  
    Instrucoes
    ----------
  
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
  
* ================================================================== *
    Dados do aluno:
  
    RA:759544
    Nome:Vinícius Pereira Aiala
  
* ================================================================== */


#include <stdio.h>

#define ICMS 0.17 //constante pré-definida de ICMS

/* <<< COMPLETE AQUI >>> */

//Este programa calcula a soma do valor do produto com e frete, em reais, o valor com o imposto de importação e com o ICMS
int main()
{
    //Declaração de variáveis
    float val_prod, val_frete, val_total_reais, val_imposto_imp, val_ICMS;

    //Comando de entrada
    scanf("%f%f", &val_prod, &val_frete);

    //Conversão e calculo de impostos
    val_total_reais = (val_prod + val_frete) * 3.3;
    val_imposto_imp = val_total_reais + val_total_reais * 0.6;
    val_ICMS = val_imposto_imp + val_imposto_imp * ICMS;

    //Comando de saída
    printf("%.2f\n%.2f\n%.2f\n", val_total_reais, val_imposto_imp, val_ICMS);


    return 0;
}