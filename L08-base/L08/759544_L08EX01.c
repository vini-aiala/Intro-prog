/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 1
	Prof. Tiago A. Almeida

	Lista 08 - Exercício 01 - Funcoes e Procedimentos

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


// Enumeração das opções do menu.
enum opcoes{
	OPC_SAIR,
	OPC_FIBONACCI_1, 	// Exibir o n1-ésimo elemento da sequência Fibonacci
	OPC_FIBONACCI_2, 	// Exibir o n2-ésimo elemento da sequência Fibonacci
	OPC_FATORIAL_1,		// Exibir o fatorial de n1
	OPC_FATORIAL_2,		// Exibir o fatorial de n2
	OPC_POTENCIA,		// Exibir o resultado da potência (n1)^n2
	OPC_SOMAPARES,		// Exibir a soma de todos os números pares entre n1 e n2
	OPC_SOMAIMPARES,	// Exibir a soma de todos os números ímpares entre n1 e n2
	OPC_SOMAPRIMOS,		// Exibir a soma de todos os números primos entre n1 e n2
	OPC_MAIORPRIMO,		// Exibir o maior primo existente entre n1 e n2
	OPC_MMC,			// Exibir o valor do mínimo múltiplo comum (mmc) entre n1 e n2
	OPC_MDC,			// Exibir o valor do máximo divisor comum (mdc) entre n1 e n2
	OPC_DESVIOPADRAO,	// Exibir o desvio padrão dos valores entre n1 e n2
	OPC_COMBINACAO,		// Exibir a combinação C(n1,n2)
	OPC_MEDIAHARMONICA,	// Exibir a media harmonica dos valores entre n1 e n2
	OPC_COEFICIENTEVARIACAO // Exibir o coeficiente de variacao dos valores entre n1 e n2
};


/* ---------------------- */
/* DECLARACAO DAS FUNCOES */
/* ---------------------- */

// Declare as funcoes aqui.
unsigned int fibonacci (unsigned int n);
unsigned int fatorial (unsigned int n);
float potencia (unsigned int n1, unsigned int n2);
unsigned int somapares (unsigned int n1, unsigned int n2);
unsigned int somaimpares (unsigned int n1, unsigned int n2);
unsigned int somaprimos (unsigned int n1, unsigned int n2);
unsigned int maiorprimo (unsigned int n1, unsigned int n2);
unsigned int mmc (unsigned int n1, unsigned int n2);
unsigned int mdc (unsigned int n1, unsigned int n2);
float desvio (unsigned int n1, unsigned int n2);
float combinacao (unsigned int n1, unsigned int n2);
float mediaharmonica (unsigned int n1, unsigned int n2);
float coef_var (unsigned int n1, unsigned int n2);



