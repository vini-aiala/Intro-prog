/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Introdução a Programação
	Prof. Tiago A. Almeida
	Profa. Tiemi C. Sakata

	Lista 03 - Exercício 04 - Método de Heron

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

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main()
{
	int n1, n2, contador;
	float k;

	//Comando de entrada
	scanf("%d %d", &n1, &n2);
	if (n1 > n2)
	{
		while (n2 <= n1)
		{
			//Cálculo da raiz pela fórmula
			k = 1;

			while (contador <= 10)
			{
				k = (k + ((float)n2 / k)) / 2.00;
				contador ++;
			}

		contador = 0;
		//Comando de saída
		printf("%.2f\n", k);
		n2 ++;
		}
	} else {
		//Determinação da quantidade de raízes a serem calculadas
		while (n1 <= n2)
		{
			//Cálculo da raiz pela fórmula
			k = 1;

			while (contador <= 10)
			{
				k = (k + ((float)n1 / k)) / 2.00;
				contador ++;
			}

		contador = 0;
		//Comando de saída
		printf("%.2f\n", k);
		n1 ++;
		}
	}
	return (0);
}
