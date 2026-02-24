#include "board.h"
#include <vector>

Board::Board(std::vector<Piece *> whitePieces, std::vector<Piece *> blackPieces)
    : whitePieces(whitePieces), blackPieces(blackPieces) {
  moves = {};
}

std::vector<Piece *> Board::getWhitePieces() { return whitePieces; }

std::vector<Piece *> Board::getBlackPieces() { return blackPieces; }

std::vector<Move> Board::getMoves() { return moves; }

void Board::makeMove(Move move) {
  move.getPiece()->moveTo(move.getFile(), move.getRank());
  moves.push_back(move);
}

bool Board::whiteInCheck() {
  Piece *king;
  for (Piece *piece : whitePieces) {
    if (piece->getType() == PieceType::KING) {
      king = piece;
    }
  }
  for (Piece *piece : blackPieces) {
    for (Move move : piece->getMoves()) {
      if (move.getFile() == king->getFile() &&
          move.getRank() == king->getRank()) {
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
    for (Move move : piece->getMoves()) {
      if (move.getFile() == king->getFile() &&
          move.getRank() == king->getRank()) {
        return true;
      }
    }
  }
  return false;
}

Piece::Piece() : white(1) {}

Piece::Piece(Board *board, int file, int rank, bool white)
    : board(board), file(file), rank(rank), white(white) {}

std::vector<Move> Piece::getMoves() { return {}; }

PieceType Piece::getType() { return PieceType::NONE; }

int Piece::getFile() { return file; }

int Piece::getRank() { return rank; }

void Piece::moveTo(int newFile, int newRank) {
  file = newFile;
  rank = newRank;
}

bool Piece::isWhite() { return white; }

Move::Move(Piece *piece, int file, int rank)
    : piece(piece), file(file), rank(rank) {}

Piece *Move::getPiece() { return piece; }

int Move::getFile() { return file; }

int Move::getRank() { return rank; }
