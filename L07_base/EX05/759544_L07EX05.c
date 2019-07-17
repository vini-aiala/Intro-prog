/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: Algoritmos e Programação 1
    Prof. Tiago A. Almeida

    Lista 07 - Exercício 05 - Ordenações

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

int main() {
    int matriz[20][20], ordem, linha, coluna, auxA, auxB, auxelem;

    scanf("%d", &ordem);

    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            scanf("%d", &matriz[linha][coluna]);
        }
    }

    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            for (auxA = coluna, auxB = coluna + 1; auxB < ordem; auxB++)
            {
                if (matriz[linha][auxA] > matriz[linha][auxB])
                {
                    auxA = auxB;
                }
            }
            auxelem = matriz[linha][coluna];
            matriz[linha][coluna] = matriz[linha][auxA];
            matriz[linha][auxA] = auxelem;
        }
    }

    for (coluna = 0; coluna < ordem; coluna++)
    {
        for (linha = 0; linha < ordem; linha++)
        {
            for (auxA = linha, auxB = linha + 1; auxB < ordem; auxB++)
            {
                if (matriz[auxA][coluna] < matriz[auxB][coluna])
                {
                    auxA = auxB;
                }
            }
            auxelem = matriz[linha][coluna];
            matriz[linha][coluna] = matriz[auxA][coluna];
            matriz[auxA][coluna] = auxelem;
        }
    }

    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

	return 0;
}