/* ================================================================== *
  Universidade Federal de Sao Carlos - UFSCar, Sorocaba

  Disciplina: Introdução a Programação
  Prof. Tiago A. Almeida
  Profa. Tiemi C. Sakata

  Lista 07 - Exercício 02 - Operaação com uma Matriz

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
#define INVALIDO "Operção Inválida!\n"
#define IDENT "A matriz é identidade\n"
#define NAO_IDENT "A matriz não é identidade\n"
#define SIMETRICA "A matriz é simétrica\n"
#define NAO_SIMETRICA "A matriz não é simétrica\n"
#define ESPARSA "A matriz é esparsa\n"
#define NAO_ESPARSA "A matriz não é esparsa\n"
#define TRIANGULAR_UPP "A matriz é triangular superior\n"
#define TRIANGULAR_DOWN "A matriz é triangular inferior\n"
#define NAO_TRIANGULAR "A matriz não é triangular\n"

typedef enum op {sair = 0, soma, mult, transposta, identidade, simetrica, esparsa, triangular, imprimir}Operacoes;


#include <stdio.h>

int main() {
    int matriz[MAX][MAX], ordem, linha, coluna, opcao, escalar, flag, flag2, cont_zero;

    do {
        scanf("%d", &ordem);
    } while (ordem <= 0 || ordem > 100);

    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            scanf("%d", &matriz[linha][coluna]);
        }
    }

    while (1)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
            case sair:
                return(0);
                break;

            case soma:
                scanf("%d", &escalar);
                for (linha = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < ordem; coluna++)
                    {
                        matriz[linha][coluna] += escalar;
                    }
                }
                break;

            case mult:
                scanf("%d", &escalar);
                for (linha = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < ordem; coluna++)
                    {
                        matriz[linha][coluna] *= escalar;
                    }
                }
                break;

            case transposta:
                for (coluna = 0; coluna < ordem; coluna++)
                {
                    for (linha = 0; linha < ordem; linha++)
                    {
                        printf("%02d ", matriz[linha][coluna]);
                    }
                    printf("\n");
                }
                break;

            case identidade:
                for (linha = 1, flag = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < linha; coluna++)
                    {
                        if (matriz[linha][coluna] != 0 && !flag)
                        {
                            flag = 1;
                        }
                    }
                }
                for (coluna = 1; coluna < ordem; coluna++)
                {
                    for (linha = 0; linha < coluna; linha++)
                    {
                        if (matriz[linha][coluna] != 0 && !flag)
                        {
                            flag = 1;
                        }
                    }
                }
                for (coluna = 1; coluna < ordem; coluna++)
                {
                    if (matriz[coluna][coluna] != 1 && !flag)
                    {
                        flag = 1;
                    }
                }
                if (!flag)
                {
                    printf(IDENT);
                } else {
                    printf(NAO_IDENT);
                }
                break;

            case simetrica:
                for (linha = 0, flag = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < ordem; coluna++)
                    {
                        if (matriz[linha][coluna] != matriz[coluna][linha])
                        {
                            flag = 1;
                        }
                    }
                }
                if (!flag)
                {
                    printf(SIMETRICA);
                } else {
                    printf(NAO_SIMETRICA);
                }
                break;

            case esparsa:
                for (linha = 0, flag = 0, cont_zero = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < ordem; coluna++)
                    {
                        if (matriz[linha][coluna] == 0)
                        {
                            cont_zero++;
                        }
                    }
                }
                if (cont_zero >= (ordem * ordem / 2))
                {
                    printf(ESPARSA);
                } else {
                    printf(NAO_ESPARSA);
                }
                break;

            case triangular:
                for (linha = 1, flag = 0, flag2 = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < linha; coluna++)
                    {
                        if (matriz[linha][coluna] != 0 && !flag)
                        {
                            flag = 1;
                        }
                    }
                }
                if (!flag)
                {
                    printf(TRIANGULAR_UPP);
                    flag2 = 1;
                }
                for (coluna = 1, flag = 0; coluna < ordem; coluna++)
                {
                    for (linha = 0; linha < coluna; linha++)
                    {
                        if (matriz[linha][coluna] != 0 && !flag)
                        {
                            flag = 1;
                        }
                    }
                }
                if (!flag)
                {
                    printf(TRIANGULAR_DOWN);
                    flag2 = 1;
                }
                if (!flag2)
                {
                    printf(NAO_TRIANGULAR);
                }
                break;

            case imprimir:
                for (linha = 0, flag = 0; linha < ordem; linha++)
                {
                    for (coluna = 0; coluna < ordem; coluna++)
                    {
                        printf("%02d ", matriz[linha][coluna]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf(INVALIDO);
                break;

        }
    }

    return (0);
}
