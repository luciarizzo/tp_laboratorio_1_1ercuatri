/*
 * Rizzo Lucía TRABAJO PRÁCTICO NÚMERO #1
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
2
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "operaciones.h"

int main(void) {
	int opcion;
	int primerOperando;
	int segundoOperando;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorialPrimerOperando;
	int factorialSegundoOperando;
	int flagPrimerEjecucion = 0;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagOpcionUno = 0;
	int flagOpcionDos = 0;
	int flagOpcionTres = 0;
	do {
		if (flagPrimerEjecucion == 0){
		printf("BIENVENIDO. POR FAVOR, ELIJA UNA OPCIÓN:");
		flagPrimerEjecucion = 1;
		};
		if (flagPrimerOperando){
			printf("\n1. Ingresar 1er operando. Valor actual cargado: %d", primerOperando);
		} else {
			printf("\n1. Ingresar 1er operando.");
		};
		if (flagSegundoOperando){
			printf("\n 2. Ingresar 2do operando Valor actual cargado: %d", segundoOperando);
		} else {
			printf("\n2. Ingresar 2do operando.");
		}
		printf("\n 3. Calcular todas las operaciones:"
				"\n 3A. SUMA"
				"\n 3B. RESTA"
				"\n 3C. DIVISION"
				"\n 3D. MULTIPLICACION"
				"\n 3E. FACTORIAL (Recuerde que si ingresa un número decimal, el factorial sólo se calculará con la parte entera del mismo.)\n");
		printf("\n4. Informar resultados");
		printf("\n5. Salir\n");
		scanf("%d", &opcion);
		switch(opcion){
		case 1:
			printf("\n Ingrese el 1er operando (debe ser un número entero).\n");
			scanf("%d", &primerOperando);
			flagPrimerOperando = 1;
			flagOpcionUno = 1;
			break;
		case 2:
			if(flagPrimerOperando){
			printf("\n Ingrese el 2do operando (debe ser un número entero)\n");
			scanf("%d", &segundoOperando);
			flagSegundoOperando = 1;
			flagOpcionDos = 1;
			} else {
				printf("\nDebe ingresar el primer operando, seleccionando en el menú la opción 1.\n Por favor, REINTENTAR.\n");
			}
			break;
		case 3:
			suma = sumar(primerOperando, segundoOperando);
			resta = restar(primerOperando, segundoOperando);
			division = dividir(primerOperando, segundoOperando);
			multiplicacion = multiplicar(primerOperando, segundoOperando);
			factorialPrimerOperando = realizarFactorial(primerOperando);
			factorialSegundoOperando = realizarFactorial(segundoOperando);
			if (division == -1) {
				printf("\n Error: no es posible dividir por CERO.\n Por favor REINTENTAR.\n");
				opcion = 5;
			} else if (flagOpcionUno == 0) {
				printf("\n Error: debe introducir el primer operando para realizar operaciones. Por favor REINTENTAR\n");
			} else if (flagOpcionDos == 0) {
				printf("\n Error: debe introducir el segundo operando para realizar operaciones. Por favor REINTENTAR\n");
			}
			else{
				printf("Operaciones realizadas exitosamente.\n Para visualizar resultados, elija opción 4 como indica el menú.\n");
			};
			flagOpcionTres = 1;
			break;
		case 4:
			if (flagOpcionTres){
			printf("\nA El resultado de la SUMA es: %d", suma);
			printf("\nB El resultado de la RESTA es: %d", resta);
			printf("\nC El resultado de la DIVISION es: %f", division);
			printf("\nD El resultado de la MULTIPLICACION es: %d", multiplicacion);
				if(factorialPrimerOperando == -1 || factorialSegundoOperando == -1){
					printf("\n Error: no se puede calcular el factorial de un número negativo.\n Por favor REINTENTAR\n");
				} else if(factorialPrimerOperando != 0 || factorialSegundoOperando != 0 ){
				printf("\nE El FACTORIAL del primer número ingresado  %d  es: %d \n El FACTORIAL del segundo número ingresado  %d  es: %d \n", primerOperando, factorialPrimerOperando, segundoOperando, factorialSegundoOperando);
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				}else {
					printf("\nError: para imprimir resultados primero debe realizar operaciones eligiendo la opción 3 del menú\n");
				}
			}
			break;
		default:
			printf("\nError: por favor, elija una opción del menú válida.\n");
		}
	}while(opcion>5 || opcion<5);
	return EXIT_SUCCESS;
}
