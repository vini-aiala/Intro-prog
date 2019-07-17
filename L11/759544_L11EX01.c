/* ================================================================== *
Universidade Federal de Sao Carlos - UFSCar, Sorocaba

Disciplina: Introdução à Programação
Prof. Tiago A. Almeida
Profa. Tiemi C. Sakata

Lista 11 - Exercício 01 - Campeonato de Futebol (Arquivos Binarios)

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
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_NOME_CAMPEONATO 30
#define TAM_NOME_ARQUIVO 	50
#define ARQUIVO_N_ENCONTRADO "Arquivo %s nao encontrado\n"

#define OPCAO_CRIAR_CAMPEONATO 			1
#define OPCAO_CALCULAR_RESULTADOS		2
#define OPCAO_CALCULAR_PONTOS			3
#define OPCAO_SALVAR_GOLS_POR_JOGADOR 	4
#define OPCAO_GERAR_GOLS_POR_TIME 		5
#define OPCAO_GERAR_ARTILHEIROS 		6
#define OPCAO_GERAR_TABELA_GERAL 		7
#define OPCAO_SAIR 						0

void criar_campeonato(char nome_campeonato[]);
void calcular_resultados(char nome_campeonato[]);
void calcular_pontos(char nome_campeonato[]);
void salvar_gols_por_jogador(char nome_campeonato[]);
void gerar_gols_por_time(char nome_campeonato[]);
void gerar_artilheiros(char nome_campeonato[]);
void gerar_tabela_geral(char nome_campeonato[]);

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */

int main() {
    int opcao;
    char nome_campeonato[TAM_NOME_CAMPEONATO];

    while (scanf("%d", &opcao) != EOF && opcao != OPCAO_SAIR) {
        scanf("\n%[^\n]s", nome_campeonato);

        switch (opcao) {
        case OPCAO_CRIAR_CAMPEONATO:
            criar_campeonato(nome_campeonato);
            break;
        case OPCAO_CALCULAR_RESULTADOS:
            calcular_resultados(nome_campeonato);
            break;
        case OPCAO_CALCULAR_PONTOS:
            calcular_pontos(nome_campeonato);
            break;
        case OPCAO_SALVAR_GOLS_POR_JOGADOR:
            salvar_gols_por_jogador(nome_campeonato);
            break;
        case OPCAO_GERAR_GOLS_POR_TIME:
            gerar_gols_por_time(nome_campeonato);
            break;
        case OPCAO_GERAR_ARTILHEIROS:
            gerar_artilheiros(nome_campeonato);
            break;
        case OPCAO_GERAR_TABELA_GERAL:
            gerar_tabela_geral(nome_campeonato);
            break;
        }
    }

    return 0;
}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* <<< IMPLEMENTE AS FUNCOES AQUI >>> */
void criar_campeonato(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int qtde_times, qtde_jogos, i;
	char nome_arquivo[TAM_NOME_ARQUIVO], jogo[6];
	FILE *campeonato;

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Campeonato.txt");

	//Abertura do arquivo
	campeonato = fopen(nome_arquivo, "wb");

	// Entrada da quantidade de times e da de jogos
	scanf("%d %d", &qtde_times, &qtde_jogos);
	fprintf(campeonato, "%d %d\n", qtde_times, qtde_jogos);
	

	//Entrada dos jogos do campeonato
	for (i = 0; i < qtde_jogos; i++)
	{
		scanf("\n%[^\n]s", jogo);
		fputs(jogo, campeonato);
		fputc('\n', campeonato);
	}

	//Fechamento do arquivo
	fclose(campeonato);
}

void calcular_resultados(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int time_a, time_b, qtde_times, qtde_jogos, i, j;
	char arquivo_existente[TAM_NOME_ARQUIVO], nome_arquivo[TAM_NOME_ARQUIVO], estado;
	FILE *campeonato, *resultados;

	//Definicao do nome do arquivo a ser procurado
	strcpy(arquivo_existente, nome_campeonato);
	strcat(arquivo_existente, " - Campeonato.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Resultados.txt");

	//Possível abertura do arquivo
	campeonato = fopen(arquivo_existente, "r");

	//Verificação da existencia do arquivo
	if (campeonato == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arquivo_existente);
		return;
	}

	//Abertura do arquivo de resultados
	resultados = fopen(nome_arquivo, "w");
	
	//Leitura da quantidade de times e da de jogos
	fscanf(campeonato, "%d%*c%d", &qtde_times, &qtde_jogos);
	
	//Declaração da matriz dos resultados e inicialização
	int result[qtde_times][3];
	for (i = 0; i < qtde_times; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j] = 0;
		}
	}

	//Calculo dos resultados
	while (fscanf(campeonato, "%d%*c%c%*c%d", &time_a, &estado, &time_b) != EOF)
	{
		switch (estado)
		{
			case '-':
				result[time_a - 1][2]++;
				result[time_b - 1][2]++;
				break;
			case 'x':
				result[time_a - 1][0]++;
				result[time_b - 1][1]++;
				break;
		}
	}
	
	//Escrita dos resultados no arquivo
	for (i = 0; i < qtde_times; i++)
	{
		fprintf(resultados, "%d %d %d", result[i][0], result[i][1], result[i][2]);
		fputc('\n', resultados);

	}
	
	//Fechamento dos arquivos
	fclose(campeonato);
	fclose(resultados);
}

