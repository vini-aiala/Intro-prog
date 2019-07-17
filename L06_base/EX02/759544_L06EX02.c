/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: IntroduC'C#o a ProgramaC'C#o
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 06 - ExercC-cio 02 - Maiores que a media

    Instrucoes
    ----------

    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
    Dados do aluno:

    RA: 759544
    Nome: VinC-cius Pereira Aiala

* ================================================================== */

#include <stdio.h>

#define MAX 100
#define MSG "nao ha valores maiores que a media"

int main() {    
    int cont, cont2, tamanho, flag;
    long int n_elementos, elementos[MAX], maiores[MAX];
    double media;

    do {
        scanf("%ld", &n_elementos);
    } while (n_elementos < 1 || n_elementos > 100);

    for (cont = 0, media = 0; cont < n_elementos; cont++)
    {
        scanf("%ld", &elementos[cont]);
        media += elementos[cont];
    }

    media /= n_elementos;

    printf("%.3f\n", media);

    for (cont = 0, tamanho = 0; cont < n_elementos; cont++)
    {
        if (elementos[cont] > media)
        {
            for (cont2 = 0, flag = 0; cont2 < tamanho; cont2++)
            {
                if (elementos[cont] == maiores[cont2])
                {
                    flag = 1;
                }
            }
            if (!flag) {
                tamanho++;
                maiores[tamanho - 1] = elementos[cont];
            }
        }
    }
    if (tamanho == 0)
    {
        printf(MSG);
    } else {
        for (cont = tamanho - 1; cont >= 0; cont--)
        {
            printf("%ld ", maiores[cont]);
        }
    }
    return (0);
}