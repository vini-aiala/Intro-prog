/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 06 - Exercício 04 - Medidas de Posição
 
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

#define MAX 10
#define ED 1
#define BD 2
#define ALUNO_MEDIA "Média RA %d: %.2f (P1: %.2f. P2: %.2f)\n"
#define MEDIA_GERAL "Média Geral: %.2f\n"
#define ED_LINE "---Estrutura de Dados:\n"
#define BD_LINE "---Bano de Dados:\n"
#define SEM_ALUNOS "Não há alunos inscritos\n"

typedef struct al{
    int ra;
    int disciplina;
    float p1;
    float p2;
    float media;
} Aluno;

int main() {
    Aluno alunos[MAX];

    /* COMPLETE A PARTIR DAQUI
    adicione as variáveis necessárias para lhe auxiliar neste exercício */
    int cont, n_alunos, n_alunos1, n_alunos2, flag = 0;
    float media_g1, media_g2;

    //Entrada do número de alunos
    scanf("%d", &n_alunos);

    //Entrada das informações dos alunos e o cálculo das médias individuais, da soma das notas e da quantidade de alunos de cada disciplina
    for (cont = 0, media_g1 = 0, media_g2 = 0, n_alunos1 = 0, n_alunos2 = 0; cont < n_alunos; cont++)
    {
        scanf("%d%d%f%f", &alunos[cont].ra, &alunos[cont].disciplina, &alunos[cont].p1, &alunos[cont].p2);
        if (alunos[cont].disciplina == 1)
        {
            alunos[cont].media = 0.4 * alunos[cont].p1 + 0.6 * alunos[cont].p2;
            media_g1 += alunos[cont].media;
            n_alunos1++;
        } else {
            alunos[cont].media = 0.5 * alunos[cont].p1 + 0.5 * alunos[cont].p2;
            media_g2 += alunos[cont].media;
            n_alunos2++;
        }
    }

    //Cálculo das médias gerais
    media_g1 /= n_alunos1;
    media_g2 /= n_alunos2;

    //Estrutura de dados
    printf(ED_LINE);
    for (cont = 0, flag = 0; cont < n_alunos; cont++)
    {
        if (alunos[cont].disciplina == 1)
        {
            printf(ALUNO_MEDIA, alunos[cont].ra, alunos[cont].media, alunos[cont].p1, alunos[cont].p2);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf(SEM_ALUNOS);
    } else {
        printf(MEDIA_GERAL, media_g1);
    }

    //Banco de dados
    printf(BD_LINE);
    for (cont = 0, flag = 0; cont < n_alunos; cont++)
    {
        if (alunos[cont].disciplina == 2)
        {
            printf(ALUNO_MEDIA, alunos[cont].ra, alunos[cont].media, alunos[cont].p1, alunos[cont].p2);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf(SEM_ALUNOS);
    } else {
        printf(MEDIA_GERAL, media_g2);
    }
    return 0;
}