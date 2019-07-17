/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 07 - Exercício 01 - Campo Minado

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

#define MSG_VENCEU "Voce venceu.\n"
#define MSG_PERDEU "Voce perdeu.\n"
#define MSG_SAIU "O jogador saiu do jogo.\n"

int main() {
    int ordem, campo[10][10], linha, coluna, n_cliques, n_smina = 0, sair = 0;

    //Entrada da ordem da matriz quadrada
    do {
        scanf("%d", &ordem);
    } while (ordem < 2 || ordem > 10);

    //Entrada dos elementos da matriz
    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            do {
                scanf("%d", &campo[linha][coluna]);
            } while (campo[linha][coluna] != 0 && campo[linha][coluna] != 1);
            if (campo[linha][coluna] == 0)
            {
                n_smina++;
            }
        }
    }

    //Entrada da quantidade de cliques
    do {
        scanf("%d", &n_cliques);
    } while (n_cliques > 100 || n_cliques < 1);

    //Entrada das coordenadas e verficação
    do
    {
        if (n_cliques > 0)
        {
            scanf("%d%d", &coluna, &linha);
            linha--;
            coluna--;
            if (campo[linha][coluna] == 0)
            {
                n_smina--;
                n_cliques--;
            } else {
                printf(MSG_PERDEU);
                sair = 1;
            }
        } else {
            printf(MSG_SAIU);
            sair = 1;
        }
        if (n_smina == 0)
        {
            printf(MSG_VENCEU);
            sair = 1;
        }
    } while (!sair);
    return 0;
}