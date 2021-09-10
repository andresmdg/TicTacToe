// Standard libraries
#include <stdio.h>
#include <stdlib.h>

void loop(char c[3][3]);
void tablero(char c[3][3]);
void Intro_Yo(char c[3][3]);
void Intro_Primera(char c[3][3]);
void colocar(char c[3][3], char aux);

int main(void) {
	
	char c[3][3];
	
	loop(c);
	
	return 0;
};

void loop(char c[3][3]) {
	
	Intro_Primera(c); // Crea el tablero
	Intro_Yo(c); // Pide al usuario que ingrese su marca
	
};

void Intro_Yo(char c[3][3]){
	
	system("cls");
	tablero(c);	
	
	char aux;
	
	printf("\n\nElige la casilla donde colocar tu marca: ");
	scanf(" %c", aux);
	
	if (aux < '1') {
		printf("\n Has ingresado una casilla invalida!\nPor favor ingresa una casilla valida.");
		system("pause");
		Intro_Yo(c);
		return;
	};
	
	colocar(c, aux);
	
};

void Intro_Primera(char c[3][3]) {
	
	int j, k;
	char aux;
	aux = '1';
	
	for (j = 0; j < 3; j++){
		for (k = 0; k < 3; k++){
			c[j][k] = aux++;
		};
	};
};

void tablero(char c[3][3]) {
	int j, k;
	
	for (j = 0; j < 3; j++){
		for (k = 0; k < 3; k++){
			if (k < 2){
				printf(" %c |", c[j][k]);
			} else {
				printf(" %c ", c[j][k]);
			};
		};
		
		if (j < 2){
			printf("\n-----------\n");
		};
	};
};

void colocar(char c[3][3], char aux, char token, char user) {
	
	int x = atoi(aux);
	
	if (aux >= '1' && aux <= '3') {
		
		c[0][x - 1] == token;
	
	} else if (aux >= '4' && aux <= '6'){
		
		c[1][x - 1] == token;
	
	} else if (x >= '7' && aux <= '9'){
		
		c[2][aux - 1] == token;
	
	};
	
};

/*

	 1 | 2 | 3 
	-----------
	 4 | 5 | 6 
	-----------
	 7 | 8 | 9 

*/