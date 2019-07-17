/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 1
	Prof. Tiago A. Almeida

	Lista 08 - Exercício 02 - Funcoes e Procedimentos com Vetores

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
#include <math.h>


#define MAX 100 //Tamanho máximo do vetor.

//Enumeração das opções do menu.
enum opcoes{
	OPC_SAIR,				// Encerra o programa
	OPC_TAMANHOVETOR,		// Inserir o tamanho do vetor
	OPC_POPULARVETOR,		// Popular o vetor
	OPC_IMPRIMIR,			// Imprimir os elementos do vetor
	OPC_IMPRIMIRINVERSO,	// Imprimir os elementos do vetor em ordem inversa
	OPC_SOMA,				// Exibir a soma dos elementos do vetor
	OPC_SOMAPOSITIVOS,		// Exibir a soma dos elementos positivos do vetor
	OPC_SOMANEGATIVOS,		// Exibir a soma dos elementos negativos do vetor
	OPC_MAXIMO,				// Exibir o maior elemento do vetor
	OPC_MINIMO,				// Exibir o menor elemento do vetor
	OPC_MEDIA,				// Exibir a media dos elementos do vetor
	OPC_MEDIAHARMONICA,		// Exibir a media harmonica dos elementos do vetor
	OPC_DESVIOPADRAO,		// Exibir o desvio padrao dos elementos do vetor
	OPC_MEDIANA,			// Exibir a mediana dos elementos do vetor
	OPC_ENCONTRARPRIMEIRO,	// Exibir a posicao da primeira ocorrencia de um numero n passado pelo usuario
	OPC_ENCONTRARULTIMO,	// Exibir a posicao da ultima ocorrencia de um numero n passado pelo usuario
	OPC_CONTAR,				// Exibir a contagem do numero de ocorrencias de um numero n passado pelo usuario
	OPC_ORDENARCRESCENTE,	// Ordenar definitivamente o vetor em ordem crescente
	OPC_ORDENARDECRESCENTE	// Ordenar definitivamente o vetor em ordem decrescente
};


/* ---------------------- */
/* DECLARACAO DAS FUNCOES */
/* ---------------------- */

// Declare as funcoes aqui.

int tamanhoVetor();
void popularVetor(float vet[], int tamanho);
void imprimir(float vet[], int tamanho);
void imprimirinverso(float vet[], int tamanho);
float soma(float vet[], int tamanho);
float somapositivos(float vet[], int tamanho);
float somanegativos(float vet[], int tamanho);
float maximo(float vet[], int tamanho);
float minimo(float vet[], int tamanho);
float media(float vet[], int tamanho);
float mediaharmonica(float vet[], int tamanho);
float desviopadrao(float vet[], int tamanho);
float mediana(float vet[], int tamanho);
int encontrarprimeiro(float vet[], int tamanho, float elemento);
int encontrarultimo(float vet[], int tamanho, float elemento);
int contar(float vet[], int tamanho, float elemento);
void ordenarcrescente(float vet[], int tamanho);
void ordenardecrescente(float vet[], int tamanho);




