#pragma once

#include <vector>

class Piece;

enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };

class Board {
public:
  Board(std::vector<Piece *> whitePieces, std::vector<Piece *> blackPieces);
  std::vector<Piece *> getWhitePieces();
  std::vector<Piece *> getBlackPieces();
  bool whiteInCheck();
  bool blackInCheck();

private:
  std::vector<Piece *> whitePieces;
  std::vector<Piece *> blackPieces;
};

class Piece {
public:
  Piece();
  Piece(Board *board, int file, int rank, bool isWhite);
  virtual std::vector<std::vector<int>> getMoves();
  virtual PieceType getType();
  int getFile();
  int getRank();
  void move(std::vector<int> move);
  bool isWhite();

protected:
  int file;
  int rank;
  Board *board;
  const bool white;
};