void calcular_pontos(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int vitorias, derrotas, empates, soma, i, j;
	char arquivo_existente[TAM_NOME_ARQUIVO], nome_arquivo[TAM_NOME_ARQUIVO];
	FILE *resultados, *pontos;

	//Definicao do nome do arquivo a ser procurado
	strcpy(arquivo_existente, nome_campeonato);
	strcat(arquivo_existente, " - Resultados.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Pontos.txt");

	//Possível abertura do arquivo
	resultados = fopen(arquivo_existente, "r");

	//Verificação da existencia do arquivo
	if (resultados == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arquivo_existente);
		return;
	}

	//Abertura do arquivo de resultados
	pontos = fopen(nome_arquivo, "w");

	//Calculo dos pontos e escrita dos resultados no arquivo
	
	while(fscanf(resultados, "%d%*c%d%*c%d", &vitorias, &derrotas, &empates) != EOF)
	{
		soma = (3 * vitorias + empates);
		fprintf(pontos, "%d\n", soma);
	}

	//Fechamento dos arquivos
	fclose(resultados);
	fclose(pontos);
}

void salvar_gols_por_jogador(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int qtde_times, i, j, gols;
	char arquivo_existente[TAM_NOME_ARQUIVO], nome_arquivo[TAM_NOME_ARQUIVO];
	FILE *campeonato, *gol_jogador;

	//Definicao do nome do arquivo a ser procurado
	strcpy(arquivo_existente, nome_campeonato);
	strcat(arquivo_existente, " - Campeonato.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Gols por jogador.txt");

	//Possível abertura do arquivo
	campeonato = fopen(arquivo_existente, "r");

	//Verificação da existencia do arquivo
	if (campeonato == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arquivo_existente);
		return;
	}

	//Abertura do arquivo de gols por jogador
	gol_jogador = fopen(nome_arquivo, "w");

	//Verficacao da quantidade de times
	fscanf(campeonato, "%d", &qtde_times);

	//Entrada e escrita da quantidade de gols realizados por cada jogador do time
	for (i = 0; i < qtde_times; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &gols);
			fprintf(gol_jogador, "%d ", gols);
		}
		scanf("%d", &gols);
		fprintf(gol_jogador, "%d", gols);
		fputc('\n', gol_jogador);
	}
	
	//Fechamento dos arquivos
	fclose(campeonato);
	fclose(gol_jogador);
}

void gerar_gols_por_time(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int gols, cont = 0, soma = 0;
	char arquivo_existente[TAM_NOME_ARQUIVO], nome_arquivo[TAM_NOME_ARQUIVO];
	FILE *gol_jogador, *gol_time;

	//Definicao do nome do arquivo a ser procurado
	strcpy(arquivo_existente, nome_campeonato);
	strcat(arquivo_existente, " - Gols por jogador.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Gols por time.txt");

	//Possível abertura do arquivo
	gol_jogador = fopen(arquivo_existente, "r");

	//Verificação da existencia do arquivo
	if (gol_jogador == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arquivo_existente);
		return;
	}

	//Abertura do arquivo de resultados
	gol_time = fopen(nome_arquivo, "w");

	//Calculo do total de gols por time
	while (fscanf(gol_jogador, "%d%*c", &gols) != EOF)
	{
		soma += gols;
		cont++;
		if (cont == 11)
		{
			fprintf(gol_time, "%d\n", soma);
			soma = 0;
			cont = 0;
		}
	}
	
	//Fechamento dos arquivos
	fclose(gol_jogador);
	fclose(gol_time);
}

