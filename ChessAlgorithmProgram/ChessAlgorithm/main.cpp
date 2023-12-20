#include <iostream>
#include "ChessBoard.h"

int main() {
    ChessBoard chess_board;

    while (true) {
        std::string input;
        std::cin >> input;

        std::cout << "move: " << chess_board.movePiece(input) << std::endl;

        chess_board.printBoard();

        //chess_board.s

        std::cout << std::endl << std::endl;
    }



    //Coordinates piece = {1, 2};
    //std::vector<Coordinates> poss_moves = chess_board.getPossibleMovesOfPiece(piece);
    //chess_board.showPossibleMoves(poss_moves, piece);



    return 0;
}
