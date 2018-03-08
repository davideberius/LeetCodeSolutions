#include <stdlib.h>

bool isValidRow(char* start){
    int i, index, found[9] = {0};
    
    for(i = 0; i < 9; i++){
        if(start[i] == '.')
            continue;
        index = start[i] - '0' - 1;
        if(found[index] == 1)
            return false;
        found[index] = 1;
    }
    return true;
}

bool isValidCol(char** board, int col){
    int i, index, found[9] = {0};
    
    for(i = 0; i < 9; i++){
        if(board[i][col] == '.')
            continue;
        index = board[i][col] - '0' - 1;
        if(found[index] == 1)
            return false;
        found[index] = 1;
    }
    return true;
}

bool isValidBlock(char** board, int row, int col){
    int i, j, index, found[9] = {0};
    
    for(i = row; i < row+3; i++){
        for(j = col; j < col+3; j++){
            if(board[i][j] == '.')
                continue;
            index = board[i][j] - '0' - 1;
            if(found[index] == 1)
                return false;
            found[index] = 1;
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    if(boardRowSize != 9  || boardColSize != 9)
        return false;
    
    int i, j;
    for(i = 0; i < boardRowSize; i++){
        if(!isValidRow(board[i]))
            return false;
    }
    for(i = 0; i < boardRowSize; i++){
        if(!isValidCol(board, i))
            return false;
    }
    for(i = 0; i < boardRowSize; i += 3){
        for(j = 0; j < boardColSize; j += 3){
            if(!isValidBlock(board, i, j))
                return false;
        }
    }
    return true;
}
