/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
   
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 04 - Exercício 01 - Menu de opções e operações aritmeticas
   
    Instrucoes
    ----------
   
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
   
* ================================================================== *
    Dados do aluno:
   
    RA: Vinícius Pereira Aiala
    Nome: 759544
   
* ================================================================== */
 

/* <<< COMPLETE AQUI >>> */
#include <stdio.h>
// Mensagem Pré definida
#define INVALIDO "Opção Inválida!\n"

#include <math.h>

// Este programa realiza a operação selecionada entre dois números inteiros enquanto não recebe o valor de finalização
int main()
{
    //Declaração de variáveis
    int opcao, num_1, num_2, aux1, resultado_d;
    float resultado_f;
    long resultado_li;
    long long int resultado_lli;

    //Comando de entrada
    scanf("%d%d", &num_1, &num_2);

    //Operações e comando de saída condicionados
    while (1) 
    {
     scanf("%d", &opcao);
     switch (opcao) {
        case 0:
            return (0);
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
            if (num_2 != 0){
               resultado_f = (float) num_1 / num_2;
               printf("%.2f\n", resultado_f);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 6:
	        if (num_1 != 0){
               resultado_f = (float) num_2 / num_1;
               printf("%.2f\n", resultado_f);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 7:
            if (num_2 != 0){
               resultado_d = num_1 / num_2;
               printf("%d\n", resultado_d);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 8:
            if (num_1 != 0){
               resultado_d = num_2 / num_1;
               printf("%d\n", resultado_d);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 9:
	        if (num_2 != 0){
               resultado_d = num_1 % num_2;
               printf("%d\n", resultado_d);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 10:
	        if (num_1 != 0){
               resultado_d = num_2 % num_1;
               printf("%d\n", resultado_d);
	        } else {
	           printf(INVALIDO);
	        }
            break;
        case 11:
            resultado_li = pow(num_1, num_2);
            printf("%li\n", resultado_li);
            break;
        case 12:
            resultado_li = pow(num_2, num_1);
            printf("%li\n", resultado_li);
            break;
        case 13:
            for (aux1 = 1, resultado_lli = 1; aux1 <= num_1; aux1++)
            {
                resultado_lli *= aux1;
            }
            printf("%lli\n", resultado_lli);
            break;
        case 14:
            for (aux1 = 1, resultado_lli = 1; aux1 <= num_2; aux1++)
            {
                resultado_lli *= aux1;
            }
            printf("%lli\n", resultado_lli);
            break;
        case 15:
            for (aux1 = 1; aux1 <= num_2; aux1++)
            {
                resultado_d = num_1 * aux1;
                printf("%d\n", resultado_d);
            }
            break;
        case 16:
            for (aux1 = 1; aux1 <= num_1; aux1++)
            {
                resultado_d = num_2 * aux1;
                printf("%d\n", resultado_d);
            }
            break;
        default: 
            printf(INVALIDO);
            break;
        }
    }
}