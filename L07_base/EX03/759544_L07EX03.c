/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 07 - Exercício 03 - Jogo tático

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

#define TAM 10
#define INVALIDA "Opção Inválida!\n"
#define PERDAS "Foram perdidas %d unidades.\n"
#define SEM_PERDAS "Não houveram perdas!\n"
#define ATUAL "Há um total de %d unidades em campo.\n"
#define AUMENTO "A tropa aumentou em %d unidades desde o início.\n"
#define DIMINUI "A tropa diminuiu em %d unidades desde o início.\n"
#define IGUAL "A tropa se manteve com o mesmo número.\n"

int main() {

	int mapa[TAM][TAM], qtde_linhas, qtde_colunas, qtde_inicial, sair = 0, opcao, n_unidades, linha1, coluna1, linha2, coluna2, cont1, cont2, soma_unidades = 0, perdidas = 0;

    scanf("%d%d", &qtde_linhas, &qtde_colunas);

    for (cont1 = 0; cont1 < qtde_linhas; cont1++)
    {
        for (cont2 = 0; cont2 < qtde_colunas; cont2++)
        {
            scanf("%d", &mapa[cont1][cont2]);
            soma_unidades += mapa[cont1][cont2];
            qtde_inicial = soma_unidades;
        }
    }

    while (!sair){
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                scanf("%d%d%d", &n_unidades, &linha1, &coluna1);
                linha1--;
                coluna1--;
                mapa[linha1][coluna1] += n_unidades;
                soma_unidades += n_unidades;
                break;
            case 2:
                scanf("%d%d%d", &n_unidades, &linha1, &coluna1);
                linha1--;
                coluna1--;
                mapa[linha1][coluna1] -= n_unidades;
                perdidas += n_unidades;
                soma_unidades -= n_unidades;
                break;
            case 3:
                scanf("%d%d%d%d%d", &n_unidades, &linha1, &coluna1, &linha2, &coluna2);
                linha1--;
                coluna1--;
                linha2--;
                coluna2--;
                mapa[linha1][coluna1] -= n_unidades;
                mapa[linha2][coluna2] += n_unidades;
                break;
            case 4:
                for (cont1 = 0; cont1 < qtde_linhas; cont1++)
                {
                    for (cont2 = 0; cont2 < qtde_colunas; cont2++)
                    {
                        printf("%d ", mapa[cont1][cont2]);
                    }
                    printf("\n");
                }
                printf(ATUAL, soma_unidades);
                break;
            case 5:
                if (perdidas > 0)
                {
                    printf(PERDAS, perdidas);
                } else {
                    printf(SEM_PERDAS);
                }
                if (soma_unidades > qtde_inicial)
                {
                    printf(AUMENTO, soma_unidades - qtde_inicial);
                } else if (soma_unidades == qtde_inicial)
                {
                    printf(IGUAL);
                } else {
                    printf(DIMINUI, qtde_inicial - soma_unidades);
                }
                for (cont1 = 0, soma_unidades = 0; cont1 < qtde_linhas; cont1++)
                {
                    for (cont2 = 0; cont2 < qtde_colunas; cont2++)
                    {
                        printf("%d ", mapa[cont1][cont2]);
                    }
                    printf("\n");
                }
                sair = 1;
                break;
            default:
                printf(INVALIDA);
                break;
        }
    }

	return (0);
}
