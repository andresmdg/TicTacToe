/*

	Print Template

		 1 | 2 | 3 
		---+---+---
		 4 | 5 | 6 
		---+---+---
		 7 | 8 | 9 
	 
	Indique en que casilla desea poner su ficha: 2
	
	
		 1 | X | 3 
		---+---+---
		 O | 5 | 6 
		---+---+---
		 7 | 8 | 9 
	
	Indique en que casilla desea poner su ficha: 
*/

// Standard libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Define TRUE FALSE
#define true 1
#define false 0

// Variables
static char board[9] = { "0" };

// Function declaration
  // Game Functions
void cpu(void);
void game(void);
void initGame(void);
void initBoard(void);
void updateBoard(void);
void setToken(char token, int x);
  // Validators
int winner(void);
int validPos(int x);

// Main Function

int main(void) {
	
	initBoard();
	game();
	
	system("pause");
	
	return 0;
};

// InitBoard Function
void initBoard(void){
	
	int fila;
	char iterator = '1';
	
	for (fila = 0; fila < 9; fila++){
			board[fila]= iterator++;
	};
	
};

// UpdateBoard Function
void updateBoard(void){
	
	system("cls");
	
	int columna, fila;
	
	for (fila = 0; fila < 9; fila++){
		
		if (fila == 0) {
			printf("\n %c |", board[fila]);
		} else if (fila < 2 || fila > 2 && fila < 5 || fila > 5 && fila < 8){
			printf(" %c |", board[fila]);
		} else if (fila == 2 || fila == 5){
			printf(" %c ", board[fila]);
			printf("\n---+---+---\n");
		} else {
			printf(" %c \n", board[fila]);
		};
	};
	
};

// Game Function
void game(void){
	
	updateBoard();
	
	int x;
	
	printf("\nIndica la casilla para colocar tu ficha: ");
	scanf("%d", &x);
	
	if (x < 1 || x >= 10){
		system("cls");
		printf("\n\n[DATO] Error: Dato invalido, Por favor indique un valor del 1 al 9.\n\n");
		system("pause");
		return game();
	}else if(!validPos(x - 1)) {
		system("cls");
		printf("\n\n[DATO] Error: Casilla ocupada! Por favor indique una casilla libre.\n\n");
		system("pause");
		return game();
	};

	setToken('X', x);
	
};

// Valid Position function
int validPos(int x){
	
	if (board[x] == 'X' || board[x] == 'O') {
		return false;
	};
	
	return true;
	
};

// Set Token into the board function

void setToken(char token, int x){
	
	board[x - 1] = token;
	
	if (!winner() && token == 'X'){
		return cpu();
	} else if (!winner() && token == 'O'){
		return game();
	} else if (token == 'X'){
		system("cls");
		printf("\n\nHAS GANADO EL JUEGO!!!\n\n");
		return;
	} else if (token == 'O'){
		system("cls");
		printf("\n\nHAS PERDIDO EL JUEGO!!!\n\n");
		return;
	};
	
	updateBoard();
	
};

int winner(void){
	
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X'|| board[0] == 'O' && board[1] == 'O' && board[2] == 'O'){
		return true;
	}else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X'|| board[3] == 'O' && board[4] == 'O' && board[5] == 'O'){
		return true;
	}else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X'|| board[6] == 'O' && board[7] == 'O' && board[8] == 'O'){
		return true;
	}else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X'|| board[0] == 'O' && board[3] == 'O' && board[6] == 'O'){
		return true;
	}else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X'|| board[1] == 'O' && board[4] == 'O' && board[7] == 'O'){
		return true;
	}else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X'|| board[2] == 'O' && board[5] == 'O' && board[8] == 'O'){
		return true;
	}else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'|| board[2] == 'O' && board[4] == 'O' && board[6] == 'O'){
		return true;
	}else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X'|| board[0] == 'O' && board[4] == 'O' && board[8] == 'O'){
		return true;
	};
	
	return false;
	
};

void cpu(void){
	
	int x, min = 1, max = 9;
	
	x = (rand() % (max - min + 1)) + min;

	if (!validPos(x - 1)){
		return cpu();
	};
	
	setToken('O', x);
};