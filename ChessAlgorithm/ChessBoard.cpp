#include "ChessBoard.h"
#include <iostream>


void ChessBoard::printBoard() {
    std::cout << "    A B C D E F G H" << std::endl << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << "   ";

        for (int j = 0; j < 8; j++) {
            std::cout << board_data[i][j];

            if (j < 7)
                std::cout << ' ';
        }

        std::cout << std::endl;
    }



}

ChessBoard::ChessBoard() {

}
