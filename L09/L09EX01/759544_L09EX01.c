/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 1
	Prof. Tiago A. Almeida

	Lista 09 - Exercício 01 - Cadeias de Caracteres

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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Definindo tamanho maximo da string
#define MAX 51



//Definindo opções
enum{
	OPC_SAIR,
	OPC_CONTAR_LETRAS,
	OPC_CONTAR_VOGAIS,
	OPC_CONTAR_CONSOANTES,
	OPC_CONTAR_PALAVRAS,
	OPC_OCORRENCIAS_STRING,
	OPC_CONTAR_MAIUSCULOS,
	OPC_CONTAR_MINUSCULOS,
	OPC_CONTAR_PALAVRAS_VOGAIS,
	OPC_CONTAR_PALAVRAS_CONSOANTES,
	OPC_TAMANHO,
	OPC_CONVERTER_MAIUSCULO,
	OPC_CONVERTER_MINUSCULO,
	OPC_PRIMEIRAS_LETRAS_EM_MAIUSCULAS,
	OPC_IMPRIMIR,
	OPC_IMPRIMIR_LEXICOGRAFICA,
	OPC_IMPRIMIR_INVERTIDA,
	OPC_IMPRIMIR_VOGAIS,
	OPC_IMPRIMIR_CONSOANTES,
	OPC_IMPRIMIR_PRIMEIRA_PALAVRA,
	OPC_IMPRIMIR_ULTIMA_PALAVRA,
	OPC_IMPRIMIR_INICIAIS,
	OPC_OCULTAR_VOGAIS,
	OPC_OCULTAR_CONSOANTES,
	OPC_CONCATENAR,
	OPC_COMPARAR_STRINGS,
	OPC_VERIFICAR_PALINDROMO,
	OPC_VERIFICAR_SIMETRIA,
	OPC_PRIMEIRA_OCORRENCIA,
	OPC_ULTIMA_OCORRENCIA,
	OPC_TROCAR_CARACTER,
	OPC_RETIRAR_CARACTER,
	OPC_ALTERNAR_MAIUS_MINUS
};


/* ---------------------- */
/* DECLARACAO DAS FUNCOES */
/* ---------------------- */

// Declare as funcoes aqui.
int contarCaractere(const char string[], char caractere);
int contarVogais(const char string[]);
int contarConsoantes(const char string[]);
int contarPalavras(const char string[]);
int contarOcorrenciasString(const char string[], char stringAux[]);
int contarMaiusculos(const char string[]);
int contarMinusculos(const char string[]);
int contarPalavrasVogais(const char string[]);
int contarPalavrasConsoantes(const char string[]);
int tamanho(const char string[]);
void converterMaiusculo(char string[]);
void converterMinusculo(char string[]);
void converterPrimeirasLetrasEmMaiusculas(char string[]);
void imprimir(const char string[]);
void imprimirLexicografica(const char string[]);
void imprimirInvetida(const char string[]);
void imprimirVogais(const char string[]);
void imprimirConsoantes(const char string[]);
void imprimirPrimeiraPalavra(const char string[]);
void imprimirUltimaPalavra(const char string[]);
void imprimirIniciais(const char string[]);
void ocultarVogais(const char string[]);
void ocultarConsoantes(const char string[]);
void concatenar(char string[], char stringAux[]);
int compararStrings(const char string[], char stringAux[]);
int verificarPalindromo(const char string[]);
int verificarSimetria(const char string[]);
int primeiraOcorrencia(const char string[], char caractere);
int ultimaOcorrencia(const char string[], char caractere);
void trocarCaractere(char string[], char caractere, char caractere2);
void retirarCaractere(char string[], char caractere);
void alternarMaiusMinus(char string[]);


