#ifndef CHESSALGORITHM_BOARDDATA_H
#define CHESSALGORITHM_BOARDDATA_H

#include <vector>

class Coordinates {
public:
    int x;
    int y;

    Coordinates() = default;

    Coordinates(int x, int y): x(x), y(y) {
    }

    //adds new coordinates to the old ones
    void addCoordinates(Coordinates xy_plus) {
        x += xy_plus.x;
        y += xy_plus.y;
    }

    void minusCoordinates(Coordinates xy_minus) {
        x -= xy_minus.x;
        y -= xy_minus.y;
    }
};

enum PlayerType {
    PLAYER_1, //person
    PLAYER_2, //computer
    NONE
};

//this class provides xy cartesian interface to 2d array of board data
class BoardData {
public:
    static void printBoard(std::vector<std::vector<char>> board_data_arr);
    void printBoard() const { printBoard(board_data_arr); };

    void showPossibleMoves(const std::vector<Coordinates>& possible_moves, Coordinates piece_xy) const;

protected:
    //get element from board array (x or y must be <= 7)
    char getBoardData(Coordinates pos) const;
    void setBoardData(Coordinates pos, char val);

    static PlayerType WhoseIsThePiece(char piece);
    static bool areCoordinatesOnBoard(Coordinates pos);

private:
    //    PAWN = 'p'; pesak
    //    KNIGHT = 'n'; kun
    //    BISHOP = 'b'; strelec
    //    ROOK = 'r'; vez
    //    QUEEN = 'q'; kralovna
    //    KING = 'k'; kral
    //    NONE = '.'; prazdno
    // PLAYER1, player2
    //[row][coll]
    std::vector<std::vector<char>> board_data_arr =
            {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
             {'.', '.', '.', 'K', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.'},
             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
             {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    //converts xy to rows and columns
    static void convertXYtoIJ(int x, int y, int& i, int& j);

    //this func flips the game board like if the board was turned 180deg and FLIPS THE COLOR OF PIECES
    void flipBoardData();
    static void flipColorOfPiece(char* piece);
};


#endif //CHESSALGORITHM_BOARDDATA_H
