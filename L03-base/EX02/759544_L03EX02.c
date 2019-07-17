/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Introdução a Programação
	Prof. Tiago A. Almeida
	Profa. Tiemi C. Sakata

	Lista 03 - Exercício 02 - Conjectura de Collatz

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA: 759544
	Nome: Vinícius Pereira Aiala

* ================================================================== */


/* <<< COMPLETE AQUI >>> */
#include <stdio.h>
//Este programa calcula a conjectura de Collatz
int main()
{
	//Declaração de variáveis
	int n1 = 1;

	//Calculo da conjectura condicionado
	while (1)
	{
		//Comando de entrada
		scanf("%d", &n1);
		if (n1 == 0)
		{
			return (0);
		} else {
			do {
				printf("%d ", n1);

				//Aplicação da fórmula
				if (n1 % 2 == 0)
				{
					n1 = n1 / 2;
				} else {
					n1 = 3 * n1 + 1;
				}
			} while (n1 != 1);
			printf("%d \n", n1);
		}
	}
	return 0;
}
