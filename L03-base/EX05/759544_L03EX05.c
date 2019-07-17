/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 03 - Exercício 05 - Inverter números
 
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

#define INICIO "Iniciando a sessão...\n"
#define ENCERRAR "Encerrando a sessão...\n"

int main()
{
    //Declaração das variáveis
    long long int n, n_inv;

    //Mensagem de início
    printf(INICIO);

    while (1)
    {
        //Comando de entrada
        scanf("%lli", &n);

        //Condição de finalização
        if (n == -1)
        {
            printf(ENCERRAR);
            return 0;
        } else {
            //Cálculo do inverso pelo resto da divisão decimal
            n_inv = 0;
            while (n > 10){
                n_inv = (n_inv + (n % 10)) * 10;
                n = n / 10;
            }
            n_inv = (n_inv + n);

            //Comando de saída
            printf("%lli\n", n_inv);
        }

    }
}