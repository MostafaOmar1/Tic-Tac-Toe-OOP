#ifndef TICTACTOE_H
#define TICTACTOE_H
#include<iostream>
class TicTacToe
{
    friend std::ostream& operator<<(std::ostream &os,const TicTacToe &obj);
private:
int board[3][3];
 int currentPlayer=0;
static constexpr int X=10;
static constexpr int O=-10;
static constexpr int EMPTY=0;


public:
    TicTacToe();
    bool isWin(const int mark)const;
    int get_winner()const;
    void input(const int pos);
    void setter(const int n,const int p);
    void driver();
    ~TicTacToe()=default;

};

#endif // TICTACTOE_H
