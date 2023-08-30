#ifndef CHESSALGORITHM_CHESSBOARD_H
#define CHESSALGORITHM_CHESSBOARD_H

#include "BoardData.h"
#include <vector>
#include <map>
#include <string>


class ChessBoard : public BoardData {
    typedef struct PieceMove {
        Coordinates start;
        Coordinates end;
    } PieceMove;

    typedef struct MoveRule {
        Coordinates move_dir{};

        bool can_repeat = false; //this is true when move can be done multiple times and is still valid (example: bishop NO, rook YES)
        //bool can_step_over_enemy = false; //when false piece cannot go over enemies
        bool only_first_touch = false; //when this is true it means that the move can be applied only when the piece is played for the first time
        bool only_to_attack_enemy = false; //this bool is there only bcs pawn attack diagonally
    } MoveRule;

public:
    ChessBoard();
    void movePiece(PieceMove piece_move);
    //returns false if the string format is wrong
    bool movePiece(std::string piece_move_txt);

    void showPossibleMovesOfPiece(Coordinates piece_xy);

private:
    //pieces by char, UPPERCASE
    std::map<char, std::vector<MoveRule>> pieces_move_rules;


    std::map<Coordinates, std::vector<Coordinates>> getPossibleMoves(PlayerType player_type);
    //if it doesnt recognise piece ('.' for example) it returns empty vector
    std::vector<Coordinates> getPossibleMovesOfPiece(Coordinates piece_xy);

    //ALWAYS check if the piece is really pawn and if the board has the right orientation
    static bool isPawnInInitialPosition(Coordinates pawn_xy) { return pawn_xy.y == 1; };
    bool canPawnAttack(Coordinates pawn_xy, MoveRule rule) const;
};


#endif //CHESSALGORITHM_CHESSBOARD_H
