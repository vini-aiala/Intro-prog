/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
  
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
  
    Lista 02 - Exercício 05 - Orçamento Peças Computador
  
    Instrucoes
    ----------
  
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
  
* ================================================================== *
    Dados do aluno:
  
    RA:759544
    Nome:Vinícius Pereira Aiala
  
* ================================================================== */
 
 
/* <<< COMPLETE AQUI >>> */
//Este programa estipula o valor final do orçamento
#include <stdio.h>
int main()
{
    //Declaração de variáveis
    int CPU, GPU;
    char modelo, MB;
    float valor, valor_GPU;

    //Comando de entrada
    scanf("%d %d %c %c", &CPU, &GPU, &modelo, &MB);

    //Inicialização de variáveis
    valor_GPU = 0;
    valor = 0;

    //Conversão minusculo - maiusculo
    if ((modelo > 96) || (MB > 96))
    {
        if (modelo > 96)
        {
            modelo = modelo - 32;
        }
        if (MB > 96)
        {
            MB = MB - 32;
        }
    }

    //Processador
    switch (CPU)
    {
        case 3:
            valor = valor + 300.99;
        break;
        case 5:
            valor = valor + 555.55;
        break;
        case 7:
            valor = valor + 877.99;
        break;
        default:
            valor = valor + 0;
        break;
    }

   //Placa de vídeo
    switch (GPU)
    {
        case 1050:
            valor = valor + 768.5;
            valor_GPU = 768.5;
        break;
        case 1060:
            valor = valor + 1397;
            valor_GPU = 1397;
        break;
        case 1070:
            valor = valor + 2550.99;
            valor_GPU = 2550.99;
        break;
        case 1080:
            valor = valor + 3050;
            valor_GPU = 3050;
        break;
        default:
            valor = valor + 0;
            valor_GPU = 0;
        break;
    }

    //Modelo da placa
    switch (modelo)
    {
        case 'S':
            valor = valor + (valor_GPU * 0.2);
        break;
        default:
            valor = valor + 0;
        break;
    }
    
    //Placa-mãe
    switch (MB)
    {
        case 'G':
            valor = valor + 359;
        break;
        case 'A':
            valor = valor + 520.2;
        break;
        case 'R':
            valor = valor + 670.7;
        break;
        case 'M':
            valor = valor + 1170.5;
        break;
        default:
            valor = valor + 0;
        break;
    }
    
    //Condições finais
    if ((CPU == 7) && (GPU >= 1070)) 
    {
        valor = valor + (valor * 0.2);
    } else if ((CPU == 5) || (GPU > 0))
    {
        valor = valor + (valor * 0.1);
    }
    
    //Comando de saída
    printf("%.2f\n", valor);

    return 0;
}