/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
   
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata

    Lista 03 - Exercício 06 - Decomposição em números primos
   
    Instrucoes
    ----------
   
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
   
* ================================================================== *
    Dados do aluno:
   
    RA: 759544
    Nome: Vinícius Pereira Aiala
   
* ================================================================== */
  
  
/* <<< COMPLETE AQUI >>> */
#include<stdio.h>

int main(){

    //Declaração das variáveis e incializações
    int n_primo = 2, n;
    int flag, flag2 = 1;
    int div;

    //Comando de entrada
    scanf("%d", &n);

    //Cálculo de primos
    while (n != 1){
        //Exclusão de pares
        if (n_primo <= 1 || (n_primo != 2 && n_primo % 2 == 0))
            flag = 0;
        else
            flag = 1;   

        //Cálculo dos números primos pela divisão do número até sua metade 
        div = 3;
        while (flag && div <= n_primo/2){
            if (n_primo % div == 0)
            {
                flag = 0;
            }
            div += 2;
        }
    
        //Comando de saída do prmeiro número
        if (flag2 && n % n_primo == 0)
        {
            printf("%d", n_primo);
            n = n / n_primo;
            flag2 = 0;
        }

        //Comando de saída dos outros números
        if (flag)
            while (n % n_primo == 0)
            {
                printf(" %d", n_primo);
                n = n / n_primo;
            }

        //Próximo número primo
        n_primo ++;
    }

    //Quebra de linha
    printf("\n");
    return 0;
}