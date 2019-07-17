/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 07 - Exercício 04 - Manipulando matriz
 
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
#define ARRUMADO "Arrumado\n"
#define DESARRUMADO "Desarrumado\n"

int main()
{
    //Declaração das variáveis
    int ordem, matriz[MAX][MAX], qtde_desloc, linha, coluna, cont, flag, aux;
    char opcao, direcao;

    //Entrada da ordem da matriz
    scanf("%d", &ordem);

    //Entrada da matriz
    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            scanf("%d", &matriz[linha][coluna]);
        }
    }

    //Entrada daquiantidade de deslocamentos
    scanf("%d", &qtde_desloc);

    for (cont = 0; cont < qtde_desloc; cont++)
    {
        //Entrada da opção
        scanf("%*c%c", &opcao);

        switch (opcao)
        {
            case 'L':
                //Entrada da linha a ser delocada
                scanf("%d", &linha);
                //Entrada da direção do deslocamento
                scanf("%*c%c", &direcao);
                switch (direcao)
                {
                    case 'E':
                        aux = matriz[linha][0];
                        for (coluna = 1; coluna < ordem; coluna++)
                        {
                            matriz[linha][coluna - 1] = matriz[linha][coluna];
                        }
                        matriz[linha][ordem - 1] = aux;
                        break;
                    case 'D':
                        coluna = ordem - 1;
                        aux = matriz[linha][coluna];
                        for (coluna = ordem - 2; coluna >= 0; coluna--)
                        {
                            matriz[linha][coluna + 1] = matriz[linha][coluna];
                        }
                        matriz[linha][0] = aux;
                        break;
                }
                break;
            case 'C':
                //Entrada da coluna a ser deslocada
                scanf("%d", &coluna);
                //Entrada da direção do deslocamento
                scanf("%*c%c", &direcao);
                switch (direcao)
                {
                    case 'C':
                        aux = matriz[0][coluna];
                        for (linha = 1; linha < ordem; linha++)
                        {
                            matriz[linha - 1][coluna] = matriz[linha][coluna];
                        }
                        matriz[ordem - 1][coluna] = aux;
                        break;
                    case 'B':
                        linha = ordem - 1;
                        aux = matriz[linha][coluna];
                        for (linha = ordem - 2; linha >= 0; linha--)
                        {
                            matriz[linha + 1][coluna] = matriz[linha][coluna];
                        }
                        matriz[0][coluna] = aux;
                        break;
                }
                break;
        }
    }
    
    //Saída da matriz
    for (linha = 0, flag = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    //Verficação do estado da matriz
    for (linha = 0, flag = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            if ((coluna != 0 || linha != 0) && !flag)
            {
                if (coluna == 0)
                {
                    if (matriz[linha][coluna] < matriz[linha - 1][ordem - 1])
                    {
                        flag = 1;
                    } 
                } else if (matriz[linha][coluna] < matriz[linha][coluna - 1])
                {
                    flag = 1;
                }
            }
        }
    }

    //Saída do estado da matriz
    if (!flag)
    {
        printf(ARRUMADO);
    } else {
        printf(DESARRUMADO);
    }

    return(0);
}