#include "board.h"
#include "pieces.h"

PieceType Pawn::getType() { return PieceType::PAWN; }

PieceType Knight::getType() { return PieceType::KNIGHT; }

PieceType Bishop::getType() { return PieceType::BISHOP; }

PieceType Rook::getType() { return PieceType::ROOK; }

PieceType Queen::getType() { return PieceType::QUEEN; }

PieceType King::getType() { return PieceType::KING; }
