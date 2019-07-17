/* ================================================================== *
  Universidade Federal de Sao Carlos - UFSCar, Sorocaba

  Disciplina: Introdução a Programação
  Prof. Tiago A. Almeida
  Profa. Tiemi C. Sakata

  Lista 05 - Exercício 01 - Números Complexos

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

#define INVALIDO "Operção Inválida!\n"
#define DIVIZAOZERO "Divisição por zero\n"
enum operacao {sair, soma, sub1, sub2, mult, div1, div2, modulo1, modulo2};

typedef struct complexo {
	float real;
	float imaginario;
} Complexo;


int main(){
// <COMPLETE AQUI> //
  int operacao;
  int parar = 0, semresult = 0;
  float resultR, resultC;
  Complexo n1, n2;

  scanf("%f %f\n%f %f", &n1.real, &n1.imaginario, &n2.real, &n2.imaginario);

  while (!parar){
    scanf("%d", &operacao);
    semresult = 0;
    switch (operacao){
      case sair:
        parar = 1;
        break;
      case soma:
        resultR = n1.real + n2.real;
        resultC = n1.imaginario + n2.imaginario;
        break;
      case sub1:
        resultR = n1.real - n2.real;
        resultC = n1.imaginario - n2.imaginario;
        break;
      case sub2:
        resultR = n2.real - n1.real;
        resultC = n2.imaginario - n1.imaginario;
        break;
      case mult:
        resultR = n1.real * n2.real - n1.imaginario * n2.imaginario;
        resultC = n1.real * n2.imaginario + n1.imaginario * n2.real;
        break;
      case div1:
        if (n2.real != 0 || n2.imaginario != 0)
        {
          resultR = (n1.real * n2.real + n1.imaginario * n2.imaginario) / (pow(n2.real, 2) + pow(n2.imaginario, 2));
          resultC = (n1.imaginario * n2.real - n1.real * n2.imaginario) / (pow(n2.real, 2) + pow(n2.imaginario, 2));
        } else {
          printf(DIVIZAOZERO);
          semresult = 1;
        }
        break;
      case div2:
        if (n1.real != 0 || n1.imaginario != 0)
        {
          resultR = (n2.real * n1.real + n2.imaginario * n1.imaginario) / (pow(n1.real, 2) + pow(n1.imaginario, 2));
          resultC = (n2.imaginario * n1.real - n2.real * n1.imaginario) / (pow(n1.real, 2) + pow(n1.imaginario, 2));
        } else {
          printf(DIVIZAOZERO);
          semresult = 1;
        }
        break;
      case modulo1:
        resultR = sqrt(pow(n1.real, 2) + pow(n1.imaginario, 2));
        resultC = 0;
        break;
      case modulo2:
        resultR = sqrt(pow(n2.real, 2) + pow(n2.imaginario, 2));
        resultC = 0;
        break;
      default:
        printf(INVALIDO);
    }
    if (!parar && operacao <= 8 && !semresult)
    {
      if (resultR != 0 && resultC != 0) 
      {
        if (resultC < 0)
          printf("%.2f %.2fi\n", resultR, resultC);
        else
          printf("%.2f +%.2fi\n", resultR, resultC);
      } else if (resultC != 0)
      {
        printf("%.2fi\n", resultC);
      } else {
        printf("%.2f\n", resultR);
      }

    }
  }

	return 0;
}