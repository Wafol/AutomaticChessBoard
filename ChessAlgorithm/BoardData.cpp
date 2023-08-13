
#include "BoardData.h"

#include <iostream>
#include <cctype>

void BoardData::printBoard() const {
    std::cout << "    A B C D E F G H" << std::endl << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << "   ";

        for (int j = 0; j < 8; j++) {
            std::cout << board_data_arr.at(i).at(j);

            if (j < 7)
                std::cout << ' ';
        }

        std::cout << std::endl;
    }
}

PlayerType BoardData::WhoseIsThePiece(char piece) {
    if (piece == '.')
        return NONE;

    return isupper(piece) ? PLAYER_1 : PLAYER_2;
}


char BoardData::get(int x, int y) const {
    int i, j;
    convertXYtoIJ(x, y, i, j);

    return board_data_arr.at(i).at(j);
}

void BoardData::set(int x, int y, char val) {
    int i, j;
    convertXYtoIJ(x, y, i, j);

    board_data_arr.at(i).at(j) = val;
}


void BoardData::convertXYtoIJ(int x, int y, int& i, int& j) {
    i = abs(y - 7);
    j = x;
}

void BoardData::flipBoardData() {
    //flipping rows
    std::vector<char> mem_vec;

    for (int i = 0; i < 4; i++) {
        mem_vec = board_data_arr.at(7 - i);

        board_data_arr.at(7 - i) = board_data_arr.at(i);
        board_data_arr.at(i) = mem_vec;
    }

    //flipping columns
    for (int i = 0; i < 8; i++) {
        std::vector<char>* row = &board_data_arr.at(i);

        for (int j = 0; j < 4; j++) {
            char mem_piece = row->at(7 - j);

            row->at(7 - j) = row->at(j);
            row->at(j) = mem_piece;
        }
    }
}
