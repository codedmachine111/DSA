#include <stdio.h>
#include <stdlib.h>

void board_init(int (*arr)[50]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            arr[i][j] = 0;
        }
    }
    int pawn = 1;
    for(int i=0; i<8; i++){
        arr[1][i] = pawn;
        arr[6][i] = pawn;
    }

    int bishop =2;
    arr[0][2] = bishop;
    arr[0][5] = bishop;
    arr[7][2] = bishop;
    arr[7][5] = bishop;

    int knight = 3;
    arr[0][1] = knight;
    arr[0][6] = knight;
    arr[7][1] = knight;
    arr[7][6] = knight;

    int rook = 4;
    arr[0][0] = rook;
    arr[0][7] = rook;
    arr[7][0] = rook;
    arr[7][7] = rook;

    int queen = 5;
    arr[0][3] = queen;
    arr[7][3] = queen;

    int king = 6;
    arr[0][4] = king;
    arr[7][4] = king;

}

void print_board(int (*arr)[50]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void find_position(int (*arr)[50], int x, int y){
    arr[x][y] = 1;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i==x || j==y){
                arr[i][j] = 1;
            }
        }
    }
}

void move_pawn(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 1){
        if(x1 == 1){
            if(x2 == x1+1 || x2 == x1+2){
                arr[x1][y1] = 0;
                arr[x2][y2] = 1;
            }
        }
        else{
            if(x2 == x1+1){
                arr[x1][y1] = 0;
                arr[x2][y2] = 1;
            }
        }
    }
}

void move_rook(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 4){
        if(x1 == x2 || y1 == y2){
            arr[x1][y1] = 0;
            arr[x2][y2] = 4;
        }
    }
}

void move_bishop(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 2){
        if(x1 == x2 || y1 == y2){
            arr[x1][y1] = 0;
            arr[x2][y2] = 2;
        }
    }
}

void move_knight(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 3){
        if(x1 == x2 || y1 == y2){
            arr[x1][y1] = 0;
            arr[x2][y2] = 3;
        }
    }
}

void move_queen(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 5){
        if(x1 == x2 || y1 == y2){
            arr[x1][y1] = 0;
            arr[x2][y2] = 5;
        }
    }
}

void move_king(int (*arr)[50], int x1, int y1, int x2, int y2){
    if(arr[x1][y1] == 6){
        if(x1 == x2 || y1 == y2){
            arr[x1][y1] = 0;
            arr[x2][y2] = 6;
        }
    }
}



int main(){
    int board[50][50];
    board_init(board);
    print_board(board);

    int x1, y1, x2, y2;
    int piece;

    while(1){
        printf("Enter the piece to move: ");
        scanf("%d", &piece);
        switch(piece){
            case 1:
                printf("Enter the position of the pawn : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_pawn(board, x1, y1, x2, y2);
                print_board(board);
                break;
            case 2:
                printf("Enter the position of the bishop : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_bishop(board, x1, y1, x2, y2);
                print_board(board);
                break;
            case 3:
                printf("Enter the position of the Knight : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_bishop(board, x1, y1, x2, y2);
                print_board(board);
                break;
            case 4:
                printf("Enter the position of the rook : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_rook(board, x1, y1, x2, y2);
                print_board(board);
                break;
            case 5:
                printf("Enter the position of the Queen : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_bishop(board, x1, y1, x2, y2);
                print_board(board);
                break;
            case 6:
                printf("Enter the position of the King : ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the position to move to : ");
                scanf("%d %d", &x2, &y2);
                move_bishop(board, x1, y1, x2, y2);
                print_board(board);
                break;
            default:
                printf("Invalid piece\n");
        }
    }
        
    return 0;
}