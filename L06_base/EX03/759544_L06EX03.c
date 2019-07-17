/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 06 - Exercício 03 - Manipulação de Vetor
 
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

#define MAX 100

int main() {
	int vetor[MAX];
    
    // Modifique aqui
    int opcao, tamanho, qtde_num, posicao, cont;
    int sair = 0;

    do {
        scanf("%d", &tamanho);
    } while (tamanho < 1 || tamanho > 100);

    for (cont = 0; cont < tamanho; cont++)
    {
        scanf("%d", &vetor[cont]);
    }
    while(!sair) {
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                scanf("%d%d", &qtde_num, &posicao);
                tamanho += qtde_num;
                if (posicao >= 0){
                    for (cont = tamanho - 1; cont >= posicao + qtde_num; cont--)
                    {
                        vetor[cont] = vetor[cont - qtde_num];
                    }
                    for (cont = posicao; cont < posicao + qtde_num; cont++)
                    {
                        scanf("%d", &vetor[cont]);
                    }
                } else {
                    for (cont = tamanho - qtde_num; cont < tamanho; cont++)
                    {
                        scanf("%d", &vetor[cont]);
                    }
                }
                break;
            case 2:
                scanf("%d%d", &qtde_num, &posicao);
                tamanho -= qtde_num;
                if (posicao >= 0){
                    for (cont = posicao; cont < tamanho; cont++)
                    {
                        vetor[cont] = vetor[cont + qtde_num];
                    }
                }
                break;
            case 0:
                sair = 1;
                break;
        }
        if (!sair)
        {
            for (cont = 0; cont < tamanho; cont++)
            {
                printf("%d ", vetor[cont]);
            }
            printf("\n");
        }
    }
	return 0;
}