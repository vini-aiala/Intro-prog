/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
   
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
   
    Lista 02 - Exercício 02 - Geometria Plana Triângulos
   
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
//mensagem de erro
#define INVALIDO "Não é possível formar um triângulos\n"

/* <<< COMPLETE AQUI >>> */
// Este programa verifica diferentes propriedades do triangulo baseado em suas informações fornecidas pelo usuário
int main () 
{
	//Declaração de Variáveis
	float valor1, valor2, valor3;
	char indicador;

	//Comando de entrada
	scanf("%f %f %f%*c%c", &valor1, &valor2, &valor3, &indicador);

	//Operação
	switch (indicador) {
		case 'A':
			//Condição de existência usando angulos
			if ((valor1 + valor2 + valor3) == 180) {
				//Verificar propriendade do triângulo
				if ((valor1 == 90) || (valor2 == 90) || (valor3 == 90)) {
					printf("R\n");
				} else { 
					if ((valor1 > 90) || (valor2 > 90) || (valor3 > 90)) {
						printf("O\n");
					} else { 
						printf("A\n");
					}
				}
			} else {
				printf(INVALIDO);
			}
		break;
		case 'L':
			//Condição de existência do triangulo usando lados
			if ((valor1 < (valor2 + valor3)) && (valor2 < (valor1 + valor3)) && (valor3 < (valor1 + valor2)) && (valor1 > 0) && (valor2 > 0) && (valor3 > 0)) {
				//Verificar propriendade do triângulo
				if ((valor1 == valor2) && (valor2 == valor3)) {
					printf("E\n");
				} else {
					if ((valor1 == valor2) || (valor1 == valor3)) {
						printf("I\n");
					} else {
						printf("S\n");
					}
				}
			} else {
				printf(INVALIDO);
			}
		break;
	}

return 0;
}

			 