void gerar_artilheiros(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int n_jogador = 1, gols, time = 0, cont = 0, maior = 0;
	char arquivo_existente[TAM_NOME_ARQUIVO], nome_arquivo[TAM_NOME_ARQUIVO];
	FILE *campeonato, *artilheiros;

	//Definicao do nome do arquivo a ser procurado
	strcpy(arquivo_existente, nome_campeonato);
	strcat(arquivo_existente, " - Gols por jogador.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(nome_arquivo, nome_campeonato);
	strcat(nome_arquivo, " - Artilheiros.txt");

	//Possível abertura do arquivo
	campeonato = fopen(arquivo_existente, "r");

	//Verificação da existencia do arquivo
	if (campeonato == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arquivo_existente);
		return;
	}

	//Abertura do arquivo de resultados
	artilheiros = fopen(nome_arquivo, "w");

	//Calculo do jogador que mais fez gol
	while(fscanf(campeonato, "%d%*c", &gols) != EOF)
	{
		if (maior < gols)
		{
			n_jogador += cont;
			maior = gols;
			cont = 1;
		} else {
			cont++;
		}
		time++;
		if (time == 11)
		{
			fprintf(artilheiros, "%d\n", n_jogador);
			n_jogador = 1;
			maior = 0;
			cont = 0;
			time = 0;
		}
	}
	
	//Fechamento dos arquivos
	fclose(campeonato);
	fclose(artilheiros);
}

void gerar_tabela_geral(char nome_campeonato[])
{
	//Declaracao das variaveis e do arquivo
	int i, vitorias, derrotas, empates, n_pontos, n_gols, n_artilheiro, qtde_jogos, qtde_times;
	char arq_campeonato[TAM_NOME_ARQUIVO], arq_resultados[TAM_NOME_ARQUIVO], arq_pontos[TAM_NOME_ARQUIVO], arq_gols_time[TAM_NOME_ARQUIVO], arq_artilheiros[TAM_NOME_ARQUIVO], arq_tabela[TAM_NOME_ARQUIVO];
	FILE *campeonato, *resultados, *pontos, *gols_time, *artilheiros, *tabela;

	//Definicao dos nomes dos arquivos a serem procurados
	strcpy(arq_campeonato, nome_campeonato);
	strcat(arq_campeonato, " - Campeonato.txt");

	strcpy(arq_resultados, nome_campeonato);
	strcat(arq_resultados, " - Resultados.txt");

	strcpy(arq_pontos, nome_campeonato);
	strcat(arq_pontos, " - Pontos.txt");

	strcpy(arq_gols_time, nome_campeonato);
	strcat(arq_gols_time, " - Gols por time.txt");

	strcpy(arq_artilheiros, nome_campeonato);
	strcat(arq_artilheiros, " - Artilheiros.txt");

	//Definicao do nome do arquivo a ser gerado
	strcpy(arq_tabela, nome_campeonato);
	strcat(arq_tabela, " - Tabela geral.txt");

	//Possível abertura dos arquivos
	campeonato = fopen(arq_campeonato, "r");
	resultados = fopen(arq_resultados, "r");
	pontos = fopen(arq_pontos, "r");
	gols_time = fopen(arq_gols_time, "r");
	artilheiros = fopen(arq_artilheiros, "r");

	//Verificação da existencia dos arquivos
	if (campeonato == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arq_campeonato);
		return;
	}

	if (resultados == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arq_resultados);
		return;
	}

	if (pontos == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arq_pontos);
		return;
	}

	if (gols_time == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arq_gols_time);
		return;
	}

	if (artilheiros == NULL)
	{
		printf(ARQUIVO_N_ENCONTRADO, arq_artilheiros);
		return;
	}

	//Abertura do arquivo de resultados
	tabela = fopen(arq_tabela, "w");

	//Leitura da quantidade de times e da de jogos
	fscanf(campeonato, "%d%*c%d%*c", &qtde_times, &qtde_jogos);

	for (i = 0; i < qtde_times; i++)
	{
		fscanf(resultados, "%d%*c%d%*c%d%*c", &vitorias, &derrotas, &empates);
		fscanf(pontos, "%d%*c", &n_pontos);
		fscanf(gols_time, "%d%*c", &n_gols);
		fscanf(artilheiros, "%d%*c", &n_artilheiro);
		fprintf(tabela, "%d %d %d %d %d %d\n", vitorias, derrotas, empates, n_pontos, n_gols, n_artilheiro);
	}
	
	//Fechamento dos arquivos
	fclose(campeonato);
	fclose(resultados);
	fclose(pontos);
	fclose(gols_time);
	fclose(artilheiros);
	fclose(tabela);
}