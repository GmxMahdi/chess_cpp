#include "DisposableMove.h"

using namespace GameModel;

DisposableMove::DisposableMove(Piece* piece, Piece* (&board)[8][8])
	: _pieceToMove(piece), _pieceSteppedOn(nullptr), _board(board)
{
	_srcPos = _pieceToMove->_position;
}

void DisposableMove::movePiece(Position dst)
{
	_pieceToMove->_position = dst;
	_dstPos = dst;
	_pieceSteppedOn = _board[dst.getRow()][dst.getCol()];
	if (_pieceSteppedOn != nullptr)
		_pieceSteppedOn->_isAlive = false;

	// Remove piece from src pos
	_board[_srcPos.getRow()][_srcPos.getCol()] = nullptr;

	// Put piece on dst
	_board[dst.getRow()][dst.getCol()] = _pieceToMove;
}

DisposableMove::~DisposableMove()
{
	_pieceToMove->_position = _srcPos;
	if (_pieceSteppedOn != nullptr)
		_pieceSteppedOn->_isAlive = true;
		

	// Put back piece that was originally in the destination
	_board[_dstPos.getRow()][_dstPos.getCol()] = _pieceSteppedOn;

	// Put back piece that moved
	_board[_srcPos.getRow()][_srcPos.getCol()] = _pieceToMove;

}
