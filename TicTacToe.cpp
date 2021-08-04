#include "TicTacToe.h"
#include<iostream>
#include"conio.h"
#include"windows.h"

using namespace std;
TicTacToe::TicTacToe()
:currentPlayer{X}{// first here we initialize X to be the first one who play
    int count{1};// in the nested loop we initialize the 2D matrix row by row put the counter in each element 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=count;
            count++;
        }
    }
        
}

    void TicTacToe::input(const int pos){//Take the position search for it and assign the value to it then switch the player
        if(pos<=3)
         setter(0,pos);
        else if(pos<=6)
                setter(1,pos);
        else if(pos<=9)
                setter(2,pos);
        else
             cout<<"Number out side range"<<endl;
    }
    void TicTacToe::setter(const int n,const int p){
         for(int j=0;j<3;j++){
                if(board[n][j]==p){
                    board[n][j]=currentPlayer;
                        currentPlayer=-currentPlayer;
                }
        } 
    }

    bool TicTacToe::isWin(const int mark)const{// Check for  the winner  depending on the mark 
             int win=mark*3;
    return ((board[0][0]+board[0][1]+board[0][2]==win)
    ||(board[1][0]+board[1][1]+board[1][2]==win)
    ||(board[2][0]+board[2][1]+board[2][2]==win)
    ||(board[0][0]+board[1][0]+board[2][0]==win)
    ||(board[0][1]+board[1][1]+board[2][1]==win)
    ||(board[0][2]+board[1][2]+board[2][2]==win)
    ||(board[0][0]+board[1][1]+board[2][2]==win)
    ||(board[2][0]+board[1][1]+board[0][2]==win));
        }
    int TicTacToe::get_winner() const{
        if(isWin(X)) return X;
        else if(isWin(O)) return O;
        else 
            return EMPTY;
        }
        
void TicTacToe::driver(){
    int n={0};
    cout<<*this;
    while(1!=0){
n=getch()-'0';
        input(n);
system("cls");
cout<<*this;
    
    }
}



 std::ostream& operator<<(std::ostream &os,const TicTacToe &obj){
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
switch(obj.board[i][j]){
    case obj.X: os<<"X";break;
    case obj.O: os<<"O";break;
    default:
    os<<obj.board[i][j];
    }
   
    if(j<2) os<<"|";
            }
         if(i<2)   os<<"\n-+-+-\n";
    }
    os<<endl;
    int winner=obj.get_winner();
    if(winner!=obj.EMPTY){
        cout<<" "<<(winner==obj.X ? 'X':'O')<<":is The Winner"<<endl;
exit(0);
    }
        else{
            cout<<"Tie"<<endl;
            }
            
return os;
}