/* ------------------------------ */
/* ROTINA PRINCIPAL				  */
/* ------------------------------ */
unsigned int main(){
	unsigned int n1, n2, //Armazenam os números n1 e n2 para os cálculos.
		opc; 	//Armazena a última opção selecionada pelo usuário.

	scanf("%d %d", &n1, &n2); //Lê os valores n1 e n2.
	scanf("%d", &opc);		  //Lê a opção do usuário.

	//Repete enquanto o usuário não selecionar a opção 0 - Sair.
	while(opc != OPC_SAIR){

		//Imprime o resultado de acordo com a opção selecionada.
		switch(opc){
			//-----------------------------------------------------------
			case OPC_FIBONACCI_1:
				printf("%d\n", fibonacci(n1)); // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_FIBONACCI_2:
				printf("%d\n", fibonacci(n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_FATORIAL_1:
				printf("%d\n", fatorial(n1));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_FATORIAL_2:
				printf("%d\n", fatorial(n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_POTENCIA:
				printf("%.0f\n", potencia(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_SOMAPARES:
				printf("%d\n", somapares(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_SOMAIMPARES:
				printf("%d\n", somaimpares(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_SOMAPRIMOS:
				printf("%d\n", somaprimos(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_MAIORPRIMO:
				printf("%d\n", maiorprimo(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_MMC:
				printf("%d\n", mmc(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_MDC:
				printf("%d\n", mdc(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_DESVIOPADRAO:
				printf("%.2f\n", desvio(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_COMBINACAO:
				printf("%.2f\n", combinacao(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_MEDIAHARMONICA:
				printf("%.2f\n", mediaharmonica(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------

			//-----------------------------------------------------------
			case OPC_COEFICIENTEVARIACAO:
				printf("%.2f\n", coef_var(n1, n2));  // COMPLETE O PRINTF
			break;
			//-----------------------------------------------------------
		}

		scanf("%d", &opc); //Lê a opção do usuário.

	}

	//Finaliza o programa.
	return (0);
}


/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

// Implemente as funcoes aqui.
unsigned int fibonacci (unsigned int n)
{
	unsigned int fib, i, j, cont;
	for (i = 1, j = 1, fib = 1, cont = 3; n >= cont; cont++)
	{
		i = j;
		j = fib;
		fib = i + j;
	}
	return (fib);
}

unsigned int fatorial (unsigned int n)
{
	unsigned int fat, auxn;
	for (fat = 1, auxn = n; auxn > 1; auxn--)
	{
		fat *= auxn;
	}
	return (fat);
}

float potencia (unsigned int n1, unsigned int n2)
{
	float pot;
	unsigned int cont;
	for (pot = 1.0, cont = 0; cont < n2; cont++)
	{
		pot *= n1;
	}
	return (pot);
}

unsigned int somapares (unsigned int n1, unsigned int n2)
{
	unsigned int cont, soma;
	if (n1 > n2)
	{
		cont = n2;
		if (cont % 2 != 0)
		{
			cont++;
		}
		for (soma = 0; cont <= n1; cont += 2)
		{
			soma += cont;
		}
	} else
	{
		cont = n1;
		if (cont % 2 != 0)
		{
			cont++;
		}
		for (soma = 0; cont <= n2; cont += 2)
		{
			soma += cont;
		}
	}
	return (soma);
}

unsigned int somaimpares (unsigned int n1, unsigned int n2)
{
	unsigned int cont, soma;
	if (n1 > n2)
	{
		cont = n2;
		if (cont % 2 == 0)
		{
			cont++;
		}
		for (soma = 0; cont <= n1; cont += 2)
		{
			soma += cont;
		}
	} else
	{
		cont = n1;
		if (cont % 2 == 0)
		{
			cont++;
		}
		for (soma = 0; cont <= n2; cont += 2)
		{
			soma += cont;
		}
	}
	return (soma);
}

unsigned int somaprimos (unsigned int n1, unsigned int n2)
{
	unsigned int cont, div, flag, soma;
	if (n1 > n2)
	{
		for (cont = n2, soma = 0; cont <= n1; cont++)
		{
			for (div = 2, flag = 0; div < cont && cont != 1 && !flag; div++)
			{
				if (cont % div == 0) {
					flag = 1;
				}
			}
			if (!flag)
			{
				soma += cont;
			}
		}
	} else {
		for (cont = n1, soma = 0; cont <= n2; cont++)
		{
			for (div = 2, flag = 0; div < cont && cont != 1 && !flag; div++)
			{
				if (cont % div == 0) {
					flag = 1;
				}
			}
			if (!flag)
			{
				soma += cont;
			}
		}
	}
	return (soma);
}

unsigned int maiorprimo (unsigned int n1, unsigned int n2)
{
	unsigned int cont, div, flag, maior;
	if (n1 > n2)
	{
		for (cont = n2, maior = 0; cont <= n1; cont++)
		{
			for (div = 2, flag = 0; div < cont && cont != 1 && !flag; div++)
			{
				if (cont % div == 0) {
					flag = 1;
				}
			}
			if (!flag)
			{
				maior = cont;
			}
		}
	} else {
		for (cont = n1, maior = 0; cont <= n2; cont++)
		{
			for (div = 2, flag = 0; div < cont && cont != 1 && !flag; div++)
			{
				if (cont % div == 0) {
					flag = 1;
				}
			}
			if (!flag)
			{
				maior = cont;
			}
		}
	}
	return (maior);
}

unsigned int mmc (unsigned int n1, unsigned int n2)
{
	unsigned int div, aux1, aux2, res_mmc;
	for (aux1 = n1, aux2 = n2, res_mmc = 1, div = 2; aux1 != 1 || aux2 != 1;)
	{
		if (aux1 % div == 0 && aux2 % div == 0)
		{
			aux1 /= div;
			aux2 /= div;
			res_mmc *= div;
		} else if (aux1 % div == 0)
		{
			aux1 /= div;
			res_mmc *= div;
		} else if (aux2 % div == 0)
		{
			aux2 /= div;
			res_mmc *= div;
		} else {
			div++;
		}
	}
	return (res_mmc);
}

unsigned int mdc (unsigned int n1, unsigned int n2)
{
	unsigned int num = 0, resto = 1, mdc = 0;
	if (n1 > n2)
	{
		for (num = n1, mdc = n2; resto != 0;)
		{
			resto = num % mdc;
			if (resto != 0)
			{
				num = mdc;
				mdc = resto;
			}
		}
	} else {
		for (num = n2, mdc = n1; resto != 0;)
		{
			resto = num % mdc;
			if (resto != 0)
			{
				num = mdc;
				mdc = resto;
			}
		}
	}
	return (mdc);
}

float desvio (unsigned int n1, unsigned int n2)
{
	float cont, media, soma, desvio, n_valores;
	if (n1 > n2)
	{
		for (cont = n2, soma = 0, n_valores = 0; cont <= n1; cont++)
		{
			soma += cont;
			n_valores++;
		}
		media = soma / n_valores;
		for (cont = n2, soma = 0; cont <= n1; cont++)
		{
			soma += pow((cont - media), 2);
		}
		desvio = sqrt(soma / (n_valores - 1));
	} else {
		for (cont = n1, soma = 0, n_valores = 0; cont <= n2; cont++)
		{
			soma += cont;
			n_valores++;
		}
		media = soma / n_valores;
		for (cont = n1, soma = 0; cont <= n2; cont++)
		{
			soma += pow((cont - media), 2);
		}
		desvio = sqrt(soma / (n_valores - 1));
	}
	return (desvio);
}

float combinacao (unsigned int n1, unsigned int n2)
{
	unsigned int auxn, auxk, sub, n_fat, k_fat, sub_fat;
	float result;
	if (n1 < n2)
	{
		result = 0;
	} else {
		sub = n1 - n2;
		for (n_fat = 1, auxn = n1; auxn > 1; auxn--)
		{
			n_fat *= auxn;
		}
		for (k_fat = 1, auxk = n2; auxk > 1; auxk--)
		{
			k_fat *= auxk;
		}
		for (sub_fat = 1; sub > 1; sub--)
		{
			sub_fat *= sub;
		}
		result = (float)n_fat / (k_fat * sub_fat);
	}
	return (result);
}

float mediaharmonica (unsigned int n1, unsigned int n2)
{
	float soma, media, cont, n_valores;
	if (n1 > n2)
	{
		for (cont = n2, soma = 0, n_valores = 0; cont <= n1; cont++)
		{
			soma += 1.0 / cont;
			n_valores++;
		}
		media = n_valores / soma;
	} else {
		for (cont = n1, soma = 0, n_valores = 0; cont <= n2; cont++)
		{
			soma += 1.0 / cont;
			n_valores++;
		}
		media = n_valores / soma;
	}
	return (media);
}

float coef_var (unsigned int n1, unsigned int n2)
{
	float cont, media, soma, desvio, n_valores, coefic;
	if (n1 > n2)
	{
		for (cont = n2, soma = 0, n_valores = 0; cont <= n1; cont++)
		{
			soma += cont;
			n_valores++;
		}
		media = soma / n_valores;
		for (cont = n2, soma = 0; cont <= n1; cont++)
		{
			soma += pow((cont - media), 2);
		}
		desvio = sqrt(soma / (n_valores - 1));
	} else {
		for (cont = n1, soma = 0, n_valores = 0; cont <= n2; cont++)
		{
			soma += cont;
			n_valores++;
		}
		media = soma / n_valores;
		for (cont = n1, soma = 0; cont <= n2; cont++)
		{
			soma += pow((cont - media), 2);
		}
		desvio = sqrt(soma / (n_valores - 1));
	}
	coefic = desvio / media;
	return (coefic);
}