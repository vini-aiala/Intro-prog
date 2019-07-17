/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba

    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 05 - Exercício 05 - Algarismos Romanos

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
//#include <math.h>

//Declaração da estrutura do registro e redefinição do tipo
typedef struct prim
{
    int primo[3];
} Primos;

int main() {   
    //Declaração das variáveis e do registro
    unsigned int cont, cont2, div;
    int flag1, flag2;
	Primos primos;

    while (1)
    {
        scanf("%d", &primos.primo[0]);

        if (primos.primo[0] != 0)
        {
            //Busca dos 3 Primos menores que o número informado
            cont = primos.primo[0] - 1;
            for (cont2 = 1; cont2 <= 3; cont2++)
            {
                for (flag1 = 0; cont == 1 || !flag1; cont--)
                {
                    for (div = 2, flag2 = 0; div <= cont && cont != 1; div++) {
                            if (cont % div == 0 && div != cont) 
                                flag2 = 1;
                    }
                    if (flag2 == 0 && cont != 1) {
                        primos.primo[cont2] = cont;
                        flag1 = 1;
                    }
                }
            }

            //Reinicialização das flags
            flag1 = 0;
            flag2 = 0;

            //Conversão em numerais romanos
            for (cont2 = 0; cont2 <= 3; cont2++)
            {
                while(primos.primo[cont2] != 0)
                {
                    if (primos.primo[cont2] >= 1000)
                    {
                        printf("M");
                        primos.primo[cont2] -= 1000;
                    } else if (primos.primo[cont2] >= 900)
                    {
                        printf("CM");
                        primos.primo[cont2] -= 900;
                    } else if (primos.primo[cont2] >= 500)
                    {
                        printf("D");
                        primos.primo[cont2] -= 500;
                    } else if (primos.primo[cont2] >= 400)
                    {
                        printf("CD");
                        primos.primo[cont2] -= 400;
                    } else if (primos.primo[cont2] >= 100)
                    {
                        printf("C");
                        primos.primo[cont2] -= 100;
                    } else if (primos.primo[cont2] >= 90)
                    {
                        printf("XC");
                        primos.primo[cont2] -= 90;
                    } else if (primos.primo[cont2] >= 50)
                    {
                        printf("L");
                        primos.primo[cont2] -= 50;
                    } else if (primos.primo[cont2] >= 40)
                    {
                        printf("XL");
                        primos.primo[cont2] -= 40;
                    } else if (primos.primo[cont2] >= 10)
                    {
                        printf("X");
                        primos.primo[cont2] -= 10;
                    } else if (primos.primo[cont2] >= 9)
                    {
                        printf("IX");
                        primos.primo[cont2] -= 9;
                    } else if (primos.primo[cont2] >= 5)
                    {
                        printf("V");
                        primos.primo[cont2] -= 5;
                    } else if (primos.primo[cont2] >= 4)
                    {
                        printf("IV");
                        primos.primo[cont2] -= 4;
                    } else if (primos.primo[cont2] >= 1)
                    {
                        printf("I");
                        primos.primo[cont2] -= 1;
                    }
                }
                printf("\n");
            }
        } else {
            return (0); 
        }
    }
}
