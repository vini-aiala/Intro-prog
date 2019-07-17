/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
   
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
   
    Lista 02 - Exercício 03 - IMC
   
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

// Mensagem pre-definidas
#define MGS_ABAIXO  "Abaixo do peso\n"
#define MGS_IDEAL   "Peso Ideal\n"
#define MGS_ACIMA   "Acima do peso\n"
#define MGS_OBESO   "Obeso\n"


 /* <<< COMPLETE AQUI >>> */
// Este programa calcula o IMC e indica a classificação relativa
int main ()
{
	//Declaração de Variáveis
	int peso;
	float altura, IMC;
	char sexo, etaria;

	//Comando de entrada
	scanf("%d%f%*c%c", &peso, &altura, &etaria);

	//Calculo IMC
	IMC = (float) peso / (altura * altura);

	//Condição por faixa etária
	switch (etaria) {
		case 'I':
			//Comando de saida - idosos
			printf("%.2f\n", IMC);
			if (IMC <= 22) {
				printf(MGS_ABAIXO);
			} else {
				if (IMC >= 27) {
					printf(MGS_ACIMA);
				} else {
					printf(MGS_IDEAL);
				}
			}
		break;
		case 'A':
		//Verificar sexo
			scanf("%*c%c", &sexo);
			switch (sexo) {
				case 'M':
				//Comando de saida - adultos masculinos
				printf("%.2f\n", IMC);
				if (IMC <= 20.7) {
					printf(MGS_ABAIXO);
				} else {
					if (IMC >= 31.1) {
						printf(MGS_OBESO);
					} else {
						if (IMC <= 26.4) {
							printf(MGS_IDEAL);
						} else {
							printf(MGS_ACIMA);
						}
					}
				}
				break;
				case 'F':
				//Comando de saida - adultos femininos
				printf("%.2f\n", IMC);
				if (IMC <= 19.1) {
					printf(MGS_ABAIXO);
				} else {
					if (IMC >= 32.3) {
						printf(MGS_OBESO);
					} else {
						if (IMC <= 25.8) {
							printf(MGS_IDEAL);
						} else {
							printf(MGS_ACIMA);
						}
					}
				}
				break;
			}
		break;
		
	}

return 0;
}
