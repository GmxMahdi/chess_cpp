/* Project : Chess Game Project INF1015
*  File : TooManyKingsException.h
*  Authors : Djouhri, Anissa
			 Krayem, Mahdi Adnan
*  Last modification : 5 May 2022
*  Description :	La classe permet de levée l'exception 
*					s'il y a plus d'un roi par joueur dans 
*					le jeu.
*/
#pragma once
#include <stdexcept>

namespace GameModel
{
	class TooManyKingsException : public std::runtime_error 
	{
	public:
		//! Constructs the exception with a custom message.
		TooManyKingsException(const std::string& msg = "") :
			runtime_error(msg){}
	};
}