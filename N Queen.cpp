#include<iostream>
using namespace std;
#define N 5

void printBoard(int board[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << "  ";
      cout << endl;
   }
}

bool isValid(int board[N][N], int row, int col) {
    //check whether there is queen in the left or not
   for (int i = 0; i < col; i++)
      if (board[row][i])
         return false;

   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
       //check whether there is queen in the left upper diagonal or not
      if (board[i][j])
         return false;

   for (int i=row, j=col; j>=0 && i<N; i++, j--)

       //check whether there is queen in the left lower diagonal or not
      if (board[i][j])
         return false;

   return true;
}

bool solveNQueen(int board[N][N], int col) {
    //when N queens are placed successfully
   if (col >= N)
      return true;

  //for each row, check placing of queen is possible or not
   for (int i = 0; i < N; i++) {
      if (isValid(board, i, col) ) {
         //if validate, place the queen at place (i, col)
         board[i][col] = 1;
         //Go for the other columns recursively
         if ( solveNQueen(board, col + 1))
            return true;

         //When no place is vacant remove that queen
         board[i][col] = 0;
      }
   }
   //when no possible order is found
   return false;
}

bool checkSolution() {
   int board[N][N];
   for(int i = 0; i<N; i++)
      for(int j = 0; j<N; j++)
         board[i][j] = 0;      //set all elements to 0

   if ( solveNQueen(board, 0) == false ) {     //starting from 0th column
      cout << "Solution does not exist";
      return false;
   }
   printBoard(board);
   return true;
}

int main() {
    // cin>>N;
   checkSolution();
}
