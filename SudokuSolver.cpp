// It has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. 
// Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true and also print the board,
// otherwise print false.


#include<bits/stdc++.h>
using namespace std;
int sud[9][9];

bool isSolved(int sud[][9] ,int &row,int &col){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(sud[i][j]==0){
                row=i;
                col=j;
                return false;
            }
    return true;
}

bool valid(int sud[][9],int row,int col,int x){
    //check row
    for(int j=0;j<9;j++)
        if(sud[row][j]==x)
            return false;
    //check col
    for(int i=0;i<9;i++)
        if(sud[i][col]==x)
            return false;
    //check its box
    int rowfac=row-(row%3);
    int colfac=col-(col%3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(sud[i+rowfac][j+colfac]==x)
                return false;
    return true;
    
}

bool solve(int sud[][9]){
    int row,col;
    if(isSolved(sud,row,col))
        return true;
    
    for(int i=1;i<=9;i++){
        if(valid(sud,row,col,i)){
            sud[row][col]=i;
            if(solve(sud))
                return true;
            sud[row][col]=0;
        }
    }
    return false;
}

int main(){
    
    // write your code here
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>sud[i][j];
    }
    if(solve(sud)){
        cout<<"true"<<endl;
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<sud[i][j];
            cout<<endl;
    }
    }
    else
        cout<<"false";
    
    return 0;
}