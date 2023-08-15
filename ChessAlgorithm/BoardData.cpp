
#include "BoardData.h"

#include <iostream>
#include <cctype>

void BoardData::printBoard(std::vector <std::vector<char>> board_data_arr) {
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

void BoardData::showPossibleMoves(const std::vector<Coordinates>& possible_moves, Coordinates piece_xy) const {
    BoardData helper_board_arr = *this;

    for (Coordinates pos : possible_moves) {
        piece_xy.addCoordinates(pos);
        helper_board_arr.setBoardData(piece_xy, 'X');
        piece_xy.minusCoordinates(pos);
    }

    helper_board_arr.printBoard();
}


PlayerType BoardData::WhoseIsThePiece(char piece) {
    if (piece == '.')
        return NONE;

    return isupper(piece) ? PLAYER_1 : PLAYER_2;
}


char BoardData::getBoardData(Coordinates pos) const {
    int i, j;
    convertXYtoIJ(pos.x, pos.y, i, j);

    return board_data_arr.at(i).at(j);
}

void BoardData::setBoardData(Coordinates pos, char val) {
    int i, j;
    convertXYtoIJ(pos.x, pos.y, i, j);

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
            //flip the color
            flipColorOfPiece(&row->at(7 - j));
            flipColorOfPiece(&row->at(j));

            //flip the pieces
            char mem_piece = row->at(7 - j);

            row->at(7 - j) = row->at(j);
            row->at(j) = mem_piece;
        }
    }
}

bool BoardData::areCoordinatesOnBoard(Coordinates pos) {
    if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y > 7)
        return false;

    return true;
}

void BoardData::flipColorOfPiece(char* piece) {
    if (isupper(*piece))
        *piece = (char) tolower(*piece);
    else
        *piece = (char) toupper(*piece);
}


