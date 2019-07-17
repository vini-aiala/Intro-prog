/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Introdução a Programação
    Prof. Tiago A. Almeida
    Profa. Tiemi C. Sakata
 
    Lista 05 - Exercício 04 - Vetores Euclidianos
 
    Instrucoes
    ----------
 
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
 
* ================================================================== *
    Dados do aluno:
 
    RA: 759544
    Nome: Vinicius Pereira Aiala
 
* ================================================================== */

#include "stdio.h"
#include "math.h"

typedef enum {
    // Implemente a enumeração
    soma = 1, subtrair, multiplicar, modulo
} Instrucao;

typedef struct {
    float x, y, z;
} Vetor;

int main() {
    int instrucao;
    Vetor memoria;
    Vetor entrada;
    float escalar;
    
    scanf("%f%f%f", &memoria.x, &memoria.y, &memoria.z);
    
    do {
        scanf("%d", &instrucao);
        
        switch (instrucao) {
            case soma:
                scanf("%f%f%f", &entrada.x, &entrada.y, &entrada.z);
                memoria.x += entrada.x;
                memoria.y += entrada.y;
                memoria.z += entrada.z;
                printf("%.1f %.1f %.1f\n", memoria.x, memoria.y, memoria.z);
                break;
            case subtrair:
                scanf("%f%f%f", &entrada.x, &entrada.y, &entrada.z);
                memoria.x -= entrada.x;
                memoria.y -= entrada.y;
                memoria.z -= entrada.z;
                printf("%.1f %.1f %.1f\n", memoria.x, memoria.y, memoria.z);
                break;
            case multiplicar:
                scanf("%f", &escalar);
                memoria.x *= escalar;
                memoria.y *= escalar;
                memoria.z *= escalar;
                printf("%.1f %.1f %.1f\n", memoria.x, memoria.y, memoria.z);
                break;
            case modulo:
                printf("%.1f\n", sqrt(pow(memoria.x, 2) + pow(memoria.y, 2) + pow(memoria.z, 2)));
                break;
        }
    } while (instrucao != 0);
    
    return 0;
}