/*
 * operaciones.c
 *
 *  Created on: 12 abr. 2021
 *      Author: lucia
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sumar(int primerNumero, int segundoNumero)
{
	int resultadoSuma;
	resultadoSuma = primerNumero + segundoNumero;
	return resultadoSuma;
};
int restar(int primerNumero, int segundoNumero)
{
	int resultadoResta;
	resultadoResta = primerNumero - segundoNumero;
	return resultadoResta;
};
int dividir(int primerNumero, int segundoNumero)
{
	if(segundoNumero == 0){
		return -1;
	}
	int resultadoDivision;
	resultadoDivision = primerNumero / segundoNumero;
	return resultadoDivision;
};
int multiplicar(int primerNumero, int segundoNumero){
	int resultadoMultiplicacion;
	resultadoMultiplicacion = primerNumero * segundoNumero;
	return resultadoMultiplicacion;
};
int realizarFactorial(int numero){ /* FALTA VALIDAR DECIMALES. */
	if(numero < 0){
		return -1;
	} else if (numero == 0){
		int resultadoFactorial = 1;
		return resultadoFactorial;
	} else {
		int resultadoFactorial = 1;
		for(int i=1; i<=numero; i++){
			resultadoFactorial = resultadoFactorial * i;
		}
		return resultadoFactorial;
	}
};
