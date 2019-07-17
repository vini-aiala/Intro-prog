#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int main(){
	int n;
	int ehPrimo; // igual a TRUE se o n eh primo
	int div;

	scanf("%d", &n);
	while (n != 0){
		if (n <= 1 || (n != 2 && n % 2 == 0))
			ehPrimo = FALSE;	// descartando numeros pares
    	else
			ehPrimo = TRUE;	

		div = 3;
		while (ehPrimo && div <= sqrt(n)){ // https://www.scriptbrasil.com.br/forum/topic/152202-programa-para-c%C3%A1lculo-de-n%C3%BAmeros-primos/
			if (n % div == 0)
				ehPrimo = FALSE;
			div += 2; // testando apenas numeros impares
		}
	



		if (ehPrimo)
			printf ("%d eh primo!\n", n);
		else
			printf ("%d nao eh primo!\n", n);

		// proximo numero
		scanf("%d", &n);
	}

	return 0;
}
