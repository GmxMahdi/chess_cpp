#include "Position.h"

using namespace std;

//namespace std {
//	template<> struct hash<Position> {
//		size_t operator() (const Position& position) const noexcept
//		{
//			return hash<int>{}(position.getX())
//				^ (hash<int>{}(position.getY()) * 10);
//		}
//	};
//}