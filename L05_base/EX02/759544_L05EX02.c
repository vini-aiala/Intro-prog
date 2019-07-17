/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi c. Sakata

    Lista 05 - Exercício 02 - Notas

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

/*-----------------------------------
    Definição de mensagens padrão
-----------------------------------*/

#define MAIOR_MEDIA "A maior média é do Aluno com RA %d: %.2f\n"
#define MEDIA_IGUAL "As médias são iguais (%.2f)\n"
#define GRAFOS_PRINT "---Teoria dos Grafos---\n"
#define BD_PRINT "---Banco de Dados---\n"

/*---------------------------------
    Definição de tipo e structs
---------------------------------*/

typedef float Nota;

typedef struct d1 {
    Nota p1;
    Nota p2;
    Nota p3;
    Nota media;
} Grafos;

typedef struct d2 {
    Nota p;
    Nota trabalho;
    Nota media;
} BD;

typedef struct a{
    int RA;
    Grafos disciplina1;
    BD disciplina2;
} Aluno;



int main (){
    Aluno aluno1, aluno2;

    /*------------------------------------------------------------------
        Complete a partir daqui!
        Tente fazer os códigos apenas com as declarações já presentes
    ------------------------------------------------------------------*/
    //Comando de entrada das informações do aluno 1
    scanf("%d%f%f%f%f%f", &aluno1.RA, &aluno1.disciplina1.p1, &aluno1.disciplina1.p2, &aluno1.disciplina1.p3, &aluno1.disciplina2.p, &aluno1.disciplina2.trabalho);

    //Comando de entrada das informações do aluno 2
    scanf("%d%f%f%f%f%f", &aluno2.RA, &aluno2.disciplina1.p1, &aluno2.disciplina1.p2, &aluno2.disciplina1.p3, &aluno2.disciplina2.p, &aluno2.disciplina2.trabalho);

    //Calculo das médias do aluno 1
    aluno1.disciplina1.media = (aluno1.disciplina1.p1 + aluno1.disciplina1.p2 + aluno1.disciplina1.p3) / 3;
    if (aluno1.disciplina2.p >= 6)
    {
        aluno1.disciplina2.media = (aluno1.disciplina2.p / 2) + (aluno1.disciplina2.trabalho / 2);
    } else {
        aluno1.disciplina2.media = (aluno1.disciplina2.p * 0.6) + (aluno1.disciplina2.trabalho * 0.4);
    }

    //Calculo das médias do aluno 2
    aluno2.disciplina1.media = (aluno2.disciplina1.p1 + aluno2.disciplina1.p2 + aluno2.disciplina1.p3) / 3;
    if (aluno2.disciplina2.p >= 6)
    {
        aluno2.disciplina2.media = (aluno2.disciplina2.p / 2) + (aluno2.disciplina2.trabalho / 2);
    } else {
        aluno2.disciplina2.media = (aluno2.disciplina2.p * 0.6) + (aluno2.disciplina2.trabalho * 0.4);
    }

    //Comando de saída com a seleção da maior média
    printf(GRAFOS_PRINT);
    if (aluno1.disciplina1.media > aluno2.disciplina1.media)
        printf(MAIOR_MEDIA, aluno1.RA, aluno1.disciplina1.media);
    else if (aluno1.disciplina1.media == aluno2.disciplina1.media)
        printf(MEDIA_IGUAL, aluno1.disciplina1.media);
    else
        printf(MAIOR_MEDIA, aluno2.RA, aluno2.disciplina1.media);

    printf(BD_PRINT);
    if (aluno1.disciplina2.media > aluno2.disciplina2.media)
        printf(MAIOR_MEDIA, aluno1.RA, aluno1.disciplina2.media);
    else if (aluno1.disciplina2.media == aluno2.disciplina2.media)
        printf(MEDIA_IGUAL, aluno1.disciplina2.media);
    else
        printf(MAIOR_MEDIA, aluno2.RA, aluno2.disciplina2.media);

    return 0;
}