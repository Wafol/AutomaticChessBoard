//
// Created by pavel on 25.07.2023.
//

#ifndef CHESSALGORITHM_CHESSBOARD_H
#define CHESSALGORITHM_CHESSBOARD_H


class ChessBoard {
public:
    ChessBoard();

    void printBoard();


private:
    //    PAWN = 'p'; pesak
    //    KNIGHT = 'n'; strelec
    //    BISHOP = 'b'; kun
    //    ROOK = 'r'; vez
    //    QUEEN = 'q'; kralovna
    //    KING = 'k'; kral
    char board_data[8][8] = {{'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r'},
                             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                             {'R', 'B', 'N', 'Q', 'K', 'N', 'B', 'R'}};

};


#endif //CHESSALGORITHM_CHESSBOARD_H
