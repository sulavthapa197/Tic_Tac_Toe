#include <stdio.h> //standard input out
#include <stdbool.h> // lib for using boolean
#include <stdlib.h> // lib for using system
#include <conio.h> // lib for using getch() function

// variable declaration start
bool game_active = true;//Boolean to check the status of game
char board[9] = {'-','-','-','-','-','-','-','-','-'}; //array for the game board
char current_player;//current player(player to start first)
char winner = 'N'; // N representing no one is the winner yet
//variable declaration end


//function declaration begin
char check_row();
char check_column();
char check_diagonal();
int game_turn(char current_player);
void display_board(char board[9]);
void player_swap();
void game_winner();
void check_draw();
void player_select();
//function declaration end



//main funtion that begins the game
int main(){
	player_select();
	display_board(board);
	while(game_active == true){
		game_turn(current_player);
		game_winner();
		player_swap();
		check_draw();
		printf("\n");
	}
	if (winner == 'X' || winner == 'O'){
		printf("%c",winner);
		printf(" won.");	
	}
	else if (winner == 'D'){
		printf("Draw");
	}
	printf("\nPress any key to quit.");
	getch();// waits for any key to be pressed before quitting the console
	return 0;
}


//function to display board
void display_board(char board[9]){
	int i; //access the array such that the board is correctly displayed
	for(i=0; i<9; i++){
		if (i == 3 || i== 6 ){
			printf("\n");
		}
		printf("%c\t", board[i]);
	}
	printf("\n");
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


char check_row(){//functionn to check row of the game
	if (board[0] == board[1] && board[1] == board[2] && board[0] != '-'){
		game_active = false;
		return board[0];
	}

	else if (board[3] == board[4] && board[4] == board[5] && board[3] != '-'){
		game_active = false;
		return board[3];
	}

	else if (board[6] == board[7] && board[7] == board[8] && board[6] != '-'){
		game_active = false;
		return board[6];
	}
	return 'N';

}

char check_column(){ // function to check column of the game
	if (board[0] == board[3] && board[3] == board[6] && board[0] != '-'){
		game_active = false;
		return board[0];
	}

	else if (board[1] == board[4] && board[4] == board[7] && board[1] != '-'){
		game_active = false;
		return board[1];
	}

	else if (board[2] == board[5] && board[5] == board[8] && board[2] != '-'){
		game_active = false;
		return board[2];
	}
	return 'N';

}

char check_diagonal(){ // funtion to check diagonals of the game
	if (board[0] == board[4] && board[4]== board[8] && board[0] != '-'){
		game_active = false;
		return board[0];
	}
	else if (board[2] == board[4]&& board[4] == board[6] && board[2] != '-'){
		game_active = false;
		return board[2];
	}
	return 'N';
}



void check_draw(){ //function to check draw condition in the game
	int i;
	int j = 9; // "j" here works as a logic check variable
	char row_winner, column_winner, diagonal_winner;
	row_winner = check_row();
	column_winner = check_column();
	diagonal_winner = check_diagonal();
	for (i = 0; i<9; i++){
		if (board[i] == '-'){
			j--;
		}
	}
	if (j == 9 && row_winner == 'N' && column_winner == 'N' && diagonal_winner == 'N'){
		game_active = false;
		winner = 'D'; // 'D' here implies the game has been concluded as a draw
	}
}

int game_turn(char current_player){ //function that specifies player's turn respectively, turn refering 'X' or 'O'
	int i,j,k;
	int board_position;
	bool correct = false;
	int board_input[9] = {1,2,3,4,5,6,7,8,9};

	printf("%c", current_player);
	printf("'s turn\n"); 
	printf("Enter your board position: ");
	scanf("%d", &board_position);
	printf("\n");

	while (!correct){
		if (board[board_position-1] != '-'){
			printf("Please enter correctly: ");
			scanf("%d", &board_position);
		}
		else{
			for (i=0; i<9; i++){
				if (board_position == board_input[i]){
					switch(board_position){// switch statement to check and address according to input
						case 1:
							board[0] = current_player;
							correct = true;
							break;
						case 2:
							board[1] = current_player;
							correct = true;
							break;
						case 3:
							board[2] = current_player;
							correct = true;
							break;
						case 4:
							board[3] = current_player;
							correct = true;
							break;
						case 5:
							board[4] = current_player;
							correct = true;
							break;
						case 6:
							board[5] = current_player;
							correct = true;
							break;
						case 7:
							board[6] = current_player;
							correct = true;
							break;
						case 8:
							board[7] = current_player;
							correct = true;
							break;
						case 9:
							board[8] = current_player;
							correct = true;
							break;
					}
				}
			}
		}
	}
	system("cls");
	display_board(board);

	return 0;			
	
}

void player_select(){ //select the player 'X' or 'o'
	bool correct = false;
	char player_input ; // temp varibale to store what player inputs
	printf("Enter the player you want to start as(X/O): ");
	player_input = getchar();
	printf("\n");
	while(!correct){
		if(player_input == 'X' || player_input == 'x'){
			current_player = 'X';
			correct = true;
			system("cls");
		}

		else if( player_input == 'O' || player_input == 'o' || player_input == '0'){
			current_player = 'O';
			correct = true;
			system("cls");
		}

		else{
			printf("please enter valid input: ");
			player_input = getchar();
		}

	}
}



/* to be done list 

*work on single player mode as well(automate the second player)

*/

