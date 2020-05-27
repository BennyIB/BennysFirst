#include <iostream>
#include <ctime>
#include <time.h>
#include <array>
using namespace std;

char cpuboard[10][10]; // the ships are placed here
char playerboard[10][10]; // the board that the player sees

// resets the board to all underscores
void reset(char b[10][10]);

// displays board b with letter and numbers
void display(char b[10][10]);

//check win
bool checkWin(char playerboard[10][10]){
    int counter = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(playerboard[i][j] == 'X'){
                counter++;

            }

        }

    }
    if(counter == 17){
        return true;
    }
    else{
        return false;
    }
}

//places battle ship into the board
void PlaceShip(int size, char letter, char board[10][10], int counter){
    srand (time(NULL) + counter);
    int orient = rand() % 2; // 0 for vertical and 1 for horizontal
    int xaxis = rand() % 10;
    int yaxis = rand() % 10;

    if(letter == 'A'){ // makes sure none of the letters overlap.

        if(orient == 0 && yaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis][yaxis+1] == '_' && board[xaxis][yaxis+2] == '_' && board[xaxis][yaxis+3] == '_' && board[xaxis][yaxis+4] == '_' && board[xaxis][yaxis+5] == '_' ){

            for(int i = 0; i < size; i++){
                board[xaxis][yaxis+i] = letter;
            }
        }
        else if(orient == 1 && xaxis + size < 10 &&board[xaxis][yaxis] == '_' && board[xaxis+1][yaxis] == '_' && board[xaxis+2][yaxis] == '_' && board[xaxis+3][yaxis] == '_' && board[xaxis+4][yaxis] == '_' && board[xaxis+5][yaxis] == '_' ){
            for(int i = 0; i < size; i++){
                board[xaxis+i][yaxis] = letter;
            }
        }
        else{
            PlaceShip(size, letter, board, counter + 1);
        }


    }

    else if(letter == 'B'){ // makes sure none of the letters overlap.

        if(orient == 0 && yaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis][yaxis+1] == '_' && board[xaxis][yaxis+2] == '_' && board[xaxis][yaxis+3] == '_' && board[xaxis][yaxis+4] == '_' ){
            for(int i = 0; i < size; i++){
                board[xaxis][yaxis+i] = letter;
            }
        }
        else if(orient == 1 && xaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis+1][yaxis] == '_' && board[xaxis+2][yaxis] == '_' && board[xaxis+3][yaxis] == '_' && board[xaxis+4][yaxis] == '_' ){
            for(int i = 0; i < size; i++){
                board[xaxis+i][yaxis] = letter;
            }
        }
        else{
          PlaceShip(size, letter, board, counter + 1);
        }


    }
    else if(letter == 'C'){ // makes sure none of the letters overlap.

        if(orient == 0 && yaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis][yaxis+1] == '_' && board[xaxis][yaxis+2] == '_' && board[xaxis][yaxis+3] == '_'){
            for(int i = 0; i < size; i++){
                board[xaxis][yaxis+i] = letter;
            }
        }
        else if(orient == 1 && xaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis+1][yaxis] == '_' && board[xaxis+2][yaxis] == '_' && board[xaxis+3][yaxis] == '_'){
            for(int i = 0; i < size; i++){
                board[xaxis+i][yaxis] = letter;
            }
        }
       else{
            PlaceShip(size, letter, board, counter + 1);
        }


    }
    else if(letter == 'S'){ // makes sure none of the letters overlap.

        if(orient == 0 && yaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis][yaxis+1] == '_' && board[xaxis][yaxis+2] == '_' && board[xaxis][yaxis+3] == '_'){
            for(int i = 0; i < size; i++){
                board[xaxis][yaxis+i] = letter;
            }
        }
        else if(orient == 1 && xaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis+1][yaxis] == '_' && board[xaxis+2][yaxis] == '_' && board[xaxis+3][yaxis] == '_'){
            for(int i = 0; i < size; i++){
                board[xaxis+i][yaxis] = letter;
            }
        }
       else{
            PlaceShip(size, letter, board, counter + 1);
        }


    }
    else if(letter == 'D'){ // makes sure none of the letters overlap.

        if(orient == 0 && yaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis][yaxis+1] == '_' ){
            for(int i = 0; i < size; i++){
                board[xaxis][yaxis+i] = letter;
            }
        }
        else if(orient == 1 && xaxis + size < 10 && board[xaxis][yaxis] == '_' && board[xaxis+1][yaxis] == '_' ){
            for(int i = 0; i < size; i++){
                board[xaxis+i][yaxis] = letter;
            }
        }
        else{
            PlaceShip(size, letter, board, counter + 1);
        }


    }


}
void fireShip(char cpuboard[10][10], char playerboard[10][10], string coordinates ) //fires to the other board and place X or O in the map
{
   char xaxis = coordinates[0];
   char yaxis = coordinates[1];
   int coordinate1;
   int coordinate2;

   if(coordinates.length() == 3){
     coordinate2 = 9;
   }
   else{
     coordinate2 = int(yaxis) - 49;
   }
   if(xaxis == 'A'){
       coordinate1 = 0;

   }
   if(xaxis == 'B'){
       coordinate1 = 1;

   }
   if(xaxis == 'C'){
       coordinate1 = 2;

   }
   if(xaxis == 'D'){
       coordinate1 = 3;

   }
   if(xaxis == 'E'){
       coordinate1 = 4;

   }
   if(xaxis == 'F'){
       coordinate1 = 5;

   }
   if(xaxis == 'G'){
       coordinate1 = 6;

   }
   if(xaxis == 'H'){
       coordinate1 = 7;

   }
   if(xaxis == 'I'){
       coordinate1 = 8;

   }
   if(xaxis == 'J'){
       coordinate1 = 9;

   }
   if(cpuboard[coordinate2][coordinate1] != '_'){
       playerboard[coordinate2][coordinate1] = 'X';
   }
   else{
       playerboard[coordinate2][coordinate1] = 'O';
   }
}


