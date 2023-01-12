/* FACULDADE DOM BOSCO DE PORTO ALEGRE
* Sistemas de Informação & Análise e Desenvolvimento de Sistemas
* Algoritmos
*
* Programa SegundoT2:
* -------------------------
* Objetivo do Programa: Segundo T2, referente à disciplina de Algoritmos, do curso de ADS.
* Autor: Valdoci da Silva Moraes Junior
* Data da entrega do arquivo fonte:

A matrícula dos alunos da Faculdade Dom Bosco é formada pelas seguintes informações: os quatro
(04) primeiros caracteres indicam o ano em que o aluno se matriculou na Faculdade; o próximo
caractere indica o semestre (1 – para o primeiro; 2 – para o segundo); o próximo caractere indica o
curso ( 1 – ADM; 2 – ADS; 3 – CON; 4 – ENG; 5 – DIR; 6 – SIS; 7 – PSI; 8 – LOG ) e os
próximos seis (06) são números aleatórios que formam identificadores únicos (esta informação não
é relevante para a solução do problema). Escrever um programa que leia um número indeterminado
de matrículas e ao final da leitura mostre as seguintes informações:
a. total de alunos para cada curso;
c. percentual de alunos do curso de ADS e SIS, sobre o total de alunos lidos;
d. total de alunos matriculados por semestre;
e. qual o curso com o menor número de matrículas.*/

#include <stdio.h>
#include <strings.h>

int concat(a, b, c, d)		//função criada para concatenar strings;
{
 
    char s1[99999];
    char s2[99999];
    char s3[99999];
    char s4[99999];
    char s5[99999];
    char s6[99999];
 
    // Conversão das 3 strings para int;
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    sprintf(s3, "%d", c);
    sprintf(s4, "%d", d);
 
    // Concatenação das 3 strings;
    //strcpy(s4, s1);
    strcat(s1, s2);
    strcpy(s5, s1);
    
    strcat(s3, s4);
    strcpy(s6, s3);
    
    strcat(s5, s6);	//concatenação da cópia das duas strings;
    
 
    // Conversão da string final para int;
    int e = atoi(s5);
 	
    // retorna a integral feita;
    return e;
    s1[0] = '\0';
    s2[0] = '\0';
    s3[0] = '\0';
    s4[0] = '\0';
    s5[0] = '\0';
    s6[0] = '\0';
    
}


int main(void)

