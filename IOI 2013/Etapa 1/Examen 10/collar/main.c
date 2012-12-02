#include <stdio.h>
#include <stdlib.h>
#include "perlas.h"
#include "main.h"

int N = 4, L = 6, F = 2;
char collar [7] = "NBBNND";
int enanos [5] = {0, 0, 0, 1, 1};
int listas [5][2][2] = { {{0, 0}, {0, 0}}, {{2, 0}, {4, 0}}, {{1, 3}, {1, 0}}, {{4, 0}, {4, 0}}, {{2, 3}, {1, 0}}};

int enanoActual;
int turno;


void pasaCollar(int enano) {
	if (enanos[enanoActual] == 1) {
		printf("TURNO INCORRECTO");
		exit(0);
	}
	if (collar[turno] == 'N') {
		if (!(listas[enanoActual][0][0] == enano || listas[enanoActual][0][1] == enano)) {
			printf("NO ESTA EN LA LISTA");
			exit(0);
		}
	} else {
		if (!(listas[enanoActual][1][0] == enano || listas[enanoActual][1][1] == enano)) {
			printf("NO ESTA EN LA LISTA");
			exit(0);
		}
	}

	enanoActual = enano;
	turno++;
}

int recibeCollar(void) {
	if (enanos[enanoActual] == 0) {
		printf("TURNO INCORRECTO");
		exit(0);
	}
	if (collar[turno] == 'N')
		enanoActual = listas[enanoActual][0][0];
	else
		enanoActual = listas[enanoActual][1][0];

	turno++;
	return enanoActual;
}

void termina(void) {
	if (collar[turno] != 'D') {
		printf("NO ES UN DIAMANTE");
		exit(0);
	}
	if (enanos[enanoActual] == 1)
		printf("GANAN LOS ROJOS");
	else
		printf("GANAN LOS VERDES");

	exit(0);
}

int main(void) {
	enanoActual = F;
	turno = 0;
	juega();
	return 0;
}
