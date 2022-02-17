#include <stdio.h>
#include <stdbool.h>

// variable declaration start
char board[3][3] = {'-','-','-','-','-','-','-','-','-'};//board for tictactoe game


bool game_active = true;//Boolean to check the status of game

char current_player = 'X';//current player(player to start first)

char *winner = '\0'; // null type
//variable declaration end

//function declaration begin
void display_board(char board[3][3]);
void player_swap();
//function declaration end



//main funtion that begins the game
int main(){
	display_board(board);
	return 0;
}



// function to display board 
void display_board(char board[3][3]){ 
	int i, j; // access the 2D array such that it displays the board correctly
	for (i=0; i<3; i++ ){
		for (j=0; j<3; j++){
			printf("\t");
			printf("%c", board[i][j]);
		}
		printf("\n");	

	}
}

// function to swap the players respectively
void player_swap(){
	if(current_player == 'X'){
		current_player = 'O';
	}
	else if(current_player == 'O'){
		current_player = 'X';
	}
}