{
	int i; //iterator for;
	int totalAlunos = 0; //iterator laço do while e o número total de alunos;
	int nroMatricula[totalAlunos]; //array matricula com tamanho definido pelo numero de vezes que o laço do while foi efetuado nro matricula com os digitos concatenados;
	int ano; //últimos digitos do ano;
	int curso; //código do curso;
	int semestre; //semestre;
	int ultimosDigitos; //últimos 6 dígitos da matricula;
	int resp = 0; //boolean para o do while;
	int primeiroSem = 0, segundoSem = 0;
	int countAdm = 0, countAds = 0, countCon = 0, countEng = 0, countDir = 0, countSis = 0, countPsi = 0, countLog = 0; //contadores de cada curso foi pedido apenas de ADS e SIS, porém achei bacana colocar de todos;
	int totalTech = 0; //total de alunos e total de alunos de tecnologia, ADS e SIS;	
	float perTech;																									
	
	do {
		printf("Adicionar Matricula?\n1 - SIM;\n0 - NAO.\n");
		scanf("%d", &resp);
		if(resp == 1) {
			printf("\nPor favor, insira os DOIS ultimos digitos do ano da sua matricula.\nExemplo: Matricula no ano 2022, inserir 22. \n");
			scanf("%d", &ano);
			printf("\nSemestre:\n1 - Primeiro semestre;\n2 - Segundo semestre.\n");
			scanf("%d", &semestre);
			int flag = 1;
			while(flag) {
			
				switch (semestre) {
					case 1:
						flag = 0; 
						primeiroSem++;
						break;
					
					case 2:
						flag = 0; 
						segundoSem++;
						break;
				
					default:
						printf("Numero invalido! Por favor, digite o seu semestre novamente.\n");
						printf("Semestre: ");
						scanf("%d", &semestre);
						
				}
			}
				
			printf("\nInsira o digito do seu curso.\n1 - ADM;\n2 - ADS;\n3 - CON;\n4 - ENG;\n5 - DIR;\n6 - SIS;\n7 - PSI;\n8 - LOG.\n");
			scanf("%d", &curso);
			int flag1 = 1;
			while(flag1) {
				switch (curso) {
					case 1:
						flag1 = 0;  
						countAdm++;
						break;
					
					case 2: 
						flag1 = 0; 
						countAds++;
						break;
						
					case 3: 
						flag1 = 0; 
						countCon++;
						break;
						
					case 4: 
						flag1 = 0; 
						countEng++;
						break;
						
					case 5: 
						flag1 = 0; 
						countDir++;
						break;
						
					case 6: 
						flag1 = 0; 
						countSis++;
						break;
						
					case 7: 
						flag1 = 0; 
						countPsi++;
						break;
						
					case 8: 
						flag1 = 0; 
						countLog++;
						break;
					
					default:
						printf("Numero invalido! Por favor, digite o seu curso novamente.\n");
						printf("Insira o digito do seu curso: ");
						scanf("%d", &curso);
				}
			}
				
			printf("\nInsira os ultimos 6 digitos para finalizar sua matricula.\n(Os numeros podem ser aleatorios). \n");
			scanf("%d", &ultimosDigitos);
			nroMatricula[totalAlunos] = concat(ano, semestre, curso, ultimosDigitos);
			totalAlunos++;
									
		}
			
	} while(resp !=0);
	
	int matriculados[] = {countAdm, countAds, countCon, countEng, countDir, countSis, countPsi, countLog}; //colocando os cursos em array para definir o que tem a menor quantidade;
	
 	int n = sizeof(matriculados)/sizeof(matriculados[0]); //definição do tamanho do array de matriculados em cada curso de forma dinamica;
 	
 	int j; //iterator para definir o curso com o menor numero de matriculados;
 	
	 	totalTech = countAds + countSis;
	 	perTech = (((float)totalTech/(float)totalAlunos)*100);

		
		//Questão a)
		if(countAdm > 0) {
			printf("O total de alunos matriculados no curso de ADM: %d alunos.\n", countAdm);
		} else {
			printf("Nao ha alunos matriculados no curso de ADM.\n");
		}
		if(countAds > 0) {
			printf("O total de alunos matriculados no curso de ADS: %d alunos.\n", countAds);
		} else {
			printf("Nao ha alunos matriculados no curso de ADS.\n");
		}
		if(countCon > 0) {
			printf("O total de alunos matriculados no curso de CON: %d alunos.\n", countCon);
		} else {
			printf("Nao ha alunos matriculados no curso de CON.\n");
		}
		if(countEng > 0) {
			printf("O total de alunos matriculados no curso de ENG: %d alunos.\n", countEng);
		} else {
			printf("Nao ha alunos matriculados no curso de ENG.\n");
		}
		if(countDir > 0) {
			printf("O total de alunos matriculados no curso de DIR: %d alunos.\n", countDir);
		} else {
			printf("Nao ha alunos matriculados no curso de DIR.\n");
		}
		if(countSis > 0) {
			printf("O total de alunos matriculados no curso de SIS: %d alunos.\n", countSis);
		} else {
			printf("Nao ha alunos matriculados no curso de SIS.\n");
		}
		if(countPsi > 0) {
			printf("O total de alunos matriculados no curso de PSI: %d alunos.\n", countPsi);
		} else {
			printf("Nao ha alunos matriculados no curso de PSI.\n");
		}
		if(countLog > 0) {
			printf("O total de alunos matriculados no curso de LOG: %d alunos.\n", countLog);
		} else {
			printf("Nao ha alunos matriculados no curso de LOG.\n");
		}
		
		
		printf("\nPercentual: %.2f porcento.\n", perTech);
	 	printf("\nTotal de alunos matriculados no curso de Tecnologia: %d\n", totalTech);

			 
	 	printf("\nO total de alunos matriculados no primeiro semestre: %d, alunos.\n", primeiroSem);
	 	printf("\nO total de alunos matriculados no segundo semestre: %d, alunos.\n", segundoSem);
		
		
		for(i = 0; i < n; i++) {
		if(matriculados[i] < matriculados[j]) {
			j = i;
		}
	}
	
	switch (j) {
		case 0:
			printf("\nO curso com o menor numero de matriculas eh ADM, com %d alunos.\n", matriculados[j]);
			break;
		case 1:
			printf("O curso com o menor numero de matriculas eh ADS, com %d alunos.\n", matriculados[j]);
			break;	
		case 2:
			printf("O curso com o menor numero de matriculas eh CON, com %d alunos.\n", matriculados[j]);
			break;
		case 3:
			printf("O curso com o menor numero de matriculas eh ENG, com %d alunos.\n", matriculados[j]);
			break;
		case 4:
			printf("O curso com o menor numero de matriculas eh DIR, com %d alunos.\n", matriculados[j]);
			break;
		case 5:
			printf("O curso com o menor numero de matriculas eh SIS, com %d alunos.\n", matriculados[j]);
			break;
		case 6:
			printf("O curso com o menor numero de matriculas eh PSI, com %d alunos.\n", matriculados[j]);
			break;
		case 7:
			printf("O curso com o menor numero de matriculas eh LOG, com %d alunos.\n", matriculados[j]);
			break;
		default:
			break;
	}
		
	
	system("pause");
	return 0;
}
