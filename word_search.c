/*
    79. Word Search
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
//my ugly implementation. the general direction is correct
bool helper(
    // row: the current row index
    int row,

    // col: the current column index
    int col,

    // rowSize: size of board
    int rowSize,

    // colSize: size of board[i]
    int colSize,

    // word: target word
    char* word,

    // board: provided 2d array
    int** board,

    // word length
    int wordlen,

    // see the word count, start from 0
    int count,

    bool** visited
)
{
    if(row < 0 || rowSize <= row) return false;
    if(col < 0 || colSize <= col) return false;

    if(*word == board[row][col]){
        ++count;
        if(count == wordlen){
            return true; // full word found
        }

        visited[row][col] = true;

        // make recursive call here
        bool up = helper(row-1, col, rowSize, colSize, word+1, board, wordlen, count, visited);
        bool down = helper(row+1, col, rowSize, colSize, word+1, board, wordlen, count, visited);
        bool left = helper(row, col-1, rowSize, colSize, word+1, board, wordlen, count, visited);
        bool right = helper(row, col+1, rowSize, colSize, word+1, board, wordlen, count, visited);
        if(up || down || left || right){
            return true;
        } else {
            --count;
            return false;
        }
    } else {
        return false;
    }
}

bool exist(
    char** board, int boardSize, int* boardColSize, char * word)
{
    bool visited[boardSize][*boardColSize];
    int length = strlen(word);
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < *boardColSize; ++j){
            if(*word == board[i][j]){
                visited[i][j] = false;
                if(helper(i, j, boardSize, *boardColSize, word, board, length, 0, visited)){
                    return true;
                }
                visited[i][j] = false;
            }
        }
    }
    return false;
}
*/

bool helper(
    int row,
    int col,
    int rowSize,
    int colSize,
    char* word,
    char** board,
    int wordlen,
    int count,
    bool** visited
)
{
    if(row < 0 || row >= rowSize || col < 0 || col >= colSize || visited[row][col] || board[row][col] != *word){
        return false;
    }

    visited[row][col] = true;

    if(count+1 == wordlen){
        return true; // full word found
    }

    // make recursive call here
    bool found = helper(row-1, col, rowSize, colSize, word+1, board, wordlen, count+1, visited) ||
                 helper(row+1, col, rowSize, colSize, word+1, board, wordlen, count+1, visited) ||
                 helper(row, col-1, rowSize, colSize, word+1, board, wordlen, count+1, visited) ||
                 helper(row, col+1, rowSize, colSize, word+1, board, wordlen, count+1, visited);

    visited[row][col] = false;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    int length = strlen(word);
    
    // Dynamically allocate memory for `visited` here
    bool** visited = (bool**)malloc(boardSize * sizeof(bool*));
    for(int i = 0; i < boardSize; ++i){
        visited[i] = (bool*)malloc(boardColSize[i] * sizeof(bool));
        memset(visited[i], 0, boardColSize[i] * sizeof(bool));
    }

    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardColSize[i]; ++j){
            if(helper(i, j, boardSize, boardColSize[i], word, board, length, 0, visited)){
                // Free the memory for `visited` before returning
                for(int k = 0; k < boardSize; ++k)
                    free(visited[k]);
                free(visited);

                return true;
            }
        }
    }
    // Free the memory for `visited` before returning
    for(int k = 0; k < boardSize; ++k)
        free(visited[k]);
    free(visited);

    return false;
}
