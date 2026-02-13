#include "board.h"
#include <vector>

Board::Board(std::vector<Piece *> whitePieces, std::vector<Piece *> blackPieces)
    : whitePieces(whitePieces), blackPieces(blackPieces) {}

std::vector<Piece *> Board::getWhitePieces() { return whitePieces; }

std::vector<Piece *> Board::getBlackPieces() { return blackPieces; }

bool Board::whiteInCheck() {
  Piece *king;
  for (Piece *piece : whitePieces) {
    if (piece->getType() == PieceType::KING) {
      king = piece;
    }
  }
  for (Piece *piece : blackPieces) {
    for (std::vector<int> move : piece->getMoves()) {
      int pieceFile = piece->getFile() + move[0];
      int pieceRank = piece->getRank() + move[1];
      if (pieceFile == king->getFile() && pieceRank == king->getRank()) {
        return true;
      }
    }
  }
  return false;
}

bool Board::blackInCheck() {
  Piece *king;
  for (Piece *piece : blackPieces) {
    if (piece->getType() == PieceType::KING) {
      king = piece;
    }
  }
  for (Piece *piece : whitePieces) {
    for (std::vector<int> move : piece->getMoves()) {
      int pieceFile = piece->getFile() + move[0];
      int pieceRank = piece->getRank() + move[1];
      if (pieceFile == king->getFile() && pieceRank == king->getRank()) {
        return true;
      }
    }
  }
  return false;
}

Piece::Piece() : white(1) {}

Piece::Piece(Board *board, int file, int rank, bool white)
    : board(board), file(file), rank(rank), white(white) {}

std::vector<std::vector<int>> Piece::getMoves() { return {{}}; }

PieceType Piece::getType() { return PieceType::NONE; }

int Piece::getFile() { return file; }

int Piece::getRank() { return rank; }

void Piece::move(std::vector<int> move) {
  file += move[0];
  rank += move[1];
}

bool Piece::isWhite() { return white; }
