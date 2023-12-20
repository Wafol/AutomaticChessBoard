#include "ChessBoard.h"
#include <iostream>
#include <cctype>
#include <regex>


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

void ChessBoard::movePiece(ChessBoard::PieceMove piece_move) {
    char piece = getBoardData(piece_move.start);

    setBoardData(piece_move.start, '.');
    setBoardData(piece_move.end, piece);
}

bool ChessBoard::movePiece(std::string piece_move_txt) {
    std::regex pattern("([a-hA-H])([1-8])([a-hA-H])([1-8])$");
    if (!std::regex_match(piece_move_txt, pattern))
        return false;

    PieceMove piece_move;
    piece_move.start.x = piece_move_txt[0] - 'a';
    piece_move.start.y = piece_move_txt[1] - '0' - 1;
    piece_move.end.x = piece_move_txt[2] - 'a';
    piece_move.end.y = piece_move_txt[3] - '0' - 1;

    movePiece(piece_move);

    return true;
}

void ChessBoard::showPossibleMovesOfPiece(Coordinates piece_xy) {
    std::vector<Coordinates> possible_moves = getPossibleMovesOfPiece(piece_xy);
    BoardData::showPossibleMovesOfPiece(possible_moves, piece_xy);

}


std::map<Coordinates, std::vector<Coordinates>> ChessBoard::getPossibleMoves(PlayerType player_type) {
    std::map<Coordinates, std::vector<Coordinates>> possible_moves;
    if (player_type == PLAYER_2) flipBoardData();

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Coordinates piece_xy = {x, y};
            possible_moves.insert(std::make_pair(piece_xy, getPossibleMovesOfPiece(piece_xy)));
        }
    }

    if (player_type == PLAYER_2) flipBoardData();
    return possible_moves;
}

std::vector<Coordinates> ChessBoard::getPossibleMovesOfPiece(Coordinates piece_xy) {
    std::vector<Coordinates> possible_moves;

    auto it = pieces_move_rules.find(getBoardData(piece_xy));
    if (it == pieces_move_rules.end()) return possible_moves;
    std::vector<MoveRule> rules = it->second;

    for (MoveRule rule : rules) {
        Coordinates maybe_pos = piece_xy;

        while (true) {
            maybe_pos.addCoordinates(rule.move_dir);

            ///general///
            if (!BoardData::areCoordinatesOnBoard(maybe_pos)) break; //move is outside the board
            if (isupper(getBoardData(maybe_pos))) break; //stand on your piece
            if (getBoardData(maybe_pos) == 'k') break; //stand on king of enemy

            ///pawn rules///
            if (getBoardData(piece_xy) == 'P') {
                if (rule.only_first_touch && !isPawnInInitialPosition(piece_xy)) break; //discards the first move of pawn if the pawn is not in init position
                if (rule.only_to_attack_enemy && !canPawnAttack(piece_xy, rule)) break;
            }

            maybe_pos.minusCoordinates(piece_xy);  //distracting the move_dir from maybe_pos
            possible_moves.push_back(maybe_pos);
            maybe_pos.addCoordinates(piece_xy);
            if (!rule.can_repeat) break; //if the move should not repeat

            ///repeating move pieces///
            if (islower(getBoardData(maybe_pos))) break;  //end repeating when you destroyed one enemy piece
        }
    }

    return possible_moves;
}


bool ChessBoard::canPawnAttack(Coordinates pawn_xy, ChessBoard::MoveRule rule) const {
    Coordinates maybe_pos = pawn_xy.addCoordinates(rule.move_dir);
    return islower(getBoardData(maybe_pos));
}









