#include "ChessBoard.h"
#include <iostream>
#include <cctype>
#include <cstring>


ChessBoard::ChessBoard() {
    //fill up moves rules
    //PAWN
    std::vector<MoveRule> pawn_rules;

    MoveRule move_rule;
    move_rule.move_dir = {0, 1};
    pawn_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {0, 2};
    move_rule.only_first_touch = true;
    pawn_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 1};
    move_rule.only_to_attack_enemy = true;
    pawn_rules.push_back(move_rule);

    piecesMoveRules['p'] = pawn_rules;

    //KNIGHT
}
/*
std::vector<ChessBoard::PieceMove> ChessBoard::getPossibleMoves(PlayerType player_type) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (ChessBoard::WhoseIsThePiece(board_data[i][j]) == PLAYER_1) {

            }
        }
    }

    return std::vector<PieceMove>();
}





std::vector<ChessBoard::PieceMove> ChessBoard::getPossibleMovesOfPiece(int piece_i, int piece_j) {
    if (board_data[][] == ROOK) {

    }
}
*/

