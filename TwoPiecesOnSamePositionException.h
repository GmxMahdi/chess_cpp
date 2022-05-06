/* Project : Chess Game Project INF1015
*  File : TooPiecesOnSamePositionException.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe permet de levée l'exception
*					s'il y a plus d'une pièce sur la même
*					case.
*/

#pragma once
#include <stdexcept>

namespace GameModel
{
	class TwoPiecesOnSamePositionException : public std::logic_error
	{
	public:
		//! Constructs the exception with a custom message.
		TwoPiecesOnSamePositionException(const std::string& msg = "") :
			logic_error(msg) {}
	};
}