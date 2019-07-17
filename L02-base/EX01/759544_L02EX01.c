/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
   
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
   
    Lista 02 - Exercício 01 - Menu de opções e operações aritmeticas
   
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
// Mensagem Pré definida
#define INVALIDO "Opção Inválida!\n"

/* <<< COMPLETE AQUI >>> */
// Este programa realiza a operação selecionada entre dois números inteiros
int main()
{
    //Declaração de variáveis
	int opcao, num_1, num_2, resultado_d;
	float resultado_f;

    //Comando de entrada
	scanf("%d%d%d", &num_1, &num_2, &opcao);

    //Operações e comando de saída
	switch (opcao) {
	case 1:
		resultado_d = num_1 + num_2;
		printf("%d\n", resultado_d);
		break;
	case 2:
		resultado_d = num_1 - num_2;
		printf("%d\n", resultado_d);
		break;
	case 3:
		resultado_d = num_2 - num_1;
		printf("%d\n", resultado_d);
		break;
	case 4:
		resultado_d = num_1 * num_2;
		printf("%d\n", resultado_d);
		break;
	case 5:
		resultado_f = (float) num_1 / num_2;
		printf("%.2f\n", resultado_f);
		break;
	case 6:
		resultado_f = (float) num_2 / num_1;
		printf("%.2f\n", resultado_f);
		break;
	case 7:
		resultado_d = num_1 / num_2;
		printf("%d\n", resultado_d);
		break;
	case 8:
		resultado_d = num_2 / num_1;
		printf("%d\n", resultado_d);
		break;
	case 9:
		resultado_d = num_1 % num_2;
		printf("%d\n", resultado_d);
		break;
	case 10:
		resultado_d = num_2 % num_1;
		printf("%d\n", resultado_d);
		break;
	default: 
		printf(INVALIDO);
	}


    return 0;
}
