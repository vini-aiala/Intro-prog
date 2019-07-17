/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução à Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 11 - Exercício 02 - Cadastro de Alunos (Arquivo Binario)
  
    Instrucoes
    ----------
 
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
 
* ================================================================== *
    Dados do aluno:
 
    RA: 759544
    Nome: Vinícius Pereira Aiala
 
* ================================================================== */

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constantes */
#define MAX_ALUNO 1000
#define MAX_NOME 100

/* Arquivo */
#define ARQUIVO "Alunos.dat"

/* Mensagens de erro */
#define ALUNO_JA_CADASTRADO "Aluno já está cadastrado\n"
#define ALUNO_N_CADASTRADO "Aluno não cadastrado.\n"

/* Menu de opcoes */
#define CADASTRAR 1
#define ALTERAR 2
#define REMOVER 3
#define BUSCAR 4
#define LISTAR 5

/* Aluno */
typedef struct aluno{
    int ra;
    char nome[MAX_NOME];
    int ano;
    int creditos;
}aluno;

/* /* ===================== PROTORIPO DAS FUNCOES ===================== */

/* Exibe os dados do aluno da posicao i */
void exibir(aluno alunos[MAX_ALUNO], int i);

/* Verifica se o arquivo existe e carrega para a memoria
 Retorna o numero de alunos lido, e 0 caso nao exista arquivo */
int carregar_arquivo(aluno alunos[MAX_ALUNO]);

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, insere o aluno no vetor
    Retorna 1 para cadastro com sucesso e 0 caso contrario */
int cadastrar(aluno alunos[MAX_ALUNO], aluno alunoTemp, int numAlunos);

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, solicita os dados e altera os dados do aluno */
void alterar(aluno alunos[MAX_ALUNO], int ra, int numAlunos);

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, remove o aluno do vetor 
    Retorna 1 para remocao com sucesso e 0 caso contrario */
int remover(aluno alunos[MAX_ALUNO], int ra, int numAlunos);

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, remove o aluno do vetor */
void buscar(aluno alunos[MAX_ALUNO], int ra, int numAlunos);

/* Lista todos os alunos em ordem crescente de RA */
void listar(aluno alunos[MAX_ALUNO], int numAlunos);

/* Escreve o vetor no arquivo */
void escrever_arquivo(aluno alunos[MAX_ALUNO], int numAlunos);

/* ============================ MAIN ============================ */

int main() {
    int opcao = 0;
    int ra;
    int numAlunos;
    aluno alunos[MAX_ALUNO];
    aluno alunoTemp;
    
    numAlunos = carregar_arquivo(alunos);

    while (opcao != 6) {
        scanf("%d", &opcao);
        switch (opcao) {
            case CADASTRAR:
                scanf("%d\n%d\n%d\n%[^\n]s", &(alunoTemp.ra), &(alunoTemp.ano), &(alunoTemp.creditos), (alunoTemp.nome));
                numAlunos += cadastrar(alunos, alunoTemp, numAlunos);
                break;
            case ALTERAR:
                scanf("%d",&ra);
                alterar(alunos, ra, numAlunos);
                break;
            case REMOVER:
                scanf("%d",&ra);
                numAlunos -= remover(alunos, ra, numAlunos);
                break;
            case BUSCAR:
                scanf("%d",&ra);
                buscar(alunos, ra, numAlunos);
                break;
            case LISTAR:
                listar(alunos, numAlunos);
                break;
        }
    }

    escrever_arquivo(alunos, numAlunos);
    return 0;
}

/* ========================= FUNCOES ========================= */

/* Exibe os dados do aluno da posicao i */
void exibir(aluno alunos[MAX_ALUNO], int i) {
    printf("\nDados:\n");    
    printf("RA: %d\n",alunos[i].ra);
    printf("Nome: %s\n",alunos[i].nome);
    printf("Ano: %d\n",alunos[i].ano);
    printf("Creditos: %d\n",alunos[i].creditos);
}

/* IMPLEMENTE AS FUNCOES AQUI */
/* Verifica se o arquivo existe e carrega para a memoria
 Retorna o numero de alunos lido, e 0 caso nao exista arquivo */
int carregar_arquivo(aluno alunos[MAX_ALUNO])
{
    int cont = 0;
    char nome_aluno[MAX_NOME];
    FILE *arq_alunos;
    
    arq_alunos = fopen("Alunos.dat", "r");
    
    if(arq_alunos == NULL)
    {
        arq_alunos = fopen("Alunos.dat", "w");
        fclose(arq_alunos);
        return (0);
    }
    
    while(fscanf(arq_alunos, "%d%*c%d%*c%d%*c%[^\n]s", &alunos[cont].ra, &alunos[cont].ano, &alunos[cont].creditos, alunos[cont].nome) != EOF)
    {
        cont++;
    }

    fclose(arq_alunos);
    
    return (cont);
}

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, insere o aluno no vetor
    Retorna 1 para cadastro com sucesso e 0 caso contrario */