/* ------------------------------ */
/* ROTINA PRINCIPAL - NÃO ALTERAR */
/* ------------------------------ */
int main(){
	int opcao;
	char string[MAX], stringAux[MAX], caractere, caractere2;

	scanf("%[^\n]s", string);

	scanf("%d", &opcao);

	while(opcao != OPC_SAIR){

		switch(opcao){
			//------------------------------------------------------------------------------
			case OPC_CONTAR_LETRAS:
				scanf("\n%c", &caractere);
				printf("%d\n", contarCaractere(string, caractere));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_VOGAIS:
				printf("%d\n", contarVogais(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_CONSOANTES:
				printf("%d\n", contarConsoantes(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_PALAVRAS:
				printf("%d\n", contarPalavras(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_OCORRENCIAS_STRING:
				scanf("\n%[^\n]s", stringAux);
				printf("%d\n", contarOcorrenciasString(string, stringAux));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_MAIUSCULOS:
				printf("%d\n", contarMaiusculos(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_MINUSCULOS:
				printf("%d\n", contarMinusculos(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_PALAVRAS_VOGAIS:
				printf("%d\n", contarPalavrasVogais(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONTAR_PALAVRAS_CONSOANTES:
				printf("%d\n", contarPalavrasConsoantes(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_TAMANHO:
				printf("%d\n", tamanho(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_CONVERTER_MAIUSCULO:
				converterMaiusculo(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_CONVERTER_MINUSCULO:
				converterMinusculo(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_PRIMEIRAS_LETRAS_EM_MAIUSCULAS:
				converterPrimeirasLetrasEmMaiusculas(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR:
				imprimir(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_LEXICOGRAFICA:
				imprimirLexicografica(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_INVERTIDA:
				imprimirInvetida(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_VOGAIS:
				imprimirVogais(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_CONSOANTES:
				imprimirConsoantes(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_PRIMEIRA_PALAVRA:
				imprimirPrimeiraPalavra(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_ULTIMA_PALAVRA:
				imprimirUltimaPalavra(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_IMPRIMIR_INICIAIS:
				imprimirIniciais(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_OCULTAR_VOGAIS:
				ocultarVogais(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_OCULTAR_CONSOANTES:
				ocultarConsoantes(string);
			break;

			//------------------------------------------------------------------------------
			case OPC_CONCATENAR:
				scanf("\n%[^\n]s", stringAux);
				concatenar(string, stringAux);
			break;

			//------------------------------------------------------------------------------
			case OPC_COMPARAR_STRINGS:
				scanf("\n%[^\n]s", stringAux);
				printf("%d\n", compararStrings(string, stringAux));
			break;

			//------------------------------------------------------------------------------
			case OPC_VERIFICAR_PALINDROMO:
				printf("%d\n", verificarPalindromo(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_VERIFICAR_SIMETRIA:
				printf("%d\n", verificarSimetria(string));
			break;

			//------------------------------------------------------------------------------
			case OPC_PRIMEIRA_OCORRENCIA:
				scanf("\n%c", &caractere);
				printf("%d\n", primeiraOcorrencia(string, caractere));
			break;

			//------------------------------------------------------------------------------
			case OPC_ULTIMA_OCORRENCIA:
				scanf("\n%c", &caractere);
				printf("%d\n", ultimaOcorrencia(string, caractere));
			break;

			//------------------------------------------------------------------------------
			case OPC_TROCAR_CARACTER:
				scanf("\n%c %c", &caractere, &caractere2);
				trocarCaractere(string, caractere, caractere2);
			break;

			//------------------------------------------------------------------------------
			case OPC_RETIRAR_CARACTER:
				scanf("\n%c", &caractere);
				retirarCaractere(string, caractere);
			break;

			//------------------------------------------------------------------------------
			case OPC_ALTERNAR_MAIUS_MINUS:
				alternarMaiusMinus(string);
			break;

		}

		scanf("%d", &opcao);
	}

	return 0;
}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

// Implemente as funcoes aqui.

int contarCaractere(const char string[], char caractere) {
	int i, cont = 0;
	for (i = 0; string[i] != '\0'; i++){
		if(string[i] == caractere) {
			cont++;
		}
	}
	return(cont);
}

int contarVogais(const char string[]) {
	int i, j, flag, cont;
	char vogais[] = "aeiouAEIOU";
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
			if(string[i] == vogais[j]) {
				cont++;
				flag = 1;
			}
		}
	}
	return(cont);
}

int contarConsoantes(const char string[]) {
	int i, j, flag, cont;
	char vogais[] = "aeiouAEIOU";
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
			if(string[i] == vogais[j]) {
				flag = 1;
			}
		}
		if (!flag && isalpha(string[i]))
		{
			cont++;
		}
	}
	return(cont);
}

int contarPalavras(const char string[]) {
	int i = 0, cont = 0;
	while (string[i] == ' ' && string[i] != '\0') {
		i++;
	}
	for (; string[i] != '\0'; i++)
	{
		if ((isalnum(string[i]) && string[i - 1] == ' ') || i == 0)
			cont++;
	}
	return(cont);
}

int contarOcorrenciasString(const char string[], char stringAux[]) {
	int i, j, cont = 0, tamanho, tamanhoaux, flag;
	tamanhoaux = strlen(stringAux);
	tamanho = strlen(string);
	for (i = 0; i <= tamanho - tamanhoaux; i++){
		for (j = 0, flag = 0; (stringAux[j] != '\0') && !flag; j++){
			if(string[i + j] != stringAux[j]) {
				flag = 1;
			}
		}
		if (!flag) {
			cont++;
		} 
	}
	return(cont);
}

int contarMaiusculos(const char string[]) {
	int i, cont;
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		if(isupper(string[i])) {
			cont++;
		}
	}
	return(cont);
}

int contarMinusculos(const char string[]) {
	int i, cont;
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		if(islower(string[i])) {
			cont++;
		}
	}
	return(cont);
}

int contarPalavrasVogais(const char string[]) {
	int i, j, flag, cont;
	char vogais[] = "aeiouAEIOU";
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		if(i == 0 || (string[i - 1] == ' ')) {
			for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
				if(string[i] == vogais[j]) {
					cont++;
					flag = 1;
				}
			}
		}
	}
	return(cont);
}

int contarPalavrasConsoantes(const char string[]) {
	int i, j, flag, cont;
	char vogais[] = "aeiouAEIOU";
	for (i = 0, cont = 0; string[i] != '\0'; i++){
		if(i == 0 || (string[i - 1] == ' ')) {
			for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
				if((string[i] == vogais[j])) {
					flag = 1;
				}
			}
			if (!flag && isalpha(string[i]))
			{
				cont++;
			}
		}
	}
	return(cont);
}

int tamanho(const char string[]) {
	return(strlen(string));
}

void converterMaiusculo(char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; i++){
		string[i] = toupper(string[i]);
	}
}

void converterMinusculo(char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; i++){
		string[i] = tolower(string[i]);
	}
}

void converterPrimeirasLetrasEmMaiusculas(char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; i++){
		string[i] = tolower(string[i]);
	}
	for (i = 0; string[i] != '\0'; i++){
		if(i == 0 || (string[i - 1] == ' ')) {
			string[i] = toupper(string[i]);
		}
	}
}

void imprimir(const char string[]) {
	puts(string);
}

void imprimirLexicografica(const char string[]) {
	char palavras[25][51], padronizado[25][51];
	int n_palavras, i, j, indices[25], pos, cont;
	
	//Inicialização dos indices
	for (i = 0; i < 25; i++)
		indices[i] = -1;
	
	//Separação da string em palavras
	for (i = 0, n_palavras = 0, pos = 0; string[i] != '\0'; i++){
		if (string[i] == ' ' && isalpha(string[i + 1])) {
			palavras[n_palavras][pos] = '\0';
			n_palavras++;
			pos = 0;
		} else if (string[i] != ' '){
			palavras[n_palavras][pos] = string[i];
			pos++;
		}
	}
	palavras[n_palavras][pos] = '\0';
	n_palavras++;
	
	//Padronização das palavras em maiusculas
	for (j = 0; j < n_palavras; j++) {
		for (i = 0; palavras[j][i] != '\0'; i++) {
			padronizado[j][i] = toupper(palavras[j][i]);
		}
		padronizado[j][i] = '\0';
	}
	
	//Ordenação dos indices
	cont = 0;
	do {
		i = 0;
		for (j = 0; j < n_palavras; j++) {
			if (strcmp (padronizado[i], padronizado[j]) > 0) {
				i = j;
			}
		}
		indices[cont] = i;
		padronizado[i][0] = 127;
		cont++;
	} while (cont <= n_palavras);
	
	//Saída das palavras
	for (i = 0; i < n_palavras; i++) {
		for (j = 0; palavras[indices[i]][j] != '\0'; j++)
		{
			printf("%c", palavras[indices[i]][j]);
		}
		if (i != n_palavras - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void imprimirInvetida(const char string[]) {
	int tamanho, i;
	tamanho = strlen(string);
	for (i = tamanho - 1; i >= 0; i--) {
		printf("%c", string[i]);
	}
	printf("\n");
}

void imprimirVogais(const char string[]) {
	char vogais[] = "aeiouAEIOU";
	int i, j;
	for (i = 0; string[i] != '\0'; i++){
		for (j = 0; (vogais[j] != '\0'); j++){
			if(string[i] == vogais[j]) {
				printf("%c ", string[i]);
			}
		}
	}
	printf("\n");
}

void imprimirConsoantes(const char string[]) {
	char vogais[] = "aeiouAEIOU";
	int i, j, flag;
	for (i = 0; string[i] != '\0'; i++){
		for (j = 0, flag = 0; (vogais[j] != '\0'); j++){
			if(string[i] == vogais[j]) {
				flag = 1;
			}
		}
		if (!flag && isalpha(string[i]))
		{
			printf("%c ", string[i]);
		}
	}
	printf("\n");
}

void imprimirPrimeiraPalavra(const char string[]) {
	int i;
	for (i = 0; string[i] != ' ' && string[i] != '\0'; i++){
		printf("%c", string[i]);
	}
	printf("\n");
}

void imprimirUltimaPalavra(const char string[]) {
	int tamanho, i;
	tamanho = strlen(string);
	for (i = tamanho - 1; string[i] != ' ' && i >= 0; i--){
	}
	for (i++; i < tamanho; i++) {
		printf("%c", string[i]);
	}
	printf("\n");
}

void imprimirIniciais(const char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; i++){
		if ((i == 0 || (string[i - 1] == ' ')) && isalpha(string[i])) {
			printf("%c ", string[i]);
		}
	}
	printf("\n");
}

void ocultarVogais(const char string[]) {
	int i, j, flag;
	char vogais[] = "aeiouAEIOU";
	for (i = 0; string[i] != '\0'; i++){
		for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
			if(string[i] == vogais[j]) {
				flag = 1;
			}
		}
		if (flag) {
			printf("*");
		} else {
			printf("%c", string[i]);
		}
	}
	printf("\n");
}

void ocultarConsoantes(const char string[]) {
	int i, j, flag;
	char vogais[] = "aeiouAEIOU";
	for (i = 0; string[i] != '\0'; i++){
		for (j = 0, flag = 0; (vogais[j] != '\0') && !flag; j++){
			if(string[i] == vogais[j]) {
				flag = 1;
			}
		}
		if (!flag && isalpha(string[i])) {
			printf("*");
		} else {
			printf("%c", string[i]);
		}
	}
	printf("\n");
}

void concatenar(char string[], char stringAux[]) {
	strcat (string, stringAux);
}

int compararStrings(const char string[], char stringAux[]) {
	int comparar, result;
	comparar = strcmp(string, stringAux);
	if (comparar == 0) {
		result = 1;
	} else {
		result = 0;
	}
	return (result);
}

int verificarPalindromo(const char string[]) {
	int tamanho, i, j, result, flag;
	tamanho = strlen(string);
	for (i = 0, j = tamanho - 1, flag = 0; i < tamanho && j >= 0 && !flag;) {
		while (!(isalpha(string[i]))) {
			i++;
		}
		while (!(isalpha(string[j]))) {
			j--;
		}
		if (string[i] == toupper(string[j]) || string[i] == tolower(string[j]))
		{
			i++;
			j--;
		} else {
			flag = 1;
		}
	}
	if (flag == 0)
	{
		result = 1;
	} else {
		result = 0;
	}
	return (result);
}

int verificarSimetria(const char string[]) {
	int tamanho, i, j, flag, result;
	tamanho = strlen(string);
	for (i = 0, j = tamanho - 1, flag = 0; i < tamanho && j >= 0 && !flag; i++, j--) {
		if (string[i] != string[j]) {
			flag = 1;
		}
	}
	if (flag == 0)
	{
		result = 1;
	} else {
		result = 0;
	}
	return(result);
}

int primeiraOcorrencia(const char string[], char caractere) {
	int result, i, flag = 0;
	for (i = 0, result = -1; string[i] != '\0' && !flag; i++)
	{
		if (string[i] == caractere)
		{
			result = i;
			flag = 1;
		}
	}
	return(result);
}

int ultimaOcorrencia(const char string[], char caractere) {
	int result, tam, i, flag = 0;
	tam = tamanho(string);
	for (i = tam - 1, result = -1; i >= 0 && !flag; i--)
	{
		if (string[i] == caractere)
		{
			result = i;
			flag = 1;
		}
	}
	return(result);
}

void trocarCaractere(char string[], char caractere, char caractere2) {
	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == caractere)
		{
			string[i] = caractere2;
		}
	}
}

void retirarCaractere(char string[], char caractere) {
	int cont, i;
	for (i = 0, cont = 0; string[i] != '\0'; i++)
	{
		if (string[i] == caractere) {
			cont++;
		} else {
			string[i - cont] = string[i];
		}
	}
	string[i - cont] = '\0';
}

void alternarMaiusMinus(char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (isupper(string[i])) {
			string[i] = tolower(string[i]);
		} else if (islower(string[i])) {
			string[i] = toupper(string[i]);
		}
	}
}