// 01FE21BEC263 | 519 | E | AKASH S NAYAK
// BACKTRACKING ALGORITHM
// PROGRAM TO PLACE N QUEENS ON A CHESSBOARD SUCH THAT NO QUEEN ATTACKS ANY OTHER QUEEN
// DATA STRUCTURE USED: 2D ARRAY
// TIME COMPLEXITY: O(n!)

#include <stdio.h>
#include <stdlib.h>

#define N 4
int chess_board[N][N];

int isSafe(int row, int col){
    int i,j;

    // CHECKING FOR QUEENS IN THE SAME ROW
    for(i=0; i<col; i++){
        if(chess_board[row][i]){
            // NOT SAFE
            return 0;
        }
    }

    // CHECKING FOR QUEENS IN THE UPPER DIAGONAL
    for (i=row, j=col; i>=0 && j>=0; i--, j--){
        if(chess_board[i][j]){
            // NOT SAFE
            return 0;
        }
    }

    for (i=row, j=col; j>=0 && i<N; i++, j--){
        if(chess_board[i][j]){
            // NOT SAFE
            return 0;
        }
    }

    // SAFE
    return 1;
}

int solveNQueens(int col){
    if(col == N){
        return 1;
    }
    int res=0;

    // CHECKING FOR EACH ROW
    for(int i=0; i<N; i++){
        if(isSafe(i,col)){
            chess_board[i][col] = 1;

            // RECURSIVE CALL TO CHECK FOR THE NEXT COLUMN
            res = solveNQueens(col+1);

            // IF THE NEXT COLUMN IS NOT SAFE, THEN BACKTRACK
            if(res){
                return 1;
            }
            chess_board[i][col] = 0;
        }
    }
    return res;
}
int main(){
    int i,j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            chess_board[i][j] = 0;
        }
    }

    if(solveNQueens(0)){
        for(i =0; i<N; i++){
            for(j=0; j<N; j++){
                printf("%d ", chess_board[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("No solution exists");
    }

    return 0;
}
