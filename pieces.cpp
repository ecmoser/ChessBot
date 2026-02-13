#include "board.h"
#include "pieces.h"

PieceType Pawn::getType() { return PieceType::PAWN; }

std::vector<std::vector<int>> Pawn::getMoves() {
  std::vector<std::vector<int>> moves{};
  if (isWhite()) {
    std::vector<std::vector<int>> tryMoves = {{0, 1}};
    if (getRank() == 1) {
      tryMoves.push_back({0, 2});
    }
    for (std::vector<int> move : tryMoves) {
      bool valid{true};
      std::vector<int> tryPos{getFile() + move[0], getRank() + move[1]};
      for (Piece *wPiece : board->getWhitePieces()) {
        if (wPiece->getFile() == tryPos[0] && wPiece->getRank() == tryPos[1]) {
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
        moves.push_back({1, 1});
      } else if (bPiece->getFile() == getFile() - 1 &&
                 bPiece->getRank() == getRank() + 1) {
        moves.push_back({-1, 1});
      }
    }
  } else {
    std::vector<std::vector<int>> tryMoves = {{0, -1}};
    if (getRank() == 6) {
      tryMoves.push_back({0, -2});
    }
    for (std::vector<int> move : tryMoves) {
      bool valid{true};
      std::vector<int> tryPos{getFile() + move[0], getRank() + move[1]};
      for (Piece *wPiece : board->getWhitePieces()) {
        if (wPiece->getFile() == tryPos[0] && wPiece->getRank() == tryPos[1]) {
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
        moves.push_back({1, -1});
      } else if (bPiece->getFile() == getFile() - 1 &&
                 bPiece->getRank() == getRank() - 1) {
        moves.push_back({-1, -1});
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
