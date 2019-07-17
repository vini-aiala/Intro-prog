/* ================================================================== *
  Universidade Federal de Sao Carlos - UFSCar, Sorocaba

  Disciplina: Introdução a Programação
  Prof. Tiago A. Almeida
  Profa. Tiemi C. Sakata

  Lista 04 - Exercício 05 - Binário e Decimal

  Instrucoes
  ----------

  Este arquivo contem o codigo que auxiliara no desenvolvimento do
  exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
  Dados do aluno:

  RA: 759544
  Nome: Vinícius Pereira Aiala

* ================================================================== */

#include <stdio.h>
#include <math.h>

#define SAIR                0
#define OPC_BINARIO_DECIMAL 1
#define OPC_DECIMAL_BINARIO 2

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main()
{
  int opcao, ndigitos, digito, pot2, cont, resultado;

  while (1) {
    scanf("%d", &opcao);
    switch (opcao){
      case 0:
        return (0);
      case 1:
        scanf("%d", &ndigitos);
        pot2 = pow(2, (ndigitos - 1));
        for (cont = 1, resultado = 0; cont <= ndigitos; cont++, pot2 /= 2)
        {
          scanf("%d", &digito);
          resultado = resultado + (digito * pot2);
        }
        printf("%d\n", resultado);
        break;
      case 2:
        scanf("%d", &ndigitos);
        pot2 = pow(2, (ndigitos - 1));
        scanf("%d", &digito);
        for(;pot2 != 1; pot2 /= 2){
          if (digito >= pot2) {
            printf("1");
            digito -= pot2;
          } else {
            printf("0");
          }
        }
        printf("%d\n", digito);
        break;
    }
  }
}