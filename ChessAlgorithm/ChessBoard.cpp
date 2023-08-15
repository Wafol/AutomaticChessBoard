#include "ChessBoard.h"
#include <iostream>
#include <cctype>


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

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 1};
    move_rule.only_to_attack_enemy = true;
    pawn_rules.push_back(move_rule);

    pieces_move_rules['P'] = pawn_rules;

    //KNIGHT
    std::vector<MoveRule> knight_rules;

    move_rule = MoveRule();
    move_rule.move_dir = {2, 1};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 2};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 2};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-2, 1};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-2,-1};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, -2};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, -2};
    knight_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {2, -1};
    knight_rules.push_back(move_rule);

    pieces_move_rules['N'] = knight_rules;

    //BISHOP
    std::vector<MoveRule> bishop_rules;

    move_rule = MoveRule();
    move_rule.move_dir = {1, 1};
    move_rule.can_repeat = true;
    bishop_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, -1};
    move_rule.can_repeat = true;
    bishop_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 1};
    move_rule.can_repeat = true;
    bishop_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, -1};
    move_rule.can_repeat = true;
    bishop_rules.push_back(move_rule);

    pieces_move_rules['B'] = bishop_rules;

    //ROOK
    std::vector<MoveRule> rook_rules;

    move_rule = MoveRule();
    move_rule.move_dir = {0, 1};
    move_rule.can_repeat = true;
    rook_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 0};
    move_rule.can_repeat = true;
    rook_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {0, -1};
    move_rule.can_repeat = true;
    rook_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 0};
    move_rule.can_repeat = true;
    rook_rules.push_back(move_rule);

    pieces_move_rules['R'] = rook_rules;

    //QUEEN
    std::vector<MoveRule> queen_rules;

    move_rule = MoveRule();
    move_rule.move_dir = {0, 1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 0};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, -1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {0, -1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, -1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 0};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 1};
    move_rule.can_repeat = true;
    queen_rules.push_back(move_rule);

    pieces_move_rules['Q'] = queen_rules;

    //KING
    std::vector<MoveRule> king_rules;

    move_rule = MoveRule();
    move_rule.move_dir = {0, 1};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 1};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, 0};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {-1, -1};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {0, -1};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, -1};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 0};
    king_rules.push_back(move_rule);

    move_rule = MoveRule();
    move_rule.move_dir = {1, 1};
    king_rules.push_back(move_rule);

    pieces_move_rules['K'] = king_rules;
}

std::vector<ChessBoard::PieceMove> ChessBoard::getPossibleMoves(PlayerType player_type) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

        }
    }

    return std::vector<PieceMove>();
}

std::vector<Coordinates> ChessBoard::getPossibleMovesOfPiece(Coordinates piece_xy) {
    std::vector<Coordinates> possible_moves;

    auto it = pieces_move_rules.find(getBoardData(piece_xy));
    std::vector<MoveRule> rules = it->second;

    for (MoveRule rule : rules) {
        Coordinates maybe_pos = piece_xy;

        while (true) {
            maybe_pos.addCoordinates(rule.move_dir);

            if (!BoardData::areCoordinatesOnBoard(maybe_pos)) //move is outside the board
                break;

            if (isupper(getBoardData(maybe_pos))) //stand on your piece
                break;

            if (getBoardData(maybe_pos) == 'k') //stand on king of enemy
                break;

            maybe_pos.minusCoordinates(piece_xy);  //distracting the move_dir from maybe_pos
            possible_moves.push_back(maybe_pos);
            maybe_pos.addCoordinates(piece_xy);

            if (islower(getBoardData(maybe_pos))) //you destroyed one enemy piece
                break;

            if (!rule.can_repeat)
                break;
        }
    }

    return possible_moves;
}



