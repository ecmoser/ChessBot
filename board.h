#pragma once

#include <vector>

class Piece;

enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };

class Board {
public:
  Board(std::vector<Piece> pieces);
  std::vector<Piece> getPieces();

private:
  std::vector<Piece> pieces;
};

class Piece {
public:
  Piece();
  Piece(std::vector<int> position, bool isWhite);
  virtual std::vector<int> getPosition();
  virtual std::vector<std::vector<int>> getMoves(const Board &board);
  virtual PieceType getType();
  virtual bool getWhite();

private:
  std::vector<int> position;
  const bool isWhite;
};
