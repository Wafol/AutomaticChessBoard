#include <iostream>
#include "ChessBoard.h"

int main() {
    ChessBoard chess_board;
    Coordinates piece = {3, 5};
    std::vector<Coordinates> poss_moves = chess_board.getPossibleMovesOfPiece(piece);
    chess_board.showPossibleMoves(poss_moves, piece);

    chess_board.printBoard();

    return 0;
}
