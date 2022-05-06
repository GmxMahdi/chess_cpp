/* Project : Chess Game Project INF1015
*  File : Position.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe définie les positions dans l'échéquiers 
*					en les divisant par lignes et colonnes.
*					
*/

#pragma once
#include <unordered_map>


namespace GameModel
{
	class Position
	{
	public:
		//! Constructs a position with default values.
		Position() : _row(0), _col(0) {}

		//! Constructs a position with a defined row and col.
		/*!
			\param row
			\param col
		*/
		Position(int row, int col) : _row(row), _col(col) {}

		//! Constructs a position from another position
		/*!
			\param position position to copy
		*/
		Position(const Position& position) : _row(position._row), _col(position._col) {}

	public:
		//! Gets the row.
		int getRow() const { return _row; }

		//! Gets the column.
		int getCol() const { return _col; }

		//! Sets the row.
		void setRow(int row) { _row = row; }

		//! Sets the column.
		void setCol(int col) { _col = col; }

		//! Sets the row and column based on a position.
		void set(Position position) { _row = position.getRow(); _col = position.getCol(); }

		//! Overload of the == operator.
		//! Check if two Position instances have
		//! the same row and column attributes.
		bool operator==(const Position& position) const
		{
			return (position._row == _row && position._col == _col);
		}

	private:
		int _row;
		int _col;
	};
}
// Hashing for std::unordered_set<Position>
namespace std {
	template<> struct hash<GameModel::Position> {
		size_t operator() (const GameModel::Position& position) const noexcept
		{
			return hash<int>{}(position.getRow())
				^ (hash<int>{}(position.getCol()) * 10);
		}
	};
}