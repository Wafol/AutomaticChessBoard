
#ifndef CHESSALGORITHM_CHESSBOARD_H
#define CHESSALGORITHM_CHESSBOARD_H

#include "BoardData.h"
#include <vector>
#include <map>


class ChessBoard : public BoardData {


public:
    ChessBoard();


private:

    typedef struct PieceMove {
        Coordinates start;
        Coordinates end;
    } PieceMove;



    typedef struct MoveRule {
        Coordinates move_dir{};

        bool can_repeat = false; //this is true when move can be done multiple times and is still valid (example: bishop NO, rook YES)
        bool can_step_over_enemy = false; //when false piece cannot go over enemies
        bool only_first_touch = false; //when this is true it means that the move can be applied only when the piece is played for the first time
        bool only_to_attack_enemy = false; //this bool is there only bcs pawn attack diagonally
    } MoveRule;

    //pieces by char, LOWERCASE
    std::map<char, std::vector<MoveRule>> piecesMoveRules;


    std::vector<PieceMove> getPossibleMoves(PlayerType player_type);





};


#endif //CHESSALGORITHM_CHESSBOARD_H
