/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
  
    Lista 02 - Exercício 04 - Notas Finais
  
    Instrucoes
    ----------
  
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
  
* ================================================================== *
    Dados do aluno:
  
    RA:759544
    Nome:Vinícius Pereira Aiala
  
* ================================================================== */
 

#include <stdio.h>

#define MF_AABAIXO "MF < 6.0: %.1lf\n"
#define APROVADO "Aprovado\n"
#define REPROVADO "Reprovado\n"
#define SAC "SAC\n"
#define INVALIDO "Opção Inválida!\n"

/* <<< COMPLETE AQUI >>> */
//Este programa calcula a média do aluno em determinada disciplina e apresenta sua situação
int main()
{
    //Declaração de variáveis
    int disciplina;
    double nota1, nota2, nota3, media, auxiliar, arredondar;
    //Comando de entrada
    scanf("%d", &disciplina);
    //Seleção da disciplina
    switch (disciplina) {
        case 1 :
            //Teoria dos Grafos
            scanf("%lf %lf %lf", &nota1, &nota2, &nota3);
            media = ((3 * nota1 + 3 * nota2 + 4 * nota3) / 10);
			if (media > 10)
            {
                media = 10;
            }
            break;
        case 2 :
            //Banco de Dados
            scanf("%lf %lf %lf", &nota1, &nota2, &nota3);
            media = ((4 * nota1 + 6 * nota2) / 10);
            if (media >= 5)
            {
                media = (media + nota3) / 2;
            } else {
                media = ((7 * media + 3 * nota3) / 10);
            }
            break;
        case 3 :
            //Teoria da Computação
            scanf("%lf %lf", &nota1, &nota2);
            media = ((nota1 + nota2) / 2 );
            if (media < 6) 
            {
                printf(MF_AABAIXO, media);
                scanf("%lf", &nota3);
                if (nota1 >= nota2)
                {
                	if (nota3 >= nota2)
                	{
                    	media = ((nota1 + nota3) / 2 );
                	}
                } else {
                	if (nota3 >= nota1)
                    media = ((nota2 + nota3) / 2 );
                }
            }
            break;

        default :
            printf(INVALIDO);
            return 0;
    }

    //Comando de saída
    printf("%.1lf\n", media);
    if (media >= 6)
    {
        printf(APROVADO);
    } else if (media < 5)
        {
            printf(REPROVADO);
        } else {
            printf(SAC);
        
    }
    return 0;
}

