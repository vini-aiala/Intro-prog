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
    int primo1;
    int primo2;
    int primo3;
} Primos;

int main() {   
    //Declaração das variáveis e do registro
    unsigned int num, cont, div;
    int flag1, flag2;
	Primos primos;

    while (1)
    {
        scanf("%d", &num);

        if (num > 5 && num < 4000)
        {
            //Busca dos 3 Primos menores que o número informado
            cont = num - 1;
            for (flag1 = 0; cont == 1 || !flag1; cont--)
            {
                for (div = 2, flag2 = 0; div <= cont && cont != 1; div++) {
                        if (cont % div == 0 && div != cont) 
                            flag2 = 1;
                }
                if (flag2 == 0 && cont != 1) {
                    primos.primo1 = cont;
                    flag1 = 1;
                }
            }

            for (flag1 = 0; cont == 1 || !flag1; cont--)
            {
                for (div = 2, flag2 = 0; div <= cont && cont != 1; div++) {
                        if (cont % div == 0 && div != cont) 
                            flag2 = 1;
                }
                if (flag2 == 0 && cont != 1) {
                    primos.primo2 = cont;
                    flag1 = 1;
                }
            }

            for (flag1 = 0; cont == 1 || !flag1; cont--)
            {
                for (div = 2, flag2 = 0; div <= cont && cont != 1; div++) {
                        if (cont % div == 0 && div != cont) 
                            flag2 = 1;
                }
                if (flag2 == 0 && cont != 1) {
                    primos.primo3 = cont;
                    flag1 = 1;
                }
            }

            //Reinicialização das flags
            flag1 = 0;
            flag2 = 0;
            //Conversão em numerais romanos
            while(num != 0)
            {
                if (num >= 1000)
                {
                    printf("M");
                    num -= 1000;
                } else if (num >= 900)
                {
                    printf("CM");
                    num -= 900;
                } else if (num >= 500)
                {
                    printf("D");
                    num -= 500;
                } else if (num >= 400)
                {
                    printf("CD");
                    num -= 400;
                } else if (num >= 100)
                {
                    printf("C");
                    num -= 100;
                } else if (num >= 90)
                {
                    printf("XC");
                    num -= 90;
                } else if (num >= 50)
                {
                    printf("L");
                    num -= 50;
                } else if (num >= 40)
                {
                    printf("XL");
                    num -= 40;
                } else if (num >= 10)
                {
                    printf("X");
                    num -= 10;
                } else if (num >= 9)
                {
                    printf("IX");
                    num -= 9;
                } else if (num >= 5)
                {
                    printf("V");
                    num -= 5;
                } else if (num >= 4)
                {
                    printf("IV");
                    num -= 4;
                } else if (num >= 1)
                {
                    printf("I");
                    num -= 1;
                }

                if (num == 0)
                {
                    if (!flag1) {
                        num = primos.primo1;
                        flag1 = 1;
                        printf("\n");
                    } else if (!flag2)
                    {
                        num = primos.primo2;
                        flag2 = 1;
                        printf("\n");
                    } else {
                        num = primos.primo3;
                        primos.primo3 = 0;
                        printf("\n");
                    }
                }
            }
        } else {
            return (0); 
        }
    }
}
