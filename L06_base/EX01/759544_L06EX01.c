/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Introdução a Programação 
	Prof. Tiago A. Almeida
	Profa. Tiemi C. Sakata

	Lista 06 - Exercício 01 - Calculadora Vetor

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

#define INVALIDO "Operção Inválida!\n"
#define DIVISAOZERO "Divisição por zero\n"
#define POSICAO_INVALIDA "Posição Inválida!\n"
enum operacao {sair, soma, sub, mult, div, somaEscalar, multEscalar, imprimir, inverso};

int main()
{
	//Entrada do número de elementos
	int n_elementos;
	scanf("%d", &n_elementos);

	//Declaração das variáveis e inicialização da variável lógica
	int vetor[n_elementos], operacao, cont, escalar, pos1, pos2, parar = 0;
	double result_f;
	int result_d;

	for (cont = 0; cont < n_elementos; cont++)
	{
		scanf("%d", &vetor[cont]);
	}


	//Cálculos selecionados de acordo com a operação escolhida
	while (!parar) {
		scanf("%d", &operacao);
		switch (operacao){
			case sair:
				parar = 1;
				break;
			case soma:
				for (cont = 0, result_d = 0; cont < n_elementos; cont++)
				{
					result_d += vetor[cont];
				}
				printf("%d\n", result_d);
				break;
			case sub:
				for (cont = 0, result_d = 0; cont < n_elementos; cont++)
				{
					result_d -= vetor[cont];
				}
				printf("%d\n", result_d);
				break;
			case mult:
				for (cont = 0, result_d = 1; cont < n_elementos; cont++)
				{
					result_d *= vetor[cont];
				}
				printf("%d\n", result_d);
				break;
			case div:
				do {
					scanf("%d%d", &pos1, &pos2);
					if (pos1 >= n_elementos || pos2 >= n_elementos || pos1 < 0 || pos2 < 0)
					{
						printf(POSICAO_INVALIDA);
					}
				} while (pos1 >= n_elementos || pos2 >= n_elementos || pos1 < 0 || pos2 < 0);
				if (vetor[pos2] == 0)
				{
					printf(DIVISAOZERO);
				} else {
					result_f = (double)vetor[pos1] / vetor[pos2];
					printf("%.2f\n", result_f);
				}
				break;
			case somaEscalar:
				scanf("%d", &escalar);
				for (cont = 0; cont < n_elementos; cont++)
				{
					vetor[cont] += escalar;
				}
				break;
			case multEscalar:
				scanf("%d", &escalar);
				for (cont = 0; cont < n_elementos; cont++)
				{
					vetor[cont] *= escalar;
				}
				break;
			case imprimir:
				for (cont = 0; cont < n_elementos; cont++)
				{
					printf("%d ", vetor[cont]);
				}
				printf("\n");
				break;
			case inverso:
				for (cont = n_elementos - 1; cont >= 0; cont--)
				{
					printf("%d ", vetor[cont]);
				}
				printf("\n");
				break;
			default:
				printf(INVALIDO);
		}
	}
	return 0;
}