int main(){
  int moves = 0;
  bool win = false;
	reset(cpuboard);
	reset(playerboard);
	PlaceShip(5, 'A', cpuboard, 0);
	PlaceShip(4, 'B', cpuboard, 0);
	PlaceShip(3, 'C', cpuboard, 0);
  PlaceShip(3, 'S', cpuboard, 0);
	PlaceShip(2, 'D', cpuboard, 0);
	display(cpuboard);
	cout << endl;
	int difficulty = 0;
	string coordinate;
	display(playerboard);
  //playerboard[9][0] = 'B';
	cout<< endl;
	cout << "Please type in the number of turns you would like: 70 for easy, 50 for medium, and 30 for hard:";
	cin >> moves;
	while(moves != 0){
	    display(playerboard);
      cout<<endl;
      cout<<"You have this many moves left:";
      cout<<moves;

	    cout<< endl;
	    int difficulty = 0;
	    cout << "Please type in a coordinate(ex. A1) also 'X' means a hit while 'O' is a miss:";
	    cin >> coordinate;
	    fireShip(cpuboard, playerboard, coordinate);
	    if(checkWin(playerboard)==true){
	        break;
	    }
	    moves--;
	}
	if(checkWin(playerboard)==true){
	    cout<<"congrats you have won the game";
	}
	else{
	    cout<<"Sorry, looks like you loss.";
	}

}

void reset(char b[10][10]){
	for(int r=0; r<10; r++){
		for(int c = 0; c<10; c++){
			b[r][c] = '_';
		}
	}
}

void display(char b[10][10]){


	cout << endl;
	for(int r=0; r<10; r++){
		if(r<9){
			cout <<" ";
		}
		cout << r+1 <<" ";
		for(int c = 0; c<10; c++){
			cout << b[r][c] << " ";
		}
		cout << endl;
	}

	cout << "   ";
	for(char letter = 'A'; letter < 'A' + 10; letter++){
		cout << letter << " ";
	}
}
