/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Introdução a Programação
	Prof. Tiago A. Almeida
	Profa. Tiemi C. Sakata

	Lista 03 - Exercício 03 - Anos Bissextos

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

//Definindo a frase de erro
#define FRASE_ERRO "Erro: O primeiro ano deve ser menor que o segundo.\n" 

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main(){
	//Declaração das variáveis
	int ano1 = 1, ano2 = 1, qtde_bissextos = 0;

	while (1)
	{
		//Comando de entrada e inicialização do contador
		scanf("%d", &ano1);
		scanf("%d", &ano2);
		qtde_bissextos = 0;

		if ((ano1 == 0 && ano2 == 0))
		{
			return (0);
		} else if (ano1 > ano2)
			{
				printf(FRASE_ERRO);
			} else {
				while (ano1 <= ano2)
				{ 
					//Verificação se é um ano bissexto
					if (!((ano1 % 4 != 0) || (ano1 % 4 == 0) && (ano1 % 100 == 0) && (ano1 % 400 != 0))) {
						qtde_bissextos ++;
						printf("%d ", ano1);
						ano1++;
					} else {
						ano1++;
					}
				}
				printf("\n%d\n", qtde_bissextos);
			}
	}
}	