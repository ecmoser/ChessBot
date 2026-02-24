#pragma once

#include "board.h"
#include <vector>

class Pawn : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};

class Knight : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};

class Bishop : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};

class Rook : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};

class Queen : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};

class King : public Piece {
public:
  std::vector<Move> getMoves() override;
  PieceType getType() override;
};
