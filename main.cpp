#include<iostream>
#include<memory>
#include"TicTacToe.h"
using namespace std;


int main(){
   unique_ptr<TicTacToe>t=make_unique<TicTacToe>();
t->driver();
    
    
   
    return 0;
    }