#include "board.h"
#include "pieces.h"

PieceType Pawn::getType() { return PieceType::PAWN; }

std::vector<Move> Pawn::getMoves() {
  std::vector<Move> moves{};
  if (isWhite()) {
    std::vector<Move> tryMoves = {Move(this, file, rank + 1)};
    if (getRank() == 1) {
      tryMoves.push_back(Move(this, file, rank + 2));
    }
    for (Move move : tryMoves) {
      bool valid{true};
      for (Piece *wPiece : board->getWhitePieces()) {
        if (wPiece->getFile() == move.getFile() &&
            wPiece->getRank() == move.getRank()) {
          valid = false;
          break;
        }
      }
      if (valid) {
        moves.push_back(move);
      }
    }
    for (Piece *bPiece : board->getBlackPieces()) {
      if (bPiece->getFile() == getFile() + 1 &&
          bPiece->getRank() == getRank() + 1) {
        moves.push_back(Move(this, file + 1, rank + 1));
      } else if (bPiece->getFile() == getFile() - 1 &&
                 bPiece->getRank() == getRank() + 1) {
        moves.push_back(Move(this, file - 1, rank + 1));
      }
    }
  } else {
    std::vector<Move> tryMoves = {Move(this, file, rank - 1)};
    if (getRank() == 6) {
      tryMoves.push_back(Move(this, file, rank - 2));
    }
    for (Move move : tryMoves) {
      bool valid{true};
      for (Piece *wPiece : board->getWhitePieces()) {
        if (wPiece->getFile() == move.getFile() &&
            wPiece->getRank() == move.getRank()) {
          valid = false;
          break;
        }
      }
      if (valid) {
        moves.push_back(move);
      }
    }
    for (Piece *bPiece : board->getBlackPieces()) {
      if (bPiece->getFile() == getFile() + 1 &&
          bPiece->getRank() == getRank() - 1) {
        moves.push_back(Move(this, file + 1, rank - 1));
      } else if (bPiece->getFile() == getFile() - 1 &&
                 bPiece->getRank() == getRank() - 1) {
        moves.push_back(Move(this, file - 1, rank - 1));
      }
    }
  }
  return moves;
}

PieceType Knight::getType() { return PieceType::KNIGHT; }

PieceType Bishop::getType() { return PieceType::BISHOP; }

PieceType Rook::getType() { return PieceType::ROOK; }

PieceType Queen::getType() { return PieceType::QUEEN; }

PieceType King::getType() { return PieceType::KING; }
