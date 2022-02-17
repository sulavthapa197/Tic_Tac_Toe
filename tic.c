#include <stdio.h>
#include <stdbool.h>

// variable declaration start
char board[3][3] = {'-','-','-','-','-','-','-','-','-'};//board for tictactoe game


bool game_active = true;//Boolean to check the status of game

char current_player = 'X';//current player(player to start first)
//variable declaration end

//function declaration begin
void display_board(char board[3][3]);
//function declaration end



//main funtion that begins the game
int main(){
	display_board(board);
	return 0;
}

void display_board(char board[3][3]){ // function to display board 
	int i, j; // access the 2D array such that it displays the board correctly
	for (i=0; i<3; i++ ){
		for (j=0; j<3; j++){
			printf("\t");
			printf("%c", board[i][j]);
		}
		printf("\n");	

	}
}