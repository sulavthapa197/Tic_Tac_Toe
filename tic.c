#include <stdio.h>
#include <stdbool.h>

// variable declaration start
char board[3][3] = {'-','O','X','X','X','O','O','X','O'};//board for tictactoe game
bool game_active = true;//Boolean to check the status of game
char current_player = 'X';//current player(player to start first)
char winner = 'N'; // N representing no one is the winner yet
//variable declaration end


//function declaration begin
void display_board(char board[3][3]);
void player_swap();
void game_winner();
void check_draw();
int game_turn(char current_player);
char check_row();
char check_column();
char check_diagonal();
//function declaration end



//main funtion that begins the game
int main(){
	printf("%c\n",winner );
	display_board(board);
	game_turn(current_player);
	game_winner();
	check_draw();
	printf("\n");
	printf("%c",winner);
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


void game_winner(){ // function to tell "X" or "O" won the game
	char row_winner, column_winner, diagonal_winner;
	row_winner = check_row();
	column_winner = check_column();
	diagonal_winner = check_diagonal();
	if (row_winner != 'N'){
		winner = row_winner;
	}

	else if(column_winner != 'N'){
		winner = column_winner;
	}

	else if(diagonal_winner != 'N'){
		winner = diagonal_winner;
	}

	else{
		winner = 'N';
	}
}


char check_row(){ //functionn to check row of the game
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '-'){
		game_active = false;
		return board[0][0];
	}

	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '-'){
		game_active = false;
		return board[1][0];
	}

	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '-'){
		game_active = false;
		return board[2][0];
	}
	return 'N';

}

char check_column(){ // function to check column of the game
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '-'){
		game_active = false;
		return board[0][0];
	}

	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '-'){
		game_active = false;
		return board[0][1];
	}

	else if (board[0][2] == board[1][2] && board[1][2] == board[1][2] && board[0][2] != '-'){
		game_active = false;
		return board[0][2];
	}
	return 'N';

}

char check_diagonal(){ // funtion to check diagonals of the game
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
		game_active = false;
		return board[0][0];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'){
		game_active = false;
		return board[0][2];
	}
	return 'N';
}

void check_draw(){ //function to check draw condition in the game
	char row_winner, column_winner, diagonal_winner;
	row_winner = check_row();
	column_winner = check_column();
	diagonal_winner = check_diagonal();
	if (row_winner == 'N' && column_winner == 'N' && diagonal_winner == 'N'){
		game_active = false;
		winner = 'D'; // 'D' here implies the game has been concluded as a draw
	}
}


int game_turn(char current_player){ //function that specifies player's turn respectively, turn refering 'X' or 'O'
	int i;
	char board_position;
	bool correct = false;
	char board_input[9] = {'1','2','3','4','5','6','7','8','9'};

	printf("%c", current_player);
	printf("'s turn\n");
	printf("Enter your board position: ");
	scanf("%c", &board_position);

	while(!correct){
		for(i=0; i<9; i++){
			if (board_position == board_input[i]){
				switch(board_position){
					case '1':
						board[0][0] = current_player;
						correct = true;
						break;
					case '2':
						board[0][1] = current_player;
						correct = true;
						break;
					case '3':
						board[0][2] = current_player;
						correct = true;
						break;
					case '4':
						board[1][0] = current_player;
						correct = true;
						break;
					case '5':
						board[1][1] = current_player;
						correct = true;
						break;
					case '6':
						board[1][2] = current_player;
						correct = true;
						break;
					case '7':
						board[2][0] = current_player;
						correct = true;
						break;
					case '8':
						board[2][1] = current_player;
						correct = true;
						break;
					case '9':
						board[2][2] = current_player;
						correct = true;
						break;
				}				
			}
		}
	}
	return 0;
	
}





/* to be done list 

*input users data 

* work on slecting either "X" or "O" during beginning of the game
		- work on single player mode as well(automate the second player)
* function to determine the turn
* incor[orate all these functions into the main() 

*/