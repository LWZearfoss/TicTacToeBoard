/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, toggleTurnOnce)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, placePieceOnce)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceRowLessThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(-1, 0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceRowGreaterThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceColumnLessThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, -1), Invalid);
}

TEST(TicTacToeBoardTest, placePieceColumnGreaterThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 3), Invalid);
}

TEST(TicTacToeBoardTest, placePieceTwice)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.placePiece(0, 1), O);
}

TEST(TicTacToeBoardTest, placePieceSamePlace)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.placePiece(0, 0), X);
  ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, getPieceRowLessThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(-1, 0), Invalid);
}

TEST(TicTacToeBoardTest, getPieceRowGreaterThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, getPieceColumnLessThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, -1), Invalid);
}

TEST(TicTacToeBoardTest, getPieceColumnGreaterThanBoard)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, 3), Invalid);
}

TEST(TicTacToeBoardTest, getPieceBlank)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, getPieceXAfterPlacement)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceOAfterPlacement)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(1, 0);
  ASSERT_EQ(board.getPiece(1, 0), O);
}

TEST(TicTacToeBoardTest, getWinnerNotFinished)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerHorizontal)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.toggleTurn();
  board.placePiece(0, 1);
  board.toggleTurn();
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerVertical)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.toggleTurn();
  board.placePiece(1, 0);
  board.toggleTurn();
  board.placePiece(2, 0);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalOne)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(2, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalTwo)
{
  TicTacToeBoard board;
  board.placePiece(2, 0);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerO)
{
  TicTacToeBoard board;
  board.toggleTurn();
  board.placePiece(0, 0);
  board.toggleTurn();
  board.placePiece(0, 1);
  board.toggleTurn();
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerNoWinner)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(0, 1);
  board.placePiece(0, 2);
  board.placePiece(1, 1);
  board.placePiece(1, 0);
  board.placePiece(1, 2);
  board.placePiece(2, 1);
  board.placePiece(2, 0);
  board.placePiece(2, 2);
  ASSERT_EQ(board.getWinner(), Blank);
}
