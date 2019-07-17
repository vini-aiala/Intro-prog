/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 05 - Exercício 03 - Dia da Semana
 
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
#define SEGUNDA "Segunda-feira\n"
#define TERCA "Terça-feira\n"
#define QUARTA "Quarta-feira\n"
#define QUINTA "Quinta-feira\n"
#define SEXTA "Sexta-feira\n"
#define SABADO "Sabado\n"
#define DOMINGO "Domingo\n"
#define ERRO "Data invalida\n"

enum { Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez };

enum { Seg = 0, Ter, Qua, Qui, Sex, Sab, Dom };

typedef struct data
{
	// Implementar a struct
    int dia;
    int mes;
    int ano;
} Data;

int main()
{
	// COMPLETE A PARTIR DAQUI
    int A, B, C, D, result, qtde, cont;
	
	Data dia_da_semana;	

    //Comando de entrada da quantidade de datas
    scanf("%d", &qtde);

    //Loop condicionado
    for (cont = 0; cont < qtde; cont++)
    {
        //Comando de entrada das datas
    	scanf("%d/%d/%d", &dia_da_semana.dia, &dia_da_semana.mes, &dia_da_semana.ano);

    	//Verficador da vailidez das datas
        if (!(((dia_da_semana.mes == Abr || dia_da_semana.mes == Jun || dia_da_semana.mes == Set || dia_da_semana.mes == Nov) && dia_da_semana.dia > 30) || ((dia_da_semana.mes == Fev) && ((!((dia_da_semana.ano % 4 == 0 && dia_da_semana.ano % 100 != 0) || dia_da_semana.ano % 400 == 0)) && (dia_da_semana.dia > 28) || (dia_da_semana.dia > 29)))) && (dia_da_semana.ano >= 1900 && dia_da_semana.ano <= 2399))
        {
            //Cálculo dos valores A, B, C e D
            A = dia_da_semana.ano - 1900;
            B = A / 4;
            if (dia_da_semana.ano % 4 == 0 && (dia_da_semana.mes == Fev || dia_da_semana.mes == Jan))
                B--;
            C = dia_da_semana.mes;
            if (C == Jan || C == Out)
            {
                C = 0;
            } else if (C == Mai)
            {
                C = 1;
            } else if (C == Ago)
            {
                C = 2;
            } else if (C == Fev || C == Mar || C == Nov)
            {
                C = 3;
            } else if (C == Jun)
            {
                C = 4;
            } else if (C == Set || C == Dez)
            {
                C = 5;
            } else if (C == Abr || C == Jul)
            {
                C = 6;
            }
            D = dia_da_semana.dia - 1;
            result = (A + B + C + D) % 7;

            if(dia_da_semana.ano > 2100)

            //Comando de saída baseado no dia da semana
            switch(result) {
                case Seg:
                    printf(SEGUNDA);
                    break;
                case Ter:
                    printf(TERCA);
                    break;
                case Qua:
                    printf(QUARTA);
                    break;
                case Qui:
                    printf(QUINTA);
                    break;
                case Sex:
                    printf(SEXTA);
                    break;
                case Sab:
                    printf(SABADO);
                    break;
                case Dom:
                    printf(DOMINGO);
                    break;
                case -1:
                    printf(SEGUNDA);
                    break;
            }
        } else {
            printf(ERRO);
        }
    }

    return(0);
}