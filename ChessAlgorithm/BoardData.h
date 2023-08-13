//
// Created by pavel on 8/13/2023.
//

#ifndef CHESSALGORITHM_BOARDDATA_H
#define CHESSALGORITHM_BOARDDATA_H

#include <vector>

typedef struct Coordinates {
    int x;
    int y;
} Coordinates;

enum PlayerType {
    PLAYER_1, //person
    PLAYER_2, //computer
    NONE
};

//this class provides xy cartesian interface to 2d array of board data
class BoardData {
public:
    void printBoard() const;

protected:
    //get element from board array (x or y must be <= 7)
    char get(int x, int y) const;
    void set(int x, int y, char val);

    static PlayerType WhoseIsThePiece(char piece);

private:
    //    PAWN = 'p'; pesak
    //    KNIGHT = 'n'; strelec
    //    BISHOP = 'b'; kun
    //    ROOK = 'r'; vez
    //    QUEEN = 'q'; kralovna
    //    KING = 'k'; kral
    // PLAYER1, player2
    //[row][coll]
    std::vector<std::vector<char>> board_data_arr =
            {{'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r'},
             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
             {'R', 'B', 'N', 'Q', 'K', 'N', 'B', 'R'}};

    //converts xy to rows and columns
    static void convertXYtoIJ(int x, int y, int& i, int& j);

    //this func flips the game board like if the board was turned 180deg
    void flipBoardData();
};


#endif //CHESSALGORITHM_BOARDDATA_H
