#pragma once

#include <vector>

class Piece;

enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };

class Board {
public:
  Board(std::vector<Piece> whitePieces, std::vector<Piece> blackPieces);
  std::vector<Piece> getWhitePieces();
  std::vector<Piece> getBlackPieces();
  bool whiteInCheck(std::vector<Piece> whitePieces,
                    std::vector<Piece> blackPieces);
  bool blackInCheck(std::vector<Piece> whitePieces,
                    std::vector<Piece> blackPieces);

private:
  std::vector<Piece> whitePieces;
  std::vector<Piece> blackPieces;
};

class Piece {
public:
  Piece();
  Piece(std::vector<int> position, bool isWhite);
  virtual std::vector<std::vector<int>> getMoves(Board &board);
  virtual PieceType getType();
  std::vector<int> getPosition();
  bool isWhite();

private:
  std::vector<int> position;
  const bool white;
};
