/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 06 - Exercício 06 - Operacoes com Conjuntos
 
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
#define MAX 500
#define VAZIO "Vazio!"

int main()
{
    int op, n_eleA = 0, n_eleB = 0, n_eleResult = 0, cont = 0, conjA[MAX], conjB[MAX], conjResult[MAX], auxA = 0, auxB = 0, auxResult = 0, flag = 0;

    while(1)
    {
        //Entrada da opção
        scanf("%d", &op);
        switch(op)
        {
            // Sai do programa
            case 0:
                return 0;
                break;

            // Popula A
            case 1:
                //Entrada da quantidade de elementos
                scanf("%d", &n_eleA);
                for (cont = 0; cont < n_eleA; cont++)
                {
                    //Entrada dos elementos do conjunto
                    scanf("%d", &conjA[cont]);
                    for (auxA = cont - 1; auxA >= 0; auxA--)
                    {
                        //Verificador de repetição de um elemento
                        if (conjA[cont] == conjA[auxA])
                        {
                            //Entrada de um elemento por conta da repetição
                            scanf("%d", &conjA[cont]);
                            auxA = cont;
                        }
                    }
                }
                //Ordenador de forma crescente
                for (cont = 0; cont < n_eleA; cont++)
                {
                    for (auxA = cont, auxB = cont + 1; auxB < n_eleA; auxB++)
                    {
                        if (conjA[auxA] > conjA[auxB])
                        {
                            auxA = auxB;
                        }
                    }
                    auxResult = conjA[cont];
                    conjA[cont] = conjA[auxA];
                    conjA[auxA] = auxResult;
                }
                break; 
            // Popula B
            case 2:
                //Entrada da quantidade de elementos
                scanf("%d", &n_eleB);
                for (cont = 0; cont < n_eleB; cont++)
                {
                    //Entrada dos elementos do conjunto
                    scanf("%d", &conjB[cont]);
                    for (auxA = cont - 1; auxA >= 0; auxA--)
                    {
                        //Verificador de repetição de um elemento
                        if (conjB[cont] == conjB[auxA])
                        {
                            //Entrada de um elemento por conta da repetição
                            scanf("%d", &conjB[cont]);
                            auxA = cont;
                        }
                    }
                }
                //Ordenador de forma crescente
                for (cont = 0; cont < n_eleB; cont++)
                {
                    for (auxA = cont, auxB = cont + 1; auxB < n_eleB; auxB++)
                    {
                        if (conjB[auxA] > conjB[auxB])
                        {
                            auxA = auxB;
                        }
                    }
                    auxResult = conjB[cont];
                    conjB[cont] = conjB[auxA];
                    conjB[auxA] = auxResult;
                }
                break; 
            // Uniao
            case 3:
				//Verificação de casos especiais
                if (n_eleA == 0)
                {
                    for (cont = 0, n_eleResult = 0; cont < n_eleB; cont++)
                    {
                        conjResult[cont] = conjB[cont];
                    }
                    n_eleResult = n_eleB;
                } else if (n_eleB == 0)
                {
                    for (cont = 0; cont < n_eleA; cont++)
                    {
                        conjResult[cont] = conjA[cont];
                    }
                    n_eleResult = n_eleA;
                } else {
                    //Verficação até um conjunto ser completamente comparado 
                    auxA = 0;
                    auxB = 0;
                    auxResult = 0;
                    n_eleResult = 0;            
                    do {
                        if (conjA[auxA] == conjB[auxB])
                        {
                            conjResult[auxResult] = conjA[auxA];
                            auxResult++;
                            n_eleResult++;
                            auxA++;
                            auxB++;
                        } else if (conjA[auxA] > conjB[auxB])
                        {
                            conjResult[auxResult] = conjB[auxB];
                            auxResult++;
                            n_eleResult++;
                            auxB++;
                        } else {
                            conjResult[auxResult] = conjA[auxA];
                            auxResult++;
                            n_eleResult++;
                            auxA++;
                        }
                    } while (auxA < n_eleA && auxB < n_eleB);
                    //Atribuição do restante de um dos conjuntos no conjunto resultante
                    if (auxA != n_eleA)
                    {
                        while (auxA < n_eleA)
                        {
                            conjResult[auxResult] = conjA[auxA];
                            auxResult++;
                            n_eleResult++;
                            auxA++;
                        }
                    }  else if (auxB != n_eleB)
                    {
                        while (auxB < n_eleB)
                        {
                            conjResult[auxResult] = conjB[auxB];
                            auxResult++;
                            n_eleResult++;
                            auxB++;
                        }
                    }
                }
                //Saída do conjunto resultante
                if (n_eleResult == 0)
                {
                    printf(VAZIO);
                } else {
                    for (cont = 0; cont < n_eleResult; cont++)
                    {
                        printf("%d ", conjResult[cont]);
                    }
                }
                printf("\n");
                break;

            // Interseccao
            case 4:
				//Verificação de casos especiais
				if (n_eleA == 0)
                {
                    n_eleResult = 0;  
                } else if (n_eleB == 0)
                {
                        n_eleResult = 0;
                } else {
		            auxA = 0;
                    auxB = 0;
                    auxResult = 0;
                    n_eleResult = 0;            
                    do {
                        if (conjA[auxA] == conjB[auxB])
                        {
                            conjResult[auxResult] = conjA[auxA];
                            auxResult++;
                            n_eleResult++;
                            auxA++;
                            auxB++;
                        } else if (conjA[auxA] > conjB[auxB])
                        {
                            auxB++;
                        } else {
                            auxA++;
                        }
                    } while (auxA < n_eleA && auxB < n_eleB);
				}
                //Saída do conjunto resultante
                if (n_eleResult == 0)
                {
                    printf(VAZIO);
                } else {
                    for (cont = 0; cont < n_eleResult; cont++)
                    {
                        printf("%d ", conjResult[cont]);
                    }
                }
                printf("\n");
                break;

            // Diferenca A - B
            case 5:
                //Verificação de casos especiais
                if (n_eleA == 0)
                {
                    //Se A é vazio, A - B é vazio
                    n_eleResult = 0;
                } else if (n_eleB == 0)
                {
                    //Se B é vazio, A - B = A
                    for (cont = 0, n_eleResult = 0; cont < n_eleA; cont++)
                    {
                        conjResult[cont] = conjA[cont];
                    }
                    n_eleResult = n_eleA;
                } else {
                    //Caso normal:
                	for (cont = 0, n_eleResult = 0; cont < n_eleA; cont++)
                	{
                        //Para cada A, é comparado com todos os elementos de B
                    	for (auxB = 0, auxA = 0; auxB < n_eleB; auxB++)
                    	{
		                    if (conjA[cont] == conjB[auxB])
		                    {
		                        auxA = 1;
		                    }
                    	}
                        //Verifica se não houve igualdade
						if (auxA == 0)
						{
							n_eleResult++;
							conjResult[n_eleResult - 1] = conjA[cont];
						}
                	}
				}
                //Saída do conjunto resultante
                if (n_eleResult == 0)
                {
                    printf(VAZIO);
                } else {
                    for (cont = 0; cont < n_eleResult; cont++)
                    {
                        printf("%d ", conjResult[cont]);
                    }
                }
                printf("\n");
                break;

            // Diferenca B - A
            case 6:
                //Verificação de casos especiais
                if (n_eleA == 0)
                {
                    //Se A é vazio, B - A = B
                    for (cont = 0; cont < n_eleB; cont++)
                    {
                        conjResult[cont] = conjB[cont];
                    }
                    n_eleResult = n_eleB;
                } else if (n_eleB == 0)
                {
                    //Se B é vazio, B - A é vazio
                    n_eleResult = 0;
                } else {
                    //Caso normal:
                    for (cont = 0, n_eleResult = 0; cont < n_eleB; cont++)
                    {
                        //Para cada B, é comparado com todos os elementos de A
                        for (auxB = 0, auxA = 0; auxB < n_eleA; auxB++)
                        {
                            if (conjB[cont] == conjA[auxB])
                            {
                                auxA = 1;
                            }
                        }
                        //Verifica se não houve igualdade
                        if (auxA == 0)
                        {
                            n_eleResult++;
                            conjResult[n_eleResult - 1] = conjB[cont];
                        }
                    }
                }
                //Saída do conjunto resultante
                if (n_eleResult == 0)
                {
                    printf(VAZIO);
                } else {
                    for (cont = 0; cont < n_eleResult; cont++)
                    {
                        printf("%d ", conjResult[cont]);
                    }
                }
                printf("\n");
                break;

            // A contem B?
            case 7:
                //Verificação de casos especiais
                if (n_eleA == 0)
                {
                    //Se A é vazio, ele nao contem apenas o vazio
                    if (n_eleB == 0)
                    {
                        printf("S\n");
                    } else {
                    printf("N\n");
                    }
                } else if (n_eleB == 0)
                {
                    //Se B é vazio, sempre estara contido em A
                    printf("S\n");
                } else {
                    //Caso normal:
                    for (cont = 0, n_eleResult = 0, flag = 0; cont < n_eleB && flag == 0; cont++)
                    {
                        //Para cada B, é comparado com todos os elementos de A
                        for (auxB = 0, auxA = 0; auxB < n_eleA; auxB++)
                        {
                            if (conjB[cont] == conjA[auxB])
                            {
                                auxA = 1;
                            }
                        }
                        //Verifica se não houve igualdade
                        if (auxA == 0)
                        {

                            printf("N\n");
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                    {
                        printf("S\n");
                    }
                }
                break;

            // B contem A?
            case 8:
                //Verificação de casos especiais
                if (n_eleB == 0)
                {
                    //Se B é vazio, ele contem apenas o vazio
                    if (n_eleA == 0)
                    {
                        printf("S\n");
                    } else
                    {
                       printf("N\n"); 
                    }
                } else if (n_eleA == 0)
                {
                    //Se A é vazio, sempre estara contido em B
                    printf("S\n");
                } else {
                    //Caso normal:
                    for (cont = 0, n_eleResult = 0, flag = 0; cont < n_eleA && flag == 0; cont++)
                    {
                        //Para cada A, é comparado com todos os elementos de B
                        for (auxB = 0, auxA = 0; auxB < n_eleB; auxB++)
                        {
                            if (conjA[cont] == conjB[auxB])
                            {
                                auxA = 1;
                            }
                        }
                        //Verifica se não houve igualdade
                        if (auxA == 0)
                        {
                            printf("N\n");
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                    {
                        printf("S\n");
                    }
                }
                break;
        }
    }
}