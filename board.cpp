#include "board.h"
#include "pieces.h"
#include <vector>

Board::Board(std::vector<Piece> whitePieces, std::vector<Piece> blackPieces)
    : whitePieces(whitePieces), blackPieces(blackPieces) {}

std::vector<Piece> Board::getWhitePieces() { return whitePieces; }
std::vector<Piece> Board::getBlackPieces() { return blackPieces; }

bool Board::whiteInCheck(std::vector<Piece> whitePieces,
                         std::vector<Piece> blackPieces) {
  std::vector<int> whiteKingPos;
  for (Piece piece : whitePieces) {
    if (piece.getType() == PieceType::KING) {
      whiteKingPos = piece.getPosition();
    }
  }
  for (Piece piece : blackPieces) {
    for (std::vector<int> move : piece.getMoves(*this)) {
      if (move == whiteKingPos) {
        return true;
      }
    }
  }
  return false;
}

bool Board::blackInCheck(std::vector<Piece> whitePieces,
                         std::vector<Piece> blackPieces) {
  std::vector<int> blackKingPos;
  for (Piece piece : blackPieces) {
    if (piece.getType() == PieceType::KING) {
      blackKingPos = piece.getPosition();
    }
  }
  for (Piece piece : whitePieces) {
    for (std::vector<int> move : piece.getMoves(*this)) {
      if (move == blackKingPos) {
        return true;
      }
    }
  }
  return false;
}

Piece::Piece() : position({0, 0}), white(1) {}
Piece::Piece(std::vector<int> position, bool white)
    : position(position), white(white) {}

std::vector<int> Piece::getPosition() { return position; }
std::vector<std::vector<int>> Piece::getMoves(Board &board) { return {{}}; }

PieceType Piece::getType() { return PieceType::NONE; }
bool Piece::isWhite() { return white; }
