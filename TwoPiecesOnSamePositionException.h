#pragma once
#include <stdexcept>

namespace GameModel
{
	class TwoPiecesOnSamePositionException : public std::logic_error
	{
	public:
		TwoPiecesOnSamePositionException(const std::string& msg = "") :
			logic_error(msg) {}
	};
}