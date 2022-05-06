// Les test pour le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "ChessGame.h"
#include "BoardSetupTest.h"
#include "BoardSetupClassic.h"
#include "BoardSetupQueenMarathon.h"
#include "BoardSetupPawnsBehind.h"
#include "BoardSetupRooksCentered.h"
#include "BoardSetupRandom.h"

using namespace GameModel;

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(ChessGame, alternating_turns) {
	GameModel::ChessGame game;
	game.setupBoard(new BoardSetupTest());
	game.printBoard();

	EXPECT_FALSE(game.movePiece({ 1,0 }, { 2,0 })); // It is not blacks turn
	EXPECT_TRUE(game.movePiece({ 6,0 }, { 5,0 }));

	EXPECT_FALSE(game.movePiece({ 5,0 }, { 4,0 })); // It is not whites turn
	EXPECT_TRUE(game.movePiece({ 1,0 }, { 2,0 }));

	EXPECT_FALSE(game.movePiece({ 2,0 }, { 3,0 })); // It is not blacks turn
	EXPECT_TRUE(game.movePiece({ 5,0 }, { 4,0 }));

	EXPECT_EQ(game.getGameState(), ChessGame::State::PLAYING);
	game.printBoard();
}

TEST(ChessGame, illegal_moves) {
	GameModel::ChessGame game;
	game.setupBoard(new BoardSetupTest());
	game.printBoard();
	EXPECT_FALSE(game.movePiece({ 6,1 }, { 5,1 })); // Moving pawn puts king in check
	EXPECT_TRUE(game.movePiece({ 6,0 }, { 5,0 }));
	EXPECT_TRUE(game.movePiece({ 0,7 }, { 7,7 }));

	game.printBoard();
	EXPECT_FALSE(game.movePiece({ 7,1 }, { 5,2 })); // Cannot move knight, will put king in danger
	EXPECT_TRUE(game.movePiece({ 7,0 }, { 6,0 }));
	EXPECT_TRUE(game.movePiece({ 7,7 }, { 7,3 }));

	EXPECT_FALSE(game.movePiece({ 6,0 }, { 5,1 })); // Cannot move king in line of sight of queen
	EXPECT_TRUE(game.movePiece({ 7,1 }, { 5,2 }));  // But we can now move the knight

	EXPECT_EQ(game.getGameState(), ChessGame::State::PLAYING);
	game.printBoard();
}

TEST(ChessGame, king_in_check) {
	GameModel::ChessGame game;
	game.setupBoard(new BoardSetupTest());
	game.printBoard();

	// Move white queen in front of  black king
	EXPECT_TRUE(game.movePiece({ 7,7 }, { 1,1 }));

	EXPECT_EQ(game.getGameState(), ChessGame::State::CHECK);
	game.printBoard();

	EXPECT_FALSE(game.movePiece({ 0,7 }, { 1,7 })); // Cannot move black queen, king still in check
	EXPECT_FALSE(game.movePiece({ 0,7 }, { 2,7 })); // ''
	EXPECT_FALSE(game.movePiece({ 0,7 }, { 7,7 })); // ''

	EXPECT_FALSE(game.movePiece({ 0,1 }, { 2,0 })); // Cannot move black knight, king still in check
	EXPECT_FALSE(game.movePiece({ 0,1 }, { 2,2 })); // ''
	EXPECT_FALSE(game.movePiece({ 0,1 }, { 1,3 })); // ''

	EXPECT_TRUE(game.movePiece({ 0,0 }, { 1,1 })); // Move black king, capture white queen
	EXPECT_EQ(game.getGameState(), ChessGame::State::PLAYING);
	game.printBoard();


}

TEST(ChessGame, checkmate) {
	GameModel::ChessGame game;
	game.setupBoard(new BoardSetupTest());
	game.printBoard();
	EXPECT_TRUE(game.movePiece({ 7,1 }, { 5,0 })); // Move white knight away
	EXPECT_TRUE(game.movePiece({ 1,0 }, { 3,0 })); // Move random black pawn
	EXPECT_TRUE(game.movePiece({ 5,0 }, { 3,1 })); // Move white knight further
	EXPECT_TRUE(game.movePiece({ 0,7 }, { 7,7 })); // Move queen, put white king in checkmate

	EXPECT_EQ(game.getGameState(), ChessGame::State::CHECKMATE);
	game.printBoard();
}

TEST(ChessGame, rest_of_coverage)
{
	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupTest());
		game.getErrorMessages();
		game.getPiece({ 0, 0 });
		game.getPiece({ 7, 4 });
		game.getPiece(0, 0);
		game.getPiece(7, 4);
		game.getPiece(99, 99);
		game.getCurrentPlayerColor();
		game.getCurrentPlayerKingPosition();
	}

	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupClassic());
		game.getPiece(1, 0)->getImageName();
		game.getPiece(1, 0)->getColor();

		for (int i = 0; i < 8; ++i)
			game.getPiece(0, i)->getImageName();
		game.movePiece({ 6,0 }, { 5,0 });
		game.printBoard();

		Player a(Color::WHITE);
		Player b(a);
	}
	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupQueenMarathon());
	}
	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupPawnsBehind());
	}
	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupRooksCentered());
	}

	{
		GameModel::ChessGame game;
		game.setupBoard(new BoardSetupRandom());
	}
}

#endif