int cadastrar(aluno alunos[MAX_ALUNO], aluno alunoTemp, int numAlunos)
{
    int i, flag;
    
    for (i = 0; i < numAlunos && !flag; ++i)
    {
        if (alunoTemp.ra == alunos[i].ra)
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf(ALUNO_JA_CADASTRADO);
        return (0);
    }

    alunos[numAlunos].ra = alunoTemp.ra;
    alunos[numAlunos].creditos = alunoTemp.creditos;
    alunos[numAlunos].ano = alunoTemp.ano;
    strcpy(alunos[numAlunos].nome, alunoTemp.nome);

    return (1);
}

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, solicita os dados e altera os dados do aluno */
void alterar(aluno alunos[MAX_ALUNO], int ra, int numAlunos)
{
    int i, flag, idx, ano, creditos;
    char nome[MAX_NOME];
    
    for (i = 0, flag = 0; i < numAlunos && !flag; ++i)
    {
        if (ra == alunos[i].ra)
        {
            flag = 1;
            idx = i;
        }
    }

    if (flag == 0)
    {
        printf(ALUNO_N_CADASTRADO);
        return;
    }

    scanf("%d\n%d\n%[^\n]s", &ano, &creditos, nome);

    alunos[idx].ano = ano;
    alunos[idx].creditos = creditos;
    strcpy (alunos[idx].nome, nome);

    return;
}

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, remove o aluno do vetor 
    Retorna 1 para remocao com sucesso e 0 caso contrario */
int remover(aluno alunos[MAX_ALUNO], int ra, int numAlunos)
{
    int i, flag, idx;
    
    for (i = 0, flag = 0; i < numAlunos && !flag; i++)
    {
        if (ra == alunos[i].ra)
        {
            flag = 1;
            idx = i;
        }
    }

    if (flag == 0)
    {
        printf(ALUNO_N_CADASTRADO);
        return (0);
    }

    for (i = idx + 1; i < numAlunos; ++i)
    {
        alunos[i - 1].ra = alunos[i].ra;
        alunos[i - 1].creditos = alunos[i].creditos;
        alunos[i - 1].ano = alunos[i].ano;
        strcpy(alunos[i - 1].nome, alunos[i].nome);
    }

    return (1);
}

/* Verifica se o RA ja esta cadastrado, informando o erro
    Caso contrario, exibe os dados do aluno */
void buscar(aluno alunos[MAX_ALUNO], int ra, int numAlunos)
{
    int i, flag, idx;
    
    for (i = 0; i < numAlunos && !flag; i++)
    {
        if (ra == alunos[i].ra)
        {
            flag = 1;
            idx = i;
        }
    }

    if (flag == 0)
    {
        printf(ALUNO_N_CADASTRADO);
        return;
    }

    exibir(alunos, idx);
}

/* Lista todos os alunos em ordem crescente de RA */
void listar(aluno alunos[MAX_ALUNO], int numAlunos)
{
    int indices[numAlunos], i, j, flag, cont;

    for (i = 0; i < numAlunos; ++i)
    {
        for (j = 0, flag = 0, cont = 0; j < numAlunos && !flag; ++j)
        {
            if(alunos[i].ra > alunos[j].ra)
            {
                ++cont;
            }
        }
        indices[cont] = i;
    }

    for (i = 0; i < numAlunos; ++i)
    {
        exibir(alunos, indices[i]);
    }
}

/* Escreve o vetor no arquivo */
void escrever_arquivo(aluno alunos[MAX_ALUNO], int numAlunos)
{
    int indices[numAlunos], i, j, flag, cont;
    FILE *arq_alunos;

    arq_alunos = fopen("Alunos.dat", "w");

    for (i = 0; i < numAlunos; ++i)
    {
        for (j = 0, flag = 0, cont = 0; j < numAlunos && !flag; ++j)
        {
            if(alunos[i].ra > alunos[j].ra)
            {
                ++cont;
            }
        }
        indices[cont] = i;
    }

    for (i = 0; i < numAlunos; i++)
    {
        fprintf(arq_alunos, "%d@%d@%d@%s\n", alunos[indices[i]].ra, alunos[indices[i]].ano, alunos[indices[i]].creditos, alunos[indices[i]].nome);
    }

    fclose(arq_alunos);
}