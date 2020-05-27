

#include <iostream>

using namespace std;

void createtable(char table[6][7]){ //fills board with underscore
    for(int row = 0; row < 7; row++){
        for(int column = 0; column < 7; column++){
            table[row][column] = '_';
        }
    }
}

void displaytable(char table[6][7]){
    for(int row=0; row<6;row++){
        for(int column=0; column<7;column++){
            cout<<table[row][column]<<' ';
            
        
        }
        cout<<endl;
        
    }
    for(int c = 1; c <= 7; ++c)
        cout<<c<<' ';//display numbers below board
        cout<<endl;
    
}
bool checkwin(int row, int column, char player, char table[6][7]){
    if(row+3 < 6 && player == table[row+1][column] && player ==table[row+2][column] && player == table[row+3][column])
        return true; //vertical check
        
    int p;
    for(int i = 0; i <= 3; ++i)//horizontal check
        if(column-i >= 0 && player == table[row][column-i])
            p = i;
        else
            i = 4;
    if(column-p+3 < 7 && player == table[row][column-p+1] && player == table[row][column-p+2] && player == table[row][column-p+3])
        return true;
    
    for(int i = 0; i <= 3; ++i)//digonal check
        if(row+i < 6 && column-i >= 0 && player == table[row+i][column-i])
            p = i;
        else
            i = 4;
    if(row+p-3 >= 0 && column-p+3 < 7 && player == table[row+p-1][column-p+1] && player == table[row+p-2][column-p+2] && player == table[row+p-3][column-p+3])
        return true;
    
    for(int i = 0; i <= 3; ++i)
        if(row+i < 6 && column+i < 7 && player == table[row+i][column+i])
            p = i;
        else
            i = 4;
    if(row+p-3 >= 0 && column+p-3 >= 0 && player == table[row+p-1][column+p-1] && player == table[row+p-2][column+p-2] && player == table[row+p-3][column+p-3])
        return true;
    
    return false;
        
}
int findrow(char table[6][7], int column){
    for(int row = 5; row >= 0; row--)
        if(table[row][column-1] == '_'){
            return row;
        }
    
}
            
void drop(char player, int column, char table[6][7]){ //drops X and Os
    for(int row = 5; row >= 0; row--)
        if(table[row][column-1] == '_'){
            table[row][column-1] = player;
            break;
            
}
}
int main()
{
    cout<<"Welcome to connect 4. Beat your opponent by having four blocks in the same row, column, or diagonals."
    int column;
    int row;
    char table[6][7];
    bool win = false;
    createtable(table); 
    while(win = true){
        displaytable(table);   //X's turn
        cout<<"Please select a column to drop:";
        cin>>column;
        row = findrow(table, column);
        drop('X', column, table);
        if(checkwin(row, column-1, 'X', table)==true){
            cout<<"Congratulations the winner is X";
            break;
            
        }
        displaytable(table);
        
        displaytable(table);   //O's turn
        cout<<"Please select a column to drop:";
        cin>>column;
        row = findrow(table, column);
        drop('O', column, table);
        if(checkwin(row, column-1, 'O', table)==true){
            cout<<"Congratulations the winner is O";
            break;
            
        }
        displaytable(table);
        
        
        
    }
    
    
    
}
