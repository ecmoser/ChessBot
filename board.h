#pragma once

#include <vector>

class Piece;
class Move;

enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };

class Board {
public:
  Board(std::vector<Piece *> whitePieces, std::vector<Piece *> blackPieces);
  std::vector<Piece *> getWhitePieces();
  std::vector<Piece *> getBlackPieces();
  bool whiteInCheck();
  bool blackInCheck();
  std::vector<Move> getMoves();
  void makeMove(Move move);

private:
  std::vector<Piece *> whitePieces;
  std::vector<Piece *> blackPieces;
  std::vector<Move> moves;
};

class Piece {
public:
  Piece();
  Piece(Board *board, int file, int rank, bool isWhite);
  virtual std::vector<Move> getMoves();
  virtual PieceType getType();
  int getFile();
  int getRank();
  void moveTo(int newFile, int newRank);
  bool isWhite();

protected:
  int file;
  int rank;
  Board *board;
  const bool white;
};

class Move {
public:
  Move(Piece *piece, int file, int rank);
  Piece *getPiece();
  int getFile();
  int getRank();

private:
  Piece *piece;
  int file;
  int rank;
};
