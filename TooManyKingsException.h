#pragma once
#include <stdexcept>

namespace GameModel
{
	class TooManyKingsException : public std::runtime_error 
	{
	public:
		TooManyKingsException(const std::string& msg = "") :
			runtime_error(msg){}
	};
}