#pragma once
#include <unordered_map>


namespace GameModel
{
	class Position
	{
	public:
		Position() : _row(0), _col(0) {}
		Position(int x, int y) : _row(x), _col(y) {}
		Position(const Position& position) : _row(position._row), _col(position._col) {}

	public:
		int getRow() const { return _row; }
		int getCol() const { return _col; }
		void setRow(int pos) { _row = pos; }
		void setCol(int pos) { _col = pos; }
		void set(Position position) { _row = position.getRow(); _col = position.getCol(); }

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