/* ------------------------------ */
/* ROTINA PRINCIPAL 			  */
/* ------------------------------ */
int main()
{
	int numElementos = 0,	//Armazena o tamanho do vetor.
		opcao;				//Armazena o a opção selecionada pelo usuário.
	float vetor[MAX],
		  numero;			//Armazena o número digitado pelo usuário para contagem e busca.

	scanf("%d", &opcao);	//Lê a opção selecionada pelo usuário.

	//Executa as opções enquanto o usuário não digitar a opção 0 - Sair.
	while(opcao != OPC_SAIR)
	{

		switch(opcao)
		{			

		//----------------------------------------------------------
		case OPC_TAMANHOVETOR:
			numElementos = tamanhoVetor();
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_POPULARVETOR:
			popularVetor(vetor, numElementos);
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_IMPRIMIR:
			// COMPLETE AQUI
			imprimir(vetor, numElementos);
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_IMPRIMIRINVERSO:
			imprimirinverso(vetor, numElementos);
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_SOMA:
			printf("%.2f\n", soma(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_SOMAPOSITIVOS:
			printf("%.2f\n", somapositivos(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_SOMANEGATIVOS:
			printf("%.2f\n", somanegativos(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_MAXIMO:
			printf("%.2f\n", maximo(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_MINIMO:
			printf("%.2f\n", minimo(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_MEDIA:
			printf("%.2f\n", media(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_MEDIAHARMONICA:
			printf("%.2f\n", mediaharmonica(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_DESVIOPADRAO:
			printf("%.2f\n", desviopadrao(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_MEDIANA:
			printf("%.2f\n", mediana(vetor, numElementos)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_ENCONTRARPRIMEIRO:
			scanf("%f", &numero);
			printf("%d\n", encontrarprimeiro(vetor, numElementos, numero)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_ENCONTRARULTIMO:
			scanf("%f", &numero);
			printf("%d\n", encontrarultimo(vetor, numElementos, numero)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_CONTAR:
			scanf("%f", &numero);
			printf("%d\n", contar(vetor, numElementos, numero)); // COMPLETE O PRINTF
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_ORDENARCRESCENTE:
			// COMPLETE AQUI
			ordenarcrescente(vetor, numElementos);
		break;
		//----------------------------------------------------------

		//----------------------------------------------------------
		case OPC_ORDENARDECRESCENTE:
			// COMPLETE AQUI
			ordenardecrescente(vetor, numElementos);
		break;
		//----------------------------------------------------------
		}

		scanf("%d", &opcao);		
	}

	return (0);
}



/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

//Lê o tamanho do vetor passado pelo usuário e retorna o valor.
int tamanhoVetor(){
	int tamanho;

	do {
		scanf("%d", &tamanho);
	} while(tamanho < 1 || tamanho > 100);

	return (tamanho);
}


//Lê os elementos do vetor passados pelo usuário.
void popularVetor(float vet[], int tamanho){
	int i;

	for(i = 0; i < tamanho; i++)
		scanf("%f", &vet[i]);
}


// Implemente as demais funcoes aqui.
void imprimir(float vet[], int tamanho){
	int cont;
	for (cont = 0; cont < tamanho; cont++)
    {
        printf("%.2f ", vet[cont]);
    }
    printf("\n");
}

void imprimirinverso(float vet[], int tamanho){
	int cont;
	for (cont = tamanho - 1; cont >= 0; cont--)
    {
        printf("%.2f ", vet[cont]);
    }
    printf("\n");
}

float soma(float vet[], int tamanho){
	int cont;
	float soma;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
    {
        soma += vet[cont];
    }
    return (soma);
}

float somapositivos(float vet[], int tamanho){
	int cont;
	float soma;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
    {
    	if (vet[cont] > 0)
    	{
        	soma += vet[cont];
    	}
    }
    return (soma);
}

float somanegativos(float vet[], int tamanho){
	int cont;
	float soma;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
    {
    	if (vet[cont] < 0)
    	{
        	soma += vet[cont];
    	}
    }
    return (soma);
}

float maximo(float vet[], int tamanho){
	int cont, indice;
	for (indice = 0, cont = 1; cont < tamanho; cont++)
    {
        if (vet[indice] < vet[cont])
    	{
            indice = cont;
        }
    }
    return (vet[indice]);
}

float minimo(float vet[], int tamanho){
	int cont, indice;
	for (indice = 0, cont = 1; cont < tamanho; cont++)
    {
        if (vet[indice] > vet[cont])
    	{
            indice = cont;
        }
    }
    return (vet[indice]);
}

float media(float vet[], int tamanho){
	int cont;
	float soma;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
    {
        soma += vet[cont];
    }
    return (soma / tamanho);
}

float mediaharmonica(float vet[], int tamanho){
	int cont;
	float soma, media;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
	{
		soma += 1.0 / vet[cont];
	}
	media = tamanho / soma;
	return (media);
}

float desviopadrao(float vet[], int tamanho){
	float media, soma, desvio;
	int cont;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
    {
        soma += vet[cont];
    }
	media = soma / tamanho;
	for (cont = 0, soma = 0; cont < tamanho; cont++)
	{
		soma += pow((vet[cont] - media), 2);
	}
	desvio = sqrt(soma / (tamanho - 1));
	return(desvio);
}

float mediana (float vet[], int tamanho){
	int cont, meio, auxA, auxB;
	float vet_aux[MAX], auxResult, mediana;
	meio = tamanho / 2;
	for (cont = 0; cont < tamanho; cont++)
    {
        vet_aux[cont] = vet[cont];
    }
	for (cont = 0; cont < tamanho; cont++)
	{
	    for (auxA = cont, auxB = cont + 1; auxB < tamanho; auxB++)
	    {
	        if (vet_aux[auxA] > vet_aux[auxB])
	        {
	            auxA = auxB;
	        }
	    }
		auxResult = vet_aux[cont];
		vet_aux[cont] = vet_aux[auxA];
		vet_aux[auxA] = auxResult;
	}
	if (tamanho % 2 == 0)
	{
		mediana = (vet_aux[meio - 1] + vet_aux[meio]) / 2;
 	} else {
 		mediana = (vet_aux[meio]);
	}
	return (mediana);
}

int encontrarprimeiro (float vet[], int tamanho, float elemento){
	int cont, flag = 0, indice = -1;
	for (cont = 0; cont < tamanho && !flag; cont++)
    {
        if (vet[cont] == elemento)
        {
        	flag = 1;
        	indice = cont;
        }
    }
    return(indice);
}

int encontrarultimo (float vet[], int tamanho, float elemento){
	int cont, flag = 0, indice = -1;
	for (cont = tamanho - 1; cont >= 0 && !flag; cont--)
    {
        if (vet[cont] == elemento)
        {
        	flag = 1;
        	indice = cont;
        }
    }
    return(indice);
}

int contar (float vet[], int tamanho, float elemento){
	int cont, ocorr = 0;
	for (cont = 0; cont < tamanho; cont++)
    {
        if (vet[cont] == elemento)
        {
        	ocorr++;
        }
    }
    return(ocorr);
}

void ordenarcrescente (float vet[], int tamanho){
	int cont, auxA, auxB;
	float auxResult;
	for (cont = 0; cont < tamanho; cont++)
	{
	    for (auxA = cont, auxB = cont + 1; auxB < tamanho; auxB++)
	    {
	        if (vet[auxA] > vet[auxB])
	        {
	            auxA = auxB;
	        }
	    }
		auxResult = vet[cont];
		vet[cont] = vet[auxA];
		vet[auxA] = auxResult;
	}
}

void ordenardecrescente (float vet[], int tamanho){
	int cont, auxA, auxB;
	float auxResult;
	for (cont = 0; cont < tamanho; cont++)
	{
	    for (auxA = cont, auxB = cont + 1; auxB < tamanho; auxB++)
	    {
	        if (vet[auxA] < vet[auxB])
	        {
	            auxA = auxB;
	        }
	    }
		auxResult = vet[cont];
		vet[cont] = vet[auxA];
		vet[auxA] = auxResult;
	}
}