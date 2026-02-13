#include "board.h"
#include <vector>

Board::Board(std::vector<Piece> pieces) : pieces(pieces) {}

std::vector<Piece> Board::getPieces() { return pieces; }

Piece::Piece() : position({0, 0}), isWhite(1) {}
Piece::Piece(std::vector<int> position, bool isWhite)
    : position(position), isWhite(isWhite) {}

std::vector<int> Piece::getPosition() { return position; }
std::vector<std::vector<int>> Piece::getMoves(const Board &board) {
  return {{}};
}
PieceType Piece::getType() { return PieceType::NONE; }
bool Piece::getWhite() { return isWhite; }
